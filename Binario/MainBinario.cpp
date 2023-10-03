#include "ArbolBinario.h"
#include <iostream>
#include <stack>
using namespace std;

int main(){
    ArbolBinario<int> arbolB = *new ArbolBinario<int>();
    int nums [] = {11,6,2,4,5,12,14,17};

    for(int a: nums){
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

    int a = 5;
    std::stack<int> ruta;
    arbolB.ruta(a, ruta);
    cout<<"RUTA: " <<endl;
    while(!ruta.empty()){
        int e = ruta.top();
        cout << e << "\t";
        ruta.pop();
    }

    int i = 11;
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