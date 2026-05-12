#ifndef IPLAYLISTMANAGER_H
#define IPLAYLISTMANAGER_H

#include <vector>
#include <string>
#include "Playlist.h"

class IPlaylistManager {
    public:
        virtual void createPlaylist(const std::string& name) = 0;
        virtual void removePlaylist(const std::string& name) = 0;
        virtual void showAllPlaylists() = 0;
        virtual void addSongToPlaylist(const std::string& playlistName, Song* song) = 0;
        virtual void removeSong(const std::string& songTitle) = 0;
        virtual void moveSongUp(const std::string& playlistName, const std::string& songTitle, int position) = 0;
        virtual void moveSongDown(const std::string& playlistName, const std::string& songTitle, int position) = 0;
        virtual void displayPlaylist(const std::string& playlistName) = 0;
        virtual Playlist* getPlaylist(const std::string& name) = 0;

        virtual ~IPlaylistManager() = default;
};

#endif