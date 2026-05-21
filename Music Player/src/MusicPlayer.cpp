#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer() {
    currentIndex = 0;
}

bool MusicPlayer::play() {

    if (music.openFromFile(
            playlist->getSongs()[currentIndex]->getFilePath())) {

        music.play();

        std::cout << "Playlist Playing: "
                  << playlist->getSongs()[currentIndex]->getTitle()
                  << std::endl;

        return true;
    }

    else {

        std::cout << "Error loading file!"
                  << std::endl;

        return false;
    }
}

bool MusicPlayer::pause() {

    if (music.getStatus() == sf::Music::Playing) {

        music.pause();

        std::cout << "Playlist Paused"
                  << std::endl;

        return true;
    }

    else if (music.getStatus() == sf::Music::Paused) {

        music.play();

        std::cout << "Playlist Resumed"
                  << std::endl;

        return true;
    }

    return false;
}

bool MusicPlayer::stop() {

    music.stop();

    std::cout << "Playlist Stopped"
              << std::endl;

    return true;
}

bool MusicPlayer::next() {

    if (playlist->getSongs().empty()) {
        return false;
    }

    currentIndex =
        (currentIndex + 1)
        % playlist->getSongs().size();

    return play();
}

bool MusicPlayer::previous() {

    if (playlist->getSongs().empty()) {
        return false;
    }

    currentIndex =
        (currentIndex - 1
         + playlist->getSongs().size())
        % playlist->getSongs().size();

    return play();
}

bool MusicPlayer::setPlaylist(Playlist* playlist) {

    this->playlist = playlist;

    currentIndex = 0;

    return true;
}