/*
 * DataParser.cpp
 *
 *  Created on: Jul 13, 2022
 *      Author: nachiket
 */

#include "PositionParser.h"

PositionParser::PositionParser() {
	// TODO Auto-generated constructor stub
	positionSanta = std::pair<int,int>(0,0);
	positionRoboSanta = std::pair<int,int>(0,0);
	coordinatesSanta.push_back(positionSanta);
	coordinatesRoboSanta.push_back(positionRoboSanta);

}

std::pair<int,int> PositionParser::currentPosition(){
	return positionSanta;
}

std::pair<int,int> PositionParser::currentPositionRoboSanta(){
	return positionRoboSanta;
}

std::pair<int,int> PositionParser::convertCharacterToMovement(char c){

		switch (c) {
			case '^':
			return std::pair<int,int>(0,1);
				break;
			case '<':
				return std::pair<int,int>(-1,0);
				break;
			case '>':
				return std::pair<int,int>(1,0);
				break;
			case 'v':
				return std::pair<int,int>(0,-1);
			default:
				return std::pair<int,int>(0,0);
				break;
		}
}

inline std::pair<int,int> operator+(const std::pair<int,int>& currentPosition, std::pair<int,int>& newPosition){
	return {currentPosition.first + newPosition.first, currentPosition.second + newPosition.second};
}

std::pair<int,int> PositionParser::updatePosition(std::pair<int,int> moveBy){
	positionSanta = positionSanta + moveBy;
	return positionSanta ;
}

std::pair<int,int> PositionParser::updatePositionRoboSanta(std::pair<int,int> moveBy){
	positionRoboSanta = positionRoboSanta + moveBy;
	return positionRoboSanta ;
}

std::pair<int,int> PositionParser::MoveSanta(char c){

	positionSanta = updatePosition(convertCharacterToMovement(c));	//superfluous
	coordinatesSanta.push_back(positionSanta);
	return positionSanta;
}

std::pair<int,int> PositionParser::MoveRoboSanta(char c){

	positionRoboSanta = updatePositionRoboSanta(convertCharacterToMovement(c));	//superfluous
	coordinatesRoboSanta.push_back(positionRoboSanta);
	return positionRoboSanta;
}

std::vector<std::pair<int,int>> PositionParser::whereWasSanta(){
	return coordinatesSanta;
}

std::vector<std::pair<int,int>> PositionParser::whereWasRoboSanta(){
	return coordinatesRoboSanta;
}

std::vector<std::pair<int,int>> PositionParser::whereWasSantaUnique(){

	coordinatesUnique = coordinatesSanta;

	std::sort(coordinatesUnique.begin(),coordinatesUnique.end());
	auto last = std::unique(coordinatesUnique.begin(),coordinatesUnique.end());
	coordinatesUnique.erase(last,coordinatesUnique.end());

	return coordinatesUnique;

}


std::vector<std::pair<int,int>> PositionParser::whereWasRoboSantaUnique(){

	coordinatesUniqueRoboSanta = coordinatesRoboSanta;

	std::sort(coordinatesUniqueRoboSanta.begin(),coordinatesUniqueRoboSanta.end());
	auto last = std::unique(coordinatesUniqueRoboSanta.begin(),coordinatesUniqueRoboSanta.end());
	coordinatesUniqueRoboSanta.erase(last,coordinatesUniqueRoboSanta.end());

	return coordinatesUniqueRoboSanta;

}

std::vector<std::pair<int,int>> PositionParser::whereWereBothSantaUnique(){

	//do not use wherewasSanata().begin(). will lead to dangling reference due to return parameter going out of scope
	std::vector<std::pair<int,int>> santa = whereWasSanta();
	std::vector<std::pair<int,int>> roboSanta = whereWasRoboSanta();


	coordinatesFinal.insert(coordinatesFinal.end(), santa.begin(), santa.end());
	coordinatesFinal.insert(coordinatesFinal.end(), roboSanta.begin(), roboSanta.end());

	std::sort(coordinatesFinal.begin(),coordinatesFinal.end());
	auto last  = std::unique(coordinatesFinal.begin(),coordinatesFinal.end());
	coordinatesFinal.erase(last,coordinatesFinal.end());
	return coordinatesFinal;
}



PositionParser::~PositionParser() {
	// TODO Auto-generated destructor stub
}

