#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

template<typename T, size_t ROWS, size_t COLS> class Matrix
{
public:
	Matrix();
	~Matrix();
	
//	void fillRow(size_t r);
	void fill();
	
	template <typename U, size_t M, size_t N> friend ostream& operator << (ostream& os, const Matrix<U, M, N>& m);
	
    T operator()(size_t row, size_t col) const
    {
        return matrix[row][col];
    }

    T& operator()(size_t row, size_t col)
    {
        return matrix[row][col];
    }

	bool operator == (const Matrix<T, ROWS, COLS>& right);
	bool operator != (const Matrix<T, ROWS, COLS>& right);
	Matrix<T, ROWS, COLS> operator + (const Matrix<T, ROWS, COLS>& right);
	Matrix<T, ROWS, COLS> operator - (const Matrix<T, ROWS, COLS>& right);
	Matrix<T, ROWS, COLS>& operator = (const Matrix<T, ROWS, COLS>& right);
	
	Matrix<T, COLS, ROWS> transposed();
	
private:
	T** matrix;
	size_t numOfRows;
	size_t numOfColumns;
};



template<typename T, size_t ROWS, size_t COLS>
Matrix<T, ROWS, COLS>::Matrix()
{
	numOfRows = ROWS;
	numOfColumns = COLS;
	
	matrix = new T* [ROWS];
	
	for (size_t r = 0; r < ROWS; r++) {
		matrix[r] = new T [COLS];
		for (size_t c = 0; c < COLS; c++) {
			matrix[r][c] = 0;
		}
	}
}

template<typename T, size_t ROWS, size_t COLS>
Matrix<T, ROWS, COLS>::~Matrix()
{
	for (size_t r = 0; r < ROWS; r++) {
		cout << "destroing row " << r+1 << endl;
		delete[] matrix[r];
		}
	delete[] matrix;
	cout << "MATRIX " << ROWS << "x" << COLS << " DESTROYED" << endl;
}



template<typename T, size_t ROWS, size_t COLS>
void Matrix<T, ROWS, COLS>::fill() {

    cout << "Wypelnij macierz o wymiarach " << ROWS << "x" << COLS << endl;
	for (size_t r = 0; r < ROWS; r++) {
		cout << "Rzad " << r+1 << ": ";
		for (size_t c = 0; c < COLS; c++) {
			cin >> matrix[r][c];				//wczytywanie niezabezpieczone
//			while(!cin.good()) {
//				cin.ignore(1000, '\n');
//				cin >> matrix[r][c];
//				}
			}
	}
	cout << endl;
	cin.ignore(1000, '\n');
}




//---------------------------------------< OPERATORS >------------------------------------------//

template<typename T, size_t ROWS, size_t COLS>
Matrix<T, ROWS, COLS>& Matrix<T, ROWS, COLS>::operator = (const Matrix<T, ROWS, COLS>& right) {
	
	for (size_t i = 0; i < numOfRows; i++) {
		for (size_t j = 0; j < numOfColumns; j++) {
			this->matrix[i][j] = right(i, j);
		}
	}
	return *this;
}


template<typename T, size_t ROWS, size_t COLS>
bool Matrix<T, ROWS, COLS>::operator == (const Matrix<T, ROWS, COLS>& right) {
	
	for (size_t i = 0; i < numOfRows; i++) {
		for (size_t j = 0; j < numOfColumns; j++) {
			if (this->matrix[i][j] != right(i, j)) {
				return false;
			}
		}
	}
    return true;
}



template<typename T, size_t ROWS, size_t COLS>
bool Matrix<T, ROWS, COLS>::operator != (const Matrix<T, ROWS, COLS>& right) {
	
	return !(left == *this);
}



template<typename T, size_t ROWS, size_t COLS>
Matrix<T, ROWS, COLS>  Matrix<T, ROWS, COLS>::operator + (const Matrix<T, ROWS, COLS>& right) {
	
	Matrix<T, ROWS, COLS> result;
	
	for(size_t i = 0; i < ROWS; i++) {
		for(size_t j = 0; j < COLS; j++) {
				result(i, j) = matrix[i][j] + right(i,j);
		}
	}
	return result;
}



template<typename T, size_t ROWS, size_t COLS>
Matrix<T, ROWS, COLS> Matrix<T, ROWS, COLS>::operator - (const Matrix<T, ROWS, COLS>& right) {
	
	Matrix<T, ROWS, COLS> result;
	
	for(size_t i = 0; i < ROWS; i++) {
		for(size_t j = 0; j < COLS; j++) {
				result(i, j) = matrix[i][j] - right(i, j);
		}
	}
	return result;
}



template <typename U, size_t M, size_t N, size_t K>
Matrix<U, M, K> operator * (const Matrix<U, M, N>& left, const Matrix<U, N, K>& right) {
	
	Matrix<U, M, K> result;
	
	for(size_t i = 0; i < M; i++) {
		for(size_t k = 0; k < K; k++) {
			for(size_t j = 0; j < N; j++) {
			result(i, k) += left(i, j) * right(j, k);
			}
		}
	}
	return result;
}



template <typename U, size_t N, size_t M>
ostream& operator << (ostream& os, const Matrix<U, N, M>& m) {
	
	for(size_t i = 0; i<m.numOfRows; i++) {
		os << "| ";
		for(size_t j = 0; j<m.numOfColumns; j++) {
			os << setw(3) << setprecision(4) << m.matrix[i][j] << ' ';
		}
		os << '|' << endl;
	}
	
	return os;
}
//----------------------------------------------------------------------------------------------//


template<typename T, size_t ROWS, size_t COLS>
Matrix<T, COLS, ROWS> Matrix<T, ROWS, COLS>::transposed() {
	
	Matrix<T, COLS, ROWS> result;
	
	for(size_t i = 0; i<ROWS; i++) {
		for(size_t j = 0; j<COLS; j++) {
			result(j, i) = matrix[i][j];
		}
	}
	
	return result;
}



template <typename T, size_t M>
T det(Matrix<T, M, M> &A) {
    if(M == 1) {
        return A(0, 0);
    }
    else if (M > 1){
        T s = 0;
        for(size_t i = 0; i<M; i++) {
            Matrix<T, M-1, M-1> Next;
            for(size_t j = 1; j<M; j++) {
                for(size_t k = 0; k<M; k++) {
                    if(k<i) {
                        Next(k, j-1) = A(k, j);
                    }
                    else if(k>i) {
                        Next(k-1, j-1) = A(k, j);
                    }
                }
            }
            cout << Next << endl;
            s = det(Next);
//            if(i%2) {
//                s -= A(i, 0) * det(Next);
//            }
//            else {
//                s += A(i, 0) * det(Next);
//            }

        }
        return s;
    }
};

#endif // MATRIX_HPP
