#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer() {
    currentIndex = 0;
}

void MusicPlayer::play() {
    if (music.openFromFile(playlist->getSongs()[currentIndex]->getFilePath())) {
        music.play();
        std::cout << "Playlist Playing: " << playlist->getSongs()[currentIndex]->getTitle() << std::endl;
    } else {
        std::cout << "Error loading file! " <<std::endl;
    }
}

void MusicPlayer::pause() {
    if (music.getStatus() == sf::Music::Playing) {
        music.pause();
        std::cout << "Playlist Paused" << std::endl;
    }
    else if (music.getStatus() == sf::Music::Paused) {
        music.play();
        std::cout << "Playlist Resumed" << std::endl;
    }
}

void MusicPlayer::stop() {
    music.stop();
    std::cout << "Playlist Stopped" << std::endl;
}

void MusicPlayer::next() {
    if (playlist->getSongs().empty()) return;
    currentIndex = (currentIndex + 1) % playlist->getSongs().size();
    play();
}

void MusicPlayer::previous() {
    if (playlist->getSongs().empty()) return;
    currentIndex = (currentIndex - 1 + playlist->getSongs().size()) % playlist->getSongs().size();
    play();
}

void MusicPlayer::setPlaylist(Playlist* playlist) {
    this->playlist = playlist;
    currentIndex = 0;
}