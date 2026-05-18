#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "MusicPlayerController.h"
#include "MockMusicPlayer.h"
#include "MockPlaylistManager.h"

using namespace testing;

class MusicPlayerControllerTest : public ::testing::Test {
protected:
    MockMusicPlayer mockPlayer;
    MockPlaylistManager mockManager;

    SongLibrary library;

    MusicPlayerController controller{
        &mockPlayer,
        &mockManager,
        library
    };
};

TEST_F(MusicPlayerControllerTest, ConstructorInitialization) {
    SUCCEED();
}
