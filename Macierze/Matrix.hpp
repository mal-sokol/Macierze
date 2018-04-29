#ifndef MATRIX_HPP
#define MATRIX_HPP
#define NDEBUG

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cassert>

using namespace std;

template<typename T, size_t ROWS, size_t COLS> class Matrix
{
public:
	Matrix();
	~Matrix();

	
	template <typename U, size_t M, size_t N> friend ostream& operator << (ostream& os, const Matrix<U, M, N>& m);
    template <typename U, size_t M, size_t N> friend istream& operator >> (istream& is, const Matrix<U, M, N>& m);
	
    T operator()(size_t row, size_t col) const
    {
        if(row<0 || row>ROWS || col<0 || col>COLS) {
            throw out_of_range("nawias1");
        }
        return matrix[row][col];
    }

    T& operator()(size_t row, size_t col)
    {
        if(row<0 || row>ROWS || col<0 || col>COLS) {
            throw out_of_range("nawias2");
        }
        return matrix[row][col];
    }

	bool operator == (const Matrix<T, ROWS, COLS>& right);
	bool operator != (const Matrix<T, ROWS, COLS>& right);
	Matrix<T, ROWS, COLS> operator + (const Matrix<T, ROWS, COLS>& right);
	Matrix<T, ROWS, COLS> operator - (const Matrix<T, ROWS, COLS>& right);
	Matrix<T, ROWS, COLS>& operator = (const Matrix<T, ROWS, COLS>& right);
    Matrix<T, ROWS, COLS> operator * (T scalar);
	
	Matrix<T, COLS, ROWS> transposed();
	void replaceColumn(size_t col, const Matrix<T, ROWS, 1>& vector);
	
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
		assert(cout << "destroing row " << r+1 << endl);
		delete[] matrix[r];
		}
	delete[] matrix;
	assert(cout << "MATRIX " << ROWS << "x" << COLS << " DESTROYED" << endl);
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


template<typename T, size_t ROWS, size_t COLS>
Matrix<T, ROWS, COLS> Matrix<T, ROWS, COLS>::operator * (T scalar){

    for(size_t i = 0; i < ROWS; i++) {
        for(size_t j = 0; j < COLS; j++) {
            matrix[i][j] *= scalar;
        }
    }
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

template <typename U, size_t N, size_t M>
istream& operator >> (istream& is, const Matrix<U, N, M>& m) {

    U input;
    cout << "Wypelnij macierz o wymiarach " << N << "x" << M << endl;
    for(size_t i = 0; i<m.numOfRows; i++) {
        cout << "Rzad " << i+1 << ": ";

        for(size_t j = 0; j<m.numOfColumns; j++) {
            is >> input;
            while(!is.good()) {
                is.clear();
                is.ignore(1000, ' ');
                is >> input;
            }
            m.matrix[i][j] = input;
        }
    }

    return is;
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
           const size_t X = M-1;
            Matrix<T, X, X> Next;
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
            assert(cout << Next << endl);
            if(i%2) {
                s -= A(i, 0) * det(Next);
            }
            else {
                s += A(i, 0) * det(Next);
            }

        }
        return s;
    }
};

template <typename T>
T det(Matrix<T, 1, 1> &A) {
    return A(0, 0);
}


template <typename T, size_t ROWS, size_t COLS>
void Matrix<T, ROWS, COLS>::replaceColumn(size_t col, const Matrix<T, ROWS, 1>& vector){

    for(size_t i = 0; i<ROWS; i++) {
        this->matrix[i][col] = vector(i, 0);
    }
}


#endif // MATRIX_HPP
