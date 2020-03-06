// File: Tracks.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Tracks class

#include "Tracks.hpp"
#include "Albums.hpp"

Tracks::Tracks() {

}

Tracks::~Tracks() {

}

void Tracks::addTracks(Track *track) {
    listOfTracks()->push_back(track);
}

void Tracks::loadTracksFromFile(std::string fileName) {
    JSONTokenizer *tokenizer = new JSONTokenizer(fileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}


std::vector<Track *>* Tracks::listOfTracks() {
        if (_listOfDataObjects == nullptr)
            _listOfDataObjects = new std::vector<JSONDataObject *>;
        return (std::vector<Track *> *) _listOfDataObjects;
}
