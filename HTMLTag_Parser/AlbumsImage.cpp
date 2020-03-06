// File: AlbumsImage.hpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the AlbumsImage class

#include "AlbumsImage.hpp"

AlbumsImage::AlbumsImage() {

}

AlbumsImage::~AlbumsImage() {

}

void AlbumsImage::loadAlbumsImageFromFile(std::string fileName) {
    JSONTokenizer *tokenizer = new JSONTokenizer(fileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}

JSONDataObject* AlbumsImage::jsonObjectNode() {
    return new AlbumImage();
}

void AlbumsImage::setAlbumsForAlbumsImage(Albums *albums) {
    for (unsigned i = 0; i < listOfAlbumsImages()->size(); i++)
        albums->setImageForAlbums(listOfAlbumsImages()->at(i));      //pass albumimage to setImageforAlbums
}