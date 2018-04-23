#include "Test.hpp"
#include "Matrix.hpp"

Test::Test()
{
}

Test::~Test()
{
}

void Test::emptyMatrix() {
	
	Matrix<int, 4, 5> intMatrix;
	Matrix<double, 3, 7> dblMatrix;
	Matrix<char, 2, 2> charMatrix;
	
	intMatrix(2, 2) = 76;
	intMatrix(4, 1) = 476;
	dblMatrix(3, 7) = 3.14;
	dblMatrix(1, 3) = 2.8;
	
	charMatrix.fill();
	cout <<endl;
	intMatrix.fill();
	
	cout << intMatrix << endl
		<< dblMatrix << endl
		<< charMatrix;
}


void Test::operators1() {
	
	Matrix<int, 4, 5> M1;
	Matrix<int, 4, 5> M2;
	Matrix<int, 4, 5> M3;
	Matrix<int, 5, 2> M4;
	Matrix<int, 4, 2> M5;
	
	
	M1.fill();
	M2.fill();
	M4.fill();
	
	cout << M1 <<endl
		<< M2 <<endl
		<< M3 <<endl
		<< M4 <<endl
		<< M5 << endl;
	
	M3 = M2 - M1;
	M5 = M3 * M4;
	
	cout << "M2 - M1 =" << endl << M3 << endl
		<< "M3 * M4 =" << endl << M5 << endl;
	
}