#include "NodoBinario.h"
#include <iostream>
#include <queue>
#include <stack>

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
        delete this->hijoD;
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
    if(this->hijoI != nullptr){
        this->hijoI->inOrden();
    }
    if(this->hijoD != nullptr){
        this->hijoD->inOrden();
    }
    std::cout << this->getDato()<<"\t";
}

template< class T >
void NodoBinario<T>::preOrden(){
    std::cout << this->dato << "\t";
    if (this->hijoI != nullptr){
        this->hijoI->preOrden();
    }
    if (this->hijoD != nullptr){
        this->hijoD->preOrden();
    }
}

template< class T >
void NodoBinario<T>::niveles(){
    std::queue < NodoBinario <T> * > cola;
    NodoBinario<T> * nodo = this;

    while(nodo != nullptr){
        std::cout << nodo->getDato() << "\t";
        if(nodo->hijoI != nullptr){
            cola.push(nodo->hijoI);
        }
        if(nodo->hijoD != nullptr){
            cola.push(nodo->hijoD);
        }
        if(!cola.empty()){
            nodo = cola.front();
            cola.pop();
        }
        else{
            nodo = nullptr;
        }
    }
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

    NodoBinario<T> * padreEliminado = this;
    NodoBinario<T> * nodoEliminar = this;
    bool eliminado = false;
    bool encontrado = false;

    while(padreEliminado != nullptr){
        padreEliminado = nodoEliminar;
        if(val < nodoEliminar->dato){
            nodoEliminar = nodoEliminar->hijoI;
        }
        else if(val > nodoEliminar->dato){
            nodoEliminar = nodoEliminar->hijoD;
        }
        if(nodoEliminar->getDato() == val){
            encontrado = true;
            break;
        }
    }

    std::cout << "\n---------------ELIMINACION---------------" << std::endl ;
    std::cout << "NODO A BORRAR: " << nodoEliminar->getDato() << std::endl;
    std::cout << "PADRE NODO A BORRAR: " << padreEliminado->getDato() << std::endl;

    if(encontrado){

        //tiene 2 hijos
        if(nodoEliminar->hijoI != nullptr && nodoEliminar->hijoD != nullptr){
            std::cout << "NODO A BORRAR TIENE 2 HIJOS" << std::endl;
            NodoBinario<T> * sucesor = nodoEliminar->hijoI;
            NodoBinario<T> *  padreSucesor = nodoEliminar;

            while(sucesor->hijoD != nullptr){
                padreSucesor = sucesor;
                sucesor = sucesor->hijoD;
            }

            std::cout << "SUCESOR " << sucesor->getDato() << std::endl;
            std::cout << "PADRE DEL SUCESOR " << padreSucesor->getDato() << std::endl;

            nodoEliminar->dato = sucesor->dato;

            if(padreSucesor == nodoEliminar){
                padreSucesor->hijoI = sucesor->hijoI;
            }else{
                padreSucesor->hijoD = sucesor->hijoI;
            }

        }

        //tiene menos de 2 hijos
        else{
            //hoja
            if(nodoEliminar->hoja()){
                std::cout<<"NODO HOJA"<<std::endl;
                if(padreEliminado->hijoI == nodoEliminar){
                    padreEliminado->hijoI = nullptr;
                } else if(padreEliminado->hijoD == nodoEliminar){
                    padreEliminado->hijoD = nullptr;
                }
            }

            if(padreEliminado->hijoI == nodoEliminar){
                //hijo izquierdo
                if(nodoEliminar->hijoI != nullptr){
                    padreEliminado->hijoI = nodoEliminar->hijoI;
                    nodoEliminar->hijoI = nullptr;
                }
                //hijo derecho
                else if(nodoEliminar->hijoD != nullptr){
                    padreEliminado->hijoI = nodoEliminar->hijoD;
                    nodoEliminar->hijoD = nullptr;
                }
            } else if(padreEliminado->hijoD == nodoEliminar){
                //hijo izquierdo
                if(nodoEliminar->hijoI != nullptr){
                    padreEliminado->hijoD = nodoEliminar->hijoI;
                    nodoEliminar->hijoI = nullptr;
                }
                //hijo derecho
                else if(nodoEliminar->hijoD != nullptr){
                    padreEliminado->hijoD = nodoEliminar->hijoD;
                    nodoEliminar->hijoD = nullptr;
                }
            }

        }
        eliminado = true;
        std::cout << "-----------------------------------------" << std::endl;
    }
    return eliminado;
}

template< class T >
bool NodoBinario<T>::hoja(){
    return this->hijoI == nullptr && this->hijoD == nullptr;
}

template< class T >
int NodoBinario<T>::altura(){
    int alt = 0;
    if(this->hoja()){
        alt = 0;
    } else {
        int alti = -1;
        int altd = -1;
        if(this->hijoI != nullptr){
            alti = this->hijoI->altura();
        }
        if(this->hijoD != nullptr){
            altd = this->hijoD->altura();
        }
        if(alti > altd){
            alt = alti + 1;
        }else{
            alt = altd + 1;
        }
    }
    return alt;
}

template< class T >
int NodoBinario<T>::minimo(){
    NodoBinario<T> * nodo = this;
    float min = -1;
    if(nodo->hijoI == nullptr){
        return min;
    }else{
        while (nodo->hijoI != nullptr){
            nodo = nodo->hijoI;
        }
        min = nodo->dato;
    }
    return min;
}

template< class T >
int NodoBinario<T>::maximo(){
    NodoBinario<T> * nodo = this;
    float max = -1;
    if(nodo->hijoD == nullptr){
        return max;
    }else{
        while (nodo->hijoD != nullptr){
            nodo = nodo->hijoD;
        }
        max = nodo->dato;
    }
    return max;
}

template < class T >
bool NodoBinario<T>::ruta(T val, std::stack<T>& camino, NodoBinario<T> * nodo){

    if(nodo == nullptr){
        return false;
    }
    camino.push(nodo->dato);
    if(nodo->dato == val){
        return true;
    }
    if(ruta(val, camino, nodo->hijoI) || ruta(val, camino, nodo->hijoD)){
        return true;
    }
    camino.pop();
    return false;
}