#ifndef TALLER3_ARBOLGENERAL_H
#define TALLER3_ARBOLGENERAL_H

#include "NodoGeneral.h"
#include <list>
#include <stack>

template<class T>
class ArbolGeneral{

private:
    NodoGeneral<T> *raiz;
public:
    //constructores
    ArbolGeneral();
    ArbolGeneral(T dato);

    //destructor
    ~ArbolGeneral();

    //getters
    NodoGeneral<T>* getRaiz();

    //setters
    void setRaiz(NodoGeneral<T> * raiz);

    //operaciones
    bool vacio();
    bool insert(T& padreNuevo, T& nodoNuevo);
    void insertHijos(T& padreNuevo, std::list < NodoGeneral<T>* > hijos);
    bool erase(T& nodoEliminar);
    int altura();
    int altura(NodoGeneral<T> *nodo);
    int size();
    T maximo();
    T minimo();
    void camino(T&valor, std::stack< T >& ruta);

    //recorridos
    void preorder();
    void posorder();
    void niveles();
};

#include "ArbolGeneral.hxx"

#endif //TALLER3_ARBOLGENERAL_H
