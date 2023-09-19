#ifndef ARBOL_B_H
#define ARBOL_B_H
#include "nodoBinario.h"

template<class T>
class arbolBinario{
protected:
    NodoBinario<T>* raiz;
public:
    arbolBinario();
    arbolBinario(T val);
    ~arbolBinario();
    T getDatoRaiz();
    void setDatoRaiz(T val);
    bool esVacio();
    int altura();
    int altura(NodoBinario<T>* nodo);
    int altura2();
    int tamano();
    void inOrden();
    void inOrden(NodoBinario<T>* nodo);
    void inOrden2();
    void preOrden();
    void posOrden();
    void nivelOrden();
    bool insertar(T val);
    bool eliminar(T val);
    bool buscar(T val);
};

#include "arbolBinario.hxx"
#endif