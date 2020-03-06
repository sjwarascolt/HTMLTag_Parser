// File: ArtistsImage.hpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the ArtistsImage class

#ifndef PROJECT4_ARTISTSIMAGE_HPP
#define PROJECT4_ARTISTSIMAGE_HPP

#include "ArtistImage.hpp"
#include "JSONArray.hpp"
#include "Artists.hpp"

class ArtistsImage: public JSONArray {

public:
    ArtistsImage();
    ~ArtistsImage();

    void loadArtistsImageFromFile(std::string fileName);
    JSONDataObject *jsonObjectNode();
    void setArtistForArtistImage(Artists *artists);
    std::vector<ArtistImage *> *listOfArtistsImages() {
        if (_listOfDataObjects == nullptr)
            _listOfDataObjects = new std::vector<JSONDataObject *>;
        return (std::vector<ArtistImage *> *) _listOfDataObjects; }
};


#endif //PROJECT4_ARTISTSIMAGE_HPP
