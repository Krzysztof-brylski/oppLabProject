//
// Created by Krzysztof on 09.03.2023.
//
#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sheet {
private:
    int** arrayPtr= nullptr;
    int numRows=0;
    int numColumns=0;
private:
    float processRow(int rowNumber, float(*action)(int* arr, int size) );
    float processColumn(int rowNumber, float(*action)(int* arr, int size) );
    static float sum(int* arr, int size);
    static float min(int* arr, int size);
    static float max(int* arr, int size);
    static float avg(int* arr, int size);
public:

    /**
     * Constructor for sheet
     * @param[in] rowsNumber - number of rows for new sheet
     * @param[in] columnsNumber - number of columns for new sheet
     */
    Sheet(int rowsNumber=0, int columnsNumber=0);

    /**
     * Building sheet object from file
     * @param[in] path - path to text file with data for sheet
     * @return Sheet* - return pointer to new sheet object
     */
    static Sheet* buildFromFile(string path);
public:

    int getRowsNumber();
    int getColumnsNumber();
    int* &operator[](int i);
public:

    /**
     * resizing sheet array
     * @param[in] newRowsNumber - new number of rows for new sheet
     * @param[in] newColumnsNumber - new number of columns for new sheet
     */
    void resize( int newRowsNumber, int newColumnsNumber);

    /**
     * setting value for specified cell
     * @param[in] value - value to set up in cell
     * @param[in] rowNumber - specified cell row number
     * @param[in] columnNumber -specified cell column number
     * @return 0 if succeed, other value error codes
     */
    int setCellValue(int value, int rowNumber, int columnNumber);

    /**
     * save object in file
     * @param[in] fileName - name of file specified to save sheet
     * @return  0 if succeed, other value error codes
     */
    int saveInFile(string fileName);


public:
    /**
     * @param[in] rowNumber specified row number
     * @return sum of cells in specified row
     */
    int sumByRow(int rowNumber);

    /**
     * @param[in] rowNumber specified row number
     * @return max value from cells in specified row
     */
    int maxInRow(int rowNumber);

    /**
     * @param[in] rowNumber specified row number
     * @return min value from cells in specified row
     */
    int minInRow(int rowNumber);

    /**
     * @param[in] rowNumber specified row number
     * @return avg value from cells in specified row
     */
    float avgInRow(int rowNumber);


public:
    /**
     * @param[in] columnNumber specified row column
     * @return sum of cells in specified column
     */
    int sumByColumn(int columnNumber);

    /**
     * @param[in] columnNumber specified row column
     * @return max value from cells in specified column
     */
    int maxInColumn(int columnNumber);

    /**
     * @param[in] columnNumber specified row column
     * @return min value from cells in specifiedcolumn
     */
    int minInColumn(int columnNumber);

    /**
     * @param[in] columnNumber specified row column
     * @return avg value from cells in specified column
     */
    float avgInColumn(int columnNumber);

};


