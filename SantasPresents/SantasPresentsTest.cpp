//#include <gmock/gmock.h>
//
//#include "FileRead.h"
//#include <vector>
//#include <string>
//#include "PositionParser.h"
//
//using ::testing::Test;
//
//class ElvesGiftIO : public ::testing::Test{
//public:
//protected:
//	FileRead fr;
//};
//
////part 1 file read
//TEST_F(ElvesGiftIO,Readfile){
//	bool result = fr.openFile("PuzzleInput");
//	ASSERT_EQ(result,true);
//}
//
//
//TEST_F(ElvesGiftIO,ReadWrongfile){
//	bool result = fr.openFile("TestCheckList2");
//	ASSERT_NE(result,true);
//}
//
//TEST_F(ElvesGiftIO,ReadFileNotEmpty){
//	fr.openFile("PuzzleInput");
//	bool result = fr.isEmpty();
//	ASSERT_EQ(result,false);
//}
//
//
//
//class SantaLocomotion : public ::testing::Test{
//public:
//protected:
//	PositionParser dp;
//};
//
//TEST_F(SantaLocomotion,StartPosition){
//	std::pair<int,int> startPos = dp.currentPosition();
//	std::pair<int,int> nullPos(0,0);
//	ASSERT_EQ(startPos,nullPos);
//}
//
//TEST_F(SantaLocomotion,ReadEachCharacter){
//	std::pair<int,int> result = dp.convertCharacterToMovement('v');
//	std::pair<int,int> down(0,-1);
//	ASSERT_EQ(result,down);
//}
//
//TEST_F(SantaLocomotion,ChangeCoordinates){
//	std::pair<int,int> result = dp.updatePosition(std::pair<int,int>(1,1));
//	result = dp.updatePosition(std::pair<int,int>(1,-3));
//	std::pair<int,int> movedSanta(2,-2);
//	ASSERT_EQ(result,movedSanta);
//}
//
//TEST_F(SantaLocomotion,MoveSanta){
//	std::pair<int,int> result = dp.MoveSanta('v');
//	result = dp.MoveSanta('v');
//	result = dp.MoveSanta('>');
//
//	std::pair<int,int> whereIsSanta(1,-2);
//	ASSERT_EQ(result,whereIsSanta);
//}
//
//TEST_F(SantaLocomotion,ListOfAllPositions){
//	std::pair<int,int> result = dp.MoveSanta('v');
//	result = dp.MoveSanta('v');
//	result = dp.MoveSanta('>');
//	result = dp.MoveSanta('<');
//	result = dp.MoveSanta('>');
//	std::vector<std::pair<int,int>> listOfVisits = dp.whereWasSanta();
//	std::vector<std::pair<int,int>> resultAllMoves{{0,0}, {0,-1}, {0,-2},{1,-2}, {0,-2},{1,-2} };
//	EXPECT_EQ(resultAllMoves, listOfVisits);
//}
//
//TEST_F(SantaLocomotion,ListAllUniquePositions){
//	std::pair<int,int> result = dp.MoveSanta('v');
//	result = dp.MoveSanta('v');
//	result = dp.MoveSanta('>');
//	result = dp.MoveSanta('<');
//	result = dp.MoveSanta('>');
//	std::vector<std::pair<int,int>> listOfVisits = dp.whereWasSantaUnique();
//	std::vector<std::pair<int,int>> resultAllMoves{{0,0}, {0,-1}, {0,-2},{1,-2}};
//	std::sort(resultAllMoves.begin(),resultAllMoves.end());
//	EXPECT_EQ(resultAllMoves, listOfVisits);
//}
//
//TEST_F(SantaLocomotion,StartPositionRoboSanta){
//	std::pair<int,int> startPos = dp.currentPositionRoboSanta();
//	std::pair<int,int> nullPos(0,0);
//	ASSERT_EQ(startPos,nullPos);
//}
//
//TEST_F(SantaLocomotion,ListAllUniquePositionsRoboSanta){
//	std::pair<int,int> result = dp.MoveRoboSanta('^');
//	result = dp.MoveRoboSanta('v');
//	result = dp.MoveRoboSanta('v');
//	result = dp.MoveRoboSanta('^');
//	std::vector<std::pair<int,int>> listOfVisits = dp.whereWasRoboSantaUnique();
//	std::vector<std::pair<int,int>> resultAllMoves{{0,0}, {0,1}, {0,-1}};
//	std::sort(resultAllMoves.begin(),resultAllMoves.end());
//	EXPECT_EQ(resultAllMoves, listOfVisits);
//}
