#include "ArbolBinario.h"
#include <iostream>
using namespace std;

int main(){
    ArbolBinario<int> arbolB = *new ArbolBinario<int>();
    int nums [] = {1,4,5,6,9,12,10,15};

    for(int a: nums){
        arbolB.insert(a);
    }

    cout<<"ARBOL BINARIO"<<endl;
    arbolB.inOrden();



}