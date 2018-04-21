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
	
//	void setValue(T value, size_t r, size_t c) {matrix[r][c] = value;}
//	void fillRow(size_t r);
//	void fill();
	
	template <typename U, size_t M, size_t N> friend ostream& operator<<(ostream& os, const Matrix<U, M, N>& m);
	
private:
	T matrix[ROW][COL];
	size_t numOfRows;
	size_t numOfColumns;
};

#endif // MATRIX_HPP
