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
	Matrix<float, 3, 3> flMatrix;
	Matrix<char, 2, 2> charMatrix;
	
	intMatrix(1, 1) = 76;
	intMatrix(2, 0) = 476;
	dblMatrix(2, 6) = 3.14;
	dblMatrix(0, 2) = 2.8;
	flMatrix(2, 2) = 25.56f;
	
//	charMatrix.fill();
//	cout <<endl;
//	intMatrix.fill();
	
	cout << "Matrix of ints: " << endl
        << intMatrix << endl
        << "Matrix of doubles: " << endl
		<< dblMatrix << endl
        << "Matrix of chars: " << endl
		<< charMatrix << endl
        << "Matrix of floats: " << endl
        << flMatrix;
}


void Test::operators1() {
	
	Matrix<int, 4, 5> M1;
	Matrix<int, 4, 5> M2;
	Matrix<int, 5, 2> M4;
	Matrix<int, 4, 2> M6;

	
	M1.fill();
	M2.fill();
	M4.fill();
	M6.fill();

    Matrix<int, 4, 5>  M3 = M2 - M1;
    Matrix<int, 4, 2> M5 = M3 * M4;
    Matrix<int, 4, 2> M7 = M5 + M6;
    Matrix<int, 2, 4> M8 = M7.transposed();

	cout << "M2: " << endl
         << M2 << endl
         << "M1: " << endl
         << M1 << endl
         << "M2 - M1 = M3" << endl << M3 << endl
         << "M4: " << endl
         << M4 << endl
         << "M3 * M4 = M5" << endl << M5 << endl
         << "M6: " << endl
         << M6 << endl
         << "M5 + M6 = M7" << endl << M7 << endl
         << "Transposed M7:" << endl
         << M8 << endl;
}

void Test::chooseTest() {
    cout << "   ______________________________________________________" << endl
         << " /|                                                      |" << endl
         << "| |      Welcome to Matrix Template Testing Program      |" << endl
         << "| |                                                      |" << endl
         << "| |                                                      |" << endl
         << "| |      Available Tests:                                |" << endl
         << "| |      1 - auto create Matrices of different types     |" << endl
         << "| |      2 - test available operations on int Matrices   |" << endl
         << "| |      3 - count determinant of matrix                 |" << endl
         << "| |      4 - exit program                                |" << endl
         << "| | ____________________________________________________ |" << endl
         << "|/______________________________________________________/ " << endl << endl << endl
         << "Enter your choice: ";

    int choice;
    cin >> choice;
    switch ( choice ) {
        case 1 :
            emptyMatrix();
            chooseTest();
            break;
        case 2:
            operators1();
            chooseTest();
            break;
        case 3 :
            determinant();
            chooseTest();
            break;
        case 4 :
            break;
        default:
            cout << "There is no such a test, try again" << endl;
            cin.clear();
            cin.ignore();
            chooseTest();
            break;
    }


}

void Test::determinant(){

    Matrix<int, 1, 1> A;
    int result;

    A.fill();

    cout << "A =" << endl
         << A << endl;

    result = det(A);
    cout << "det(A) = " << result << endl;

}