#ifndef MUSICPLAYERCONTROLLER_H
#define MUSICPLAYERCONTROLLER_H

#include "IMusicPlayer.h"
#include "IPlaylistManager.h"
#include "Song.h"
#include "SongLibrary.h"
#include "Validations.h"

class MusicPlayerController {
private:
    IMusicPlayer* player;
    IPlaylistManager* manager;
    SongLibrary library;
    Validations validations;
    std::string currentPlaylist;

public:
    MusicPlayerController(IMusicPlayer* p, IPlaylistManager* m, SongLibrary& lib);
    void run();
};
#endif