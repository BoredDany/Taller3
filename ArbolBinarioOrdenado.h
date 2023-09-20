#ifndef __ARBOLBINARIOORDENADO_H__
#define __ARBOLBINARIOORDENADO_H__

#include "NodoBinario.h"
template<class T>
class ArbolBinarioOrdenado{
protected:
    NodoBinario<T>* raiz;
public:
    ArbolBinarioOrdenado();
    ~ArbolBinarioOrdenado();
    NodoBinario<T>* getRaiz();
    bool esVacio();
    T datoRaiz();
    int altura();
    int altura(NodoBinario<T>* nodo);
    int tamano();
    int tamano(NodoBinario<T>* nodo);
    bool insertar(T val);
    void eliminar(T val);
    bool buscar(T val);
    void preOrden(NodoBinario<T>* nodo);
    void inOrden();
    void inOrden(NodoBinario<T>* nodo);
    void posOrden(NodoBinario<T>* nodo);
    void nivelOrden();

    void elimHoja();
    void elimConHijoIzq();
    void elimConHijoDer();
    void elimConDosHijos();
};
#include "ArbolBinarioOrdenado.hxx"
#endif // __ARBOLBINARIOORD_H__
