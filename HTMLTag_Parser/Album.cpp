// File: Album.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Album class

#include "Album.hpp"
#include "Pair.hpp"
#include "AlbumImage.hpp"
#include "Artists.hpp"
#include "Tracks.hpp"



Album::Album(): _title {""},
                _albumID {0},
                _numImages {0},
                _numTracks {0},
                _genre {""},
                _year {""},
                _artistID {0},
                cachedGenre{false},
                cachedYear{false},
                cachedArtistID{false},
                cachedNumTracks{false},
                cachedAlbumID{false},
                cachedTitle{false},
                _tracks {nullptr},
                _artists {nullptr},
                _primaryAlbumImage {nullptr},
                _secondaryAlbumImage {nullptr}
{}

Album::~Album() {

}

std::string Album::title() {
    if (cachedTitle)
        return _title;
    cachedTitle = true;
    return _title = valueForStringAttribute("title");
}

unsigned Album::albumID() {
    if (cachedAlbumID)
        return _albumID;
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

unsigned Album::numImages() {
    if (cachedNumImages)
        return _numImages;
    cachedNumImages = true;
    return _numImages = valueForIntegerAttribute("num_images");
}

unsigned Album::numTracks() {
    if (cachedNumTracks)
        return _numTracks;
    cachedNumTracks = true;
    return _numTracks = valueForIntegerAttribute("num_tracks");
}

std::string Album::year() {
    if (cachedYear)
        return _year;
    cachedYear = true;
    return _year = valueForStringAttribute("year");
}

std::string Album::genre() {
    if (cachedGenre)
        return _genre;
    cachedGenre = true;
    return _genre = valueForStringAttribute("genres");
}

unsigned Album::artistID() {
    if (cachedArtistID)
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

std::ostream& Album::htmlString(std::ostream &outs) { //Output info and tags
    if (_primaryAlbumImage != nullptr) //Check if image exists
        primaryImage()->htmlString(outs);
    else if (_secondaryAlbumImage != nullptr)
        secondaryImage()->htmlString(outs);

    outs << "class=\"albumInfo\"><tr><td class=\"aTitle\" colspan=2>" <<
    title() << "</td></tr><tr><td class=\"tdNarrow\">Artist:</td><td class=\"value\">";

    for (unsigned i = 0; i < artists()->listOfArtists()->size(); i++) {
        outs << artists()->listOfArtists()->at(i)->name() << "</td></tr><tr><td class=\"tdNarrow\">Genres:</td><td class=\"value\">" << genre();
        outs << "</td></tr><tr><td>Year:</td><td class=\"value\">" << year() << "</td></tr></table>";
        outs << "<div class=\"clear\">&nbsp;</div><h2>Tracklist</h2><table class=\"tracks\">";
        for (unsigned x = 0; x < tracks()->listOfTracks()->size(); x++) {
            tracks()->listOfTracks()->at(x)->htmlString(outs);

        }
        outs << "</table></li>";
    }
    return outs;
}

void Album::setImages(AlbumImage *albumImage) { //Set primary and secondary images for each album
    if (_primaryAlbumImage == nullptr)
        _primaryAlbumImage = albumImage;
    else
        _secondaryAlbumImage = albumImage;
}

AlbumImage*& Album::primaryImage() {
    return _primaryAlbumImage;
}

AlbumImage*& Album::secondaryImage() {
    return _secondaryAlbumImage;
}

Tracks* Album::tracks() {
    return _tracks;
}