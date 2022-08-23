/*
 * StringParser.cpp
 *
 *  Created on: Jul 19, 2022
 *      Author: nachiket
 */

#include "StringParser.h"
#include <iostream>

//Thanks to https://github.com/pviafore/AdventOfCode2015/blob/master/challenges/challenge5.cpp for reference

StringParser::StringParser() {
	// TODO Auto-generated constructor stub

}
void StringParser::addData(std::vector<std::string> data)  {
	this->pData = data;
	pDataAdded = true;

}

bool StringParser::CheckIfStringIsValid(std::string& inputString){

	for(auto character:inputString){

		if((character > 122) | (character < 97) ){
			return false;
		}
	}

	return true;
}

bool StringParser::checkIfAtLeastThreeVowels(std::string& inputString){

	std::string vowels = "aeiou";

	if (std::count_if(inputString.begin(),inputString.end(),[&vowels](char c){ return vowels.find(c) != std::string::npos; }) >= 3){
		return true;
	}
	return false;
}




bool StringParser::CheckIfAtLeastOneLetterRepeats(std::string& inputString){

	for (size_t i =1; i < inputString.size(); i++){
		if(inputString[i] == inputString[i-1]){
			return true;
		}
	}

	return false;

}

bool StringParser::CheckIfDisallowedStringsPresent(std::string& inputString){

/*
	std all_of syntax:
	std::all_of(vector.begin,vector.end,lambda);
	std::all_of(vector.begin,vector.end,[incomingvariable](vectorunpackingtype){ return condition (a == b) in bool });
*/

	return std::all_of(disallowedCharacters.begin(), disallowedCharacters.end(), [inputString](std::string& disallowedCharacter){ return (inputString.find(disallowedCharacter) == std::string::npos); });



}

uint32_t StringParser::getAllNiceStrings(){

		//use count_if to return
	int nicestrings = std::count_if(pData.begin(), pData.end(), [&](std::string s){ return (CheckIfStringIsValid(s) &&  checkIfAtLeastThreeVowels(s) && CheckIfAtLeastOneLetterRepeats(s) && CheckIfDisallowedStringsPresent(s) ); });

	return nicestrings;
}

//part two


bool StringParser::CheckDoubleRepeat(std::string& inputString){

	std::regex doubleMatch("([a-z]{2}).*\\1");	//match [a-z] small cases two times(repeat) followed by any characters, \\1 match the same string which was matched in the group before
	std::smatch sm;
	return std::regex_search(inputString,sm,doubleMatch);

}

bool StringParser::CheckInBetweenRepeat(std::string& inputString){
	std::regex repeateMatch("([a-z])[a-z]\\1");	//match ([a-z]) small cases two times(repeat) followed by any characters, \\1 match the same string which was matched in the group () before
	std::smatch sm;
	return std::regex_search(inputString,sm,repeateMatch);		//match ([a-z]) small cases two times(repeat) in a group
}

bool StringParser::getNicerString(std::string& inputString){

	return (CheckInBetweenRepeat(inputString) && CheckDoubleRepeat(inputString));
}

uint32_t StringParser::getAllNicerStrings(){
	// https://github.com/pviafore/AdventOfCode2015/blob/master/challenges/challenge5.cpp

//	return std::count_if(pData.begin(),pData.end(),std::bind1st(std::mem_fn(&StringParser::getNicerString),&));		//Not working
	std::regex doubleMatch("([a-z]{2}).*\\1");	//match [a-z] small cases two times(repeat) followed by any characters, \\1 match the same string which was matched in the group before
	std::regex repeateMatch("([a-z])[a-z]\\1");	//match ([a-z]) small cases two times(repeat) followed by any characters, \\1 match the same string which was matched in the group () before
	std::smatch sm;

	return std::count_if(pData.begin(),pData.end(),[&doubleMatch,&repeateMatch,&sm](std::string inputString){ return (std::regex_search(inputString,sm,doubleMatch) && std::regex_search(inputString,sm,repeateMatch)); });
}

StringParser::~StringParser() {
	// TODO Auto-generated destructor stub
}

