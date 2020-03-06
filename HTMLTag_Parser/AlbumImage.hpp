// File: AlbumImage.hpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the AlbumImage class

#ifndef PROJECT4_ARTISTIMAGE_HPP
#define PROJECT4_ARTISTIMAGE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "JSONDataObject.hpp"

class Pair;
class Albums;

class AlbumImage: public JSONDataObject {

public:
    AlbumImage();
    ~AlbumImage();
    unsigned height();
    std::string uri();
    std::string type();
    unsigned width();
    unsigned albumID();

    std::ostream & htmlString(std::ostream &outs);


private:
    std::string _uri, _type;
    unsigned _height, _width, _albumID;
    bool cachedUri, cachedType, cachedHeight, cachedWidth, cachedAlbumID;
    Albums *_albums;

};


#endif //PROJECT4_ARTISTIMAGE_HPP
