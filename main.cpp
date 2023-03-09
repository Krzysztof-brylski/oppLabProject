
#include "sheet/sheet.h"
#include "view/menu.h"

int main(){

    Sheet* sheet = Sheet::buildFromFile("test.txt");
    sheetView(sheet);
    sheet->resize(7,7);
    sheetView(sheet);

    sheet->saveInFile("text2.txt");

}