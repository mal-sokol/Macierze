#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

template<typename T, size_t ROW, size_t COL> class Matrix
{
public:
	Matrix();
	~Matrix();
	
	
private:
	T matrix[ROW][COL];
};

#endif // MATRIX_HPP
