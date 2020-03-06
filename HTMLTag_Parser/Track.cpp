// File: Track.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Track class

#include "Track.hpp"
#include "Pair.hpp"
#include <iostream>
#include "Tracks.hpp"

Track::Track(): _artistName {""},
                _title {""},
                _albumName {""},
                _duration {""},
                _position {""},
                _albumID {0},
                cachedPosition {false},
                cachedDuration {false},
                cachedAlbumID {false},
                cachedAlbumName {false},
                cachedArtistName {false},
                cachedTitle {false}

                          {}

Track::~Track() {

}

std::string Track::artistName() {
    if (cachedArtistName)
        return _artistName;
    cachedArtistName = true;
    return _artistName = valueForStringAttribute("name");
}

std::string Track::title() {
    if (cachedTitle)
        return _title;
    cachedTitle = true;
    return _title = valueForStringAttribute("title");
}

std::string Track::albumName() {
    if (cachedAlbumName)
        return _albumName;
    cachedAlbumName = true;
    return _albumName = valueForStringAttribute("album_name");
}

unsigned Track::albumID() {
    if (cachedAlbumID)
        return _albumID;
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

std::string Track::duration() {
    if (cachedDuration)
        return _duration;
    cachedDuration = true;
    return _duration = valueForStringAttribute("duration");
}

std::string Track::position() {
    if (cachedPosition)
        return _position;
    cachedPosition = true;
    return _position = valueForStringAttribute("position");
}



std::ostream& Track::htmlString(std::ostream &outs) { //Output tags and track info
    outs << "<tr class=\"tracks\"><td class=\"trackName\">" << title();
    outs << "</td><td>" << duration() << "</td></tr>";

    return outs;
}
