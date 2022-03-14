/*
This file represent a little main for the mat function
*/
#include <iostream>
#include "mat.hpp"


int main(){
    int row, col;
    char sym1, sym2;
    std::cout << "please enter tow symbols and then the columns number and rows number:" << std::endl;
    std::cin >> sym1 >> sym2 >> col >> row;
    std::cout << ariel::mat(col, row, sym1, sym2);
}