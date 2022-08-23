/*
 * StringTester.cpp
 *
 *  Created on: Jul 19, 2022
 *      Author: nachiket
 */

#include <gmock/gmock.h>

#include "FileRead.h"
#include <vector>
#include <string>
#include "StringParser.h"

using ::testing::Test;
using namespace FileParser;

class ElvesGiftIO : public ::testing::Test{
public:
protected:
	FileRead fr;
	StringParser sp;
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
	bool result = fr.openFile("PuzzleInput");
	ASSERT_EQ(result,true);
	bool resultempty = fr.isEmpty();
	ASSERT_EQ(resultempty,false);
}

TEST_F(ElvesGiftIO,PassDataToParser){
	bool result = fr.openFile("PuzzleInput");
	ASSERT_EQ(result,true);
	std::vector<std::string> readData =  fr.readFileData();
	sp.addData(readData);
	ASSERT_EQ(readData,sp.getData());
}

TEST_F(ElvesGiftIO,CheckIfStringHasValidCharacters){
	std::string stringToPass = "ledsltggvrbvlefn";
	bool result  = sp.CheckIfStringIsValid(stringToPass);
	ASSERT_FALSE(result);
}

TEST_F(ElvesGiftIO,CheckVowel){
	std::string stringToPass = "jkallimne";
	bool result = sp.checkIfAtLeastThreeVowels(stringToPass);
	ASSERT_TRUE(result);
}

TEST_F(ElvesGiftIO,CheckRepetitiveStrings){
	std::string stringToPass = "jkallimne";
	bool result = sp.CheckIfAtLeastOneLetterRepeats(stringToPass);
	ASSERT_TRUE(result);
}

TEST_F(ElvesGiftIO,CheckForInvalidStrings){
	std::string stringToPass = "jkallimne";
	bool result = sp.CheckIfDisallowedStringsPresent(stringToPass);
	ASSERT_FALSE(result);

	stringToPass = "jkallimne";
	bool disallowed = sp.CheckIfDisallowedStringsPresent(stringToPass);
	ASSERT_FALSE(disallowed);
}

TEST_F(ElvesGiftIO,GetAllNiceStrings){

	bool result = fr.openFile("PuzzleInput");
	ASSERT_EQ(result,true);
	std::vector<std::string> readData =  fr.readFileData();
	sp.addData(readData);
	ASSERT_EQ(readData,sp.getData());

	uint32_t countOfNiceStrings = sp.getAllNiceStrings();
	ASSERT_EQ(countOfNiceStrings,(const unsigned int )1000);

}


TEST_F(ElvesGiftIO,DoubleRepeat){

	std::string stringToPass = "khokh";
	bool result = sp.CheckDoubleRepeat(stringToPass);
	ASSERT_TRUE(result);

}

TEST_F(ElvesGiftIO,LetterInBetweenRepeat){

	std::string stringToPass = "khohk";
	bool result = sp.CheckInBetweenRepeat(stringToPass);
	ASSERT_TRUE(result);

}



TEST_F(ElvesGiftIO,GetAllNicerStrings){

	bool result = fr.openFile("PuzzleInput");
	ASSERT_EQ(result,true);
	std::vector<std::string> readData =  fr.readFileData();
	sp.addData(readData);
	ASSERT_EQ(readData,sp.getData());

	uint32_t countOfNiceStrings = sp.getAllNicerStrings();
	ASSERT_EQ(countOfNiceStrings,(const unsigned int )1000);

}
