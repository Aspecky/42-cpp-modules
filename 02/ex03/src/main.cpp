#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	// Define a triangle with vertices at (0,0), (10,0), and (5,10)
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)\n" << std::endl;

	// Test 1: Point inside the triangle
	Point inside(5.0f, 5.0f);
	std::cout << "Test 1 - Point(5,5) inside: " 
			  << (bsp(a, b, c, inside) ? "TRUE ✓" : "FALSE ✗") << std::endl;

	// Test 2: Point outside the triangle (above)
	Point outside1(5.0f, 15.0f);
	std::cout << "Test 2 - Point(5,15) outside (above): " 
			  << (bsp(a, b, c, outside1) ? "TRUE ✗" : "FALSE ✓") << std::endl;

	// Test 3: Point outside the triangle (left)
	Point outside2(-5.0f, 5.0f);
	std::cout << "Test 3 - Point(-5,5) outside (left): " 
			  << (bsp(a, b, c, outside2) ? "TRUE ✗" : "FALSE ✓") << std::endl;

	// Test 4: Point outside the triangle (right)
	Point outside3(15.0f, 5.0f);
	std::cout << "Test 4 - Point(15,5) outside (right): " 
			  << (bsp(a, b, c, outside3) ? "TRUE ✗" : "FALSE ✓") << std::endl;

	// Test 5: Point on vertex (edge case)
	Point vertex(0.0f, 0.0f);
	std::cout << "Test 5 - Point(0,0) on vertex: " 
			  << (bsp(a, b, c, vertex) ? "TRUE" : "FALSE") 
			  << " (edge case)" << std::endl;

	// Test 6: Point on edge (edge case)
	Point edge(5.0f, 0.0f);
	std::cout << "Test 6 - Point(5,0) on edge: " 
			  << (bsp(a, b, c, edge) ? "TRUE" : "FALSE") 
			  << " (edge case)" << std::endl;

	// Test 7: Another inside point
	Point inside2(6.0f, 3.0f);
	std::cout << "Test 7 - Point(6,3) inside: " 
			  << (bsp(a, b, c, inside2) ? "TRUE ✓" : "FALSE ✗") << std::endl;

	// Test 8: Point outside below the base
	Point outside4(5.0f, -5.0f);
	std::cout << "Test 8 - Point(5,-5) outside (below): " 
			  << (bsp(a, b, c, outside4) ? "TRUE ✗" : "FALSE ✓") << std::endl;

	return 0;
}
