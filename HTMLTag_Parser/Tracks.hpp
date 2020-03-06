// File: Tracks.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Tracks class

#ifndef PROJECT4_TRACKS_HPP
#define PROJECT4_TRACKS_HPP

#include "JSONArray.hpp"
#include "Track.hpp"


class Albums;

class Tracks: public JSONArray {
public:
    Tracks();
    ~Tracks();

    void addTracks(Track *track);
    void loadTracksFromFile(std::string fileName);
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Track(); }

    std::vector<Track *> *listOfTracks();

};


#endif //PROJECT4_TRACKS_HPP
