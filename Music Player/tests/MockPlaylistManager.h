#ifndef MOCKPLAYLISTMANAGER_H
#define MOCKPLAYLISTMANAGER_H

#include <gmock/gmock.h>
#include "IPlaylistManager.h"

class MockPlaylistManager : public IPlaylistManager {
public:
    MOCK_METHOD(void, createPlaylist, (const std::string& name), (override));
    MOCK_METHOD(void, removePlaylist, (const std::string& name), (override));
    MOCK_METHOD(bool, showAllPlaylists, (), (override));

    MOCK_METHOD(void, addSongToPlaylist,(const std::string& playlistName, Song* song),(override));
    MOCK_METHOD(void, removeSong,(const std::string& songTitle),(override));
    MOCK_METHOD(void, moveSongUp,(const std::string& playlistName,const std::string& songTitle,int position),(override));
    MOCK_METHOD(void, moveSongDown,(const std::string& playlistName,const std::string& songTitle,int position),(override));
    MOCK_METHOD(void, displayPlaylist,(const std::string& playlistName),(override));
    MOCK_METHOD(Playlist*, getPlaylist,(const std::string& name),(override));
};

#endif