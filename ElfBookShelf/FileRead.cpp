/*
 * fileRead.cpp
 *
 *  Created on: Jul 4, 2022
 *      Author: nachiket
 */

#include "FileRead.h"


FileParser::FileRead::FileRead() {
	// TODO Auto-generated constructor stub

}

bool FileParser::FileRead::isEmpty()
{
	if(fileToRead.is_open()){
		return fileToRead.peek() == std::ifstream::traits_type::eof();
	}

	return false;		//should throw exception
}

bool FileParser::FileRead::openFile(std::string filename){
	fileToRead.open(filename);
	if(fileToRead.is_open()){
		return true;
	}
	return false;
}

std::vector<std::string> FileParser::FileRead::readFileData(){
	if(fileToRead.is_open()){
		std::string eachLineRead;
		allReadLines.clear();
		while(std::getline(fileToRead,eachLineRead)){
			allReadLines.push_back(eachLineRead);
			eachLineRead.clear();
		}
		return allReadLines;
	}
	return std::vector<std::string>();		//empty string
}

std::vector<std::vector<int>> FileParser::FileRead::getDimensionsAllBoxes(){

	if(!allReadLines.empty()){

		std::vector<std::vector<int>> boxes;
		for(auto singleLine : allReadLines){
			std::stringstream streamdata(singleLine);
			std::string splittedString;
			std::vector<int> box;			
			while(getline(streamdata,splittedString,'x')){
				box.push_back(stoi(splittedString));
			}
			boxes.push_back(box);
		}
		return boxes;
	}
	return std::vector<std::vector<int>>();

}

FileParser::FileRead::~FileRead() {
	// TODO Auto-generated destructor stub
	if(fileToRead.is_open()){
		fileToRead.close();
	}
}

