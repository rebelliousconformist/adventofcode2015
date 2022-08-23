/*
 * GiftBox.cpp
 *
 *  Created on: Jul 1, 2022
 *      Author: nachiket
 */

#include "GiftBox.h"

GiftBox::GiftBox() {
	// TODO Auto-generated constructor stub

}
GiftBox::GiftBox(int length,int breadth,int height){
	this->pHeight =height;
	this->pLength = length;
	this->pBreadth = breadth;
}

void GiftBox::addDimensions(int length,int breadth,int height){
	this->pHeight =height;
	this->pLength = length;
	this->pBreadth = breadth;
}

std::vector<int> GiftBox::getTwoSmallestDimensions(){
	std::vector<int> smallestDimensions;

	smallestDimensions.push_back(pLength);
	smallestDimensions.push_back(pBreadth);
	smallestDimensions.push_back(pHeight);
	std::sort(smallestDimensions.begin(),smallestDimensions.end());

	return std::vector<int>(smallestDimensions.begin(),smallestDimensions.begin()+2);

}

int GiftBox::getAreaOfSmallestDimension(){
	return (this->getTwoSmallestDimensions()[0] * this->getTwoSmallestDimensions()[1]);
}

int GiftBox::getPerimeterOfSmallestDimension(){
	return (2*(this->getTwoSmallestDimensions()[0] + this->getTwoSmallestDimensions()[1]));
}

int GiftBox::getAreaOfBox(){
	return (2*((pLength * pBreadth) + (pBreadth * pHeight) + (pLength * pHeight)));
}

int GiftBox::getVolumeOfBox(){
	return (pLength * pBreadth * pHeight);
}

int GiftBox::getAreaOfWrappingPaperRequired(){
	return (this->getAreaOfSmallestDimension() + this->getAreaOfBox());
}

int GiftBox::getLengthOfRibbonRequired(){
	return (this->getVolumeOfBox() + this->getPerimeterOfSmallestDimension());
}

GiftBox::~GiftBox() {
	// TODO Auto-generated destructor stub
}

