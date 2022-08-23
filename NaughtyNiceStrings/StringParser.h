/*
 * StringParser.h
 *
 *  Created on: Jul 19, 2022
 *      Author: nachiket
 */

#ifndef STRINGPARSER_H_
#define STRINGPARSER_H_

#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include <functional>
class StringParser {
private:
	std::vector<std::string> pData;
	std::vector<std::string> disallowedStrings;
	bool pDataAdded = false;
	std::vector<std::string> disallowedCharacters = { "ab","cd","pq","xy"};
public:
	StringParser();
	void addData(std::vector<std::string>);
	std::vector<std::string> getData() { return this->pData;}
	bool CheckIfStringIsValid(std::string&);
	bool checkIfAtLeastThreeVowels(std::string&);
	bool CheckIfAtLeastOneLetterRepeats(std::string&);
	bool CheckIfDisallowedStringsPresent(std::string&);
	bool CheckDoubleRepeat(std::string&);
	bool CheckInBetweenRepeat(std::string&);
	bool getNicerString(std::string& inputString);
	uint32_t getAllNiceStrings();	//use internal pData
	uint32_t getAllNicerStrings();	//use internal pData
	virtual ~StringParser();
};

#endif /* STRINGPARSER_H_ */
