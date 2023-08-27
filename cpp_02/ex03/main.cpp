#include <iostream>
#include "Point.hpp"

int main( void ) {
	Point A(0,0);
	Point B(4,0);
	Point C(2,4);

	Point P(2,2);
	
	std::cout << "A: " << A << std::endl;
	std::cout << "B: " << B << std::endl;
	std::cout << "C: " << C << std::endl;
	std::cout << "P: " << P << std::endl;

	bool answer = bsp(A,B,C,P);
	std::cout << "Is Inside: " << answer << std::endl;
	return 0;
}