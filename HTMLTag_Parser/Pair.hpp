//
// Created by Peyton on 11/4/2018.
//

#ifndef PROJECT3_PAIR_HPP
#define PROJECT3_PAIR_HPP

#include <string>
#include <vector>

class JSONTokenizer;

class Pair {
    // represents a entity and its value:

public:
    Pair();
    bool isNumber();  // is the datatype of the value of this entity integer?
    int numberValue();
    std::string stringValue();
    std::string attributeName();
    void parseAPair( JSONTokenizer &tokenizer);

private:
    std::string _attributeName, _attributeStringValue;
    int _attributeNumberValue;
    bool _isNumber;
};


#endif //PROJECT3_PAIR_HPP
