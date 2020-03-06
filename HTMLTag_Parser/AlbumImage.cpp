// File: AlbumImage.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the AlbumImage class

#include "AlbumImage.hpp"
#include "Pair.hpp"
#include "Albums.hpp"

AlbumImage::AlbumImage(): _albumID {0},
                          _width {0},
                          _height {0},
                          _type {""},
                          _uri {""},
                          cachedAlbumID {false},
                          cachedWidth {false},
                          cachedType {false},
                          cachedUri {false},
                          cachedHeight {false},
                          _albums {nullptr}
                                        {}

AlbumImage::~AlbumImage() {

}

unsigned AlbumImage::height() {
    if (cachedHeight)
        return _height;
    cachedHeight = true;
    return _height = valueForIntegerAttribute("height");
}

std::string AlbumImage::uri() {
    if (cachedUri)
        return _uri;
    cachedUri = true;
    return _uri = valueForStringAttribute("uri");
}

std::string AlbumImage::type() {
    if (cachedType)
        return _type;
    cachedType = true;
    return _uri = valueForStringAttribute("type");
}

unsigned AlbumImage::width() {
    if (cachedWidth)
        return _width;
    cachedWidth = true;
    return _width = valueForIntegerAttribute("width");
}

unsigned AlbumImage::albumID() {
    if (cachedAlbumID)
        return _albumID;
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}


std::ostream& AlbumImage::htmlString(std::ostream &outs) { //Output info and tags
    outs << "<img class=\"image\" width=" << width();
    outs << " height=" << height();
    outs << " src=\"" << uri() << "\"><table ";
    return outs;
}


