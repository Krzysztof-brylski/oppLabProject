#include <iostream>
#include "../sheet/sheet.h"
using namespace std;

//
// Created by Krzysztof on 09.03.2023.
//
/**
 * displaying specified sheet
 * @param[in] Sheet - sheet to display
 * @return void
 */
void sheetView(Sheet* sheet);
/**
 * displaying specified size of sheet
 * @param sheet - specified sheet
 * @return void
 */
void sheetSizeView(Sheet* sheet);

/**
 *  displaying ui for resize option on specified sheet
 * @param sheet - specified sheet
 * @return void
 */
void sheetResizeView(Sheet* sheet);

/**
 * displaying ui for setting cel value on specified sheet
 * @param sheet - specified sheet
 * @return void
 */
void setCellValueView(Sheet* sheet);

/**
 * displaying ui for opening sheet from specified file
 * @param[out] sheet - opened sheet
 * @return void
 */
void openSheetFromFileView(Sheet* &sheet);

/**
 * displaying ui for saving sheet in specified file
 * @param[in] sheet - sheet to save
 * @return void
 */
void saveSheetInFileView(Sheet* sheet);

/**
 * displaying ui for performing math actions on  specified sheet
 * @return void
 */
void mathActionMenuSubView();

/**
 *  displaying ui for result of math action
 *  @param[in] result  - result of math action
 *  @return void
 */
void mathActionResultView(float result);

/**
 *  displaying ui for performing math actions on row in specified sheet
 *  @param sheet  - specified sheet
 *  @return void
 */
void processRowView(Sheet* sheet);

/**
 *  displaying ui for performing math actions on columns in specified sheet
 *  @param sheet  - specified sheet
 *  @return void
 */
void processColumnView(Sheet* sheet);

/**
 * displaying ui for select on wat math actions wants to be executed (rows/columns)
 * @param sheet - specified sheet
 * @param mathAction - specified math action
 * @return void
 */
void sheetActionMenu(Sheet* sheet, int mathAction);


