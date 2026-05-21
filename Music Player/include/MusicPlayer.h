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

    bool play() override;
    bool pause() override;
    bool stop() override;
    bool next() override;
    bool previous() override;
    bool setPlaylist(Playlist* playlist) override;
    ~MusicPlayer() = default;
};

#endif