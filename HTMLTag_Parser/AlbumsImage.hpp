// File: AlbumsImage.hpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the AlbumsImage class

#ifndef PROJECT4_ALBUMSIMAGE_HPP
#define PROJECT4_ALBUMSIMAGE_HPP

#include "JSONArray.hpp"
#include "Albums.hpp"

class AlbumsImage: public JSONArray {

public:
    AlbumsImage();
    ~AlbumsImage();

    void loadAlbumsImageFromFile(std::string fileName);
    std::ostream & htmlString(std::ostream &outs);
    JSONDataObject *jsonObjectNode();
    void setAlbumsForAlbumsImage(Albums *albums);
    std::vector<AlbumImage *> *listOfAlbumsImages() {
        if (_listOfDataObjects == nullptr)
            _listOfDataObjects = new std::vector<JSONDataObject *>;
        return (std::vector<AlbumImage *> *) _listOfDataObjects; }
};


#endif //PROJECT4_ALBUMSIMAGE_HPP
