#ifndef TALLER3_NODOGENERAL_H
#define TALLER3_NODOGENERAL_H

#include <list>
#include <stack>

template <class T>
class NodoGeneral {

protected:
    T dato;
    std::list< NodoGeneral<T>* > hijos;
public:
    //constructores
    NodoGeneral();
    NodoGeneral(T& val);

    //destructor
    ~NodoGeneral();

    //getters
    T& getDato();
    std::list< NodoGeneral<T>* > getHijos();

    //setters
    void setDato(T& dato);
    void setHijos(std::list< NodoGeneral<T>* > hijos);

    //limpiar
    void cleanList();

    //operaciones
    bool buscar(T& val);
    NodoGeneral<T>* searchNodo(T& val);
    NodoGeneral<T>* searchPadre(T& val);
    bool insert(T& datoNuevo, NodoGeneral<T> * raiz);
    bool erase(T& datoEliminar, NodoGeneral<T> * raiz);
    bool eraseHijo(NodoGeneral<T> * eliminar);
    bool hoja();
    int tamano();
    T maximo();
    T minimo();
    bool camino(T&valor, std::stack< T >& ruta);

    //recorridos
    void posOrden();
    void preOrden();
    void niveles();

};

#include "NodoGeneral.hxx"

#endif //TALLER3_NODOGENERAL_H
