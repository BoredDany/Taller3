#include "ArbolGeneral.h"
#include <iostream>
using namespace std;

int main(){
    ArbolGeneral<int> arbolG = *new ArbolGeneral<int>();
    int nums [] = {1,4,5,6,9,12,10,15};

    for(int a: nums){
        arbolG.insert(a);
    }

    cout<<"ARBOL BINARIO"<<endl;
    arbolG.inOrden();

    cout<<"ALTURA"<<endl;

    cout<<"TAMANIO"<<endl;


}