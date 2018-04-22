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
	
	cout << intMatrix << endl
		<< dblMatrix << endl
		<< charMatrix;
}