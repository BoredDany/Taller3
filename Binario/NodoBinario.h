#ifndef TALLER3_NODOBINARIO_H
#define TALLER3_NODOBINARIO_H

#include <stack>
#include <queue>


template < class T >
class NodoBinario{

private:
    T dato;
    NodoBinario<T> *hijoI;
    NodoBinario<T> *hijoD;
public:
    NodoBinario();
    ~NodoBinario();
    NodoBinario(T& val);

    T& getDato();
    NodoBinario<T>* getHijoI();
    NodoBinario<T>* getHijoD();

    void setDato(T& val);
    void setHijoI(NodoBinario<T> *hijoI);
    void setHijoD(NodoBinario<T> *hijoD);

    void inOrden();
    void posOrden();
    void preOrden();
    void niveles();

    bool buscar(T& val);
    bool insert(T& val);
    bool erase(T& val);

    bool hoja();

    int altura();
    int minimo();
    int maximo();

    bool ruta(T val, std::stack<T>& camino,  NodoBinario<T> * nodo);

};

#include "NodoBinario.hxx"

#endif //TALLER3_NODOBINARIO_H
