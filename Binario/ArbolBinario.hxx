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

}

template < class T >
void ArbolBinario<T>::preOrden(){

}

template < class T >
void ArbolBinario<T>::niveles(){

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

}

template < class T >
bool ArbolBinario<T>::vacio(){
    return this->raiz == nullptr;
}