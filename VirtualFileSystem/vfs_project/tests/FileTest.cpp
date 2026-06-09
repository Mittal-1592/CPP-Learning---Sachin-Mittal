#include "gtest/gtest.h"
#include "File.h"

class FileTest : public ::testing::Test
{
    protected:
        File file{"test.txt"};
};

TEST_F(FileTest,WhenSettingContent_ThenContentCanBeRetrieved)
{
    file.setContent("hello");
    EXPECT_EQ(file.getContent(),"hello");
}

TEST_F(FileTest,WhenAppendingContent_ThenContentIsExtended)
{
    file.setContent("hello");
    file.appendContent(" world");
    EXPECT_EQ(file.getContent(),"hello world");
}

TEST_F(FileTest,WhenContentChanges_ThenSizeReflectsContentLength)
{
    file.setContent("hello");
    EXPECT_EQ(file.getSize(),5);
}