#include <gtest/gtest.h>
#include "PlaylistManager.h"
#include "Song.h"

class PlaylistManagerTest : public ::testing::Test {
protected:
    PlaylistManager manager;

    Song* song1 = new Song("Believer", "songs/believer.wav");

    void TearDown() override {
        delete song1;
    }
};

TEST_F(PlaylistManagerTest, WhenCreatePlaylistIsCalled_ThenPlaylistIsCreatedSuccessfully) {
    manager.createPlaylist("Workout");

    EXPECT_NE(manager.getPlaylist("Workout"), nullptr);
}

TEST_F(PlaylistManagerTest, WhenRemovePlaylistIsCalled_ThenPlaylistIsDeletedSuccessfully) {
    manager.createPlaylist("Workout");

    manager.removePlaylist("Workout");

    EXPECT_EQ(manager.getPlaylist("Workout"), nullptr);
}

TEST_F(PlaylistManagerTest, WhenGetPlaylistIsCalledWithInvalidName_ThenReturnsNullptr) {
    EXPECT_EQ(manager.getPlaylist("Unknown"), nullptr);
}

TEST_F(PlaylistManagerTest, WhenAddSongToPlaylistIsCalled_ThenSongIsAddedSuccessfully) {
    manager.createPlaylist("Workout");

    manager.addSongToPlaylist("Workout", song1);

    Playlist* playlist = manager.getPlaylist("Workout");

    ASSERT_NE(playlist, nullptr);
    EXPECT_EQ(playlist->getSongs().size(), 1);
}

TEST_F(PlaylistManagerTest, WhenRemoveSongIsCalled_ThenSongIsRemovedSuccessfully) {
    manager.createPlaylist("Workout");
    manager.addSongToPlaylist("Workout", song1);

    manager.removeSong("Believer");

    Playlist* playlist = manager.getPlaylist("Workout");

    EXPECT_TRUE(playlist->getSongs().empty());
}