#include "gtest/gtest.h"
#include "CommandParser.h"

TEST(CommandParserTest,WhenParsingCommand_ThenCommandNameAndArgumentsAreExtracted)
{
    auto cmd = CommandParser::parse("mkdir docs");

    EXPECT_EQ(cmd.name, "mkdir");

    ASSERT_EQ(cmd.args.size(), 1);
    EXPECT_EQ(cmd.args[0], "docs");
}

TEST(CommandParserTest,WhenParsingMultipleArguments_ThenAllArgumentsAreStored)
{
    auto cmd = CommandParser::parse("touch a.txt b.txt c.txt");

    EXPECT_EQ(cmd.name, "touch");

    ASSERT_EQ(cmd.args.size(), 3);
    EXPECT_EQ(cmd.args[0], "a.txt");
    EXPECT_EQ(cmd.args[1], "b.txt");
    EXPECT_EQ(cmd.args[2], "c.txt");
}