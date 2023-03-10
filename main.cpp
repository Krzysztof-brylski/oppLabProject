
#include "sheet/sheet.h"
#include "view/menu.h"

int main(){

    Sheet* sheet = Sheet::buildFromFile("test.txt");
    sheetView(sheet);
    //cout<<sheet->maxInRow(0)<<endl;
    //sheet->resize(6,9);
    //sheetView(sheet);
//
   // sheet->saveInFile("text2.txt");
//    Sheet* sheet = new Sheet(1,2);
//    sheetView(sheet);

}