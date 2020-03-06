// File: JSONArray.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the JSONArray class

#include "JSONArray.hpp"

JSONArray::JSONArray(): _listOfDataObjects {nullptr}
                                                {}

JSONArray::~JSONArray() {

}

void JSONArray::parseJSONArray(JSONTokenizer *tokenizer)
{
    JSONToken token = tokenizer->getToken();
    if( ! token.isOpenBrace() ) {
        std::cout << "Error: JSONArray::parseJSONArray: Expected an open brace, but found " << std::endl;
        token.print();
        std::cout << "\nTerminating..." << std::endl;
        exit(31);
    }
    if (_listOfDataObjects == nullptr)
        _listOfDataObjects = new std::vector<JSONDataObject *>;
    do {
        JSONDataObject *dItem = jsonObjectNode(); //Gets the artist, album, or track
        dItem->parseDataObject(tokenizer);
        _listOfDataObjects->push_back(dItem);
        token = tokenizer->getToken();
    } while( token.isComma() );
    if( ! token.isCloseBrace()) {
        std::cout << "Error: JSONArray::parseJSONArray: Expected a close brace, but found " << std::endl;
        token.print();
        std::cout << "\nTerminating..." << std::endl;
        exit(30);
    }

    for (int i = 0; i < _listOfDataObjects->size(); i++)
        _listOfDataObjects->at(i)->print();

}

void JSONArray::print() {

}