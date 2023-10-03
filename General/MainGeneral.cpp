#include "ArbolGeneral.h"
#include "NodoGeneral.h"
#include <iostream>
#include <list>
using namespace std;

int main(){
    ArbolGeneral<int> arbolG = *new ArbolGeneral<int>();
    int nums [] = {1,4,5,6,9,12};
    int padre = 1;
    int nuevo = 2;
    std::list< NodoGeneral<int> * > hijos ;
    for(int i: nums){
        NodoGeneral<int> * h = new NodoGeneral<int>(i);
        hijos.push_back(h);
    }
    arbolG.insert(padre,nuevo);
    padre = 2;
    nuevo = 3;
    arbolG.insert(padre,nuevo);
    arbolG.insertHijos(padre, hijos);

    padre = 5;
    nuevo = 8;
    arbolG.insert(padre,nuevo);

    cout<<"ARBOL GENERAL---------------------------------"<<endl;

    cout<<"POSORDEN" <<endl;
    arbolG.posorder();
    cout<<"PREORDEN" <<endl;
    arbolG.preorder();
    cout<<"NIVELES" <<endl;
    arbolG.niveles();

    int altura = arbolG.altura();
    cout<<"ALTURA: " << altura << endl;
    int tamano = arbolG.size();
    cout<<"TAMANIO: " << tamano << endl;
    int maximo = arbolG.maximo();
    cout<<"MAXIMO: " << maximo << endl;
    int minimo = arbolG.minimo();
    cout<<"MINIMO: " << minimo << endl;

    std::stack < int > ruta;
    std::stack < int > rutaCorrecta;
    int a = 12;
    arbolG.camino(a, ruta);
    cout<<"CAMINO: " << endl;
    while(!ruta.empty()){
        rutaCorrecta.push(ruta.top());
        ruta.pop();
    }
    while(!rutaCorrecta.empty()){
        cout << rutaCorrecta.top() << "\t";
        rutaCorrecta.pop();
    }
    cout << endl;

}