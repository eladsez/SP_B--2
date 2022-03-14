/**
 * @file Test.cpp
 * @author elad sezanayev (you@domain.com)
 * @brief This file is testing the mat.cpp file (the mat function)
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
    // checking good carpet inputs and there outputs 
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

    CHECK(nospaces(mat(3, 3, '|', '-')) == nospaces("|||\n"
                                                    "|-|\n"
                                                    "|||"));

    CHECK(nospaces(mat(1, 1, '|', '-')) == nospaces("|"));

    CHECK(nospaces(mat(7, 3, '+', '-')) == nospaces("+++++++\n"
                                                    "+-----+\n"
                                                    "+++++++\n"));

    CHECK(nospaces(mat(1, 5, 'A', '|')) == nospaces("A\n"
                                                    "A\n"
                                                    "A\n"
                                                    "A\n"
                                                    "A\n"));

    CHECK(nospaces(mat(3, 3, 'A', 'A')) == nospaces("AAA\n"
                                                    "AAA\n"
                                                    "AAA"));

}

TEST_CASE("Bad input") {
    // invalid rows&colunms numbers inputs, negetive and even numbers 
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(-5, 5, '$', '%'));
    CHECK_THROWS(mat(2, 2, 'w', 'D'));
    CHECK_THROWS(mat(-1, -1, '-', 'A'));
    CHECK_THROWS(mat(5, 0, 'X', 'm'));
    CHECK_THROWS(mat(-1, 2, '$', '%'));
    CHECK_THROWS(mat(0, 0, '5', '5'));
    CHECK_THROWS(mat(2, 2, '1', '0'));

    // invalid symbol inputs
    CHECK_THROWS(mat(5, 5, '\n', 'T'));
    CHECK_THROWS(mat(5, 5, '$', ' '));
    CHECK_THROWS(mat(1, 1, 't', '\t'));
    CHECK_THROWS(mat(7, 1, '\r', ' '));
    CHECK_THROWS(mat(3, 5, ' ', ' '));
    CHECK_THROWS(mat(1, 1, ' ', '\n'));
    CHECK_THROWS(mat(3, 3, '\n', '\t'));

    // both symbols and integers bad inputs
    CHECK_THROWS(mat(0, 5, '\n', '5'));
    CHECK_THROWS(mat(52, 0, ' ', '5'));
    CHECK_THROWS(mat(8, 8, '\t', '\r'));
    
}

