// File: Album.hpp
// Author: Peyton Waterman
// Date: 11/01/2018
// Description: This file initializes Album parsing


#ifndef PROJECT4_ALBUM_HPP
#define PROJECT4_ALBUM_HPP

#include <fstream>
#include <cstring>
#include <vector>
#include "JSONDataObject.hpp"

class Tracks;
class Pair;
class AlbumImage;
class Artists;

class Album: public JSONDataObject {
public:
    Album ();
    ~Album();

    std::string title();
    unsigned albumID();
    unsigned numImages();
    unsigned numTracks();
    std::string genre();
    std::string year();
    unsigned artistID();

    std::ostream & htmlString(std::ostream &outs);

    void setTracks(Tracks *tracks) { _tracks = tracks; }
    void setArtists(Artists *artists) { _artists = artists; }
    void setImages (AlbumImage *albumImage);
    Artists *artists() { return _artists; }
    Tracks *tracks();

    AlbumImage *&primaryImage();
    AlbumImage *&secondaryImage();


private:
    std::string _title, _genre, _year;
    unsigned _albumID, _numImages, _numTracks, _artistID;
    bool cachedTitle, cachedAlbumID, cachedGenre, cachedYear, cachedNumImages, cachedNumTracks, cachedArtistID;

    AlbumImage *_primaryAlbumImage, *_secondaryAlbumImage;
    Tracks *_tracks;
    Artists *_artists;

};


#endif //PROJECT4_ALBUM_HPP
