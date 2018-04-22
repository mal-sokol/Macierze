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