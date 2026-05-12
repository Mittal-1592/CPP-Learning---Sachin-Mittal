#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <iostream>
#include <unordered_map>
#include "IPlaylistManager.h"
#include "Song.h"
#include "Playlist.h"

class PlaylistManager : public IPlaylistManager {
private:
   std::vector<std::pair<std::string, Playlist*>> playlists;

public:
    PlaylistManager();
    void createPlaylist(const std::string& name) override;
    void removePlaylist(const std::string& name) override;
    void showAllPlaylists() override;
    void addSongToPlaylist(const std::string& playlistName, Song* song) override;
    void removeSong(const std::string& songTitle) override;
    void moveSongUp(const std::string& playlistName, const std::string& songTitle, int position);
    void moveSongDown(const std::string& playlistName, const std::string& songTitle, int position);
    void displayPlaylist(const std::string& playlistName);
    Playlist* getPlaylist(const std::string& name) override;

    ~PlaylistManager();
};

#endif