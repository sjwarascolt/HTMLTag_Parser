// File: Albums.hpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Albums class

#ifndef PROJECT4_ALBUMS_HPP
#define PROJECT4_ALBUMS_HPP

#include "JSONArray.hpp"
#include "Album.hpp"
#include "AlbumImage.hpp"
#include "Artists.hpp"

class Albums: public JSONArray {

public:
    Albums();
    ~Albums();

    void addAlbums(Album *album);
    void loadAlbumsFromFile (std::string fileName);
    JSONDataObject *jsonObjectNode();
    void setTracksForAlbums (Tracks *tracks);
    void setArtistsForAlbums (Artists *artists);
    void setImageForAlbums(AlbumImage *);
    std::vector<Album *> *listOfAlbums() {
        if (_listOfDataObjects == nullptr)
            _listOfDataObjects = new std::vector<JSONDataObject *>;
        return (std::vector<Album *> *) _listOfDataObjects; }

};


#endif //PROJECT4_ALBUMS_HPP
