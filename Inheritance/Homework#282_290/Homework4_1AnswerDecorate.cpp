//
// Created by ahmed-kashkoush on 3/1/23.
//
#include "macros.h"
class DecoratedString:public string{
public:
    using string::string;// to use all string constructors;
    void Decorate(){
        string str=*this;
        str="<<[["+str+"]]>>";
        this->assign(str);
    }
};
int main(){
    DecoratedString str= "I am reading";
    str.Decorate();
    cout<<str;

}



