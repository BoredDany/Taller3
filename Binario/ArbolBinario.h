#include "NodoBinario.h"

#ifndef TALLER3_ARBOLBINARIO_H
#define TALLER3_ARBOLBINARIO_H

#include <stack>
#include <queue>

template < class T >
class ArbolBinario{
private:
    NodoBinario<T> *raiz;
public:
    ArbolBinario();
    ArbolBinario(T& val);
    ~ArbolBinario();

    NodoBinario<T>* getRaiz();

    void setRaiz(NodoBinario<T>* raiz);

    void inOrden();
    void posOrden();
    void preOrden();
    void niveles();

    bool buscar(T& val);
    bool insert(T& val);
    bool erase(T& val);

    bool vacio();

    int tamano(NodoBinario<T> * nodo);
    int altura();
    int minimo();
    int maximo();

    void ruta(T val, std::stack<T>& camino,  NodoBinario<T> * nodo);
};

#include "ArbolBinario.hxx"

#endif //TALLER3_ARBOLBINARIO_H
