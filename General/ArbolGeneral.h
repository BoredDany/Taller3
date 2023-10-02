#ifndef TALLER3_ARBOLGENERAL_H
#define TALLER3_ARBOLGENERAL_H

#include "NodoGeneral.h"

template<class T>
class ArbolGeneral{

private:
    NodoGeneral<T> *raiz;
public:
    ArbolGeneral();
    ArbolGeneral(T dato);
    ~ArbolGeneral();
    NodoGeneral<T>* getRaiz();
    void setRaiz(NodoGeneral<T> * raiz);
    bool vacio();
    bool insert(T padreNuevo, T nodoNuevo);
    bool erase(T nodoEliminar);
    bool search(T nodoBuscar);
    int altura();
    int altura(NodoGeneral<T> *nodo)
    int size();
    void preorder();
    void posorder();
    void inorder();
};

#include "ArbolGeneral.hxx"

#endif //TALLER3_ARBOLGENERAL_H
