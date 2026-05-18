#include <gtest/gtest.h>
#include "PlaylistManager.h"

class PlaylistManagerTest : public ::testing::Test {
protected:
    PlaylistManager manager;
    Song* song;

    void SetUp() override {
        song = new Song("Believer", "path");
    }

    void TearDown() override {
        delete song;
    }
};

TEST_F(PlaylistManagerTest, CreatePlaylistSuccessfully) {
    manager.createPlaylist("Workout");

    Playlist* playlist = manager.getPlaylist("Workout");

    EXPECT_NE(playlist, nullptr);
}

TEST_F(PlaylistManagerTest, DuplicatePlaylistNotCreated) {
    manager.createPlaylist("Workout");
    manager.createPlaylist("Workout");

    EXPECT_NE(manager.getPlaylist("Workout"), nullptr);
}

TEST_F(PlaylistManagerTest, RemovePlaylistSuccessfully) {
    manager.createPlaylist("Workout");

    manager.removePlaylist("Workout");

    EXPECT_EQ(manager.getPlaylist("Workout"), nullptr);
}

TEST_F(PlaylistManagerTest, AddSongToPlaylistSuccessfully) {
    manager.createPlaylist("Workout");

    manager.addSongToPlaylist("Workout", song);

    Playlist* playlist = manager.getPlaylist("Workout");

    EXPECT_EQ(playlist->getSongs().size(), 1);
}