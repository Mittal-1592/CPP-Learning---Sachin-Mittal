#include <gtest/gtest.h>
#include "Validations.h"

class ValidationsTest : public ::testing::Test {
    protected:
        Validations validations;
};

TEST_F(ValidationsTest, ValidPlaylistName) {
    EXPECT_TRUE(validations.validatePlaylistName("Workout Playlist"));
}

TEST_F(ValidationsTest, EmptyPlaylistName) {
    EXPECT_FALSE(validations.validatePlaylistName(""));
}

TEST_F(ValidationsTest, OnlySpacesPlaylistName) {
    EXPECT_FALSE(validations.validatePlaylistName("     "));
}

TEST_F(ValidationsTest, InvalidCharactersPlaylistName) {
    EXPECT_FALSE(validations.validatePlaylistName("@@@@"));
}