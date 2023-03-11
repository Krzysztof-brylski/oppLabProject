//
// Created by Krzysztof on 09.03.2023.
//
#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include "../cell/intCell.h"
using namespace std;

class Sheet {
private:
    IntCell** arrayPtr= nullptr;
    int numRows=0;
    int numColumns=0;
private:
    /**
     * get all elements from specified row and perform action on it
     * @param[in] rowNumber - specified row number
     * @param[in] action callback function to perform on selected data set
     * @return callback function result
     */
    float processRow(int rowNumber, float(*action)(int* arr, int size) );

    /**
     * get all elements from specified column and perform action on it
     * @param[in] columnNumber - specified column number
     * @param[in] action callback function to perform on selected data set
     * @return callback function result
     */
    float processColumn(int columnNumber, float(*action)(int* arr, int size) );

    /**
     * summing function
     * @param arr - array with data to sum
     * @param size - size of array
     * @return sum
     */
    static float sum(int* arr, int size);

    /**
     * finding min function
     * @param arr - array with data to find min
     * @param size - size of array
     * @return min value
     */
    static float min(int* arr, int size);

    /**
     * finding max function
     * @param arr - array with data to find max
     * @param size - size of array
     * @return max value
     */
    static float max(int* arr, int size);

    /**
     * finding avg function
     * @param arr - array with data to find avg
     * @param size - size of array
     * @return avg value
     */
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
    /**
     * getter for rows number
     * @return rows number
     */
    int getRowsNumber();
    /**
    * getter for columns number
    * @return columns number
    */
    int getColumnsNumber();
    /**
     * overloaded array subscript operator
     * @param[in] i - array index element
     * @return  selected object by index
     */
    IntCell* &operator[](int i);
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
    //int setCellValue(int value, int rowNumber, int columnNumber);


    int setCell(IntCell* cell, int rowNumber,int columnNumber);

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


