#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "&str       = " << &str << "\n";
	std::cout << "&stringPTR = " << stringPTR << "\n";
	std::cout << "&stringREF = " << &stringREF << "\n";
	
	
	std::cout << "str        = " << str << "\n";
	std::cout << "*stringPTR = " << *stringPTR << "\n";
	std::cout << "stringREF  = " << stringREF << "\n";
	
}
