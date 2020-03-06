// File: JSONToken.hpp
// Author: Peyton Waterman
// Date: 11/01/2018
// Description: This file contains the constructs of the JSONToken class

#ifndef PROJECT1_JSONTOKEN_HPP
#define PROJECT1_JSONTOKEN_HPP

#include <iostream>
#include <iomanip>
#include <string>

class JSONToken {

public:
    JSONToken();
    bool &isOpenCurlyBracket();
    bool &isCloseCurlyBracket();
    bool &isComma();
    bool &isColon();
    bool &isOpenBrace();
    bool &isCloseBrace();
    bool &isDoublyQuote();
    bool &isInteger();
    bool &endOfFile();

    std::string commandName();
    int value();

    void inDoublyQuote (std::string name);
    void integerValue (int value);
    void print();

private:
    bool _isOpenCurlyBracket, _isCloseCurlyBracket, _isComma, _isColon, _isForSlash,
            _eof, _isOpenBrace, _isCloseBrace, _isDoublyQuote, _isInteger;

    std::string _commandName;
    int _value;

};


#endif //PROJECT1_JSONTOKEN_HPP
