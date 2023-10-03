#include "ArbolGeneral.h"
#include <stack>

//constructores
// ------------------------------------------------
template<class T>
ArbolGeneral<T>::ArbolGeneral() {
    this->raiz = nullptr;
}

template<class T>
ArbolGeneral<T>::ArbolGeneral(T dato) {
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->setDato(dato);
    this->raiz = nodo;
}

//destructor
// ------------------------------------------------
template<class T>
ArbolGeneral<T>::~ArbolGeneral(){
    this->raiz = nullptr;
}

//getters
// ------------------------------------------------
template<class T>
NodoGeneral<T> *ArbolGeneral<T>::getRaiz() {
    return this->raiz;
}

//setters
// ------------------------------------------------
template<class T>
void ArbolGeneral<T>::setRaiz(NodoGeneral<T> *raiz) {
    this->raiz = raiz;
}

//operaciones
// ------------------------------------------------
template<class T>
bool ArbolGeneral<T>::vacio() {
    return this->raiz == nullptr;
}

template<class T>
bool ArbolGeneral<T>::insert(T& padreNuevo, T& nodoNuevo) {
    if(this->raiz == nullptr){
        NodoGeneral<T> * nuevo = new NodoGeneral<T>(nodoNuevo);
        this->raiz = nuevo;
        return true;
    } else{
        NodoGeneral<T> * padre = this->raiz;
        padre = padre->searchNodo(padreNuevo);
        if(padre != nullptr){
            return padre->insert(nodoNuevo);
        }
        else{
            return false;
        }
    }
}

template<class T>
void ArbolGeneral<T>::insertHijos(T& padreNuevo, std::list < NodoGeneral<T>* > hijos){
    if(this->raiz == nullptr){
        return;
    } else{
        NodoGeneral<T> * padre = this->raiz;
        padre = padre->searchNodo(padreNuevo);
        if(padre != nullptr){
            return padre->setHijos(hijos);
        }
        else{
            return;
        }
    }
}

template<class T>
bool ArbolGeneral<T>::erase(T nodoEliminar) {

}

template<class T>
bool ArbolGeneral<T>::search(T nodoBuscar) {

}

template<class T>
int ArbolGeneral<T>::altura() {
    if(this->vacio()){
        return -1;
    }else{
        return this->altura(this->raiz);
    }
}

template<class T>
int ArbolGeneral<T>::altura(NodoGeneral<T> *nodo) {
    int alt = -1;
    if(nodo->hoja()){
        alt = 0;
    }else{
        int alth = 0;
        for(NodoGeneral<T> * n: nodo->getHijos()){
            alth = this->altura(n);
            if(alt < alth + 1){
                alt = alth + 1;
            }
        }
    }
    return alt;
}

template<class T>
int ArbolGeneral<T>::size() {
    if(this->raiz == nullptr){
        return 0;
    }else{
        return this->raiz->tamano();
    }
}

template<class T>
T ArbolGeneral<T>::maximo(){
    if(this->raiz == nullptr){
        return -1;
    }else{
        return this->raiz->maximo();
    }
}

template<class T>
T ArbolGeneral<T>::minimo(){
    if(this->raiz == nullptr){
        return -1;
    }else{
        return this->raiz->minimo();
    }
}

template<class T>
void ArbolGeneral<T>::camino(T&valor, std::stack< T >& ruta){
    if(this->raiz == nullptr){
        return;
    }else{
        this->raiz->camino(valor, ruta);
    }
}

//recorridos
// ------------------------------------------------
template<class T>
void ArbolGeneral<T>::niveles() {
    if(this->raiz == nullptr){
        return;
    }else{
        this->raiz->niveles();
        std::cout << std::endl;
    }
}

template<class T>
void ArbolGeneral<T>::preorder() {
    if(this->raiz == nullptr){
        return;
    }else{
        this->raiz->preOrden();
        std::cout << std::endl;
    }
}

template<class T>
void ArbolGeneral<T>::posorder() {
    if(this->raiz == nullptr){
        return;
    }else{
        this->raiz->posOrden();
        std::cout << std::endl;
    }
}