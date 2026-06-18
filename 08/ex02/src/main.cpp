#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <ostream>
#include <stack>
#include <string>

// Helper template to print any iterable container
template <typename T> void printContainer(T &c, const std::string &name)
{
	std::cout << name << " contents: ";
	typename T::iterator it	 = c.begin();
	typename T::iterator ite = c.end();
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

// Overload for const containers
template <typename T> void printContainer(const T &c, const std::string &name)
{
	std::cout << name << " contents (const): ";
	typename T::const_iterator it  = c.begin();
	typename T::const_iterator ite = c.end();
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

// ==========================================
// 1. The mandatory subject test
// ==========================================
void subjectTest()
{
	std::cout << "=== Subject Test ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Copied to std::stack size: " << s.size() << std::endl;
}

// ==========================================
// 2. Empty Stack test
// ==========================================
void testEmpty()
{
	std::cout << "\n=== Empty Stack Test ===" << std::endl;
	MutantStack<int> mstack;

	if (mstack.begin() == mstack.end())
		std::cout << "Begin equals end on empty stack. (Success)" << std::endl;
	else
		std::cout << "Error: Begin does not equal end on empty stack!"
				  << std::endl;
}

// ==========================================
// 3. Const-Correctness test
// ==========================================
void testConst()
{
	std::cout << "\n=== Const Container Test ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);

	// Create a const reference to the stack
	const MutantStack<int> constMstack(mstack);

	// This will only compile if you defined `const_iterator` and `const`
	// versions of begin() and end()
	MutantStack<int>::const_iterator cit  = constMstack.begin();
	MutantStack<int>::const_iterator cite = constMstack.end();

	std::cout << "Iterating const stack: ";
	while (cit != cite) {
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;
}

// ==========================================
// 4. Copy Assignment Operator test
// ==========================================
void testAssignment()
{
	std::cout << "\n=== Assignment Operator Test ===" << std::endl;
	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);

	MutantStack<int> assigned;
	assigned.push(99); // Put some junk in it first

	assigned = original; // Test operator=

	printContainer(original, "Original");
	printContainer(assigned, "Assigned ");

	// Modify the assigned one to ensure they are deep copies (separate memory)
	assigned.push(4);
	std::cout << "After pushing 4 to 'assigned'..." << std::endl;
	printContainer(original, "Original");
	printContainer(assigned, "Assigned ");
}

// ==========================================
// 5. Different Data Type (std::string) test
// ==========================================
void testStrings()
{
	std::cout << "\n=== String Test ===" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World!");
	strStack.push("42");

	strStack.pop(); // Remove "42"

	printContainer(strStack, "String Stack");
}

// ==========================================
// 6. Direct comparison with std::list
// ==========================================
void testAgainstList()
{
	std::cout << "\n=== Comparison with std::list ===" << std::endl;
	MutantStack<int> mstack;
	std::list<int>	 lst;

	// Fill both with the exact same data
	for (int i = 0; i < 10; ++i) {
		mstack.push(i * 10);
		lst.push_back(i * 10);
	}

	printContainer(mstack, "MutantStack");
	printContainer(lst, "std::list ");

	// Compare element by element
	MutantStack<int>::iterator mit	 = mstack.begin();
	std::list<int>::iterator   lit	 = lst.begin();
	bool					   match = true;

	while (mit != mstack.end()) {
		if (*mit != *lit) {
			match = false;
			break;
		}
		++mit;
		++lit;
	}

	if (match)
		std::cout << "Outputs match perfectly!" << std::endl;
	else
		std::cout << "Outputs do NOT match!" << std::endl;
}

int main()
{
	subjectTest();
	testEmpty();
	testConst();
	testAssignment();
	testStrings();
	testAgainstList();
}
