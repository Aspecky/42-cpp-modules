#include "Array.hpp"
#include <exception>
#include <iostream>
#include <string>

int main()
{
	std::cout << "=== Test 1: Default constructor (empty array) ==="
			  << std::endl;
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;

	std::cout << "\n=== Test 2: Parameterized constructor ===" << std::endl;
	Array<int> nums(5);
	std::cout << "Size: " << nums.size() << std::endl;
	for (unsigned int i = 0; i < nums.size(); i++) {
		std::cout << "nums[" << i << "] = " << nums[i] << std::endl;
	}

	std::cout << "\n=== Test 3: Assignment and modification ===" << std::endl;
	for (unsigned int i = 0; i < nums.size(); i++) {
		nums[i] = i * 10;
	}
	for (unsigned int i = 0; i < nums.size(); i++) {
		std::cout << "nums[" << i << "] = " << nums[i] << std::endl;
	}

	std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
	Array<int> copy(nums);
	std::cout << "Original: ";
	for (unsigned int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Copy:     ";
	for (unsigned int i = 0; i < copy.size(); i++) {
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n=== Test 5: Deep copy verification ===" << std::endl;
	copy[0] = 999;
	std::cout << "After modifying copy[0] to 999:" << std::endl;
	std::cout << "nums[0] = " << nums[0] << " (should be 0)" << std::endl;
	std::cout << "copy[0] = " << copy[0] << " (should be 999)" << std::endl;

	std::cout << "\n=== Test 6: Assignment operator ===" << std::endl;
	Array<int> assigned;
	assigned = nums;
	std::cout << "assigned[0] = " << assigned[0] << std::endl;
	assigned[0] = 777;
	std::cout << "After modifying assigned[0] to 777:" << std::endl;
	std::cout << "nums[0] = " << nums[0] << " (should be 0)" << std::endl;
	std::cout << "assigned[0] = " << assigned[0] << " (should be 777)"
			  << std::endl;

	std::cout << "\n=== Test 7: Self-assignment ===" << std::endl;
	nums = nums;
	std::cout << "nums[0] = " << nums[0] << " (should still be 0)" << std::endl;

	std::cout << "\n=== Test 8: Out of bounds exception (non-const) ==="
			  << std::endl;
	try {
		nums[10] = 42;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 9: Out of bounds exception (const) ==="
			  << std::endl;
	const Array<int> constNums(nums);
	try {
		std::cout << constNums[10] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 10: Different type (std::string) ===" << std::endl;
	Array<std::string> words(3);
	words[0] = "Hello";
	words[1] = "World";
	words[2] = "42";
	for (unsigned int i = 0; i < words.size(); i++) {
		std::cout << "words[" << i << "] = " << words[i] << std::endl;
	}

	std::cout << "\n=== Test 11: String copy and assignment ===" << std::endl;
	Array<std::string> wordsCopy(words);
	wordsCopy[0] = "Goodbye";
	std::cout << "words[0] = " << words[0] << " (should be Hello)" << std::endl;
	std::cout << "wordsCopy[0] = " << wordsCopy[0] << " (should be Goodbye)"
			  << std::endl;

	std::cout << "\n=== All tests passed! ===" << std::endl;

	return 0;
}
