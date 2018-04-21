#include "Matrix.hpp"

template<typename T, size_t ROW, size_t COL>
Matrix<T, ROW, COL>::Matrix()
{
	matrix = new T*[ROW];
	
	for (size_t r = 0; r < ROW; r++) {
		matrix[r] = new T[COL];
		for (size_t c = 0; c < COL; c++) {
			matrix[r][c] = 0;
		}
	}
}

template<typename T, size_t ROW, size_t COL>
Matrix<T, ROW, COL>::~Matrix()
{
	for (size_t r = 0; r < ROW; r++) {
		matrix[r] = delete[] matrix[r];
		}
	delete[] matrix;
}

