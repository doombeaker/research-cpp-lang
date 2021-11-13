#include <iostream>

template <typename... Args>
void function(Args&&...  args){
    std::cout << "template function"<< std::endl;
}

int main(int argc, char* argv[]){
    int i = 100;
    function(100);
    function(i);
    return 0;
}