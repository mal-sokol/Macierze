//
// Created by Małgorzata on 2018-04-24.
//

#include "View.hpp"
#include "Matrix.hpp"

void View::menu() {

        cout << "   ______________________________________________________" << endl
             << " /|                                                      |" << endl
             << "| |      Program wykonujacy operacje na macierzach       |" << endl
             << "| |                                                      |" << endl
             << "| |                                                      |" << endl
             << "| |      Dostepne operacje:                              |" << endl
             << "| |      1 - dodawanie macierzy                          |" << endl
             << "| |      2 - odejmowanie macierzy                        |" << endl
             << "| |      3 - mnozenie macierzy                           |" << endl
             << "| |      4 - transpozycja                                |" << endl
             << "| |      5 - wyznacznik                                  |" << endl
             << "| |      6 - rozwiazanie ukladu Cramera                  |" << endl
             << "| |      7 - zakonczenie programu                        |" << endl
             << "| | ____________________________________________________ |" << endl
             << "|/______________________________________________________/ " << endl << endl << endl
             << "Wprowadz wybor: ";
}

int View::size(bool square) {

    int choice = 0;

    cout << endl << endl
         << "         Dostepne rozmiary:" << endl
         << "      Macierze kwadratowe:" << endl
         << "         1 - 2x2" << endl
         << "         2 - 3x3" << endl
         << "         3 - 4x4" << endl
         << "         4 - 5x5" << endl;
    if(!square) {
        cout << "      Macierze prostokatne:" << endl
             << "         5 - 3x4" << endl
             << "         6 - 5x6" << endl << endl;
    }
    cout << endl <<  "Wybierz z listy lub powroc do menu: ";

    cin >> choice;

    if(!cin.good() || choice< 1 || choice>6) {
        return 0;
    }
    if(square && (choice == 5 || choice == 6)) {
        return 0;
    }
    else return choice;
}

void View::operations() {

    int choice;
    cin >> choice;
    cin.ignore(1000, '\n');

    while(choice != 7) {
        switch (choice) {
            case 1 :
                plusMinus(true);
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 2:
                plusMinus(false);
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 3 :
                multiplication();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 4 :
                transposition();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 5:
                determinant();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            case 6 :
                cramer();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
            default:
                cout << "Niepoprawny numer pozycji" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                menu();
                cin >> choice;
                break;
        }
    }
}

void View::multiplication() {

    int choice;
    choice = size(false);

    switch(choice) {
        case 1 : {
            Matrix<double, 2, 2> A1;
            Matrix<double, 2, 2> B1;
            Matrix<double, 2, 2> C1;

            A1.fill();
            B1.fill();

            cout << "A = " << endl << A1 << endl
                 << "B = " << endl << B1 << endl << endl;

            C1 = A1 * B1;
            cout << "A * B = " << endl << C1 << endl;
        }
            break;
        case 2 : {
            Matrix<double, 3, 3> A2;
            Matrix<double, 3, 3> B2;
            Matrix<double, 3, 3> C2;

            A2.fill();
            B2.fill();

            cout << "A = " << endl << A2 << endl
                 << "B = " << endl << B2 << endl << endl;

            C2 = A2 * B2;
            cout << "A * B = " << endl << C2 << endl;
        }
            break;
        case 3 : {
            Matrix<double, 4, 4> A3;
            Matrix<double, 4, 4> B3;
            Matrix<double, 4, 4> C3;

            A3.fill();
            B3.fill();

            cout << "A = " << endl << A3 << endl
                 << "B = " << endl << B3 << endl << endl;

            C3 = A3 * B3;
            cout << "A * B = " << endl << C3 << endl;
        }
            break;
        case 4 : {
            Matrix<double, 5, 5> A4;
            Matrix<double, 5, 5> B4;
            Matrix<double, 5, 5> C4;

            A4.fill();
            B4.fill();

            cout << "A = " << endl << A4 << endl
                 << "B = " << endl << B4 << endl << endl;

            C4 = A4 * B4;
            cout << "A * B = " << endl << C4 << endl;
        }
            break;
        case 5 : {
            Matrix<double, 3, 4> A5;
            Matrix<double, 4, 2> B5;
            Matrix<double, 3, 2> C5;

            A5.fill();
            B5.fill();

            cout << "A = " << endl << A5 << endl
                 << "B = " << endl << B5 << endl << endl;

            C5 = A5 * B5;
            cout << "A * B = " << endl << C5 << endl;
        }
            break;
        case 6: {
            Matrix<double, 5, 6> A6;
            Matrix<double, 6, 2> B6;
            Matrix<double, 5, 2> C6;

            A6.fill();
            B6.fill();

            cout << "A = " << endl << A6 << endl
                 << "B = " << endl << B6 << endl << endl;

            C6 = A6 * B6;
            cout << "A * B = " << endl << C6 << endl;
        }
        default :
            cout << "Powrot" << endl;
    }


}

