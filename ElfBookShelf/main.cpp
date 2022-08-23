#include <iostream>
#include "FileRead.h"
#include "GiftBox.h"


int main(int, char**) {

   std::cout << "hello" << std::endl;
    //1. read data
   FileParser::FileRead fr;
   fr.openFile("PuzzleInput");
   fr.readFileData();
   std::vector<std::vector<int>> allboxes = fr.getDimensionsAllBoxes();
   //2. create gift boxes
   std::vector<GiftBox*> allGiftBoxes;
    //push data to gift boxes
   for (auto box : allboxes){
       allGiftBoxes.push_back(new GiftBox(box[0],box[1],box[2]));

   }
   //3. get areas
   long totalarea = 0;
   int totalribbonlength = 0;

   for(auto giftbox : allGiftBoxes){

       totalarea += giftbox->getAreaOfWrappingPaperRequired();
       totalribbonlength += giftbox->getLengthOfRibbonRequired();
   }

   std::cout << "total area required" << totalarea << "ribbon length" << totalribbonlength << std::endl;

   //4. clean up memory
   for(auto box : allGiftBoxes){
       delete box;
   }

   allGiftBoxes.clear();


}
