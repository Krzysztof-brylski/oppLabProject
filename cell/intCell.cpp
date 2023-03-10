//
// Created by Krzysztof on 10.03.2023.
//

#include "intCell.h"


IntCell::IntCell(int value,string type){
    this->value = value;
    this->type=type;
}



int IntCell::setValue(int value){
//    if(!regex_match(to_string(value).c_str(),this->mask)){
//        return 1;
//    }
    this->value=value;

    return 0;
}

int IntCell::getValue() {
    return this->value;
}
string IntCell::getType() {
    return this->type;
}


//void IntCell::setMask(string mask){
//    this -> mask = regexRule(mask);
//}

string IntCell::serialize() {
    string valueStr = to_string(this->value);
    string type = this->type;

    return (type+ ", " + valueStr);
}


IntCell* IntCell::deSerialize(string data,int &error) {
    int brakePos = data.find(',');
    if(brakePos == string::npos){
        error=1;
        return nullptr;
    }
    string type=data.substr(0,brakePos);
    string value = data.substr(brakePos+1,data.length());

    IntCell* cell = new  IntCell(stoi(value),type);
   // cout<<cell->getType()<<endl;
    return  cell;
}

IntCell &IntCell::operator=(const IntCell& other) {
    if(this == &other){
        return *this;
    }
    this->value=other.value;
    this->type=other.type;
    return *this;
}