void View::plusMinus(bool plus) {

    int choice;
    choice = size(false);

    switch(choice) {
        case 1 : {
            Matrix<double, 2, 2> A1;
            Matrix<double, 2, 2> B1;
            Matrix<double, 2, 2> C1;

            A1.fill();
            B1.fill();

            cout << "A = " << endl << A1 << endl
                 << "B = " << endl << B1 << endl << endl;

            if (plus) {
                C1 = A1 + B1;
                cout << "A + B = " << endl << C1 << endl;
            } else {
                C1 = A1 - B1;
                cout << "A - B = " << endl << C1 << endl;
            }
        }
            break;
        case 2 : {
            Matrix<double, 3, 3> A2;
            Matrix<double, 3, 3> B2;
            Matrix<double, 3, 3> C2;

            A2.fill();
            B2.fill();

            cout << "A = " << endl << A2 << endl
                 << "B = " << endl << B2 << endl << endl;

            if (plus) {
                C2 = A2 + B2;
                cout << "A + B = " << endl << C2 << endl;
            } else {
                C2 = A2 - B2;
                cout << "A - B = " << endl << C2 << endl;
            }
        }
            break;
        case 3 : {
            Matrix<double, 4, 4> A3;
            Matrix<double, 4, 4> B3;
            Matrix<double, 4, 4> C3;

            A3.fill();
            B3.fill();

            cout << "A = " << endl << A3 << endl
                 << "B = " << endl << B3 << endl << endl;

            if (plus) {
                C3 = A3 + B3;
                cout << "A + B = " << endl << C3 << endl;
            } else {
                C3 = A3 - B3;
                cout << "A - B = " << endl << C3 << endl;
            }
        }
            break;
        case 4 : {
            Matrix<double, 5, 5> A4;
            Matrix<double, 5, 5> B4;
            Matrix<double, 5, 5> C4;

            A4.fill();
            B4.fill();

            cout << "A = " << endl << A4 << endl
                 << "B = " << endl << B4 << endl << endl;

            if (plus) {
                C4 = A4 + B4;
                cout << "A + B = " << endl << C4 << endl;
            } else {
                C4 = A4 - B4;
                cout << "A - B = " << endl << C4 << endl;
            }
        }
            break;
        case 5 : {
            Matrix<double, 3, 4> A5;
            Matrix<double, 3, 4> B5;
            Matrix<double, 3, 4> C5;

            A5.fill();
            B5.fill();

            cout << "A = " << endl << A5 << endl
                 << "B = " << endl << B5 << endl << endl;

            if (plus) {
                C5 = A5 + B5;
                cout << "A + B = " << endl << C5 << endl;
            } else {
                C5 = A5 - B5;
                cout << "A - B = " << endl << C5 << endl;
            }
        }
            break;
        case 6: {
            Matrix<double, 5, 6> A6;
            Matrix<double, 5, 6> B6;
            Matrix<double, 5, 6> C6;

            A6.fill();
            B6.fill();

            cout << "A = " << endl << A6 << endl
                 << "B = " << endl << B6 << endl << endl;

            if (plus) {
                C6 = A6 + B6;
                cout << "A + B = " << endl << C6 << endl;
            } else {
                C6 = A6 - B6;
                cout << "A - B = " << endl << C6 << endl;
            }
        }
        default :
            cout << "Powrot" << endl;
    }

}

