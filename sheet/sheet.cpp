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

float Sheet::processRow(int rowNumber, float (*action)(int *, int)) {
    return action(this->arrayPtr[rowNumber], this->numRows);
}
float Sheet::processColumn(int columnNumber, float (*action)(int *, int)) {
    int* arr = new int[this->numColumns];
    int index=0;
    for(int i=0;i<this->numRows;i++){
        for(int z=0;z<this->numColumns;z++){
            if(z != columnNumber){
                continue;
            }
            arr[index]=this->arrayPtr[i][z];
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
    float max=0;
    for(int i =0;i<size;i++){
        if(arr[i]>max){max=(float)arr[i];}
    }
    return max;
}
float Sheet::avg(int *arr, int size) {
    return (Sheet::sum(arr,size))/size;
}

