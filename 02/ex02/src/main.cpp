#include "Fixed.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing Constructors ===" << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	std::cout << "a (default): " << a << std::endl;
	std::cout << "b (int 10): " << b << std::endl;
	std::cout << "c (float 42.42): " << c << std::endl;
	std::cout << "d (copy of b): " << d << std::endl;

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	a = Fixed(1234.4321f);
	std::cout << "a after assignment: " << a << std::endl;

	std::cout << "\n=== Testing Arithmetic Operators ===" << std::endl;
	Fixed x(5.5f);
	Fixed y(2.5f);
	float fx = 5.5f;
	float fy = 2.5f;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x + y = " << (x + y) << " (FPU: " << (fx + fy) << ")" << std::endl;
	std::cout << "x - y = " << (x - y) << " (FPU: " << (fx - fy) << ")" << std::endl;
	std::cout << "x * y = " << (x * y) << " (FPU: " << (fx * fy) << ")" << std::endl;
	std::cout << "x / y = " << (x / y) << " (FPU: " << (fx / fy) << ")" << std::endl;

	std::cout << "\n=== Testing Unary Minus ===" << std::endl;
	Fixed z(10.5f);
	std::cout << "z = " << z << std::endl;
	std::cout << "-z = " << (-z) << std::endl;

	std::cout << "\n=== Testing Increment/Decrement Operators ===" << std::endl;
	Fixed n(5.25f);
	std::cout << "n = " << n << std::endl;
	std::cout << "++n = " << ++n << std::endl;
	std::cout << "n = " << n << std::endl;
	std::cout << "n++ = " << n++ << std::endl;
	std::cout << "n = " << n << std::endl;
	std::cout << "--n = " << --n << std::endl;
	std::cout << "n = " << n << std::endl;
	std::cout << "n-- = " << n-- << std::endl;
	std::cout << "n = " << n << std::endl;

	std::cout << "\n=== Testing Comparison Operators ===" << std::endl;
	Fixed p(10.5f);
	Fixed q(5.5f);
	Fixed r(10.5f);
	std::cout << "p = " << p << ", q = " << q << ", r = " << r << std::endl;
	std::cout << "p > q: " << (p > q ? "true" : "false") << std::endl;
	std::cout << "p < q: " << (p < q ? "true" : "false") << std::endl;
	std::cout << "p >= r: " << (p >= r ? "true" : "false") << std::endl;
	std::cout << "p <= r: " << (p <= r ? "true" : "false") << std::endl;
	std::cout << "p == r: " << (p == r ? "true" : "false") << std::endl;
	std::cout << "p != q: " << (p != q ? "true" : "false") << std::endl;

	std::cout << "\n=== Testing Min/Max Static Functions ===" << std::endl;
	Fixed m1(42.5f);
	Fixed m2(21.25f);
	std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
	std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
	std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

	std::cout << "\n=== Testing toInt() and toFloat() ===" << std::endl;
	Fixed conv(42.42f);
	std::cout << "conv = " << conv << std::endl;
	std::cout << "conv.toInt() = " << conv.toInt() << std::endl;
	std::cout << "conv.toFloat() = " << conv.toFloat() << std::endl;

	std::cout << "\n=== Testing Edge Cases ===" << std::endl;
	Fixed zero(0);
	Fixed negative(-15.75f);
	std::cout << "zero = " << zero << std::endl;
	std::cout << "negative = " << negative << std::endl;
	std::cout << "zero + negative = " << (zero + negative) << std::endl;
	std::cout << "negative * negative = " << (negative * negative) << std::endl;

	return 0;
}
