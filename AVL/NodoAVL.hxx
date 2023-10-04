#include "NodoAVL.h"
#include <iostream>
#include <queue>
#include <stack>

//constructores
// ------------------------------------------------
template< class T >
NodoAVL<T>::NodoAVL(){
    this->hijoI = nullptr;
    this->hijoD = nullptr;
    this->alt = -1;
}

template< class T >
NodoAVL<T>::NodoAVL(T& val){
    this->hijoI = nullptr;
    this->hijoD = nullptr;
    this->alt = 0;
    this->dato = val;
}

//destructor
// ------------------------------------------------
template< class T >
NodoAVL<T>::~NodoAVL(){
    if (this->hijoI != nullptr) {
        delete this->hijoI;
        this->hijoI = nullptr;
    }
    if (this->hijoD != nullptr) {
        delete this->hijoD;
        this->hijoD = nullptr;
    }
}


//getters
// ------------------------------------------------
template< class T >
T& NodoAVL<T>::getDato(){
    return this->dato;
}

template< class T >
NodoAVL<T>* NodoAVL<T>::getHijoI(){
    return this->hijoI;
}

template< class T >
NodoAVL<T>* NodoAVL<T>::getHijoD(){
    return this->hijoD;
}

template< class T >
int NodoAVL<T>::getAltura(){
    return this->alt;
}

//setters
// ------------------------------------------------
template< class T >
void NodoAVL<T>::setDato(T& val){
    this->dato = dato;
}

template< class T >
void NodoAVL<T>::setHijoI(NodoAVL<T> *hijoI){
    this->hijoI = hijoI;
}

template< class T >
void NodoAVL<T>::setHijoD(NodoAVL<T> *hijoD){
    this->hijoD = hijoD;
}

//recorridos
// ------------------------------------------------
template< class T >
void NodoAVL<T>::inOrden(){
    if(this->hijoI != nullptr){
        this->hijoI->inOrden();
    }
    std::cout << this->getDato() << "-" << this->getAltura() <<"\t";
    if(this->hijoD != nullptr){
        this->hijoD->inOrden();
    }
}

template< class T >
void NodoAVL<T>::posOrden(){
    if(this->hijoI != nullptr){
        this->hijoI->posOrden();
    }
    if(this->hijoD != nullptr){
        this->hijoD->posOrden();
    }
    std::cout << this->getDato() << "-" << this->getAltura() <<"\t";
}

template< class T >
void NodoAVL<T>::preOrden(){
    std::cout << this->getDato() << "-" << this->getAltura() <<"\t";
    if (this->hijoI != nullptr){
        this->hijoI->preOrden();
    }
    if (this->hijoD != nullptr){
        this->hijoD->preOrden();
    }
}

template< class T >
void NodoAVL<T>::niveles(){
    std::queue < NodoAVL <T> * > cola;
    NodoAVL<T> * nodo = this;

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

//operaciones
// ------------------------------------------------
template< class T >
bool NodoAVL<T>::buscar(T& val){
    NodoAVL<T>* nodo = this;
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
bool NodoAVL<T>::insert(T& val){
    NodoAVL<T> * padre = this;
    NodoAVL<T> * nodo = this;
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
        NodoAVL<T>* nuevo = new NodoAVL(val);
        if(nuevo != nullptr){
            if(val < nodo->getDato()){
                nodo->setHijoI(nuevo);
            }else{
                nodo->setHijoD(nuevo);
            }
            insertado = true;
        }
        this->updateAlturas();
    }

    return insertado;
}

template< class T >
void NodoAVL<T>::updateAlturas() {
    int i = -1;
    int d = -1;
    if (this->hijoI == nullptr && this->hijoD == nullptr){
        this->alt = 0;
    }
    if(this->hijoI != nullptr){
        this->hijoI->updateAlturas();
        i = this->hijoI->alt;
    }
    if(this->hijoD != nullptr){
        this->hijoD->updateAlturas();
        d = this->hijoD->alt;
    }
    if(i < d){
        this->alt = d + 1;
    }else{
        this->alt = i + 1;
    }
}

template< class T >
bool NodoAVL<T>::erase(T& val){

    NodoAVL<T> * padreEliminado = this;
    NodoAVL<T> * nodoEliminar = this;
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

    if(encontrado){

        std::cout << "\n---------------ELIMINACION---------------" << std::endl ;
        std::cout << "NODO A BORRAR: " << nodoEliminar->getDato() << std::endl;
        std::cout << "PADRE NODO A BORRAR: " << padreEliminado->getDato() << std::endl;

        //tiene 2 hijos
        if(nodoEliminar->hijoI != nullptr && nodoEliminar->hijoD != nullptr){
            std::cout << "NODO A BORRAR TIENE 2 HIJOS" << std::endl;
            NodoAVL<T> * sucesor = nodoEliminar->hijoI;
            NodoAVL<T> *  padreSucesor = nodoEliminar;

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

        this->updateAlturas();
    }
    return eliminado;
}

template< class T >
bool NodoAVL<T>::hoja(){
    return this->hijoI == nullptr && this->hijoD == nullptr;
}

template< class T >
int NodoAVL<T>::altura(){
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
int NodoAVL<T>::minimo(){
    NodoAVL<T> * nodo = this;
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
int NodoAVL<T>::maximo(){
    NodoAVL<T> * nodo = this;
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
bool NodoAVL<T>::ruta(T val, std::stack<T>& camino, NodoAVL<T> * nodo){

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