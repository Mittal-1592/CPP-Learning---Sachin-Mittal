#include "Playlist.h"
#include <iostream>
#include <algorithm>

Playlist::Playlist() {
    name = "Untitled";
}

Playlist::Playlist(const std::string& name) {
    this->name = name;
}

bool Playlist::addSong(Song* song) {

    if (song == nullptr) {
        return false;
    }

    if (std::find(songs.begin(), songs.end(), song) != songs.end()) {

        std::cout << "Song already exists in the playlist!"
                  << std::endl;

        return false;
    }

    songs.push_back(song);

    std::cout << song->getTitle()
              << " added to playlist."
              << std::endl;

    return true;
}

bool Playlist::removeSong(const std::string& title) {

    for (auto it = songs.begin(); it != songs.end(); ++it) {

        if ((*it)->getTitle() == title) {

            songs.erase(it);

            std::cout << "Song removed from playlist: "
                      << title
                      << std::endl;

            return true;
        }
    }

    std::cout << "Song not found in the playlist!"
              << std::endl;

    return false;
}

bool Playlist::moveSongUp(
    const std::string& songTitle,
    int position) {

    for (int i = 1; i < songs.size(); i++) {

        if (songs[i]->getTitle() == songTitle) {

            if (i <= position) {

                std::cout
                    << "Song is already above the given position."
                    << std::endl;

                return false;
            }

            while (i > position) {

                std::swap(songs[i], songs[i - 1]);

                i--;
            }

            std::cout
                << "Song moved up in the playlist: "
                << songTitle
                << std::endl;

            return true;
        }
    }

    std::cout << "Song not found in the playlist!"
              << std::endl;

    return false;
}

bool Playlist::moveSongDown(
    const std::string& songTitle,
    int position) {

    for (int i = 0; i < songs.size(); i++) {

        if (songs[i]->getTitle() == songTitle) {

            if (i >= position) {

                std::cout
                    << "Song is already below the given position."
                    << std::endl;

                return false;
            }

            while (i < position &&
                   i < songs.size() - 1) {

                std::swap(songs[i], songs[i + 1]);

                i++;
            }

            std::cout
                << "Song moved down in the playlist: "
                << songTitle
                << std::endl;

            return true;
        }
    }

    std::cout << "Song not found in the playlist!"
              << std::endl;

    return false;
}

bool Playlist::display() const {

    std::cout << "Playlist: "
              << name
              << std::endl;

    int index = 1;

    for (auto song : songs) {

        std::cout << index++
                  << ". "
                  << song->getTitle()
                  << std::endl;
    }

    return true;
}

std::vector<Song*> Playlist::getSongs() const {
    return songs;
}

std::string Playlist::getName() const {
    return name;
}

Playlist::~Playlist() {

}