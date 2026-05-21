#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "MusicPlayerController.h"
#include "MockMusicPlayer.h"
#include "MockPlaylistManager.h"
#include "SongLibrary.h"
#include "Playlist.h"
#include "Song.h"
#include "Validations.h"

using ::testing::Return;
using ::testing::_;

class MusicPlayerControllerTest : public ::testing::Test {
    protected:
        MockMusicPlayer mockPlayer;
        MockPlaylistManager mockManager;
        SongLibrary library;
        Validations validations; 

        MusicPlayerController controller{&mockPlayer,&mockManager,library,validations};

        Playlist playlist{"Workout"};

        Song* song1 = new Song("Believer", "songs/believer.wav");

        void SetUp() override {
            playlist.addSong(song1);
        }

        void TearDown() override {
            delete song1;
        }
};


TEST_F(MusicPlayerControllerTest, HandlePlayPlaylist_WhenPlaylistHasSongs_ThenCallsSetPlaylistAndPlay) {

    EXPECT_CALL(mockPlayer, setPlaylist(&playlist)).WillOnce(Return(true));
    EXPECT_CALL(mockPlayer, play()).Times(1).WillOnce(Return(true));

    controller.handlePlayPlaylist(&playlist);
}

TEST_F(MusicPlayerControllerTest, HandleNextSong_WhenPlaylistHasSongs_ThenCallsNext) {

    EXPECT_CALL(mockPlayer, next()).Times(1).WillOnce(Return(true));

    controller.handleNextSong(&playlist);
}

TEST_F(MusicPlayerControllerTest, HandlePreviousSong_WhenPlaylistHasSongs_ThenCallsPrevious) {

    EXPECT_CALL(mockPlayer, previous()).Times(1).WillOnce(Return(true));

    controller.handlePreviousSong(&playlist);
}

TEST_F(MusicPlayerControllerTest,HandleMoveSongUp_WhenPlaylistHasSongs_ThenCallsMoveSongUp){
    std::istringstream input("Believer\n""1\n");

    std::streambuf* originalCin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    EXPECT_CALL(mockManager,moveSongUp("Workout", "Believer", _)).Times(1);

    controller.handleMoveSongUp(&playlist, "Workout");

    std::cin.rdbuf(originalCin);
}

TEST_F(MusicPlayerControllerTest,HandleMoveSongDown_WhenPlaylistHasSongs_ThenCallsMoveSongDown){
    Song* song = new Song("Believer", "songs/believer.wav");

    playlist.addSong(song);

    std::istringstream input("Believer\n""1\n");

    std::streambuf* originalCin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    EXPECT_CALL(mockManager,
        moveSongDown("Workout", "Believer", _)
    ).Times(1);

    controller.handleMoveSongDown(&playlist, "Workout");

    std::cin.rdbuf(originalCin);
}

TEST_F(MusicPlayerControllerTest, HandlePauseSong_WhenPlaylistHasSongs_ThenCallsPause) {

    EXPECT_CALL(mockPlayer, pause()).Times(1).WillOnce(Return(true));

    controller.handlePauseSong(&playlist);
}

TEST_F(MusicPlayerControllerTest, HandleStopSong_WhenPlaylistHasSongs_ThenCallsStop) {

    EXPECT_CALL(mockPlayer, stop()).Times(1).WillOnce(Return(true));

    controller.handleStopSong(&playlist);
}

TEST_F(MusicPlayerControllerTest,HandleAddSong_WhenSongExists_ThenAddsSongToPlaylist)
{
    Song* song = new Song("Believer", "/songs/believer.wav");

    library.addSong(song);

    std::istringstream input("Believer\n");

    std::cin.rdbuf(input.rdbuf());

    EXPECT_CALL(mockManager,addSongToPlaylist("Workout",song)).Times(1);

    controller.handleAddSong("Workout");
}

