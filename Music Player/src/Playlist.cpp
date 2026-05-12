#include "Playlist.h"
#include <iostream>
#include <algorithm>

Playlist::Playlist() {
    name = "Untitled";
}

Playlist::Playlist(const std::string& name) {
    this->name = name;
}

void Playlist::addSong(Song* song) {
    if(std::find(songs.begin(), songs.end(), song) != songs.end()) {
        std::cout << "Song already exists in the playlist!" << std::endl;
        return;
    }
    songs.push_back(song);
    std::cout<< song->getTitle() << " added to playlist." << std::endl;
}

void Playlist::removeSong(const std::string& title) {
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if ((*it)->getTitle() == title) {
            songs.erase(it);
            std::cout << "Song removed from playlist: " << title << std::endl;
            return;
        }
    }

    std::cout << "Song not found in the playlist!" << std::endl;
}

void Playlist::moveSongUp(const std::string& songTitle, int position) {
    if(position == 1){
        std::cout<< "Song is already at the top of the playlist."<< std::endl;
        return;
    }
    for (int i = 1; i < songs.size(); i++) {
        if (songs[i]->getTitle() == songTitle) {
            if (i <= position) {
                std::cout<< "Song is already above the given position."<< std::endl;
                return;
            }
            while(i > position){
                std::swap(songs[i], songs[i - 1]);
                i--;
            }
            return;
        }
    }
    std::cout << "Song not found in the playlist!" << std::endl;
}

void Playlist::moveSongDown(const std::string& songTitle, int position) {
    for(int i = 0; i < songs.size(); i++) {
        if(songs[i]->getTitle() == songTitle) {
            if (i >= position) {
                std::cout<< "Song is already below the given position."<< std::endl;
                return;
            }
            while(i < position && i < songs.size() - 1) {
                std::swap(songs[i], songs[i + 1]);
                i++;
            }
            return;
        }
    }
    std::cout << "Song not found in the playlist!" << std::endl;
}

void Playlist::display() const {
    std::cout << "Playlist: " << name << std::endl;

    for (auto song : songs) {
        std::cout << "- " << song->getTitle() << std::endl;
    }
}

std::vector<Song*> Playlist::getSongs() const {
    return songs;
}

std::string Playlist::getName() const {
    return name;
}

Playlist::~Playlist() {

}