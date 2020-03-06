// File: Main.cpp
// Author: Peyton Waterman
// Date: 12/01/2018
// Description: This file contains the implementation of the Albums class

#include <iostream>
#include "Artists.hpp"
#include "ArtistsImage.hpp"
#include "AlbumsImage.hpp"
#include <fstream>
#include <cstring>

int main(int argc, char *argv[]) {
if( argc != 6 ) {  // we expect the name of the file as an argument to the program.
    std::cout << "usage: " << argv[0] << " nameOfAnInputFile" << std::endl;
    exit(1);
}

std::ofstream masterFile("master.html");

if (masterFile) { //Open the master output file

    //Create an instace of each entity
    Artists *artists = new Artists();
    ArtistsImage *artistsImage = new ArtistsImage();
    AlbumsImage *albumsImage = new AlbumsImage();
    Albums *albums = new Albums();
    Tracks *tracks = new Tracks();

    //Parse through each entity
    artists->loadArtistsFromFile(argv[1]);

    artistsImage->loadArtistsImageFromFile(argv[2]);

    albumsImage->loadAlbumsImageFromFile(argv[3]);

    albums->loadAlbumsFromFile(argv[4]);

    tracks->loadTracksFromFile(argv[5]);

    //Match artistIDs and albumIDs to artists, albums, tracks, and images
    artists->setAlbumsForArtists(albums);
    albums->setArtistsForAlbums(artists);
    albums->setTracksForAlbums(tracks);

    artistsImage->setArtistForArtistImage(artists);
    albumsImage->setAlbumsForAlbumsImage(albums);

    //parse the input file
    std::ifstream artistsTemplate("artists_template.html");
    std::string marker;
    if (artistsTemplate.is_open()) {
        while (getline(artistsTemplate, marker)) { //Replace the marker
            if (marker == "<% artists %>")
                artists->htmlString(masterFile);
            else
                masterFile << marker << '\n';     //Move text in template file o output file
        }
        artistsTemplate.close();
    }
    else
        std::cout << "Artist template file didn't open";
    }
    masterFile.close();


return 0;
}