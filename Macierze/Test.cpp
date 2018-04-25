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
	Matrix<bool, 2, 3> boolMatrix;


    cout << "Matrix of ints: " << endl
         << intMatrix << endl
         << "Matrix of doubles: " << endl
         << dblMatrix << endl
         << "Matrix of chars: " << endl
         << charMatrix << endl
         << "Matrix of floats: " << endl
         << flMatrix << endl
         << "Matrix of bool: " << endl
         << boolMatrix << endl << endl;

	intMatrix(1, 1) = 76;
	intMatrix(2, 0) = 476;
	dblMatrix(2, 6) = 3.14;
	dblMatrix(0, 2) = 2.8;
	flMatrix(2, 2) = 25.56f;
    charMatrix(0,1) = 'x';
    charMatrix(1, 1) = 'y';
    boolMatrix(0, 1) = true;
    boolMatrix(1, 0) = true;
	
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
        << flMatrix << endl
        << "Matrix of bool: " << endl
        << boolMatrix;
}


void Test::operators1() {
	
	Matrix<int, 4, 5> M1;
	Matrix<int, 4, 5> M2;
	Matrix<int, 5, 2> M4;
	Matrix<int, 4, 2> M6;

	
//	M1.fill();
//	M2.fill();
//	M4.fill();
//	M6.fill();

    M1(0, 0) = 1;
    M1(1, 0) = 1;
    M1(2, 0) = 1;
    M1(3, 0) = 1;
    M1(4, 0) = 1;
    M1(5, 0) = 1;

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
                cout << "Test exit value:" << endl
                     << "determinant1() : " << determinant1() << endl
                     << "determinant2() : " << determinant2() << endl
                     << "determinant3() : " << determinant3() << endl;
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
                cout << "Try again" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> choice;
                break;
        }
    }

}

int Test::determinant1(){

    Matrix<int, 3, 3> A;
    int result;

    A(0, 0) = 1;
    A(1, 1) = 2;
    A(2, 2) = 3;

//    cout << "A =" << endl
//         << A << endl;

    result = det(A);
    assert(cout << "det(A) = " << result << endl);
    if(result == 6) {
        return 0;
    }
    else return 1;

}

int Test::determinant2() {

    Matrix<int, 6, 6> A;
    int result;

    A(0, 0) = 1;
    A(1, 0) = 2;
    A(2, 0) = 3;
    A(3, 0) = 9;
    A(4, 0) = 8;
    A(5, 0) = 7;

    A(0, 1) = 4;
    A(1, 1) = 5;
    A(2, 1) = 6;
    A(3, 1) = 7;

    A(1, 2) = 5;
    A(2, 2) = 5;
    A(3, 2) = 5;
    A(5, 2) = 2;

    A(0, 3) = 9;
    A(1, 3) = 1;
    A(2, 3) = 1;
    A(3, 3) = 1;
    A(4, 3) = 1;
    A(5, 3) = 1;

    A(0, 4) = 1;
    A(1, 4) = 1;
    A(2, 4) = 1;
    A(3, 4) = 1;
    A(4, 4) = 1;
    A(5, 4) = 1;

    A(0, 5) = 1;
    A(1, 5) = 1;
    A(2, 5) = 1;
    A(3, 5) = 1;
    A(4, 5) = 1;
    A(5, 5) = 1;

//    cout << "A =" << endl
//         << A << endl;

    result = det(A);
    assert(cout << "det(A) = " << result << endl);
    if(result == 0) {
        return 0;
    }
    else return 1;
}

int Test::determinant3() {

    Matrix<int, 4, 4> A;
    int result;

    A(0, 0) = 1;
    A(1, 0) = 0;
    A(2, 0) = 5;
    A(3, 0) = 5;

    A(0, 1) = 1;
    A(1, 1) = 2;
    A(2, 1) = 2;
    A(3, 1) = 2;

    A(0, 2) = 9;
    A(1, 2) = 8;
    A(2, 2) = 7;
    A(3, 2) = 5;

    A(0, 3) = 5;
    A(1, 3) = 0;
    A(2, 3) = 1;
    A(3, 3) = 1;


//    cout << "A =" << endl
//         << A << endl;

    result = det(A);
    assert(cout << "det(A) = " << result << endl);
    if(result == -96) {
        return 0;
    }
    else return 1;
}

int Test::cramer() {

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
                result[0] == 5
                &&
                result[1] == 2.5
                &&
                result[2] == y
                &&
                result[3] == 1.25
                ) {
            cout << "Test przebiegl pomyslnie" << endl;
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        cout << "Wyznacznik rowny 0" << endl;
        return 1;
    }

}




