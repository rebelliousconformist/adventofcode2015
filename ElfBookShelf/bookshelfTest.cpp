#include <gmock/gmock.h>

#include "FileRead.h"
#include "GiftBox.h"
#include <vector>
#include <string>

using ::testing::Test;
using namespace FileParser;

class ElvesGiftIO : public ::testing::Test{
public:
protected:
	FileRead fr;
};

//part 1 file read
TEST_F(ElvesGiftIO,Readfile){
	bool result = fr.openFile("PuzzleInput");
	ASSERT_EQ(result,true);
}


TEST_F(ElvesGiftIO,ReadWrongfile){
	bool result = fr.openFile("TestCheckList2");
	ASSERT_NE(result,true);
}

TEST_F(ElvesGiftIO,ReadFileNotEmpty){
	fr.openFile("PuzzleInput");
	bool result = fr.isEmpty();
	ASSERT_EQ(result,false);
}

TEST_F(ElvesGiftIO,ReadFileEdgeCases){
	fr.openFile("PuzzleInput");
	std::vector<std::string> stringVectors =  fr.readFileData();
	ASSERT_STREQ(stringVectors[0].c_str(),"29x13x26");
	ASSERT_STREQ(stringVectors[999].c_str(),"10x9x8");

}

TEST_F(ElvesGiftIO,SplitIntoDimensionsAndStoreIt){
	fr.openFile("PuzzleInput");
	std::vector<std::string> stringVectors =  fr.readFileData();
	ASSERT_STREQ(stringVectors[0].c_str(),"29x13x26");
	ASSERT_STREQ(stringVectors[999].c_str(),"10x9x8");
	std::vector<std::vector<int>> allBoxes = fr.getDimensionsAllBoxes();
	EXPECT_THAT(allBoxes[0][1],13);
}



class ElvesGift : public ::testing::Test{
public:

protected:
	GiftBox gb;
	int length = 2;
	int breadth =3;
	int height = 4;

};

// part 2 create box
TEST_F(ElvesGift,canCreateBox){
}

TEST_F(ElvesGift,canAddDimensions){
	gb.addDimensions(length,breadth,height);
	gb.addDimensions(1,2,3);
}

TEST_F(ElvesGift,getTwoSmallestDimensions){
	gb.addDimensions(length,breadth,height);
	std::vector<int> testVector ;
	testVector.push_back(length);
	testVector.push_back(breadth);

	EXPECT_THAT(testVector,::testing::ContainerEq(gb.getTwoSmallestDimensions()));
}

TEST_F(ElvesGift,AreaOfSmallestSide){
	int length = 2;
	int breadth =7;
	int height = 14;
	gb.addDimensions(length, breadth, height);

	ASSERT_EQ(14,gb.getAreaOfSmallestDimension());
}


TEST_F(ElvesGift,AreaOfWrappingPaper){
	int length = 2;
	int breadth =7;
	int height = 14;

	gb.addDimensions(length, breadth, height);
	ASSERT_EQ(gb.getAreaOfWrappingPaperRequired(),294);

}
