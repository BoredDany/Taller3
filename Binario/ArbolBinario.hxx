#include "ArbolBinario.h"
#include <stack>
#include <queue>

template < class T >
ArbolBinario<T>::ArbolBinario(){
    this->raiz = nullptr;
}

template < class T >
ArbolBinario<T>::ArbolBinario(T& val){
    NodoBinario<T>* nodo = new NodoBinario<T> (val);
    this->setRaiz(nodo);
}

template < class T >
ArbolBinario<T>::~ArbolBinario(){
    this->raiz = nullptr;
}

template < class T >
NodoBinario<T>* ArbolBinario<T>::getRaiz(){
    return this->raiz;
}

template < class T >
void ArbolBinario<T>::setRaiz(NodoBinario<T>* raiz){
    this->raiz = raiz;
}

template < class T >
void ArbolBinario<T>::inOrden(){
    if(this->raiz != nullptr){
        this->raiz->inOrden();
    }
    std::cout << std::endl;
}

template < class T >
void ArbolBinario<T>::posOrden(){
    if(this->raiz != nullptr){
        this->raiz->posOrden();
    }
    std::cout << std::endl;
}

template < class T >
void ArbolBinario<T>::preOrden(){
    if (this->raiz != nullptr){
        this->raiz->preOrden();
    }
    std::cout << std::endl;
}

template < class T >
void ArbolBinario<T>::niveles(){
    if(this->raiz != nullptr){
        this->raiz->niveles();
    }
    std::cout << std::endl;
}

template < class T >
bool ArbolBinario<T>::buscar(T& val){
    bool encontrado = false;
    if(this->raiz == nullptr){
        encontrado = false;
    }else{
        encontrado = this->raiz->buscar(val);
    }
    return encontrado;
}

template < class T >
bool ArbolBinario<T>::insert(T& val){
    if(this->raiz == nullptr){
        NodoBinario<T> * nuevo = new NodoBinario<T>(val);
        this->setRaiz(nuevo);
    }
    if(!(this->buscar(val))){
        this->raiz->insert(val);
    }
}

template < class T >
bool ArbolBinario<T>::erase(T& val){
    bool eliminado = false;
    if(this->raiz == nullptr){
        eliminado = false;
    }
    else if(this->raiz->hoja() && this->raiz->getDato() == val){
        delete this->raiz;
        this->raiz = nullptr;
        eliminado = true;
    }
    else{
        eliminado = this->raiz->erase(val);
    }
    return eliminado;
}

template < class T >
bool ArbolBinario<T>::vacio(){
    return this->raiz == nullptr;
}

template < class T >
int ArbolBinario<T>::tamano(NodoBinario<T> * nodo){
    if(nodo == nullptr){
        return 0;
    }else{
        return 1 + tamano(nodo->getHijoI()) + tamano (nodo->getHijoD());
    }
}

template < class T >
int ArbolBinario<T>::altura(){
    if(this->vacio()){
        return -1;
    }else{
        return this->raiz->altura();
    }
}

template < class T >
int ArbolBinario<T>::minimo(){
    if(this->vacio()){
        return -1;
    }else{
        return this->raiz->minimo();
    }
}

template < class T >
int ArbolBinario<T>::maximo(){
    if(this->vacio()){
        return -1;
    }else{
        return this->raiz->maximo();
    }
}

template < class T >
void ArbolBinario<T>::ruta(T val, std::stack<T>& camino,  NodoBinario<T> * nodo){
    if(this->raiz == nullptr){
        return;
    }else{
        this->raiz->ruta(val, camino, this->raiz);
    }
}