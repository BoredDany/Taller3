#include "NodoGeneral.h"
#include <list>

template <class T>
NodoGeneral<T>::NodoGeneral() {
    this->hijos.clear();
}

template <class T>
NodoGeneral<T>::~NodoGeneral(){
    std::list< NodoGeneral<T> >::iterator it;
    for(it = this->hijos.begin() ; it != this->hijos.end() ; it++){
        delete *it;
    }
    this->hijos.clear();
}

template <class T>
T &NodoGeneral<T>::getDato() {
    return this->dato;
}

template <class T>
void NodoGeneral<T>::setDato(T &dato) {
    this->dato = dato;
}

template <class T>
void NodoGeneral<T>::cleanList() {
    this->hijos.clear();
}

template <class T>
void NodoGeneral<T>::insert(T &datoNuevo) {
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->setDato(datoNuevo);
    this->hijos.push_back(nodo);
}

template <class T>
void NodoGeneral<T>::erase(T &datoEliminar) {
    bool eliminado = false;
    //buscar nodo a eliminar
    std::list< NodoGeneral<T> >::iterator it;
    NodoGeneral<T> *aux;
    for(it = this->hijos.begin() ; it != this->hijos.end() ; it++){
        aux = *it;
        if(aux->getDato() == datoEliminar){
            break;
        }
    }
    //si se encuentra, se elimina
    if(it != this->hijos.end()){
        delete *it;
        this->hijos.erase(it);
        eliminado = true;
    }
    return eliminado;
}

template <class T>
void NodoGeneral<T>::hoja(){
    return this->hijos.size() == 0;
}
