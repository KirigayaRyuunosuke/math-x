#include "src/Tfraction.cpp"

int main(){
    Xmath::Tfraction a{1,2};
    Xmath::Tfraction b{3,4,1};
    a.print();
    b.print();
    a = a / b;
    a.print();
}
