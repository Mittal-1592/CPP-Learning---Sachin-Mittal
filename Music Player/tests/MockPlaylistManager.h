#ifndef MOCKPLAYLISTMANAGER_H
#define MOCKPLAYLISTMANAGER_H

#include <gmock/gmock.h>
#include "IPlaylistManager.h"

class MockPlaylistManager : public IPlaylistManager {
public:
    MOCK_METHOD(void, createPlaylist, (const std::string&), (override));
    MOCK_METHOD(void, removePlaylist, (const std::string&), (override));
    MOCK_METHOD(bool, showAllPlaylists, (), (override));
    MOCK_METHOD(void, addSongToPlaylist, (const std::string&, Song*), (override));
    MOCK_METHOD(void, removeSong, (const std::string&), (override));
    MOCK_METHOD(void, moveSongUp, (const std::string&, const std::string&, int), (override));
    MOCK_METHOD(void, moveSongDown, (const std::string&, const std::string&, int), (override));
    MOCK_METHOD(void, displayPlaylist, (const std::string&), (override));
    MOCK_METHOD(Playlist*, getPlaylist, (const std::string&), (override));
};

#endif