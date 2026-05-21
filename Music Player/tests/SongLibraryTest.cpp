#include <gtest/gtest.h>
#include "SongLibrary.h"
#include "Song.h"

class SongLibraryTest : public ::testing::Test {
protected:
    SongLibrary library;

    Song* song1 = new Song("Breeze Air", "/songs/Breeze Air.wav");
    Song* song2 = new Song("Broom Game", "/songs/Broom Game.wav");

    void SetUp() override {
        library.addSong(song1);
        library.addSong(song2);
    }
};

TEST_F(SongLibraryTest, WhenSongIsAdded_ThenItIsStoredCorrectlyInLibrary) {
    EXPECT_EQ(library.getSong("Breeze Air"), song1);
    EXPECT_EQ(library.getSong("Broom Game"), song2);
}

TEST_F(SongLibraryTest, WhenGetSongIsCalledWithValidTitle_ThenCorrectSongIsReturned) {
    Song* result = library.getSong("Breeze Air");

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->getTitle(), "Breeze Air");
    EXPECT_EQ(result->getFilePath(), "/songs/Breeze Air.wav");
}

TEST_F(SongLibraryTest, WhenGetSongIsCalledWithInvalidTitle_ThenReturnsNullptr) {
    EXPECT_EQ(library.getSong("Unknown Song"), nullptr);
}

TEST_F(SongLibraryTest, WhenMultipleSongsAreAdded_ThenAllSongsAreRetrievable) {
    EXPECT_NE(library.getSong("Breeze Air"), nullptr);
    EXPECT_NE(library.getSong("Broom Game"), nullptr);
}