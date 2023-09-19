#include "arbolBinario.h"


template<class T>
arbolBinario<T>::arbolBinario(){
    this->raiz = NULL;
}

template<class T>
arbolBinario<T>::arbolBinario(T val){
    this->raiz = new NodoBinario<T>(val);
}

template<class T>
arbolBinario<T>::~arbolBinario(){
    if(this->raiz != NULL){
        delete this->raiz;
        this->raiz = NULL;
    }
}

template<class T>
T arbolBinario<T>::getDatoRaiz(){
    return (this->raiz)->getDato();
}

template<class T>
void arbolBinario<T>::setDatoRaiz(T val){
    (this->raiz)->setDato(val);
}

template<class T>
bool arbolBinario<T>::esVacio(){
    return (this->raiz == NULL);
}

//recurrente
template<class T>
int arbolBinario<T>::altura(){
    if(this->esVacio()){
        return -1;
    }else{
        return this->altura(this->raiz);
    }
}

template<class T>
int arbolBinario<T>::altura(NodoBinario<T>* nodo){
    int valt;
    if(nodo->esHoja()){
        valt = 0;
    }else{
        int altIzq = -1;
        int altDer = -1;
        if(nodo->getHijoIzq() != NULL){
            altIzq = this->altura(nodo->getHijoIzq());
        }
        if(nodo->getHijoDer() != NULL){
            altDer = this->altura(nodo->getHijoDer());
        }
        if(altIzq > altDer){
            valt = altIzq + 1;
        }
        else{
            valt = altDer + 1;
        }
    }
    return valt;
}

template<class T>
int arbolBinario<T>::altura2(){
    if(this->esVacio()){
        return -1;
    }else{
        return (this->raiz)->altura();
    }
}

//recurrente
template<class T>
int arbolBinario<T>::tamano(){

}

//recurrente
template<class T>
void arbolBinario<T>::inOrden(){
    if(!this->esVacio()){
        this->inOrden(this->raiz);
    }
}

template<class T>
void arbolBinario<T>::inOrden(NodoBinario<T>* nodo){
    if(nodo != NULL){
        this->inOrden(nodo->getHijoIzq());
        std::cout<<"dato: "<<nodo->getDato()<<std::endl;
        this->inOrden(nodo->getHijoDer());
    }
}

template<class T>
void arbolBinario<T>::inOrden2(){
    if(!this->esVacio()){
        (this->raiz)->inOrden();
    }
}

//recurrente
template<class T>
void arbolBinario<T>::preOrden(){

}

//recurrente
template<class T>
void arbolBinario<T>::posOrden(){

}

//iterativo
template<class T>
void arbolBinario<T>::nivelOrden(){

}

//iterativa
template<class T>
bool arbolBinario<T>::insertar(T val){

    NodoBinario<T> *nodo = this->raiz;
    NodoBinario<T> *padre = this->raiz;
    bool duplicado = false;
    bool insertado = false;

    if(this->raiz == NULL){
        this->raiz = new NodoBinario<T>(val);
        insertado = true;
        return insertado;
    }else{
        while (nodo != NULL) {
            padre = nodo;
            if (val < nodo->getDato()){
                nodo = nodo->getHijoIzq();
            }else if(val > nodo->getDato()){
                nodo = nodo->getHijoDer();
            }else{
                duplicado = true;
                break;
            }
        }

        if(!duplicado){
            NodoBinario<T>* nuevo = new NodoBinario<T>(val);
            if(nuevo != NULL){
                if(val < padre->getDato()){
                    padre->setHijoIzq(nuevo);
                }else{
                    padre->setHijoDer(nuevo);
                }
                insertado = true;
            }
        }
        return insertado;
    }
}

