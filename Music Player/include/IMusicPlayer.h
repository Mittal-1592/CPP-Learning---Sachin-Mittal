#ifndef IMUSICPLAYER_H
#define IMUSICPLAYER_H

#include <string>
#include <vector>
#include "Playlist.h"

class IMusicPlayer {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void next() = 0;
    virtual void previous() = 0;
    virtual void setPlaylist(Playlist* playlist) = 0;
    virtual ~IMusicPlayer() {}
};
#endif