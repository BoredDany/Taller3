#include "nodoBinario.h"

template<class T>
NodoBinario<T>::NodoBinario() {
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

template<class T>
NodoBinario<T>::NodoBinario(T val) {
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->dato = val;
}

template<class T>
NodoBinario<T>::~NodoBinario() {
    if(this->hijoIzq != NULL){
        delete this->hijoIzq;
        this->hijoIzq = NULL;
    }
    if(this->hijoDer != NULL){
        delete this->hijoDer;
        this->hijoDer = NULL;
    }
}

template<class T>
T NodoBinario<T>::getDato() {
    return this->dato;
}

template<class T>
NodoBinario<T> *NodoBinario<T>::getHijoIzq() {
    return this->hijoIzq;
}

template<class T>
NodoBinario<T> *NodoBinario<T>::getHijoDer() {
    return this->hijoDer;
}

template<class T>
void NodoBinario<T>::setDato(T val) {
    this->dato = val;
}

template<class T>
void NodoBinario<T>::setHijoIzq(NodoBinario<T> *hijoIz) {
    this->hijoIzq = hijoIz;
}

template<class T>
void NodoBinario<T>::setHijoDer(NodoBinario<T> *hijoDer) {
    this->hijoDer = hijoDer;
}

template<class T>
bool NodoBinario<T>::esHoja() {
    return (this->hijoIzq == NULL && this->hijoDer == NULL);
}

template<class T>
int NodoBinario<T>::altura() {
    int valt;
    if(this->esHoja()){
        valt = 0;
    }else{
        int altIz = -1;
        int altDe = -1;
        if(hijoIzq != NULL){
            altIz = (this->hijoIzq)->altura();
        }
        if(hijoDer != NULL){
            altDe = (this->hijoDer)->altura();
        }
        if(altIz > altDe){
            valt = altIz + 1;
        }else{
            valt = altDe + 1;
        }
    }
    return valt;
}

template<class T>
void NodoBinario<T>::inOrden() {
    if(this->hijoIzq != NULL){
        (this->hijoIzq)->inOrden();
    }
    std::cout<<"dato: "<< this->dato<<std::endl;
    if(this->hijoDer != NULL){
        (this->hijoDer)->inOrden();
    }
}