/*
 * DataParser.h
 *
 *  Created on: Jul 13, 2022
 *      Author: nachiket
 */

#ifndef POSITIONPARSER_H_
#define POSITIONPARSER_H_

#include <utility>
#include <vector>
#include <algorithm>
class PositionParser {
private:
	std::pair<int,int> positionSanta;
	std::pair<int,int> positionRoboSanta;
	std::vector<std::pair<int,int>> coordinatesSanta;
	std::vector<std::pair<int,int>> coordinatesRoboSanta;
	std::vector<std::pair<int,int>> coordinatesUnique;
	std::vector<std::pair<int,int>> coordinatesUniqueRoboSanta;
	std::vector<std::pair<int,int>> coordinatesFinal;

public:
	PositionParser();
	std::pair<int,int> currentPosition();
	std::pair<int,int> currentPositionRoboSanta();
	void setPosition(std::pair<int,int>);
	std::pair<int,int> updatePosition(std::pair<int,int> moveBy);
	std::pair<int,int> updatePositionRoboSanta(std::pair<int,int> moveBy);
	std::pair<int,int> MoveSanta(char c);
	std::pair<int,int> MoveRoboSanta(char c);
	std::vector<std::pair<int,int>> whereWasSanta();
	std::vector<std::pair<int,int>> whereWasRoboSanta();
	std::vector<std::pair<int,int>> whereWasSantaUnique();
	std::vector<std::pair<int,int>> whereWasRoboSantaUnique();
	std::vector<std::pair<int,int>> whereWereBothSantaUnique();
	std::pair<int,int> convertCharacterToMovement(char c);
	virtual ~PositionParser();
};

#endif /* POSITIONPARSER_H_ */
