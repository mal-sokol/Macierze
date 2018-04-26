#include <iostream>
#include "Matrix.hpp"
#include "Test.hpp"
#include "View.hpp"

using namespace std;

int main(int argc, char **argv)
{
    int mode;
    cout << endl << "    Wybierz tryb :" << endl
                 << "      1 - normalny  2 - test" << endl
                 << "      Wpisz numer pozycji: ";
    cin >> mode;

    try{
        switch(mode) {
            case 1 :
                View view;
                view.menu();
                view.operations();
                break;
            case 2 :
                Test test;
                test.chooseTest();
                break;
        }

    }
    catch (const out_of_range& ex) {
        cout << "Out of Range error.";
    }
	return 0;
}
