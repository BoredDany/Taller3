#include "NodoGeneral.h"
#include <list>
#include <iostream>
#include <queue>
#include <stack>

//constructores
// ------------------------------------------------
template <class T>
NodoGeneral<T>::NodoGeneral() {
    this->hijos.clear();
}

template <class T>
NodoGeneral<T>::NodoGeneral(T& val) {
    this->dato = val;
    this->hijos.clear();
}

//destructores
// ------------------------------------------------
template <class T>
NodoGeneral<T>::~NodoGeneral(){
    for(NodoGeneral<T>* n : this->hijos){
        delete *n;
    }
    this->hijos.clear();
}

//getters
// ------------------------------------------------
template <class T>
T &NodoGeneral<T>::getDato() {
    return this->dato;
}

template <class T>
std::list< NodoGeneral<T>* > NodoGeneral<T>::getHijos(){
    return this->hijos;
}

//setters
// ------------------------------------------------
template <class T>
void NodoGeneral<T>::setDato(T &dato) {
    this->dato = dato;
}

//limpiar hijos
// ------------------------------------------------
template <class T>
void NodoGeneral<T>::cleanList() {
    this->hijos.clear();
}

template <class T>
void NodoGeneral<T>::setHijos(std::list< NodoGeneral<T>* > hijos){
    for(NodoGeneral<T> * hijo : hijos){
        this->hijos.push_back(hijo);
    }
}

//operaciones
// ------------------------------------------------
template <class T>
bool NodoGeneral<T>::search(T& val){
    for(NodoGeneral<T>* n : this->hijos){
        if(n->dato == val){
            return true;
        }
    }
    return false;
}

template <class T>
bool NodoGeneral<T>::insert(T &datoNuevo) {
    NodoGeneral<T> *nodo = new NodoGeneral<T>(datoNuevo);
    if(!this->search(datoNuevo)){
        this->hijos.push_back(nodo);
        return true;
    }
    return false;
}

template <class T>
bool NodoGeneral<T>::erase(T &datoEliminar) {
    /*bool eliminado = false;
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
    return eliminado;*/
}

template <class T>
NodoGeneral<T>* NodoGeneral<T>::searchNodo(T& val){
    if(val == this->dato){
        return this;
    }
    for(NodoGeneral<T> * hijo: this->hijos){
        NodoGeneral<T> * result = hijo->searchNodo(val);
        if(result != nullptr){
            return result;
        }
    }
    return nullptr;
}

template <class T>
bool NodoGeneral<T>::hoja(){
    return this->hijos.size() == 0;
}

template <class T>
int NodoGeneral<T>::tamano(){
    int tam = 1;
    for(NodoGeneral<T>* hijo : this->hijos){
        tam += hijo->tamano();
    }
    return tam;
}

template <class T>
T NodoGeneral<T>::maximo(){
    T max = this->dato;
    for(NodoGeneral<T> * hijo : this->hijos){
        int maxHijo = hijo->maximo();
        if(maxHijo > max){
            max = maxHijo;
        }
    }
    return max;
}

template <class T>
T NodoGeneral<T>::minimo(){
    T min = this->dato;
    for(NodoGeneral<T> * hijo : this->hijos){
        int minHijo = hijo->maximo();
        if(minHijo < min){
            min = minHijo;
        }
    }
    return min;
}

template <class T>
bool NodoGeneral<T>::camino(T&valor, std::stack< T >& ruta){

    ruta.push(this->dato);
    if(this->dato == valor){
        return true;
    }

    for(NodoGeneral<T> * hijo : this->hijos){
        if(hijo->camino(valor, ruta)){
            return true;
        }
    }

    ruta.pop();
    return false;
}

//recorridos
// ------------------------------------------------
template <class T>
void NodoGeneral<T>::posOrden(){
    for(NodoGeneral<T>* hijo : this->hijos){
        hijo->posOrden();
    }
    std:: cout << this->dato << "\t";
}

template <class T>
void NodoGeneral<T>::preOrden(){
    std:: cout << this->dato << "\t";
    for(NodoGeneral<T>* hijo : this->hijos){
        hijo->preOrden();
    }
}
template <class T>
void NodoGeneral<T>::niveles(){
    std::queue< NodoGeneral<T>* > q;
    q.push(this);

    while(!q.empty()){
        NodoGeneral<T>* nodo = q.front();
        std::cout << nodo->dato << "\t";
        for(NodoGeneral<T>* hijo : nodo->hijos){
            q.push(hijo);
        }
        q.pop();
    }
}