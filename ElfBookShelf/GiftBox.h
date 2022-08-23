/*
 * GiftBox.h
 *
 *  Created on: Jul 1, 2022
 *      Author: nachiket
 */

#ifndef GIFTBOX_H_
#define GIFTBOX_H_

#include <vector>
#include <algorithm>

class GiftBox {
private:
	int pLength, pBreadth, pHeight;
public:
	GiftBox();
	GiftBox(int length,int breadth,int height);
	void addDimensions(int,int,int);
	std::vector<int> getTwoSmallestDimensions();
	int getPerimeterOfSmallestDimension();
	int getAreaOfSmallestDimension();
	int getAreaOfBox();
	int getVolumeOfBox();
	int getAreaOfWrappingPaperRequired();
	int getLengthOfRibbonRequired();
	virtual ~GiftBox();
};

#endif /* GIFTBOX_H_ */
