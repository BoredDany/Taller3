#ifndef TALLER3_NODOBINARIO_H
#define TALLER3_NODOBINARIO_H

template < clas T >
class NodoBinario{

private:
    T dato
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
    void nivel();

    bool buscar();
    bool insert(T& val);
    bool erase(T& val);

    bool hoja();

};

#include "NodoBinario.hxx"

#endif //TALLER3_NODOBINARIO_H
