cmake_minimum_required(VERSION 3.12)
project(Project4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project4 main.cpp Artist.cpp Artist.hpp Album.cpp Album.hpp Track.cpp Track.hpp ArtistImage.cpp ArtistImage.hpp AlbumImage.cpp AlbumImage.hpp Pair.cpp Pair.hpp JSONDataObject.cpp JSONDataObject.hpp JSONArray.cpp JSONArray.hpp JSONToken.cpp JSONToken.hpp JSONTokenizer.cpp JSONTokenizer.hpp Albums.cpp Albums.hpp Artists.cpp Artists.hpp Tracks.cpp Tracks.hpp ArtistsImage.cpp ArtistsImage.hpp AlbumsImage.cpp AlbumsImage.hpp)