// File: ArtistImage.hpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the ArtistImage class

#ifndef PROJECT4_ARTISTIMAGE_HPP
#define PROJECT4_ARTISTIMAGE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "JSONDataObject.hpp"

class Pair;
class Artists;

class ArtistImage: public JSONDataObject {
public:
    ArtistImage();
    ~ArtistImage();
    unsigned height();
    std::string uri();
    std::string type();
    unsigned width();
    unsigned artistID();

    std::ostream & htmlString(std::ostream &outs);

private:
    std::string _uri, _type;
    unsigned _height, _width, _artistID;
    bool cachedUri, cachedType, cachedHeight, cachedWidth, cachedArtistID;

    Artists *_artists;


};


#endif //PROJECT4_ARTISTIMAGE_HPP
