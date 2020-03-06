// File: ArtistImage.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the ArtistImage class

#include "ArtistImage.hpp"
#include "Pair.hpp"
#include "Artists.hpp"


ArtistImage::ArtistImage(): _uri {""},
                            _type {""},
                            _height {0},
                            _width {0},
                            _artistID {0},
                            cachedUri {false},
                            cachedType {false},
                            cachedHeight {false},
                            cachedWidth {false},
                            cachedArtistID {false},
                            _artists {nullptr}
                             {}

ArtistImage::~ArtistImage() {

}

unsigned ArtistImage::height() {
    if (cachedHeight)
        return _height;
    cachedHeight = true;
    return _height = valueForIntegerAttribute("height");
}

std::string ArtistImage::uri() {
    if (cachedUri)
        return _uri;
    cachedUri = true;
    return _uri = valueForStringAttribute("uri");
}

std::string ArtistImage::type() {
    if (cachedType)
        return _type;
    cachedType = true;
    return _uri = valueForStringAttribute("type");
}

unsigned ArtistImage::width() {
    if (cachedWidth)
        return _width;
    cachedWidth = true;
    return _width = valueForIntegerAttribute("width");
}

unsigned ArtistImage::artistID() {
    if (cachedArtistID)
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}


std::ostream& ArtistImage::htmlString(std::ostream &outs) { //Output tags and info for artistImage
    outs << "<img class=\"image\"";
    outs << " width=" << width();
    outs << " height=" << height();
    outs << " src=\"" << uri();
    outs << "\"><table ";

    return outs;
}
