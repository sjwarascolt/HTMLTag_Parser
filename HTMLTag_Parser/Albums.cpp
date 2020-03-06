// File: Albums.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Albums class

#include "Albums.hpp"

Albums::Albums() {

}

Albums::~Albums() {

}

void Albums::addAlbums(Album *album) {
    listOfAlbums()->push_back(album);
}

void Albums::loadAlbumsFromFile(std::string fileName) {
    JSONTokenizer *tokenizer = new JSONTokenizer(fileName); //Give the file to tokenizer to parse
    parseJSONArray(tokenizer);
    delete tokenizer;
}

void Albums::setTracksForAlbums(Tracks *tracks) {
    for (unsigned i = 0; i < listOfAlbums()->size(); i++) {

        Tracks *newTracks = new Tracks();  //Make new artists to be set

        int artID = listOfAlbums()->at(i)->albumID();

        for (unsigned x = 0; x < tracks->listOfTracks()->size(); x++) { //iterate through list of tracks
            if (artID == tracks->listOfTracks()->at(x)->albumID())     //to find matching albumIDs

                newTracks->addTracks(tracks->listOfTracks()->at(x)); //If they match, add that tracks information to track
        }

        listOfAlbums()->at(i)->setTracks(newTracks); //Set the new artists that match album
    }
}

void Albums::setArtistsForAlbums(Artists *artists) {
    for (unsigned i = 0; i < listOfAlbums()->size(); i++) {

        Artists *newArtists = new Artists();  //Make new artists to be set

        int artID = listOfAlbums()->at(i)->artistID();

        for (unsigned x = 0; x < artists->listOfArtists()->size(); x++) { //iterate through list of tracks
            if (artID == artists->listOfArtists()->at(x)->artistID())     //to find matching albumIDs

                newArtists->addArtist(artists->listOfArtists()->at(x)); //If they match, add that tracks information to track
        }

        listOfAlbums()->at(i)->setArtists(newArtists); //Set the new artists that match album
    }
}


void Albums::setImageForAlbums(AlbumImage *albumImage) {
    for (unsigned i = 0; i < listOfAlbums()->size(); i++) {
        int albId = listOfAlbums()->at(i)->albumID();
        if (albId == albumImage->albumID())             //Find matching albumIDs
            listOfAlbums()->at(i)->setImages(albumImage); //Set the matching images into the list of albums

    }
}

JSONDataObject* Albums::jsonObjectNode() {
    return new Album();
}