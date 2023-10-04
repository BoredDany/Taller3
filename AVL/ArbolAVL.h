#include "NodoAVL.h"

#ifndef TALLER3_ARBOLAVL_H
#define TALLER3_ARBOLAVL_H

#include <stack>
#include <queue>

template < class T >
class ArbolAVL{
private:
    NodoAVL<T> *raiz;
public:
    ArbolAVL();
    ArbolAVL(T& val);
    ~ArbolAVL();

    NodoAVL<T>* getRaiz();

    void setRaiz(NodoAVL<T>* raiz);

    void inOrden();
    void posOrden();
    void preOrden();
    void niveles();

    bool buscar(T& val);
    bool insert(T& val);
    bool erase(T& val);

    bool vacio();
    int tamano(NodoAVL<T> * nodo);
    int altura();
    int minimo();
    int maximo();
    void ruta(T val, std::stack<T>& camino,  NodoAVL<T> * nodo);
};

#include "ArbolAVL.hxx"

#endif //TALLER3_ARBOLAVL_H
