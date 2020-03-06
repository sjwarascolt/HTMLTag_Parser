// File: JSONDataObject.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the JSONDataObject class

#include "JSONDataObject.hpp"
#include "Pair.hpp"

JSONDataObject::JSONDataObject(): _listOfDataItems {nullptr}
                                                    {}

JSONDataObject::~JSONDataObject() {

}

void JSONDataObject::parseDataObject(JSONTokenizer *tokenizer) {
    JSONToken token = tokenizer->getToken();
    if( ! token.isOpenCurlyBracket() ) {
        std::cout << "Error: JSONDataObject::parseDataObject: Expected an open curly bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(23);
    }
    if (_listOfDataItems == nullptr)
        _listOfDataItems = new std::vector<Pair *>;
    do {
        Pair *pair = new Pair();
        pair->parseAPair(*tokenizer);
        _listOfDataItems->push_back(pair);
        token = tokenizer->getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseCurlyBracket() ) {
        std::cout << "Error: JSONDataObject::parseDataObject: Expected a close curly bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(22);
    }

}

void JSONDataObject::print() {

}

std::string JSONDataObject::valueForStringAttribute(std::string s) {
    for (unsigned i = 0; i < _listOfDataItems->size(); i++) {
        if (_listOfDataItems->at(i)-> attributeName() == s)   //Search through the DataItems to find the key DataItem that
            return _listOfDataItems->at(i)->stringValue();    // matches the value stored in s
    }
    std::cout << "ERROR in std:string JSONDataObject::valueForStringAttribute function. Attribute name didn't match with an"
                 "attribute in the vector _listOfDataItems";
    exit(15);

}

unsigned JSONDataObject::valueForIntegerAttribute(std::string s) {
    for (unsigned i = 0; i < _listOfDataItems->size(); i++) {
        if (_listOfDataItems->at(i)-> attributeName() == s)  //Search through the DataItems to find the key DataItem that
            return _listOfDataItems->at(i)->numberValue();   //matches the value stored in s
    }
    std::cout << "ERROR in std:string JSONDataObject::valueForIntegerAttribute function. Attribute name didn't match with an"
                 "attribute in the vector _listOfDataItems";
    exit(16);
}