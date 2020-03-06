/****************************************/
/*Assignment: Lab 01                    */
/*File: Tokenizer.hpp                   */
/*Author: Peyton Waterman               */
/*Date: 8/21/2018                       */
/*Description: This program will read   */
/* and output tags from an html file    */
/****************************************/

#ifndef PROJECT1_JSONTOKENIZER_HPP
#define PROJECT1_JSONTOKENIZER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include "JSONToken.hpp"

class JSONTokenizer {

public:
    JSONTokenizer(std::string);
    JSONToken getToken();
    void UnGetToken();


private:
    std::string inputFileName;
    std::ifstream inputStream;
    bool charOfInterest(char c);
    JSONToken lastToken;
    bool hasUngottenJSONToken;
};


#endif //PROJECT1_JSONTOKENIZER_HPP
