// File: Pair.cpp
// Author: Peyton Waterman
// Date: 11/01/2018
// Description: This file contains the implementation of the pair class

#include "Pair.hpp"
#include "JSONTokenizer.hpp"

Pair::Pair(): _attributeName {""},
             _attributeNumberValue{0},
             _attributeStringValue {""},
             _isNumber{false} {}


bool Pair::isNumber() {
    return _isNumber;
}

int Pair::numberValue() {
    return _attributeNumberValue;
}

std::string Pair::attributeName() {
    return _attributeName;
}

std::string Pair::stringValue() {
    return _attributeStringValue;
}

void Pair::parseAPair(JSONTokenizer &tokenizer) {
    JSONToken token = tokenizer.getToken();

    if (token.isDoublyQuote()) { //Get the attribute name
        _attributeName = token.commandName();
        token = tokenizer.getToken();

        if (token.isColon()) {
            token = tokenizer.getToken();

            if (token.isDoublyQuote()) { //Check if the attribute value is a string
                _attributeStringValue = token.commandName();

            } else if (token.isInteger()) { //Check if the attribute value is an integer
                _attributeNumberValue = token.value();
                _isNumber = true;

            } else if (!token.isDoublyQuote()) {
                std::cout << "Error: expected \" in parseAPair, but got " << token.commandName();
            }
        } else if (!token.isColon()) {
            std::cout << "Error: expected ':' in parseAPair, but got " << token.commandName();
        }
    } else if (!token.isDoublyQuote()) {
        std::cout << "Error: expected \" in parseAPair, but got " << token.commandName();
    }

}
