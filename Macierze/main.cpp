#include <iostream>
#include "Matrix.hpp"
#include "Test.hpp"
#include "View.hpp"

using namespace std;

int main(int argc, char **argv)
{
//	Test test;
//	test.chooseTest();

    View view;
    view.menu();
    view.operations();

	return 0;
}
