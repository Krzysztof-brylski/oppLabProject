//
// Created by Krzysztof on 09.03.2023.
//

#include "sheet.h"

Sheet::Sheet(int rowsNumber, int columnsNumber) {
    this->numRows=rowsNumber;
    this->numColumns=columnsNumber;
    this->arrayPtr = new int*[this->numRows];
    for(int i=0;i<=this->numRows;i++){
        this->arrayPtr[i] =new int[this->numColumns];
        memset(this->arrayPtr[i], 0,(sizeof(int)*this->numColumns));

    }
}

Sheet *Sheet::buildFromFile(string path) {
    string columnsNumber, rowsNumber;
    int columns, rows;
    fstream file;

    file.open(path,ios::in);
    getline(file, rowsNumber);
    getline(file, columnsNumber);

    columns=stoi(columnsNumber);
    rows = stoi(rowsNumber);

    Sheet* newSheet = new Sheet(rows,columns);
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

int Sheet::setCellValue(int value, int rowNumber,int columnNumber) {
    this->arrayPtr[columnNumber][rowNumber]=value;
    return 0;
}

void Sheet::resize( int newRowsNumber, int newColumnsNumber) {
    int** temp= new int*[this->numRows];
    for(int i=0;i<this->numRows;i++){
        temp[i] =new int[this->numColumns];
        memcpy(temp[i],this->arrayPtr[i],(sizeof(int)*this->numColumns));
    }




    this->arrayPtr = new int*[newRowsNumber];
    for(int i=0;i<newRowsNumber;i++){
        this->arrayPtr[i] =new int[newColumnsNumber];
        memset(this->arrayPtr[i], 0,(sizeof(int)*newColumnsNumber));

    }

    for(int i=0;i<this->numRows;i++){
        memcpy(this->arrayPtr[i],temp[i],(sizeof(int)*this->numColumns));
    }
    this->numColumns=newColumnsNumber;
    this->numRows=newRowsNumber;

    delete[] temp;

}

int Sheet::saveInFile(string fileName) {
    fstream file;
    file.open(fileName,ios::out);
    file<< this->numRows<<"\n";
    file<< this->numColumns<<"\n";

    for(int i =0; i<this->numRows;i++){
        for(int z =0; z<this->numColumns;z++){
            file<<this->arrayPtr[i][z]<<", ";
        }
        file<<"\n";
    }
    file.close();
    return 0;
}
