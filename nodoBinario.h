#ifndef NODO_B_H
#define NODO_B_H

template<class T>
class NodoBinario{
protected:
    T dato;
    NodoBinario<T>* hijoIzq;
    NodoBinario<T>* hijoDer;
public:
    NodoBinario();
    NodoBinario(T val);
    ~NodoBinario();
    T getDato();
    NodoBinario<T>* getHijoIzq();
    NodoBinario<T>* getHijoDer();
    void setDato(T val);
    void setHijoIzq(NodoBinario<T>* hijoIz);
    void setHijoDer(NodoBinario<T>* hijoDer);
    bool esHoja();
    int altura();
    void inOrden();
};

#include "nodoBinario.hxx"
#endif