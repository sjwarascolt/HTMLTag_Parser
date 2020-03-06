// File: JSONDataObject.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the JSONDataObject class

#ifndef PROJECT4_JSONDATAOBJECT_HPP
#define PROJECT4_JSONDATAOBJECT_HPP

#include <string>
#include <vector>
#include "JSONTokenizer.hpp"

class Pair;

class JSONDataObject {
public:
    JSONDataObject();
    virtual ~JSONDataObject();
    void parseDataObject(JSONTokenizer *tokenizer);
    virtual void print();
    std::string valueForStringAttribute(std::string s);
    unsigned valueForIntegerAttribute(std::string s);

private:
    std::vector<Pair *> *_listOfDataItems;

};


#endif //PROJECT4_JSONDATAOBJECT_HPP
