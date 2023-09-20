#include "ArbolBinarioOrdenado.h"
#include "NodoBinario.h"
#include <queue>
#include <iostream>

template< class T >
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado(){
    this->raiz = nullptr;
}

template< class T >
ArbolBinarioOrdenado<T>::~ArbolBinarioOrdenado(){
    if(this->raiz != nullptr){
        delete this->raiz;
        this->raiz = nullptr;
    }

}

template< class T >
NodoBinario<T>* ArbolBinarioOrdenado<T>::getRaiz(){
    return this->raiz;
}

template< class T >
bool ArbolBinarioOrdenado<T>::esVacio(){
    return this->raiz==nullptr;
}

template< class T >
T ArbolBinarioOrdenado<T>::datoRaiz(){
    return (this->raiz)->obtenerDato();
}
//recurrente
template< class T >
int ArbolBinarioOrdenado<T>::altura(){
    if(this->esVacio())
        return -1;
    else
        return this-> altura(this->raiz);
}

template< class T >
int ArbolBinarioOrdenado<T>::altura(NodoBinario<T>* nodo){
    int valt;

    if(nodo->esHoja()){
        valt = 0;
    }else{
        int valt_izq = -1;
        int valt_der = -1;

        if(nodo->obtenerHijoIzq() != nullptr)
            valt_izq = this -> altura(nodo->obtenerHijoIzq());
        if(nodo->obtenerHijoDer() != nullptr)
            valt_der = this -> altura(nodo->obtenerHijoDer());
        if(valt_izq > valt_der)
            valt = valt_izq +  1;
        else
            valt = valt_der + 1;
    }

    return valt;
}
//recurrente
template<class T>
int ArbolBinarioOrdenado<T>::tamano() {
    return tamano(this->raiz);
}

template<class T>
int ArbolBinarioOrdenado<T>::tamano(NodoBinario<T>* nodo) {
    if (nodo == nullptr) {
        return -1;
    } else {
        return 1 + tamano(nodo->obtenerHijoIzq()) + tamano(nodo->obtenerHijoDer());
    }
}

//iterativa
template<class T>
bool ArbolBinarioOrdenado<T>::insertar(T val){

    NodoBinario<T> *nodo = this->raiz;
    NodoBinario<T> *padre = this->raiz;
    bool duplicado = false;
    bool insertado = false;

    if(this->raiz == nullptr){
        this->raiz = new NodoBinario<T>(val);
        insertado = true;
        return insertado;
    }else{
        while (nodo != nullptr) {
            padre = nodo;
            if (val < nodo->obtenerDato()){
                nodo = nodo->obtenerHijoIzq();
            }else if(val > nodo->obtenerDato()){
                nodo = nodo->obtenerHijoDer();
            }else{
                duplicado = true;
                break;
            }
        }

        if(!duplicado){
            NodoBinario<T>* nuevo = new NodoBinario<T>(val);
            if(nuevo != nullptr){
                if(val < padre->obtenerDato()){
                    padre->fijarHijoIzq(nuevo);
                }else{
                    padre->fijarHijoDer(nuevo);
                }
                insertado = true;
            }
        }
        return insertado;
    }
}

template<class T>
void ArbolBinarioOrdenado<T>::elimHoja(){

}

template<class T>
void ArbolBinarioOrdenado<T>::elimConHijoIzq(){

}

template<class T>
void ArbolBinarioOrdenado<T>::elimConHijoDer(){

}

template<class T>
void ArbolBinarioOrdenado<T>::elimConDosHijos(){

}

template<class T>
void ArbolBinarioOrdenado<T>::eliminar(T val){
    NodoBinario<T> *nodo = this->raiz;
    NodoBinario<T> *padre = this->raiz;
    bool encontrado = false;
    bool eliminado = false;

    if(this->buscar(val)){

        while(nodo != nullptr){
            padre = nodo;
            if(val < nodo->obtenerDato()){
                nodo = nodo->obtenerHijoIzq();
            }
            else if(val > nodo->obtenerDato()){
                nodo = nodo->obtenerHijoDer();
            }
            if(val == nodo->obtenerDato()){
                encontrado = true;
                break;
            }
        }

        std::cout<<"PADRE DEL NODO A BORRAR: "<<padre->obtenerDato()<<std::endl;
        std::cout<<"NODO A BORRAR: "<<nodo->obtenerDato()<<std::endl;

        // 1. el nodo es hoja: borrar
        if(nodo->esHoja()){
            std::cout<<"CASO HOJA-------------------"<<std::endl;
            if(padre == nullptr){
                std::cout<<"CASO HOJA PADRE NULL"<<std::endl;
                //this->raiz = nullptr;
                eliminado = true;
            }
            if(padre->obtenerHijoIzq()== nodo){
                std::cout<<"HOJA HIJO IZQ"<<std::endl;
                //padre->fijarHijoIzq(nullptr);
                eliminado = true;
            }
            else if(padre->obtenerHijoDer() == nodo){
                std::cout<<"HOJA HIJO DER"<<std::endl;
                //padre->fijarHijoDer(nullptr);
                eliminado = true;
            }
            if(eliminado){
                //delete nodo;
                std::cout<<"SE ELIMINO EN CASO HOJA------------"<<std::endl;
            }

        }else{
            std::cout<<"NO ES HOJA"<<std::endl;
        }
    }else{
        std::cout<<"NO ENCONTRADO"<<std::endl;
    }
}

//iterativa
template< class T >
bool ArbolBinarioOrdenado<T>::buscar(T val){
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    while (nodo!=nullptr && !encontrado){
        if(val < nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        } else if(val > nodo->obtenerDato()){
            nodo = nodo->obtenerHijoDer();
        }else{
            encontrado = true;
        }
    }

    return encontrado;
}

//recurrente
template< class T >
void ArbolBinarioOrdenado<T>::inOrden(){
    if(!this->esVacio())
        this->inOrden(this->raiz);
}

template< class T >
void ArbolBinarioOrdenado<T>::inOrden(NodoBinario<T>* nodo){
    if(nodo!=nullptr){
        this->inOrden(nodo->obtenerHijoIzq());
        std::cout << nodo->obtenerDato()<<std::endl;
        this->inOrden(nodo->obtenerHijoDer());
    }
}

