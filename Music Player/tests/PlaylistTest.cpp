#include <gtest/gtest.h>
#include "Playlist.h"
#include "Song.h"

class PlaylistTest : public ::testing::Test {
protected:
    Playlist playlist{"Workout"};

    Song* song1 = new Song("Believer", "/songs/believer.wav");
    Song* song2 = new Song("Thunder", "/songs/thunder.wav");
    Song* song3 = new Song("Radioactive", "/songs/radioactive.wav");

    void SetUp() override {
        playlist.addSong(song1);
        playlist.addSong(song2);
        playlist.addSong(song3);
    }
};

TEST_F(PlaylistTest, PlaylistNameInitializedCorrectly) {
    EXPECT_EQ(playlist.getName(), "Workout");
}

TEST_F(PlaylistTest, AddSongSuccessfully) {
    Song* song4 = new Song("Demons", "/songs/demons.wav");

    playlist.addSong(song4);

    EXPECT_EQ(playlist.getSongs().size(), 4);
    EXPECT_EQ(playlist.getSongs()[3], song4);
}

TEST_F(PlaylistTest, MultipleSongsStoredCorrectly) {
    EXPECT_EQ(playlist.getSongs().size(), 3);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Believer");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Thunder");
    EXPECT_EQ(playlist.getSongs()[2]->getTitle(), "Radioactive");
}

TEST_F(PlaylistTest, RemoveSongSuccessfully) {
    playlist.removeSong("Thunder");

    EXPECT_EQ(playlist.getSongs().size(), 2);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Believer");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Radioactive");
}

TEST_F(PlaylistTest, RemoveNonExistingSongDoesNothing) {
    playlist.removeSong("Unknown");

    EXPECT_EQ(playlist.getSongs().size(), 3);
}

TEST_F(PlaylistTest, RemoveAllSongsOneByOne) {
    playlist.removeSong("Believer");
    playlist.removeSong("Thunder");
    playlist.removeSong("Radioactive");

    EXPECT_TRUE(playlist.getSongs().empty());
}

TEST_F(PlaylistTest, MoveSongUpSuccessfully) {
    playlist.moveSongUp("Thunder", 0);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Thunder");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Believer");
}

TEST_F(PlaylistTest, MoveFirstSongUpShouldNotChangeOrder) {
    playlist.moveSongUp("Believer", 0);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Believer");
}

TEST_F(PlaylistTest, MoveInvalidSongUpDoesNothing) {
    playlist.moveSongUp("Unknown", 1);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Believer");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Thunder");
}

TEST_F(PlaylistTest, MoveSongDownSuccessfully) {
    playlist.moveSongDown("Believer", 1);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Thunder");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Believer");
}

TEST_F(PlaylistTest, MoveLastSongDownShouldNotChangeOrder) {
    playlist.moveSongDown("Radioactive", 2);

    EXPECT_EQ(playlist.getSongs()[2]->getTitle(), "Radioactive");
}

TEST_F(PlaylistTest, MoveInvalidSongDownDoesNothing) {
    playlist.moveSongDown("Unknown", 1);

    EXPECT_EQ(playlist.getSongs()[0]->getTitle(), "Believer");
    EXPECT_EQ(playlist.getSongs()[1]->getTitle(), "Thunder");
}

TEST_F(PlaylistTest, GetSongsReturnsCorrectSize) {
    EXPECT_EQ(playlist.getSongs().size(), 3);
}

TEST_F(PlaylistTest, GetSongsReturnsCorrectSongs) {
    std::vector<Song*> songs = playlist.getSongs();

    EXPECT_EQ(songs[0]->getTitle(), "Believer");
    EXPECT_EQ(songs[1]->getTitle(), "Thunder");
    EXPECT_EQ(songs[2]->getTitle(), "Radioactive");
}

TEST_F(PlaylistTest, GetNameReturnsCorrectPlaylistName) {
    EXPECT_EQ(playlist.getName(), "Workout");
}

TEST_F(PlaylistTest, PlaylistInitiallyNotEmptyAfterSetup) {
    EXPECT_FALSE(playlist.getSongs().empty());
}

TEST_F(PlaylistTest, PlaylistSizeUpdatesAfterRemovingSong) {
    size_t initialSize = playlist.getSongs().size();

    playlist.removeSong("Believer");

    EXPECT_EQ(playlist.getSongs().size(), initialSize - 1);
}