#include <iostream>

class T{

};

using LR = T&;
using RR = T&&;

using T1 = LR&;     //T& &;
using T2 = LR&&;    //T& &&;
using T3 = RR&;     //T&& &;
using T4 = RR&&;    // T&& &&

int main(int argc, char* argv[]){
    // T4& x = "";
    return 0;
}