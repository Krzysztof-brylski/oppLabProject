#include "menu.h"


//todo add flags for some view options
//<<"type: "<<((*sheet)[i][z]).getType()<<" Value => "<<
void sheetView(Sheet* sheet) {
    cout<<"___________________________"<<endl;
    cout<<"Displaying sheet:"<<endl<<endl;

//    cout<<(*sheet)[1][1];
    for(int i=0;i<sheet->getRowsNumber();i++){
        for(int z=0;z<sheet->getColumnsNumber();z++){
            cout<<"  "<<((*sheet)[i][z]).getValue()<<"  ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"___________________________"<<endl;
}

void sheetSizeView(Sheet* sheet){
    cout<<"___________________________"<<endl;
    cout<<"Sheet current size rows:"<<sheet->getRowsNumber()<<" columns: "<<sheet->getColumnsNumber()<<endl<<endl;
}

void sheetResizeView(Sheet* sheet){
    int newRows,newColumns;
    sheetSizeView(sheet);
    cout<<"___________________________"<<endl<<endl;
    cout<<"Set new row number: "<<endl;
    cin>>newRows;
    cout<<"Set new columns number: "<<endl;
    cin>>newColumns;
    sheet->resize(newRows,newColumns);
}

void setCellValueView(Sheet* sheet){
    int row=0,column=0,value=0;
    cout<<"___________________________"<<endl<<endl;
    cout<<"Set cell position for new value (row, column) : "<<endl;
    cin>>row;
    cin>>column;
    cout<<"Set value:"<<endl;

    sheet->setCell(
            new IntCell(value),
            row,
            column
    );

}

void openSheetFromFileView(Sheet* &sheet){
    string path;
    cout<<"___________________________"<<endl<<endl;
    cout<<"Select file name to open:"<<endl;
    cin>>path;

    sheet = Sheet::buildFromFile(path);
}


void saveSheetInFileView(Sheet* sheet){
    string path;
    cout<<"___________________________"<<endl<<endl;
    cout<<"Select file name to save:"<<endl;
    cin>>path;
    sheet->saveInFile(path);

    //sheet = Sheet::buildFromFile(path);
}

void mathActionMenuSubView(){
   // System("cls");
    cout<<"___________________________"<<endl<<endl;
    cout<<"Select option: "<<endl;
    cout<<"1. sum"<<endl;
    cout<<"2. min value"<<endl;
    cout<<"3. max value"<<endl;
    cout<<"4. avg value"<<endl;

}

void mathActionResultView(float result){
    cout<<"___________________________"<<endl<<endl;
    cout<<"Action result: "<<endl;
    cout<<result<<endl<<endl;
}

void processRowView(Sheet* sheet){
    int operation,row;

    mathActionMenuSubView();
    cin>>operation;
    switch (operation) {
        case 1:
            cin>>row;
            mathActionResultView(sheet->sumByRow(row));
            break;
        case 2:
            cin>>row;
            mathActionResultView(sheet->minInRow(row));
            break;
        case 3:
            cin>>row;
            mathActionResultView(sheet->maxInRow(row));
            break;
        case 4:
            cin>>row;
            mathActionResultView(sheet->avgInRow(row));
            break;
        default:
            //todo error
            break;
    }

}

void processColumnView(Sheet* sheet){
    int operation,column;
    mathActionMenuSubView();
    cin>>operation;
    switch (operation) {
        case 1:
            cin>>column;
            mathActionResultView(sheet->sumByColumn(column));
            break;
        case 2:
            cin>>column;
            mathActionResultView(sheet->minInColumn(column));
            break;
        case 3:
            cin>>column;
            mathActionResultView(sheet->maxInColumn(column));
            break;
        case 4:
            cin>>column;
            mathActionResultView(sheet->avgInColumn(column));
            break;
        default:
            //todo error
            break;
    }

}



void sheetActionMenu(Sheet* sheet, int mathAction){
    int select;
    cout<<"___________________________"<<endl<<endl;
    cout<<"Select option: "<<endl;
    cout<<"1. perform action on row"<<endl;
    cout<<"2. perform action on column"<<endl;
    cin >> select;
    switch (select) {
        case 1:
            processRowView(sheet);

            break;
        case 2:
            processColumnView(sheet);
            break;
        default:
            //todo error
            break;
    }
}

