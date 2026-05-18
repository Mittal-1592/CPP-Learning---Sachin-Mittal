#ifndef MOCKMUSICPLAYER_H
#define MOCKMUSICPLAYER_H

#include <gmock/gmock.h>
#include "IMusicPlayer.h"

class MockMusicPlayer : public IMusicPlayer {
public:
    MOCK_METHOD(void, play, (), (override));
    MOCK_METHOD(void, pause, (), (override));
    MOCK_METHOD(void, stop, (), (override));
    MOCK_METHOD(void, next, (), (override));
    MOCK_METHOD(void, previous, (), (override));
    MOCK_METHOD(void, setPlaylist, (Playlist* playlist), (override));
};

#endif