#ifndef IMUSICPLAYER_H
#define IMUSICPLAYER_H

#include <string>
#include <vector>
#include "Playlist.h"

class IMusicPlayer {
public:
    virtual bool play() = 0;
    virtual bool pause() = 0;
    virtual bool stop() = 0;
    virtual bool next() = 0;
    virtual bool previous() = 0;
    virtual bool setPlaylist(Playlist* playlist) = 0;
    virtual ~IMusicPlayer() = default;
};
#endif