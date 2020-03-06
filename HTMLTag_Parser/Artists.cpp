// File: Artists.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Artists class

#include "Artists.hpp"


Artists::Artists() {

}

Artists::~Artists() {

}

void Artists::addArtist(Artist *artist) {
    listOfArtists()->push_back(artist);
}

void Artists::loadArtistsFromFile(std::string fileName) {
    JSONTokenizer *tokenizer = new JSONTokenizer(fileName);
    parseJSONArray(tokenizer);
    delete tokenizer;

}

JSONDataObject* Artists::jsonObjectNode() {
    return new Artist();
}

std::ostream& Artists::htmlString(std::ostream &outs) { //Output info and tags for artists (beginning of outputs)
    for (int i = 0; i < listOfArtists()->size(); i++) {
        outs << "<h2>" << listOfArtists()->at(i)->name() << "</h2>";
        listOfArtists()->at(i)->htmlString(outs);       //Get info from artist to print
    }

    return outs;
}

void Artists::setAlbumsForArtists(Albums *albums) {

    for (unsigned i = 0; i < listOfArtists()->size(); i++) {
        Albums *newAlbums = new Albums();

        int artID = listOfArtists()->at(i)->artistID();
        for (unsigned x = 0; x < albums->listOfAlbums()->size(); x++) { //Find matching artistIds to set
            if (artID == albums->listOfAlbums()->at(x)->artistID())
                newAlbums->addAlbums(albums->listOfAlbums()->at(x));
        }
        listOfArtists()->at(i)->setAlbums(newAlbums);
    }
}

void Artists::setImagesForArtists(ArtistImage *artistImage) {
    for (unsigned i = 0; i < listOfArtists()->size(); i++) {//loop through matching artistIds to set
        int artID = listOfArtists()->at(i)->artistID();
        if (artID == artistImage->artistID())
            listOfArtists()->at(i)->setImages(artistImage);
    }
}
