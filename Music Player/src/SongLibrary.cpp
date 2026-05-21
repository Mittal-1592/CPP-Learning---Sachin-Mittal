#include "SongLibrary.h"
#include <iostream>

bool SongLibrary::addSong(Song* song) {

    if (song == nullptr) {
        return false;
    }

    songs.push_back(song);

    return true;
}

bool SongLibrary::displaySongs() const {

    if (songs.empty()) {

        std::cout << "Song Library is empty."
                  << std::endl;

        return false;
    }

    std::cout << "Song Library:\n";

    for (int positionOfSong = 0;
         positionOfSong < songs.size();
         positionOfSong++) {

        std::cout
            << (positionOfSong + 1)
            << ". "
            << songs[positionOfSong]->getTitle()
            << std::endl;
    }

    return true;
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

    for (auto song : songs) {

        delete song;
    }

    songs.clear();
}