void View::transposition() {

    int choice;
    choice = size(false);

    switch(choice) {
        case 1 : {
            Matrix<double, 2, 2> A1;
            Matrix<double, 2, 2> B1;

            A1.fill();
            B1 = A1.transposed();

            cout << "A = " << endl << A1 << endl
                 << "Macierz A transponwana: " << endl << B1 << endl << endl;
        }
            break;
        case 2 : {
            Matrix<double, 3, 3> A2;
            Matrix<double, 3, 3> B2;

            A2.fill();
            B2 = A2.transposed();

            cout << "A = " << endl << A2 << endl
                 << "Macierz A transponwana: " << endl << B2 << endl << endl;
        }
            break;
        case 3 : {
            Matrix<double, 4, 4> A3;
            Matrix<double, 4, 4> B3;

            A3.fill();
            B3 = A3.transposed();

            cout << "A = " << endl << A3 << endl
                 << "Macierz A transponwana: " << endl << B3 << endl << endl;
        }
            break;
        case 4 : {
            Matrix<double, 5, 5> A4;
            Matrix<double, 5, 5> B4;

            A4.fill();
            B4 = A4.transposed();

            cout << "A = " << endl << A4 << endl
                 << "Macierz A transponwana: " << endl << B4 << endl << endl;
        }
            break;
        case 5 : {
            Matrix<double, 3, 4> A5;
            Matrix<double, 4, 3> B5;

            A5.fill();
            B5 = A5.transposed();

            cout << "A = " << endl << A5 << endl
                 << "Macierz A transponwana: " << endl << B5 << endl << endl;
        }
            break;
        case 6: {
            Matrix<double, 5, 6> A6;
            Matrix<double, 6, 5> B6;

            A6.fill();
            B6 = A6.transposed();

            cout << "A = " << endl << A6 << endl
                 << "Macierz A transponwana: " << endl << B6 << endl << endl;
        }
        default :
            cout << "Powrot" << endl;
    }
}

void View::determinant() {

    int choice;
    choice = size(true);

    switch(choice) {
        case 1 : {
            Matrix<double, 2, 2> A1;

            A1.fill();

            cout << "A = " << endl << A1 << endl
                 << "det(A) = " << det(A1) << endl << endl;
            }
            break;
        case 2 : {
            Matrix<double, 3, 3> A2;

            A2.fill();

            cout << "A = " << endl << A2 << endl
                 << "det(A) = " << det(A2) << endl << endl;
            }
            break;
        case 3 : {
            Matrix<double, 4, 4> A3;

            A3.fill();

            cout << "A = " << endl << A3 << endl
                 << "det(A) = " << det(A3) << endl << endl;
            }
            break;
        case 4 : {
            Matrix<double, 5, 5> A4;

            A4.fill();

            cout << "A = " << endl << A4 << endl
                 << "det(A) = " << det(A4) << endl << endl;
            }
            break;
        default :
            cout << "Powrot" << endl;
    }
}


void View::cramer() {


    Matrix<double, 4, 4> A;
    Matrix<char, 4, 1> X;
    Matrix<double, 4, 1> B;
    Matrix<double, 4, 4> temp;
    double result[4];

    A.fill();
    B.fill();

    X(0, 0) = 'x';
    X(1, 0) = 'y';
    X(2, 0) = 'z';
    X(3, 0) = 't';

    double detA = det(A);
    if(detA) {
        cout << "Macierz A:" << endl << A << endl
             << "Wektor X:" << endl << X << endl
             << "Wektor B:" << endl << B << endl
             << "Rozwiazanie rownania Cramera A*X = B" << endl << endl;

        for (size_t i = 0; i < 4; i++) {
            temp = A;
            temp.replaceColumn(i, B);
            assert(cout << temp << endl);
            double x = det(temp) / detA;
            cout << X(i, 0) << " = " << x << endl << endl;
            result[i] = x;
        }
    }
    else {
        cout << "Wyznacznik macierzy A jest rowny 0" << endl;
    }
}
