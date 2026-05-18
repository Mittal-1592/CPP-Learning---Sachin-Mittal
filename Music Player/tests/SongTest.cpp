#include <gtest/gtest.h>
#include "Song.h"

class SongTest : public ::testing::Test {
protected:
    Song song{"Believer", "/music/believer.mp3"};
};

TEST_F(SongTest, ConstructorInitializesTitleCorrectly) {
    EXPECT_EQ(song.getTitle(), "Believer");
}

TEST_F(SongTest, ConstructorInitializesFilePathCorrectly) {
    EXPECT_EQ(song.getFilePath(), "/music/believer.mp3");
}

TEST_F(SongTest, TitleShouldNotBeEmpty) {
    EXPECT_FALSE(song.getTitle().empty());
}

TEST_F(SongTest, FilePathShouldNotBeEmpty) {
    EXPECT_FALSE(song.getFilePath().empty());
}
