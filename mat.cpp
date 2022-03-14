#include <iostream>
#include <vector>
#include "mat.hpp"

using namespace std;

string ariel::mat(int col, int row , char sym1, char sym2){
    // ERROR catching
    if (col % 2 == 0 || row % 2 == 0){
        throw invalid_argument("Mat size is always odd");
    }
    if (col < 0 || row < 0){
        throw invalid_argument("Mat size can't be negative");
    }
    if (isprint(sym1) == 0 || isprint(sym2) == 0 || sym1 == ' ' || sym2 == ' '){
        throw invalid_argument("symbols must be printable");
    }

    vector<int> vls = {0, 0}; // vector for the top right corner of the matrix  
    vector<int> vre = {row, col}; // vector for the bottom left corner of the matrix 
    
    bool mat_sym = true; // which symbol should we write

    // initial the vector matrix
    vector<vector<char>> matrix(row, vector<char>(col));

    while(vls[0] <= vre[0] && vls[1] <= vre[1]){  // while the vectors didnt meet horizontal and vertical

        for (int i = vls[0]; i < vre[0]; ++i){ // draws the left and right vertical lines
            matrix[i][vls[1]] = mat_sym ? sym1: sym2;
            matrix[i][vre[1] - 1] = mat_sym ? sym1: sym2;
        }
        for (int i = vls[1]; i < vre[1]; ++i){ // draws the top and bottom horizontal lines
            matrix[vls[0]][i] = mat_sym ? sym1: sym2;
            matrix[vre[0] - 1][i] = mat_sym ? sym1: sym2;
        }
        mat_sym = !mat_sym; // change the symbol
        ++vls[0], ++vls[1], --vre[0], --vre[1]; // move the vectors
    }

    string ans; // transpert the 2D vector into a printable string
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            ans += matrix[i][j];
        }
       ans += "\n";
    } 

    
    return ans;
}