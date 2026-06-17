#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{

	int r = rand() % 3;

	if (r == 0) {
		return new A();
	}
	if (r == 1) {
		return new B();
	}
	return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
}

void identify(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A";
		return;
	}
	catch (...) {
	}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B";
		return;
	}
	catch (...) {
	}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C";
		return;
	}
	catch (...) {
	}
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		Base *obj = generate();

		std::cout << "Via pointer: ";
		identify(obj);
		std::cout << "\n";

		std::cout << "Via reference: ";
		identify(*obj);
		std::cout << "\n";

		delete obj;
	}
	return 0;
}
