#include "NodoBinario.h"
#include <iostream>

template< class T >
NodoBinario<T>::NodoBinario(){
    this->hijoI = nullptr;
    this->hijoD = nullptr;
}

template< class T >
NodoBinario<T>::~NodoBinario(){
    if (this->hijoI != nullptr) {
        delete this->hijoI;
        this->hijoI = nullptr;
    }
    if (this->hijoD != nullptr) {
        delete this->hijoDer;
        this->hijoD = nullptr;
    }
}

template< class T >
NodoBinario<T>::NodoBinario(T& val){
    this->hijoI = nullptr;
    this->hijoD = nullptr;
    this->dato = val;
}

template< class T >
T& NodoBinario<T>::getDato(){
    return this->dato;
}

template< class T >
NodoBinario<T>* NodoBinario<T>::getHijoI(){
    return this->hijoI;
}

template< class T >
NodoBinario<T>* NodoBinario<T>::getHijoD(){
    return this->hijoD;
}

template< class T >
void NodoBinario<T>::setDato(T& val){
    this->dato = dato;
}

template< class T >
void NodoBinario<T>::setHijoI(NodoBinario<T> *hijoI){
    this->hijoI = hijoI;
}

template< class T >
void NodoBinario<T>::setHijoD(NodoBinario<T> *hijoD){
    this->hijoD = hijoD;
}

template< class T >
void NodoBinario<T>::inOrden(){
    if(this->hijoI != nullptr){
        this->hijoI->inOrden();
    }
    std::cout << this->getDato()<<"\t";
    if(this->hijoD != nullptr){
        this->hijoD->inOrden();
    }
}

template< class T >
void NodoBinario<T>::posOrden(){

}

template< class T >
void NodoBinario<T>::preOrden(){

}

template< class T >
void NodoBinario<T>::nivel(){

}

template< class T >
bool NodoBinario<T>::buscar(T& val){
    NodoBinario<T>* nodo = this;
    bool encontrado = false;
    while(nodo != nullptr && !encontrado){
        if(val < nodo->getDato()){
            nodo = nodo->getHijoI();
        }else if(val > nodo->getDato()){
            nodo = nodo->getHijoD();
        }else{
            encontrado = true;
        }
    }
    return encontrado;
}

template< class T >
bool NodoBinario<T>::insert(T& val){
    NodoBinario<T> * padre = this;
    NodoBinario<T> * nodo = this;
    bool duplicado = false;
    bool insertado = false;

    while(padre != nullptr){
        nodo = padre;
        if(val < padre->getDato()){
            padre = padre->getHijoI();
        } else if(val > padre->getDato()){
            padre = padre->getHijoD();
        } else{
            duplicado = true;
            break;
        }
    }

    if(!duplicado){
        NodoBinario<T>* nuevo = new NodoBinario(val);
        if(nuevo != nullptr){
            if(val < nodo->getDato()){
                nodo->setHijoI(nuevo);
            }else{
                nodo->setHijoD(nuevo);
            }
            insertado = true;
        }
    }
    return insertado;
}

template< class T >
bool NodoBinario<T>::erase(T& val){

}

template< class T >
bool NodoBinario<T>::hoja(){
    return this->hijoI == nullptr && this->hijoD == nullptr;
}