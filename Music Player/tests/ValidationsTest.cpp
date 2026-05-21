#include <gtest/gtest.h>
#include "Validations.h"

class ValidationsTest : public ::testing::Test {
    protected:
        Validations validations;
};

TEST_F(ValidationsTest, WhenPlaylistNameIsValid_ThenValidationReturnsTrue) {
    EXPECT_TRUE(validations.validatePlaylistName("Workout Playlist"));
}

TEST_F(ValidationsTest, WhenPlaylistNameIsEmpty_ThenValidationReturnsFalse) {
    EXPECT_FALSE(validations.validatePlaylistName(""));
}

TEST_F(ValidationsTest, WhenPlaylistNameContainsOnlySpaces_ThenValidationReturnsFalse) {
    EXPECT_FALSE(validations.validatePlaylistName("     "));
}

TEST_F(ValidationsTest, WhenPlaylistNameHasInvalidCharacters_ThenValidationReturnsFalse) {
    EXPECT_FALSE(validations.validatePlaylistName("@@@@"));
}