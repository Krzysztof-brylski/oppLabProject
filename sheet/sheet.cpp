//
// Created by Krzysztof on 09.03.2023.
//

#include "sheet.h"

Sheet::Sheet(int rowsNumber, int columnsNumber) {
    this->numRows=rowsNumber;
    this->numColumns=columnsNumber;
    this->arrayPtr = new IntCell* [this->numRows];
    for(int i=0;i<=this->numRows;i++){
        this->arrayPtr[i] =new IntCell[this->numColumns];
        //memset(this->arrayPtr[i], 0,(sizeof(int)*this->numColumns));
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
    int error;
    string temp;
    for(int i=0;i<rows;i++){
        for(int z=0;z<columns;z++){
            file >> temp;
            //temp.pop_back();
            //tempValue = stoi(temp);
            newSheet->setCell((IntCell::deSerialize(temp,error)),z,i);
            IntCell::deSerialize(temp,error);
            //newSheet->setCellValue( tempValue,z,i);
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

IntCell* &Sheet::operator[](int i) {
    return this->arrayPtr[i];
}

//int Sheet::setCellValue(int value, int rowNumber,int columnNumber) {
//    this->arrayPtr[columnNumber][rowNumber].setValue(value);
//    return 0;
//}
int Sheet::setCell(IntCell* cell, int rowNumber,int columnNumber) {
    this->arrayPtr[columnNumber][rowNumber]=(*cell);
    return 0;
}



void Sheet::resize( int newRowsNumber, int newColumnsNumber) {
    IntCell** temp= new IntCell*[this->numRows];
    for(int i=0;i<this->numRows;i++){
        temp[i] =new IntCell[this->numColumns];
        memcpy(temp[i],this->arrayPtr[i],(sizeof(IntCell)*this->numColumns));
    }




    this->arrayPtr = new IntCell* [newRowsNumber];
    for(int i=0;i<newRowsNumber;i++){
        this->arrayPtr[i] =new IntCell[newColumnsNumber];
        //memset(this->arrayPtr[i], 0,(sizeof(int)*newColumnsNumber));
    }

    for(int i=0;i<this->numRows;i++){
        memcpy(this->arrayPtr[i],temp[i],(sizeof(IntCell)*this->numColumns));
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
            file<<(this->arrayPtr[i][z]).serialize()<<", ";
        }
        file<<"\n";
    }
    file.close();
    return 0;
}

float Sheet::processRow(int rowNumber, float (*action)(int *, int)) {
    int* arr = new int[this->numColumns];
    for(int i=0;i<this->numRows;i++){
        if(i != numRows){
            continue;
        }
        for(int z=0;z<this->numColumns;z++) {
            arr[z]=this->arrayPtr[i][z].getValue();
        }
    }
    return action(arr, this->numRows);
}
float Sheet::processColumn(int columnNumber, float (*action)(int *, int)) {
    int* arr = new int[this->numColumns];
    int index=0;
    for(int i=0;i<this->numRows;i++){
        for(int z=0;z<this->numColumns;z++){
            if(z != columnNumber){
                continue;
            }
            arr[index]=this->arrayPtr[i][z].getValue();
            index++;
        }
    }
    return action(arr, this->numColumns);
}


int Sheet::sumByRow(int rowNumber) {
    return  this->processRow(rowNumber, sum);
}
int Sheet::maxInRow(int rowNumber) {
    return this->processRow(rowNumber, max);
}
int Sheet::minInRow(int rowNumber) {
    return this->processRow(rowNumber, min);
}
float Sheet::avgInRow(int rowNumber){
    return this->processRow(rowNumber, avg);
}

int Sheet::sumByColumn(int columnNumber){
    return  this->processColumn(columnNumber, sum);
}
int Sheet::maxInColumn(int columnNumber) {
    return this->processColumn(columnNumber, max);
}
int Sheet::minInColumn(int columnNumber) {
    return this->processColumn(columnNumber, min);
}
float Sheet::avgInColumn(int columnNumber){
    return this->processColumn(columnNumber, avg);
}



float Sheet::sum(int *arr, int size) {
    float sum=0;
    for(int i =0;i<size;i++){sum+=(float)arr[i];}
    return sum;
}
float Sheet::min(int *arr, int size) {
    float min=arr[0];
    for(int i =0;i<size;i++){
        if(arr[i]<min){min=(float)arr[i];}
    }
    return min;
}
float Sheet::max(int *arr, int size) {
    float max=arr[0];
    for(int i =0;i<size;i++){
        if(arr[i]>max){max=(float)arr[i];}
    }
    return max;
}
float Sheet::avg(int *arr, int size) {
    return (Sheet::sum(arr,size))/size;
}

