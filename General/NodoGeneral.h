#ifndef TALLER3_NODOGENERAL_H
#define TALLER3_NODOGENERAL_H

#include <list>

template <class T>
class NodoGeneral {

protected:
    T dato;
    std::list< NodoGeneral<T>* > hijos;
public:
    NodoGeneral();
    ~NodoGeneral();
    T& getDato();
    void setDato(T& dato);
    void cleanList();
    void insert(T& datoNuevo);
    bool erase(T& datoEliminar);
    bool hoja();

};

#include "NodoGeneral.hxx"

#endif //TALLER3_NODOGENERAL_H
