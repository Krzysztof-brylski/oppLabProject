#include "menu.h"

/**
 * displaying sheet view
 * @param sheet - pointer to sheet specified for display
 */
//todo add flags for some view options
void sheetView(Sheet* sheet) {
    cout<<"___________________________"<<endl;
    cout<<"displaying sheet:"<<endl<<endl;

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
//<<"type: "<<((*sheet)[i][z]).getType()<<" Value => "<<
