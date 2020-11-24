#include "Matrix.hpp"


int main()
{
	/*Matrix m1(1, 2);
	m1.setAt(0, 0, 1);
	m1.setAt(0, 1, 2);

	m1.print();
	m1.transpose();
	m1.print();
	std::cout << m1.getAt(0, 0) << " " << m1.getAt(1, 0) << std::endl;

	Matrix m2(2, 2);
	m2.setAt(0, 0, 5);
	m2.setAt(0, 1, 7);
	m2.setAt(1, 0, 2);
	m2.setAt(1, 1, 0);
	std::cout << m2.det() << std::endl;*/

	Matrix a(3, 3);
	a.setAt(0, 0, 2); a.setAt(0, 1, 4); a.setAt(0, 2, 1);
	a.setAt(1, 0, 0); a.setAt(1, 1, 2); a.setAt(1, 2, 1);
	a.setAt(2, 0, 2); a.setAt(2, 1, 1); a.setAt(2, 2, 1);
	std::cout << "det " << a.det() << std::endl;
	a.inverse().print();


	//Matrix a(4, 4);
	//a.setAt(0, 0, 1); a.setAt(0, 1, 2); a.setAt(0, 2, 3); a.setAt(0, 3, 7); // 1 2 3 7
	//a.setAt(1, 0, 8); a.setAt(1, 1, 9); a.setAt(1, 2, 4); a.setAt(1, 3, 6); // 8 9 4 6
	//a.setAt(2, 0, 7); a.setAt(2, 1, 6); a.setAt(2, 2, 5); a.setAt(2, 3, 5); // 7 6 5 5
	//a.setAt(3, 0, 1); a.setAt(3, 1, 2); a.setAt(3, 2, 3); a.setAt(3, 3, 4); // 1 2 3 4
	//std::cout << "det " << a.det() << std::endl;
}