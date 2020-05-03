#include "pch.h"
#include "FileOff.cpp"
#include "Point.cpp"
#include "Vertex.cpp"

/*
    Test class for read file .off
*/
class FileOffTest : public ::testing::Test
{
protected:
    FileOff *fileOff;
    std::string subPath = "\\GoogleTest\\cube.off";
    std::string fullPath;
;
    FileOffTest()
    {
        fileOff = new FileOff;
    }

    ~FileOffTest() override
    {
        delete fileOff;
    }

    void SetUp() override {
        fullPath = fileOff->getCurrentDir() + "\\GoogleTest\\cube.off";
    }
};

TEST_F(FileOffTest, CheckIfAFileExists) {

    std::cout << (fullPath) << std::endl;

    bool exists = fileOff->exists(fullPath);
    EXPECT_EQ(exists, true);
}

TEST_F(FileOffTest, IsValidOffFile) {
    
    vector<string> data = fileOff->load(fullPath)->getData();

    EXPECT_FALSE(data.empty());
    EXPECT_TRUE(fileOff->isValid());
}

TEST_F(FileOffTest, CountElements) {

    FileOff* loadedFile = fileOff->load(fullPath);

    EXPECT_GT(loadedFile->getCountVertex(), 0);
    EXPECT_GT(loadedFile->getCountEdges(), 0);
    EXPECT_GT(loadedFile->getCountFaces(), 0);
}

TEST_F(FileOffTest, VerticesCoordinates) {

    FileOff* loadedFile = fileOff->load(fullPath);

    size_t size = loadedFile->vertices.size();

    EXPECT_FALSE(loadedFile->vertices.empty());
}