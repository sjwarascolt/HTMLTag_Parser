/****************************************/
/*Assignment: Project 03                */
/*File: Tokenizer.cpp                   */
/*Author: Peyton Waterman               */
/*Date: 11/01/2018                      */
/*Description: This program will read   */
/* and parse through JSON object files  */
/****************************************/

#include "JSONTokenizer.hpp"

JSONTokenizer::JSONTokenizer(std::string name): inputFileName{name},
                                                hasUngottenJSONToken {false}
{
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

bool JSONTokenizer::charOfInterest(char c) {

    return (c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || c == ':' || c == '\"' || isdigit(c));

}

void JSONTokenizer::UnGetToken() {
    hasUngottenJSONToken = true;
}

JSONToken JSONTokenizer::getToken() {

    if (hasUngottenJSONToken) {
        hasUngottenJSONToken = false;
        return lastToken;
    }

    char c;

    if ( !inputStream.is_open()) {
        std::cout << "JSONTokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while ( inputStream.get(c) && ! charOfInterest(c) ) {

    }

    JSONToken JSONtoken;
    if (inputStream.eof()) {
        JSONtoken.endOfFile() = true;
        lastToken = JSONtoken;
        return JSONtoken;
    }
    std::string commandName;

    if (c == '{') {
        JSONtoken.isOpenCurlyBracket() = true;
        lastToken = JSONtoken;
        return JSONtoken;

    } else if (c == '}') {
        JSONtoken.isCloseCurlyBracket() = true;
        lastToken = JSONtoken;
        return JSONtoken;

    } else if (c == '[') {
        JSONtoken.isOpenBrace() = true;
        lastToken = JSONtoken;
        return JSONtoken;

    } else if (c == ']') {
        JSONtoken.isCloseBrace() = true;
        lastToken = JSONtoken;
        return JSONtoken;

    } else if (c == ':') {
        JSONtoken.isColon() = true;
        lastToken = JSONtoken;
        return JSONtoken;

    } else if (c == ',') {
        JSONtoken.isComma() = true;
        lastToken = JSONtoken;
        return JSONtoken;

    } else if (c == '\"') {
        while (inputStream.peek() != '\"') { //Check for quoted statements
            if (inputStream.peek() == '\\') {
                inputStream.get(c); //Grab the backslash
            }
            inputStream.get(c);
            commandName += c;
        }
        inputStream.get(c); //Get the end quote of the string
        JSONtoken.inDoublyQuote(commandName);
        lastToken = JSONtoken;
        return JSONtoken;

    } else if (isdigit(c)) {
        int value = 0;
        inputStream.putback(c); //Put back the digit character to store as an integer
        inputStream >> value;
        JSONtoken.integerValue(value);
        lastToken = JSONtoken;
        return JSONtoken;

    }

    lastToken = JSONtoken;
    return JSONtoken;

}
