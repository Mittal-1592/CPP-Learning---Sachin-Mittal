#include "gtest/gtest.h"
#include "FileSystem.h"

class FileSystemTest : public ::testing::Test
{
    protected:
        FileSystem fs;
};

TEST_F(FileSystemTest,WhenCreatingValidDirectory_ThenDirectoryIsCreated)
{
    EXPECT_TRUE(fs.createDir("docs"));

    auto results = fs.findByName("docs");

    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0]->getName(), "docs");
}

TEST_F(FileSystemTest,WhenCreatingDuplicateDirectory_ThenCreationFails)
{
    EXPECT_TRUE(fs.createDir("docs"));
    EXPECT_FALSE(fs.createDir("docs"));
}

TEST_F(FileSystemTest,WhenCreatingValidFile_ThenFileExists)
{
    EXPECT_TRUE(fs.createFile("notes.txt"));

    auto results = fs.findByName("notes.txt");

    ASSERT_EQ(results.size(), 1);
}

TEST_F(FileSystemTest,WhenChangingToExistingDirectory_ThenCurrentPathChanges)
{
    fs.createDir("docs");

    EXPECT_TRUE(fs.changeDir("docs"));
    EXPECT_EQ(fs.getCurrentPath(), "/docs");
}

TEST_F(FileSystemTest,WhenChangingToNonExistingDirectory_ThenOperationFails)
{
    EXPECT_FALSE(fs.changeDir("unknown"));
}

TEST_F(FileSystemTest,WhenChangingToParentDirectory_ThenPathUpdatesCorrectly)
{
    fs.createDir("docs");
    fs.changeDir("docs");

    EXPECT_TRUE(fs.changeDir(".."));
    EXPECT_EQ(fs.getCurrentPath(), "/");
}

TEST_F(FileSystemTest,WhenWritingToExistingFile_ThenContentIsStored)
{
    fs.createFile("file.txt");

    EXPECT_TRUE(fs.writeFile("file.txt", "hello"));
    EXPECT_EQ(fs.readFile("file.txt"), "hello");
}

TEST_F(FileSystemTest,WhenAppendingToFile_ThenNewContentIsAdded)
{
    fs.createFile("file.txt");
    fs.writeFile("file.txt", "hello");

    EXPECT_TRUE(fs.appendToFile("file.txt", " world"));
    EXPECT_EQ(fs.readFile("file.txt"), "hello world");
}

TEST_F(FileSystemTest,WhenRemovingExistingFile_ThenFileNoLongerExists)
{
    fs.createFile("file.txt");

    EXPECT_TRUE(fs.removeFile("file.txt"));

    auto results = fs.findByName("file.txt");

    EXPECT_TRUE(results.empty());
}

TEST_F(FileSystemTest,WhenRemovingExistingDirectory_ThenDirectoryNoLongerExists)
{
    fs.createDir("docs");

    EXPECT_TRUE(fs.removeDir("docs"));

    auto results = fs.findByName("docs");

    EXPECT_TRUE(results.empty());
}

TEST_F(FileSystemTest,WhenSearchingByName_ThenMatchingItemsAreReturned)
{
    fs.createFile("notes.txt");

    auto results = fs.findByName("notes.txt");

    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0]->getName(), "notes.txt");
}

TEST_F(FileSystemTest,WhenSearchingByContent_ThenMatchingFilesAreReturned)
{
    fs.createFile("notes.txt");
    fs.writeFile("notes.txt", "hello world");

    auto results = fs.findByContent("hello");

    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0]->getName(), "notes.txt");
}

TEST_F(FileSystemTest,WhenSearchingBySize_ThenMatchingFilesAreReturned)
{
    fs.createFile("a.txt");
    fs.writeFile("a.txt", "12345");

    auto results = fs.findBySize(5, 5);

    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0]->getName(), "a.txt");
}