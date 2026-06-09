#include "gtest/gtest.h"
#include "Directory.h"
#include "File.h"

class DirectoryTest : public ::testing::Test{
    protected:
        std::shared_ptr<Directory> dir;

        void SetUp() override
        {
            dir = std::make_shared<Directory>("docs");
        }

        void TearDown() override
        {
            dir.reset();
        }
};

TEST_F(DirectoryTest,WhenAddingChild_ThenChildExistsInDirectory)
{
    auto file = std::make_shared<File>("a.txt");

    dir->addChild(file);

    EXPECT_TRUE(dir->hasChild("a.txt"));
}

TEST_F(DirectoryTest,WhenRemovingChild_ThenChildNoLongerExists)
{
    auto file = std::make_shared<File>("a.txt");

    dir->addChild(file);
    dir->removeChild("a.txt");

    EXPECT_FALSE(dir->hasChild("a.txt"));
}