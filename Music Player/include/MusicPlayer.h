#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "IMusicPlayer.h"
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "Playlist.h"

class MusicPlayer : public IMusicPlayer {
private:
    sf::Music music;
    Playlist* playlist;
    int currentIndex;

public:
    MusicPlayer();

    void play() override;
    void pause() override;
    void stop() override;
    void next() override;
    void previous() override;
    void setPlaylist(Playlist* playlist) override;
    ~MusicPlayer() = default;
};

#endif