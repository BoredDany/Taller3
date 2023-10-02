#include "NodoBinario.h"

#ifndef TALLER3_ARBOLBINARIO_H
#define TALLER3_ARBOLBINARIO_H

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

};

#include "ArbolBinario.hxx"

#endif //TALLER3_ARBOLBINARIO_H
