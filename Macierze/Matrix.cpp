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
	
	numOfRows = ROW;
	numOfColumns = COL;
}

template<typename T, size_t ROW, size_t COL>
Matrix<T, ROW, COL>::~Matrix()
{
	for (size_t r = 0; r < ROW; r++) {
		matrix[r] = delete[] matrix[r];
		}
	delete[] matrix;
}

//template<typename T, size_t ROW, size_t COL>
//void Matrix<T, ROW, COL>::fillRow(size_t r) {
//	
//	for(size_t i = 0; i<COL; i++) {
//		
//	}
//}


template <typename U, size_t M, size_t N> friend ostream& operator<<(ostream& os, const Matrix<U, M, N>& m) {
	
	for(size_t i = 0; i<numOfRows; i++) {
		os << '|';
		for(size_t j = 0; j<numOfColumns; j++) {
			os << setw(3) << m.matrix[i][j];
		}
		os << '|' << endl;
	}
	
	return os;
}