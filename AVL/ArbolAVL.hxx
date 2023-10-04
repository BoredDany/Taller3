#include "NodoAVL.h"
#include "ArbolAVL.h"
#include <stack>
#include <queue>

//constructor
// ------------------------------------------------
template < class T >
ArbolAVL<T>::ArbolAVL(){
    this->raiz = nullptr;
}

template < class T >
ArbolAVL<T>::ArbolAVL(T& val){
    NodoAVL<T>* nodo = new NodoAVL<T> (val);
    this->setRaiz(nodo);
}

//destructor
// ------------------------------------------------
template < class T >
ArbolAVL<T>::~ArbolAVL(){
    this->raiz = nullptr;
}

//getters
// ------------------------------------------------
template < class T >
NodoAVL<T>* ArbolAVL<T>::getRaiz(){
    return this->raiz;
}

//setters
// ------------------------------------------------
template < class T >
void ArbolAVL<T>::setRaiz(NodoAVL<T>* raiz){
    this->raiz = raiz;
}

//recorridos
// ------------------------------------------------
template < class T >
void ArbolAVL<T>::inOrden(){
    if(this->raiz != nullptr){
        this->raiz->inOrden();
    }
    std::cout << std::endl;
}

template < class T >
void ArbolAVL<T>::posOrden(){
    if(this->raiz != nullptr){
        this->raiz->posOrden();
    }
    std::cout << std::endl;
}

template < class T >
void ArbolAVL<T>::preOrden(){
    if (this->raiz != nullptr){
        this->raiz->preOrden();
    }
    std::cout << std::endl;
}

template < class T >
void ArbolAVL<T>::niveles(){
    if(this->raiz != nullptr){
        this->raiz->niveles();
    }
    std::cout << std::endl;
}

//operaciones
// ------------------------------------------------
template < class T >
bool ArbolAVL<T>::buscar(T& val){
    bool encontrado = false;
    if(this->raiz == nullptr){
        encontrado = false;
    }else{
        encontrado = this->raiz->buscar(val);
    }
    return encontrado;
}

template < class T >
bool ArbolAVL<T>::insert(T& val){
    if(this->raiz == nullptr){
        NodoAVL<T> * nuevo = new NodoAVL<T>(val);
        this->setRaiz(nuevo);
    }
    if(!(this->buscar(val))){
        this->raiz->insert(val);
    }
}

template < class T >
bool ArbolAVL<T>::erase(T& val){
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
bool ArbolAVL<T>::vacio(){
    return this->raiz == nullptr;
}

template < class T >
int ArbolAVL<T>::tamano(NodoAVL<T> * nodo){
    if(nodo == nullptr){
        return 0;
    }else{
        return 1 + tamano(nodo->getHijoI()) + tamano (nodo->getHijoD());
    }
}

template < class T >
int ArbolAVL<T>::altura(){
    if(this->vacio()){
        return -1;
    }else{
        return this->raiz->altura();
    }
}

template < class T >
int ArbolAVL<T>::minimo(){
    if(this->vacio()){
        return -1;
    }else{
        return this->raiz->minimo();
    }
}

template < class T >
int ArbolAVL<T>::maximo(){
    if(this->vacio()){
        return -1;
    }else{
        return this->raiz->maximo();
    }
}

template < class T >
void ArbolAVL<T>::ruta(T val, std::stack<T>& camino,  NodoAVL<T> * nodo){
    if(this->raiz == nullptr){
        return;
    }else{
        this->raiz->ruta(val, camino, this->raiz);
    }
}