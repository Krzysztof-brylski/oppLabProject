
#include "sheet/sheet.h"
#include "view/menu.h"

int main(){

    Sheet* sheet = Sheet::buildFromFile("test.txt");
    sheetView(sheet);

}