//iterativa
template<class T>
bool arbolBinario<T>::eliminar(T val){
    NodoBinario<T> *nodo = this->raiz;
    NodoBinario<T> *padre = this->raiz;
    bool encontrado = false;
    bool eliminado = false;

    // comparar con dato en nodo para bajar por izq o der
    while(nodo != NULL){
        padre = nodo;
        if(val < nodo->getDato()){
            nodo = nodo->getHijoIzq();
        }
        if(val > nodo->getDato()){
            nodo = nodo->getHijoDer();
        }
        if(val == nodo->getDato()){
            encontrado = true;
            break;
        }
    }

    // si el dato esta
    if(encontrado){

        // 3. nodo tiene 2 hijos: usar maximo del izq como sucesor
        if(nodo->getHijoIzq() != NULL && nodo->getHijoDer() != NULL){

            //encontrar maximo del subarbol izquierdo
            NodoBinario<T>* sucesor = nodo;
            NodoBinario<T>* padreSucesor = nodo;
            sucesor = nodo->getHijoIzq();
            while(sucesor->getHijoDer() != NULL){
                padreSucesor = sucesor;
                sucesor = sucesor->getHijoDer();
            }

            //revisar si sucesor tiene hijo izquierdo
            if(sucesor->getHijoIzq() != NULL){
                NodoBinario<T>* hijoSucesor = sucesor->getHijoIzq();
                padreSucesor->setHijoDer(hijoSucesor);
                sucesor->setHijoIzq(NULL);
            }

            //conectar sucesor con los hijos del eliminado
            sucesor->setHijoIzq(nodo->getHijoIzq());
            sucesor->setHijoDer(nodo->getHijoDer());

            //conectar sucesor con su padre
            if(padre->getHijoDer() == nodo){
               padre->setHijoDer(sucesor);
            }else if(padre->getHijoIzq() == nodo){
                padre->setHijoIzq(sucesor);
            }
            std::cout<<"SE ELIMINO EN CASO DOS HIJOS"<<std::endl;
            delete nodo;
            eliminado = true;
            return eliminado;
        }

        // 2. el nodo tiene 1 hijo: usar hijo como remplazo
        // 2.1 el nodo tiene un hijo izquierdo
        if(nodo->getHijoIzq() != NULL){
            if(padre->getHijoIzq() == nodo){
                padre->setHijoIzq(nodo->getHijoIzq());
                delete nodo;
                eliminado = true;
                std::cout<<"SE ELIMINO EN CASO UN HIJO IZQUIERDO"<<std::endl;
                return eliminado;
            }else if(padre->getHijoDer() == nodo){
                padre->setHijoDer(nodo->getHijoIzq());
                delete nodo;
                eliminado = true;
                std::cout<<"SE ELIMINO EN CASO UN HIJO IZQUIERDO"<<std::endl;
                return eliminado;
            }
        }
        // 2.2 el nodo tiene un hijo derecho
        if(nodo->getHijoDer() != NULL){
            if(padre->getHijoIzq() == nodo){
                padre->setHijoIzq(nodo->getHijoDer());
                delete nodo;
                eliminado = true;
                std::cout<<"SE ELIMINO EN CASO UN HIJO DERECHO"<<std::endl;
                return eliminado;
            }else if(padre->getHijoDer() == nodo){
                padre->setHijoDer(nodo->getHijoDer());
                delete nodo;
                eliminado = true;
                std::cout<<"SE ELIMINO EN CASO UN HIJO DERECHO"<<std::endl;
                return eliminado;
            }

        }

        // 1. el nodo es hoja: borrar
        if(nodo->esHoja()){
            if(padre == NULL){
                this->raiz = NULL;
            }
            else if((padre->getHijoIzq())->getDato() == nodo->getDato()){
                padre->setHijoIzq(NULL);
            }
            else{
                padre->setHijoDer(NULL);
            }
            delete nodo;
            eliminado = true;
            std::cout<<"SE ELIMINO EN CASO HOJA"<<std::endl;
            return eliminado;
        }
    }
}

//iterativa
template<class T>
bool arbolBinario<T>::buscar(T val) {
    NodoBinario<T> *nodo = this->raiz;
    bool encontrado = false;

    while (nodo != NULL && !encontrado) {
        if (val < nodo->getDato()){
            nodo = nodo->getHijoIzq();
        }else if(val > nodo->getDato()){
            nodo = nodo->getHijoDer();
        }else{
            encontrado = true;
        }
    }
    return encontrado;
}