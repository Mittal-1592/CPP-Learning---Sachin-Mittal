#include <gtest/gtest.h>

#include "MusicPlayer.h"
#include "Playlist.h"
#include "Song.h"

class MusicPlayerTest : public ::testing::Test {
protected:
    MusicPlayer player;

    Playlist playlist{"Workout"};

    Song* song1 = new Song("Breeze Air", "songs/Breeze Air.wav");
    Song* song2 = new Song("Broom Game", "songs/Broom Game.wav");

    void SetUp() override {
        playlist.addSong(song1);
        playlist.addSong(song2);

        player.setPlaylist(&playlist);
    }
};

TEST_F(MusicPlayerTest, SetPlaylistDoesNotThrowException) {
    EXPECT_NO_THROW(player.setPlaylist(&playlist));
}

TEST_F(MusicPlayerTest, PlayDoesNotThrowException) {
    EXPECT_NO_THROW(player.play());
}

TEST_F(MusicPlayerTest, PauseDoesNotThrowException) {
    EXPECT_NO_THROW(player.pause());
}

TEST_F(MusicPlayerTest, StopDoesNotThrowException) {
    EXPECT_NO_THROW(player.stop());
}

TEST_F(MusicPlayerTest, NextDoesNotThrowException) {
    EXPECT_NO_THROW(player.next());
}

TEST_F(MusicPlayerTest, PreviousDoesNotThrowException) {
    EXPECT_NO_THROW(player.previous());
}

TEST_F(MusicPlayerTest, NextHandlesPlaylistWrapping) {
    player.next();
    player.next();

    EXPECT_NO_THROW(player.play());
}

TEST_F(MusicPlayerTest, PreviousHandlesPlaylistWrapping) {
    player.previous();

    EXPECT_NO_THROW(player.play());
}

TEST_F(MusicPlayerTest, EmptyPlaylistNextDoesNotCrash) {
    Playlist emptyPlaylist;

    player.setPlaylist(&emptyPlaylist);

    EXPECT_NO_THROW(player.next());
}

TEST_F(MusicPlayerTest, EmptyPlaylistPreviousDoesNotCrash) {
    Playlist emptyPlaylist;

    player.setPlaylist(&emptyPlaylist);

    EXPECT_NO_THROW(player.previous());
}