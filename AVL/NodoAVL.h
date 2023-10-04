#ifndef TALLER3_AVL_H
#define TALLER3_AVL_H

#include <stack>

template < class T >
class NodoAVL{

private:
    T dato;
    NodoAVL<T> *hijoI;
    NodoAVL<T> *hijoD;
    int alt;
public:
    NodoAVL();
    ~NodoAVL();
    NodoAVL(T& val);

    T& getDato();
    NodoAVL<T>* getHijoI();
    NodoAVL<T>* getHijoD();
    int getAltura();

    void setDato(T& val);
    void setHijoI(NodoAVL<T> *hijoI);
    void setHijoD(NodoAVL<T> *hijoD);

    void inOrden();
    void posOrden();
    void preOrden();
    void niveles();

    bool buscar(T& val);
    bool insert(T& val);
    void updateAlturas();

    bool erase(T& val);
    bool hoja();
    int altura();
    int minimo();
    int maximo();
    bool ruta(T val, std::stack<T>& camino,  NodoAVL<T> * nodo);

};

#include "NodoAVL.hxx"

#endif //TALLER3_AVL_H
