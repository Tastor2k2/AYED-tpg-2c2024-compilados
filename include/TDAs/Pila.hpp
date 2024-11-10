#ifndef PILA_HPP
#define PILA_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoLista.hpp"

class ExcepcionPila : public std::runtime_error {
public:
    ExcepcionPila(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionPila(): runtime_error("") {
    }
};

template<typename T>
class Pila {
private:
    NodoLista<T>* ultimo_nodo;
    size_t cantidad_datos;

public:
    // Constructor.
    Pila();

    // Pre: -
    // Post: Agrega el dato al final de la pila.
    void alta(T dato);

    // Pre: La pila no puede estar vacía.
    // Post: Elimina y devuelve el primer dato de la pila.
    T baja();

    // Pre: La pila no puede estar vacía.
    // Post: Devuelve el primer dato de la pila.
    T primero();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la pila.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la pila esta vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    Pila(const Pila& pila) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Pila& pila) = delete;

    // Destructor.
    ~Pila();
};

template<typename T>
Pila<T>::Pila() {
    ultimo_nodo = nullptr;
}

template<typename T>
void Pila<T>::alta(T dato) {
    NodoLista<T>* nuevo_nodo = new NodoLista<T>(dato);
    nuevo_nodo->cambiar_siguiente(ultimo_nodo); 
    ultimo_nodo = nuevo_nodo; 
    cantidad_datos++;
}

template<typename T>
T Pila<T>::baja() {
    if (vacio()) {
        throw ExcepcionPila("La pila está vacía, no hay elementos para borrar.");
    }
    NodoLista<T>* borrar_nodo = ultimo_nodo;
    ultimo_nodo = ultimo_nodo->obtener_siguiente();
    T dato = borrar_nodo->obtener_dato();  
    delete borrar_nodo;
   cantidad_datos-- ;
    return dato;
}

template<typename T>
T Pila<T>::primero() {
    if (vacio()) {
        throw ExcepcionPila("La pila está vacía.");
    }
    return ultimo_nodo->obtener_dato(); 
}
   
template<typename T>
size_t Pila<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Pila<T>::vacio() {
    return (cantidad_datos == 0);
}

template<typename T>
Pila<T>::~Pila() {  
    const size_t CANTIDAD_ELEMENTOS_A_ELIMINAR = cantidad_datos;  
    for (size_t i = 0 ; i < CANTIDAD_ELEMENTOS_A_ELIMINAR ; i++) {
        baja();
    }
}

#endif 