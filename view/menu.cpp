#include "menu.h"


void sheetView(Sheet* sheet) {
    cout<<"___________________________"<<endl;
    cout<<"displaying sheet:"<<endl<<endl;

//    cout<<(*sheet)[1][1];
    for(int i=0;i<sheet->getRowsNumber();i++){
        for(int z=0;z<sheet->getColumnsNumber();z++){
            cout<<"  "<<(*sheet)[i][z]<<"  ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"___________________________"<<endl;
}

