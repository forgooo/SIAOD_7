#include "First.h"
#include "Second.h"

int main(){
    for(int SIZE = 100; SIZE < 1000000; SIZE*=10){
        linearSearch(SIZE);
    }
    std::cout << "----------------\n";
    for(int SIZE = 100; SIZE < 1000000; SIZE*=10){
        barrierSearch(SIZE);
    }
    std::cout << "----------------\n";
    for(int SIZE = 100; SIZE < 1000000; SIZE*=10){
        interpolationSearchStart(SIZE);
    }
}