// File: Track.hpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file initializes Track parsing

#ifndef PROJECT4_TRACK_HPP
#define PROJECT4_TRACK_HPP

#include <fstream>
#include <cstring>
#include <vector>
#include "JSONDataObject.hpp"

class Albums;
class Pair;

class Track: public JSONDataObject {

public:
    Track();
    ~Track();
    std::string artistName();
    std::string title();
    std::string albumName();
    unsigned albumID();
    std::string duration();
    std::string position();

    std::ostream & htmlString(std::ostream &outs);


private:
    std::string _artistName, _title, _albumName, _duration, _position;
    unsigned _albumID;
    bool cachedArtistName, cachedTitle, cachedAlbumName, cachedDuration, cachedPosition, cachedAlbumID;

};


#endif //PROJECT4_TRACK_HPP
