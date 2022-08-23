/*
 * fileRead.cpp
 *
 *  Created on: Jul 4, 2022
 *      Author: nachiket
 */

#include "FileRead.h"

#include <string>

FileRead::FileRead() {
	// TODO Auto-generated constructor stub

}

bool FileRead::isEmpty()
{
	if(fileToRead.is_open()){
		return fileToRead.peek() == std::ifstream::traits_type::eof();
	}

	return false;		//should throw exception
}

bool FileRead::openFile(std::string filename){
	fileToRead.open(filename);
	if(fileToRead.is_open()){
		return true;
	}
	return false;
}

std::vector<std::string> FileRead::readFileData(){
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


FileRead::~FileRead() {
	// TODO Auto-generated destructor stub
	if(fileToRead.is_open()){
		fileToRead.close();
	}
}

