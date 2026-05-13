#include "SongLibrary.h"
#include <iostream>

void SongLibrary::addSong(Song* song) {
    songs.push_back(song);
}

void SongLibrary::displaySongs() const {
    std::cout << "Song Library:\n";

    for (int positionOfSong = 0; positionOfSong < songs.size(); positionOfSong++) {
        std::cout << (positionOfSong + 1) << ". " << songs[positionOfSong]->getTitle() << std::endl;
    }
}

Song* SongLibrary::getSong(std::string title) const {
    for (const auto& song : songs) {
        if (song->getTitle() == title) {
            return song;
        }
    }
    return nullptr;
}

SongLibrary::~SongLibrary() {

}