// File: Artist.hpp
// Author: Peyton Waterman
// Date: 11/01/2018
// Description: This file initializes Artist parsing

#ifndef PROJECT4_ARTIST_HPP
#define PROJECT4_ARTIST_HPP

#include <fstream>
#include <cstring>
#include <vector>
#include "JSONDataObject.hpp"
#include <iostream>
#include "Tracks.hpp"


class Pair;
class Albums;
class ArtistImage;

class Artist: public JSONDataObject {

public:
    Artist();
    ~Artist();

    std::string profile();
    std::string name();
    std::string realName();
    std::string numImages();
    unsigned artistID();

    std::ostream & htmlString(std::ostream &outs);

    void setAlbums(Albums *albums);
    void setImages (ArtistImage *image);
    Albums *albums();
    ArtistImage *&primaryImage();
    ArtistImage *&secondaryImage();

private:
    std::string _name, _realName, _profile, _numImages;
    unsigned _artistID;
    bool cachedName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;

    Albums *_albums;
    ArtistImage *_primaryImage, *_secondaryImage;
};



#endif //PROJECT3_ARTIST_HPP
