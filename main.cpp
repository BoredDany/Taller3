
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <queue>
using namespace std;

// TODO #1: incluir cabeceras implementaciones propias
#include "ArbolBinarioOrdenado.h"
#include "NodoBinario.h"

// TODO #2: definir tipos de datos para arboles de cadenas de caracteres

// -------------------------------------------------------------------------
template< class TTree >
bool ReadTree( TTree& tree, const std::string& filename );

int countLines(std::string archivo);

// -------------------------------------------------------------------------
int main( int argc, char* argv[] ) {

    if( argc < 2 ) {
        std::cerr << "Uso: " << argv[ 0 ] << " archivo_entrada" << std::endl;
        return( -1 );
    }else{
        cout<<"archivo de entrada "<<argv[1]<<endl;
    }

    ArbolBinarioOrdenado< std::string > arbolB = ArbolBinarioOrdenado<std::string>();
    std::string filename = argv[ 1 ];
    bool i = false;
    std::ifstream input( filename.c_str( ) );
    if( !input ){
        std::cout<<"Archivo no leido"<<std::endl;
    }else{
        while( !input.eof( ) ) {

            std::string code, value;
            input >> code >> value;
            if( code == "add" ){
                arbolB.insertar( value );  // El arbol debe proveer el metodo "insert"
                cout<<value<<endl;
            }
            else if( code == "del" ){
                arbolB.eliminar( value );  // El arbol debe proveer el metodo "erase"
            }
        }
    }

    input.close( );
    cout<<"ARBOL"<<endl;
    cout<<"RAIZ "<<(arbolB.getRaiz())->obtenerDato()<<endl;
    arbolB.inOrden();

    /*if (arbolB.getRaiz() == nullptr) {
        cout<<"RAIZ "<<(arbolB.getRaiz())->obtenerDato()<<endl;;
    }

    std::queue<NodoBinario<std::string>*> cola;
    cola.push(arbolB.getRaiz());

    while (!cola.empty()) {
        NodoBinario<std::string>* padre = cola.front();
        cola.pop();

        std::cout << "Padre: " << padre->obtenerDato();

        if (padre->obtenerHijoIzq() != nullptr) {
            std::cout << " - Izquierda: " << (padre->obtenerHijoIzq())->obtenerDato();
            cola.push(padre->obtenerHijoIzq());
        }

        if (padre->obtenerHijoDer() != nullptr) {
            std::cout << " - Derecha: " << (padre->obtenerHijoDer())->obtenerDato();
            cola.push(padre->obtenerHijoDer());
        }

        std::cout << std::endl;
    }*/

    return( 0 );
}
