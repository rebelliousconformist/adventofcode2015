#include <iostream>
#include <exception>
#include <iostream>

#include "FileRead.h"
#include "PositionParser.h"

int main(int, char**){

	try {
		FileRead fr;
		PositionParser pp;
		fr.openFile("PuzzleInput");
		std::vector<std::string> readData = fr.readFileData();

		int santaSelectorCounter = 0;
		for(auto eachCharacter : readData[0]){
			if((santaSelectorCounter) %2 == 0){
				pp.MoveSanta(eachCharacter);
			}
			else{
				pp.MoveRoboSanta(eachCharacter);
			}
			++santaSelectorCounter;
		}

		std::vector<std::pair<int,int>> uniqueCoor = pp.whereWasSantaUnique();
		std::vector<std::pair<int,int>> uniqueCoorRoboSanta = pp.whereWasRoboSantaUnique();

//		for (auto eachCoordinate : uniqueCoor){
//			std::cout << "{ " <<  eachCoordinate.first << " " << eachCoordinate.second << " }" << std::endl;
//		}
//
//		for (auto eachCoordinateRobo : uniqueCoorRoboSanta){
//			std::cout << "{ " <<  eachCoordinateRobo.first << " " << eachCoordinateRobo.second << " }" << std::endl;
//		}
//
//		std::cout << "total Santa coordinates " << uniqueCoor.size() << "\n";
//		std::cout << "total RoboSanta coordinates " << uniqueCoorRoboSanta.size() << "\n";
//		std::cout << "total unique coordinates " << uniqueCoor.size() + uniqueCoorRoboSanta.size() << "\n";

		std::vector<std::pair<int,int>> coordinatesFinalSanta = pp.whereWereBothSantaUnique();


		for (auto eachCoordinate : coordinatesFinalSanta){
			std::cout << "{ " <<  eachCoordinate.first << " " << eachCoordinate.second << " }" << std::endl;
		}
		std::cout << "total unique coordinates " << coordinatesFinalSanta.size()<< "\n";

	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}


	return 0;


}
