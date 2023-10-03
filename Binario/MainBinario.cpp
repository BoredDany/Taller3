#include "ArbolBinario.h"
#include <iostream>
using namespace std;

int main(){
    ArbolBinario<float> arbolB = *new ArbolBinario<float>();
    float nums [] = {11,6,2,4,5,12,14,17};

    for(float a: nums){
        arbolB.insert(a);
    }

    cout<<"ARBOL BINARIO---------------------------------------------"<<endl;

    cout<<"INORDEN"<<endl;
    arbolB.inOrden();

    cout<<"PREORDEN"<<endl;
    arbolB.preOrden();

    cout<<"POSORDEN"<<endl;
    arbolB.posOrden();

    cout<<"NIVELES"<<endl;
    arbolB.niveles();

    int altura = arbolB.altura();
    cout<<"ALTURA: "<< altura << endl;

    int max = arbolB.maximo();
    cout<<"MAXIMO: "<<max<<endl;

    int min = arbolB.minimo();
    cout<<"MINIMO: "<<min<<endl;

    int tamanio = arbolB.tamano(arbolB.getRaiz());
    cout<<"TAMANIO: "<<tamanio<<endl;

    float i = 11;
    arbolB.erase(i);
    arbolB.inOrden();

    i = 17;
    arbolB.erase(i);
    arbolB.inOrden();

    i = 2;
    arbolB.erase(i);
    arbolB.inOrden();

    i = 19;
    arbolB.insert(i);
    arbolB.inOrden();

    i = 18;
    arbolB.insert(i);
    arbolB.inOrden();

    i = 19;
    arbolB.erase(i);
    arbolB.inOrden();

    cout << "\nARBOL FINAL------------------------------------" << endl;
    arbolB.inOrden();

}