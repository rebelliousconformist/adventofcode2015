/*
 * fileRead.h
 *
 *  Created on: Jul 4, 2022
 *      Author: nachiket
 */

#ifndef FILEREAD_H_
#define FILEREAD_H_

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
namespace FileParser{
struct dimensions{
	int l,b,h;
};

class FileRead {
private:
	std::ifstream fileToRead;
	std::vector<std::string> allReadLines;
	std::vector<dimensions> readDimensions;
public:
	FileRead();

	std::vector<std::string> readFileData();
	bool openFile(std::string);
	bool isEmpty();
	virtual ~FileRead();
};


}



#endif /* FILEREAD_H_ */
