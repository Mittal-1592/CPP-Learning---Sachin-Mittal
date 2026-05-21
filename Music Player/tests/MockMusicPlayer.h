#ifndef MOCKMUSICPLAYER_H
#define MOCKMUSICPLAYER_H

#include <gmock/gmock.h>
#include "IMusicPlayer.h"

class MockMusicPlayer : public IMusicPlayer {
public:
    MOCK_METHOD(bool, play, (), (override));
    MOCK_METHOD(bool, pause, (), (override));
    MOCK_METHOD(bool, stop, (), (override));
    MOCK_METHOD(bool, next, (), (override));
    MOCK_METHOD(bool, previous, (), (override));
    MOCK_METHOD(bool, setPlaylist, (Playlist* playlist), (override));
};

#endif