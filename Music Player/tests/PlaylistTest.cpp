#include <gtest/gtest.h>
#include "Playlist.h"
#include "Song.h"

class PlaylistTest : public ::testing::Test {
protected:
    Playlist playlist{"Workout"};

    Song* song1 = new Song("Breeze Air", "songs/Breeze Air.wav");
    Song* song2 = new Song("Broom Game", "songs/Broom Game.wav");
    Song* song3 = new Song("Cloud Nine", "songs/Cloud Nine.wav");

    void SetUp() override {
        playlist.addSong(song1);
        playlist.addSong(song2);
        playlist.addSong(song3);
    }
};

TEST_F(PlaylistTest, WhenPlaylistIsCreated_ThenNameIsInitializedCorrectly) {
    EXPECT_EQ(playlist.getName(), "Workout");
}

TEST_F(PlaylistTest, WhenSongIsAdded_ThenPlaylistSizeIncreasesAndSongIsStoredCorrectly) {
    Song* song4 = new Song("Demons", "songs/Demons.wav");

    playlist.addSong(song4);

    EXPECT_EQ(playlist.getSongs().size(), 4);
    EXPECT_EQ(playlist.getSongs()[3], song4);
}

TEST_F(PlaylistTest, WhenSongsAreAddedInSetUp_ThenTheyAreStoredInCorrectOrder) {
    EXPECT_EQ(playlist.getSongs().size(), 3);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Breeze Air");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Broom Game");
    EXPECT_EQ(playlist.getSongs()[2]->getTitle(), "Cloud Nine");
}

TEST_F(PlaylistTest, WhenSongIsRemoved_ThenPlaylistSizeDecreasesAndOrderIsMaintained) {
    playlist.removeSong("Broom Game");

    EXPECT_EQ(playlist.getSongs().size(), 2);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Breeze Air");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Cloud Nine");
}

TEST_F(PlaylistTest, WhenInvalidSongIsRemoved_ThenPlaylistRemainsUnchanged) {
    playlist.removeSong("Unknown");

    EXPECT_EQ(playlist.getSongs().size(), 3);
}

TEST_F(PlaylistTest, WhenAllSongsAreRemovedOneByOne_ThenPlaylistBecomesEmpty) {
    playlist.removeSong("Breeze Air");
    playlist.removeSong("Broom Game");
    playlist.removeSong("Cloud Nine");

    EXPECT_TRUE(playlist.getSongs().empty());
}

TEST_F(PlaylistTest, WhenSongIsMovedUp_ThenOrderIsUpdatedCorrectly) {
    playlist.moveSongUp("Broom Game", 0);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Broom Game");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Breeze Air");
}

TEST_F(PlaylistTest, WhenFirstSongIsMovedUp_ThenOrderRemainsUnchanged) {
    playlist.moveSongUp("Breeze Air", 0);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Breeze Air");
}

TEST_F(PlaylistTest, WhenInvalidSongIsMovedUp_ThenPlaylistRemainsUnchanged) {
    playlist.moveSongUp("Unknown", 1);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Breeze Air");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Broom Game");
}

TEST_F(PlaylistTest, WhenSongIsMovedDown_ThenOrderIsUpdatedCorrectly) {
    playlist.moveSongDown("Breeze Air", 1);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Broom Game");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Breeze Air");
}

TEST_F(PlaylistTest, WhenLastSongIsMovedDown_ThenOrderRemainsUnchanged) {
    playlist.moveSongDown("Cloud Nine", 2);

    EXPECT_EQ(playlist.getSongs()[2]->getTitle(), "Cloud Nine");
}

TEST_F(PlaylistTest, WhenInvalidSongIsMovedDown_ThenPlaylistRemainsUnchanged) {
    playlist.moveSongDown("Unknown", 1);

    ASSERT_TRUE(playlist.getSongs().size());

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Breeze Air");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Broom Game");
}

TEST_F(PlaylistTest, WhenGetSongsIsCalled_ThenCorrectSizeIsReturned) {
    EXPECT_EQ(playlist.getSongs().size(), 3);
}

TEST_F(PlaylistTest, WhenGetSongsIsCalled_ThenCorrectSongsAreReturned) {
    std::vector<Song*> songs = playlist.getSongs();

    EXPECT_EQ(songs[0]->getTitle(), "Breeze Air");
    EXPECT_EQ(songs[1]->getTitle(), "Broom Game");
    EXPECT_EQ(songs[2]->getTitle(), "Cloud Nine");
}

TEST_F(PlaylistTest, WhenGetNameIsCalled_ThenCorrectPlaylistNameIsReturned) {
    EXPECT_EQ(playlist.getName(), "Workout");
}

TEST_F(PlaylistTest, WhenPlaylistIsInitialized_ThenItIsNotEmpty) {
    EXPECT_FALSE(playlist.getSongs().empty());
}

TEST_F(PlaylistTest, WhenSongIsRemoved_ThenPlaylistSizeDecreasesByOne) {
    int initialSize = playlist.getSongs().size();

    playlist.removeSong("Breeze Air");

    EXPECT_EQ(playlist.getSongs().size(), initialSize - 1);
}