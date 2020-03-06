// File: JSONArray.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the JSONArray class

#ifndef PROJECT4_JSONARRAY_HPP
#define PROJECT4_JSONARRAY_HPP

#include "JSONDataObject.hpp"
#include "JSONTokenizer.hpp"
#include "JSONToken.hpp"

class JSONArray {
public:
    JSONArray();
    ~JSONArray();
    std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
    virtual JSONDataObject *jsonObjectNode() = 0;
    void parseJSONArray(JSONTokenizer *tokenizer);
    virtual void print();

protected:
    std::vector<JSONDataObject *> *_listOfDataObjects;
};


#endif //PROJECT4_JSONARRAY_HPP
