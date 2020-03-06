// File: Artist.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Artist class

#include "Artist.hpp"
#include "ArtistImage.hpp"
#include "Albums.hpp"
#include "Pair.hpp"

Artist::Artist(): cachedRealName {false},
                  cachedProfile {false},
                  cachedNumImages {false},
                  cachedArtistID {false},
                  cachedName {false},
                  _artistID {0},
                  _profile {""},
                  _name {""},
                  _realName {""},
                  _numImages {""},
                  _albums {nullptr},
                  _primaryImage {nullptr},
                  _secondaryImage {nullptr}
                                    {}

Artist::~Artist() {

}

std::string Artist::profile() {
    if (cachedProfile)
        return _profile;
    cachedProfile = true;
    return _profile = valueForStringAttribute("profile");
}

std::string Artist::name() {
    if (cachedName)
        return _name;
    cachedName = true;
    return _name = valueForStringAttribute("artist_name");
}

std::string Artist::realName() {
    if (cachedRealName)
        return _realName;
    cachedRealName = true;
    return _realName = valueForStringAttribute("real_name");
}

std::string Artist::numImages() {
    if (cachedNumImages)
        return _numImages;
    cachedNumImages = true;
    return  _numImages = valueForStringAttribute("num_images");
}

unsigned Artist::artistID() {
    if (cachedArtistID)
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}


std::ostream &Artist::htmlString(std::ostream &outs) { //Output info and tags for artist
    //Output the attributes from the JSON file to the output file
    if (_primaryImage != nullptr)
        primaryImage()->htmlString(outs); //Get info from artistImage
    else if (_secondaryImage != nullptr)
        secondaryImage()->htmlString(outs);

    outs << "class=\"artistInfo\">";
    outs << "<tr><td class=\"tagName\">Number of Images:</td>";
    outs << "<td class=\"value\">" << numImages() << "</td></tr>";
    outs << "<tr><td>Profile:</td><td class=\"value\">" << profile() << "</td></tr></table><div class=\"clear\">&nbsp;</div>";
    outs << "<h2>Albums</h2><ol>";

    for(int i = 0; i < albums()->listOfAlbums()->size(); i++) {
        outs << "<li><p><strong>" << albums()->listOfAlbums()->at(i)->title() << "</strong></p>";
        albums()->listOfAlbums()->at(i)->htmlString(outs);
    }
    return outs;
}

void Artist::setImages(ArtistImage *image) {
    if (_primaryImage == nullptr)
        _primaryImage = image;
    else
        _secondaryImage = image;
}

void Artist::setAlbums(Albums *albums) {
    _albums = albums;
}

Albums* Artist::albums() {
    return _albums;
}

ArtistImage*& Artist::primaryImage() {
    return _primaryImage;
}

ArtistImage*& Artist::secondaryImage() {
    return _secondaryImage;
}
