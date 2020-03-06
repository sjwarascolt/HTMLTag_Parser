// File: JSONToken.cpp
// Author: Peyton Waterman
// Date: 11/01/2018
// Description: This file contains the implementation of the JSONToken class

#include "JSONToken.hpp"

JSONToken::JSONToken():  _isOpenCurlyBracket {false},
                         _isCloseCurlyBracket {false},
                         _isComma {false},
                         _isColon {false},
                         _isOpenBrace {false},
                         _isCloseBrace {false},
                         _isDoublyQuote {false},
                         _isInteger {false},
                         _commandName {""},
                         _eof {false}
{}

bool &JSONToken::isOpenCurlyBracket() {return _isOpenCurlyBracket; }
bool &JSONToken::isCloseCurlyBracket() {return _isCloseCurlyBracket; }
bool &JSONToken::isComma() {return _isComma; }
bool &JSONToken::isColon() {return _isColon; }
bool &JSONToken::isOpenBrace() {return _isOpenBrace; }
bool &JSONToken::isCloseBrace() {return _isCloseBrace; }
bool &JSONToken::isDoublyQuote() {return _isDoublyQuote; }
bool& JSONToken::isInteger() {return _isInteger; }

bool &JSONToken::endOfFile() {return _eof; }

std::string JSONToken::commandName() { return _commandName; }
int JSONToken::value() { return _value; }

void JSONToken::inDoublyQuote(std::string name) {
    _commandName = name;
    isDoublyQuote() = true;
}

void JSONToken::integerValue(int value) {
    _value = value;
    isInteger() = true;
}

void JSONToken::print() {

    if (isOpenCurlyBracket()) {
        std::cout << '{' << std::endl;

    } else if (isCloseCurlyBracket()) {
        std::cout << '}' << std::endl;

    } else if (isComma()) {
        std::cout << ',' << std::endl;

    } else if (isOpenBrace()) {
        std::cout << '[' << std::endl;

    } else if (isCloseBrace()) {
        std::cout << ']' << std::endl;

    } else if (isColon()) {
        std::cout << " : ";

    } else if (isDoublyQuote()) {
        std::cout << commandName();

    } else if (isInteger()) {
        std::cout << _value;

    }

}