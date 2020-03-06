//
// Created by student on 12/4/18.
//

#ifndef PROJECT4_ARTISTS_HPP
#define PROJECT4_ARTISTS_HPP

#include "JSONArray.hpp"
#include "ArtistImage.hpp"
#include "Artist.hpp"
#include "Albums.hpp"


class Artists: public JSONArray {
public:
    Artists();
    ~Artists();

    void addArtist(Artist *artist);
    void loadArtistsFromFile(std::string fileName);
    std::ostream & htmlString(std::ostream &outs);
    JSONDataObject *jsonObjectNode();
    void setAlbumsForArtists(Albums *albums);
    void setImagesForArtists(ArtistImage *);
    std::vector<Artist *> *listOfArtists() {
        if (_listOfDataObjects == nullptr)
            _listOfDataObjects = new std::vector<JSONDataObject *>;
        return (std::vector<Artist *> *) _listOfDataObjects; }

};


#endif //PROJECT4_ARTISTS_HPP
