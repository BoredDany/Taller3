#include "ArbolGeneral.h"


template<class T>
ArbolGeneral<T>::ArbolGeneral() {
    this->raiz = NULL;
}

template<class T>
ArbolGeneral<T>::ArbolGeneral(T dato) {
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->setDato(dato);
    this->raiz = nodo;
}

template<class T>
ArbolGeneral<T>::~ArbolGeneral(){
    delete this->raiz;
    this->raiz = NULL;
}

template<class T>
bool ArbolGeneral<T>::vacio() {
    return this->raiz == NULL;
}

template<class T>
NodoGeneral<T> *ArbolGeneral<T>::getRaiz() {
    return this->raiz;
}

template<class T>
void ArbolGeneral<T>::setRaiz(NodoGeneral<T> *raiz) {
    this->raiz = raiz;
}

template<class T>
bool ArbolGeneral<T>::insert(T padreNuevo, T nodoNuevo) {

}

template<class T>
bool ArbolGeneral<T>::erase(T nodoEliminar) {

}

template<class T>
bool ArbolGeneral<T>::search(T nodoBuscar) {

}

template<class T>
void ArbolGeneral<T>::preorder() {

}

template<class T>
void ArbolGeneral<T>::posorder() {

}

template<class T>
void ArbolGeneral<T>::inorder() {

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
        std::list< NodoGeneral<T>* > ::iterator it;
        for(Nodo*: nodo->getHijos()){

        }
    }
}

template<class T>
int ArbolGeneral<T>::size() {

}