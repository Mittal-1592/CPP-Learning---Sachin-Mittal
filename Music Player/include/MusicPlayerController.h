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
    SongLibrary& library;
    Validations validations;

public:

    MusicPlayerController(IMusicPlayer* player, IPlaylistManager* manager, SongLibrary& library, Validations& validations);

    void run();

    void handleMainMenuChoice(int choice);
    void openPlaylist();
    void handlePlaylistMenu(Playlist* playlist, const std::string& playlistName);
    void handlePlaylistChoice(int choice, Playlist* playlist, const std::string& playlistName);

    void handleAddSong(const std::string& playlistName);
    void handleRemoveSong(Playlist* playlist, const std::string& playlistName);
    void handleMoveSongUp(Playlist* playlist, const std::string& playlistName);
    void handleMoveSongDown(Playlist* playlist, const std::string& playlistName);
    void handlePlayPlaylist(Playlist* playlist);
    void handleNextSong(Playlist* playlist);
    void handlePreviousSong(Playlist* playlist);
    void handlePauseSong(Playlist* playlist);
    void handleStopSong(Playlist* playlist);
};

#endif