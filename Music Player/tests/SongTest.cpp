#include <gtest/gtest.h>
#include "Song.h"

class SongTest : public ::testing::Test {
    protected:
        Song song{"Believer", "/music/believer.mp3"};
};

TEST_F(SongTest, WhenSongIsCreated_ThenTitleAndFilePathAreInitializedCorrectly) {
    EXPECT_EQ(song.getTitle(), "Believer");
    EXPECT_EQ(song.getFilePath(), "/music/believer.mp3");
}

TEST_F(SongTest, WhenSongIsCreated_ThenTitleShouldNotBeEmpty) {
    EXPECT_FALSE(song.getTitle().empty());
}

TEST_F(SongTest, WhenSongIsCreated_ThenFilePathShouldNotBeEmpty) {
    EXPECT_FALSE(song.getFilePath().empty());
}
