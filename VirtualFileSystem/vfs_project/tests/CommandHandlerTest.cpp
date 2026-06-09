#include "gtest/gtest.h"
#include "CommandHandler.h"

class CommandHandlerTest : public ::testing::Test
{
    protected:
        FileSystem fs;
        CommandHandler handler{fs};
};

TEST_F(CommandHandlerTest,WhenExecutingMkdirCommand_ThenDirectoryIsCreated)
{
    ParsedCommand cmd;
    cmd.name = "mkdir";
    cmd.args = {"docs"};

    EXPECT_TRUE(handler.execute(cmd));

    auto results = fs.findByName("docs");

    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0]->getName(), "docs");
}

TEST_F(CommandHandlerTest,WhenExecutingTouchCommand_ThenFileIsCreated)
{
    ParsedCommand cmd;
    cmd.name = "touch";
    cmd.args = {"file.txt"};

    EXPECT_TRUE(handler.execute(cmd));

    auto results = fs.findByName("file.txt");

    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0]->getName(), "file.txt");
}