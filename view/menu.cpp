#include "menu.h"


void sheetView(Sheet* sheet) {
    cout<<"___________________________"<<endl;
    cout<<"displaying sheet:"<<endl<<endl;

//    cout<<(*sheet)[1][1];
    for(int i=0;i<sheet->getColumnsNumber();i++){
        for(int z=0;z<sheet->getRowsNumber();z++){
            cout<<"  "<<(*sheet)[z][i]<<"  ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"___________________________"<<endl;
}

