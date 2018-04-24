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
//	Matrix<string, 2, 3> stMatrix;
	
	intMatrix(1, 1) = 76;
	intMatrix(2, 0) = 476;
	dblMatrix(2, 6) = 3.14;
	dblMatrix(0, 2) = 2.8;
	flMatrix(2, 2) = 25.56f;
    charMatrix(0,1) = 'x';
    charMatrix(1, 1) = 'y';
//    stMatrix(0, 1) = "test";
//    stMatrix(1, 0) = "test";
	
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
        << flMatrix << endl;
//        << "Matrix of strings: " << endl
//        << stMatrix;
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


void Test::menu() {

    cout << "   ______________________________________________________" << endl
         << " /|                                                      |" << endl
         << "| |      Welcome to Matrix Template Testing Program      |" << endl
         << "| |                                                      |" << endl
         << "| |                                                      |" << endl
         << "| |      Available Tests:                                |" << endl
         << "| |      1 - auto create Matrices of different types     |" << endl
         << "| |      2 - test available operations on int Matrices   |" << endl
         << "| |      3 - count determinant of matrix                 |" << endl
         << "| |      4 - solve cramer equation                       |" << endl
         << "| |      5 - exit program                                |" << endl
         << "| | ____________________________________________________ |" << endl
         << "|/______________________________________________________/ " << endl << endl << endl
         << "Enter your choice: ";
}


void Test::chooseTest() {

    menu();
    int choice;
    cin >> choice;
    while(choice != 5) {
        switch (choice) {
            case 1 :
                emptyMatrix();
//                cin.clear();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 2:
                operators1();
//                cin.clear();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 3 :
                determinant();
                cin.clear();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 4 :
                cramer();
                cin.clear();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 5 :
                break;
            default:
                cout << "There is no such a test, try again" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> choice;
                break;
        }
    }

}

void Test::determinant(){

    Matrix<int, 3, 3> A;
    int result;

    A.fill();

    cout << "A =" << endl
         << A << endl;

    result = det(A);
    cout << "det(A) = " << result << endl;

}



void Test::cramer() {

    Matrix<double, 4, 4> A;
    Matrix<char, 4, 1> X;
    Matrix<double, 4, 1> B;
    Matrix<double, 4, 4> temp;
    double result[4];

//    A.fill();
//    B.fill();
//    X.fill();

    A(0, 0) = 1;
    A(1, 1) = 2;
    A(2, 2) = 3;
    A(3, 3) = 4;

    B(0, 0) = 5;
    B(1, 0) = 5;
    B(2, 0) = 5;
    B(3, 0) = 5;

    X(0, 0) = 'x';
    X(1, 0) = 'y';
    X(2, 0) = 'z';
    X(3, 0) = 't';

    double detA = det(A);
    if(detA) {
        cout << "Matrix A:" << endl << A << endl
             << "Vector X:" << endl << X << endl
             << "Vector B:" << endl << B << endl
             << "Solving Cramer equation A*X = B" << endl << endl;

        for(size_t i = 0; i<4; i++) {
            temp = A;
            temp.replaceColumn(i, B);
            assert(cout << temp << endl);
            double x = det(temp)/detA;
            cout << "Variable " << X(i, 0) << " = " << x << endl << endl;
            result[i] = x;
        }
        double y;
        y = 5.0 / 3.0;
        if(
//                result[0] == 5
//                &&
//                result[1] == 2.5
//                &&
                result[2] == y
//                &&
//                result[3] == 1.25
                ) {
            cout << "Test przebiegl pomyslnie" << endl;
        }
    }
    else {
        cout << "Deteminant of your matrix A is equal to 0" << endl;
    }

}


