//
// Created by Małgorzata on 2018-04-24.
//

#ifndef MATRIX_VIEW_HPP
#define MATRIX_VIEW_HPP


#include <cstddef>
#include "Matrix.hpp"

class View {

public:
    void menu();
    void operations();
    void plusMinus(bool plus);
    void multiplication();
    void transposition();
    void determinant();
    void cramer();

    int size(bool square);
};


#endif //MATRIX_VIEW_HPP
