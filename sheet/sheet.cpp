//
// Created by Krzysztof on 09.03.2023.
//

#include "sheet.h"

Sheet::Sheet(int columnsNumber,int rowsNumber) {
    this->numRows=rowsNumber;
    this->numColumns=columnsNumber;
    this->arrayPtr = new int*[this->numColumns];
    for(int i=0;i<this->numColumns;i++){
        this->arrayPtr[i] =new int[this->numRows];
    }
}

Sheet *Sheet::buildFromFile(string path) {
    string columnsNumber, rowsNumber;
    int columns, rows;
    fstream file;

    file.open(path,ios::in);
    getline(file, columnsNumber);
    getline(file, rowsNumber);

    columns=stoi(columnsNumber);
    rows = stoi(rowsNumber);

    Sheet* newSheet = new Sheet(columns,rows);
    string temp;
    int tempValue;
    for(int i=0;i<rows;i++){
        for(int z=0;z<columns;z++){
            file >> temp;
            temp.pop_back();
            tempValue = stoi(temp);
            newSheet->setCellValue(tempValue,z,i);
        }
    }
    file.close();

    return newSheet;
}

int Sheet::getRowsNumber() {
    return this->numRows;
}

int Sheet::getColumnsNumber() {
    return this->numColumns;
}

int* &Sheet::operator[](int i) {
    return this->arrayPtr[i];
}

int Sheet::setCellValue(int value, int columnNumber, int rowNumber) {
    this->arrayPtr[columnNumber][rowNumber]=value;
}
