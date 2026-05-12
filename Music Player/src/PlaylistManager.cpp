#include "PlaylistManager.h"
#include <iostream>

PlaylistManager::PlaylistManager() {
    std::cout << "PlaylistManager initialized." << std::endl;
}

void PlaylistManager::createPlaylist(const std::string& name) {
    for (auto& playlist : playlists) {
        if (playlist.first == name) {
            std::cout << "Playlist already exists!" << std::endl;
            return;
        }
    }
    Playlist* newPlaylist = new Playlist(name);
    playlists.push_back({name, newPlaylist});

    std::cout << "Playlist created successfully: " << name << std::endl;
}

void PlaylistManager::removePlaylist(const std::string& name) {
    for (auto ptrPlaylist = playlists.begin(); ptrPlaylist != playlists.end(); ++ptrPlaylist) {
        if (ptrPlaylist->first == name) {
            delete ptrPlaylist->second;
            playlists.erase(ptrPlaylist);
            std::cout << "Playlist deleted successfully: " << name << std::endl;
            return;
        }
    }
    std::cout << "Playlist not found!" << std::endl;
}

void PlaylistManager::showAllPlaylists(){
    std::cout << "Available Playlists:" << std::endl;
    for (auto& playlist : playlists) {
        std::cout << "- " << playlist.first << std::endl;
    }
    std::cout << std::endl;
}

void PlaylistManager::addSongToPlaylist(const std::string& playlistName, Song* song) {
    for (auto& playlist : playlists) {
        if (playlist.first == playlistName) {
            playlist.second->addSong(song);
            return;
        }
    }
    std::cout << "Playlist not found!" << std::endl;
}

void PlaylistManager::removeSong(const std::string& songTitle) {
    for (auto& playlist : playlists) {
        playlist.second->removeSong(songTitle);
    }
}

void PlaylistManager::moveSongUp(const std::string& playlistName, const std::string& songTitle, int position) {
    for (auto& playlist : playlists) {
        if (playlist.first == playlistName) {
            playlist.second->moveSongUp(songTitle, position);
            return;
        }
    }
    std::cout << "Playlist not found!" << std::endl;
}

void PlaylistManager::moveSongDown(const std::string& playlistName, const std::string& songTitle, int position) {
    for (auto& playlist : playlists) {
        if (playlist.first == playlistName) {
            playlist.second->moveSongDown(songTitle, position);
            return;
        }
    }
    std::cout << "Playlist not found!" << std::endl;
}

void PlaylistManager::displayPlaylist(const std::string& playlistName) {
    for (auto& playlist : playlists) {
        if (playlist.first == playlistName) {
            playlist.second->display();
            return;
        }
    }
    std::cout << "Playlist not found!" << std::endl;
}

Playlist* PlaylistManager::getPlaylist(const std::string& name) {
    for (auto& playlist : playlists) {
        if (playlist.first == name) {
            return playlist.second;
        }
    }
    return nullptr;
}

PlaylistManager::~PlaylistManager() {
    for (auto& playlist : playlists) {
        delete playlist.second;
    }
    playlists.clear();
}