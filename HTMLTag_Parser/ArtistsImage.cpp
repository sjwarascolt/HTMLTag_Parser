// File: ArtistsImage.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the ArtistsImage class

#include "ArtistsImage.hpp"

ArtistsImage::ArtistsImage() {

}

ArtistsImage::~ArtistsImage() {

}

void ArtistsImage::loadArtistsImageFromFile(std::string fileName) {
    JSONTokenizer *tokenizer = new JSONTokenizer(fileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}

JSONDataObject* ArtistsImage::jsonObjectNode() {
    return new ArtistImage();
}

void ArtistsImage::setArtistForArtistImage(Artists *artists) {
    for (unsigned i = 0; i < listOfArtistsImages()->size(); i++)
        artists->setImagesForArtists(listOfArtistsImages()->at(i)); //Send all instances of artistImages to match artistIDs
                                                                    //with instances of artists
}



