#include "ArbolAVL.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){

    ArbolAVL<int> arbolAVL = *new ArbolAVL<int>();
    int nums [] = {11,6,2,4,5,12,14,17};

    for(int a: nums){
        arbolAVL.insert(a);
    }

    cout<<"ARBOL BINARIO---------------------------------------------"<<endl;

    cout<<"INORDEN"<<endl;
    arbolAVL.inOrden();

    cout<<"PREORDEN"<<endl;
    arbolAVL.preOrden();

    cout<<"POSORDEN"<<endl;
    arbolAVL.posOrden();

    cout<<"NIVELES"<<endl;
    arbolAVL.niveles();

    int altura = arbolAVL.altura();
    cout<<"ALTURA: "<< altura << endl;

    int max = arbolAVL.maximo();
    cout<<"MAXIMO: "<<max<<endl;

    int min = arbolAVL.minimo();
    cout<<"MINIMO: "<<min<<endl;

    int tamanio = arbolAVL.tamano(arbolAVL.getRaiz());
    cout<<"TAMANIO: "<<tamanio<<endl;

/*
    int a = 5;
    std::stack<int> ruta;
    std::stack<int> rutaCorrecta;
    arbolAVL.ruta(a, ruta, arbolAVL.getRaiz());
    cout<<"RUTA: " <<endl;
    while(!ruta.empty()){
        rutaCorrecta.push(ruta.top());
        ruta.pop();
    }
    while(!rutaCorrecta.empty()){
        cout << rutaCorrecta.top() << "\t";
        rutaCorrecta.pop();
    }
    cout << endl;


    int i = 11;
    arbolAVL.erase(i);
    arbolAVL.inOrden();

    i = 17;
    arbolAVL.erase(i);
    arbolAVL.inOrden();

    i = 2;
    arbolAVL.erase(i);
    arbolAVL.inOrden();

    i = 19;
    arbolAVL.insert(i);
    arbolAVL.inOrden();

    i = 18;
    arbolAVL.insert(i);
    arbolAVL.inOrden();

    i = 19;
    arbolAVL.erase(i);
    arbolAVL.inOrden();

    cout << "\nARBOL FINAL------------------------------------" << endl;
    arbolAVL.inOrden();*/

}