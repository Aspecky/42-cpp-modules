#!/bin/sh

# Script to expand SRCS and HEADERS variables in Makefiles
# Replaces wildcard definitions with actual file lists from make print-%

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to process a single Makefile
process_makefile() {
    makefile_path="$1"
    makefile_dir=$(dirname "$makefile_path")
    
    printf "${YELLOW}Processing: ${NC}%s\n" "$makefile_path"
    
    # Change to the Makefile's directory
    cd "$makefile_dir"
    
    # Get the expanded values, capturing stderr separately
    srcs_value=$(make print-SRCS 2>&1 | grep -v "^make\[" | grep -v "Entering directory" | grep -v "Leaving directory" | tail -1 | xargs)
    headers_value=$(make print-HEADERS 2>&1 | grep -v "^make\[" | grep -v "Entering directory" | grep -v "Leaving directory" | tail -1 | xargs)
    
    # Check if values were retrieved
    if [ -z "$srcs_value" ] && [ -z "$headers_value" ]; then
        printf "${RED}  ✗ Could not retrieve variable values (both empty)${NC}\n"
        return 1
    fi
    
    # Create a temporary file
    temp_file=$(mktemp)
    
    # Read the Makefile and replace the lines
    modified=0
    
    while IFS= read -r line; do
        # Check if this line starts the HEADERS definition
        case "$line" in
            HEADERS\ :=*|HEADERS:=*|HEADERS\ =*|HEADERS=*)
                # Check if the line contains a shell command (wildcard)
                case "$line" in
                    *'$(shell'*)
                        echo "HEADERS := $headers_value" >> "$temp_file"
                        modified=1
                        printf "${GREEN}  ✓ Updated HEADERS${NC}\n"
                        ;;
                    *)
                        echo "$line" >> "$temp_file"
                        ;;
                esac
                ;;
            SRCS\ :=*|SRCS:=*|SRCS\ =*|SRCS=*)
                # Check if the line contains a shell command (wildcard)
                case "$line" in
                    *'$(shell'*)
                        echo "SRCS := $srcs_value" >> "$temp_file"
                        modified=1
                        printf "${GREEN}  ✓ Updated SRCS${NC}\n"
                        ;;
                    *)
                        echo "$line" >> "$temp_file"
                        ;;
                esac
                ;;
            *)
                echo "$line" >> "$temp_file"
                ;;
        esac
    done < "Makefile"
    
    # Replace the original Makefile if modifications were made
    if [ "$modified" -eq 1 ]; then
        mv "$temp_file" "Makefile"
        printf "${GREEN}  ✓ Makefile updated successfully${NC}\n"
        return 0
    else
        rm "$temp_file"
        printf "${YELLOW}  ⚠ No changes made${NC}\n"
        return 1
    fi
}

# Main script
printf "${GREEN}=== Makefile Variable Expansion Script ===${NC}\n\n"

# Save the starting directory
start_dir=$(pwd)

# Find all Makefiles in the workspace
makefiles=$(find . -name "Makefile" -type f)

if [ -z "$makefiles" ]; then
    printf "${RED}No Makefiles found in the current directory tree${NC}\n"
    exit 1
fi

# Count total makefiles
total=$(echo "$makefiles" | wc -l)
printf "Found ${GREEN}%s${NC} Makefile(s)\n\n" "$total"

# Process each Makefile
current=0
success=0
failed=0

echo "$makefiles" | while IFS= read -r makefile; do
    current=$((current + 1))
    printf "\n[%s/%s]\n" "$current" "$total"
    
    if process_makefile "$makefile"; then
        success=$((success + 1))
    else
        failed=$((failed + 1))
    fi
    
    # Return to the starting directory
    cd "$start_dir"
done

# Summary
printf "\n${GREEN}=== Summary ===${NC}\n"
printf "Total: %s\n" "$total"
printf "${GREEN}Success: %s${NC}\n" "$success"
if [ "$failed" -gt 0 ]; then
    printf "${RED}Failed: %s${NC}\n" "$failed"
fi
