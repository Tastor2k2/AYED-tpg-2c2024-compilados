#ifndef HEAP_HPP
#define HEAP_HPP

#include <cstddef>
#include <stdexcept>
#include "Vector.hpp"

class ExcepcionHeap : public std::runtime_error {
public:
    ExcepcionHeap(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionHeap(): runtime_error("") {
    }
};

// El dato debe implementar el operator<() y el operator>().
template<typename T>
class Heap {
private:
    Vector<T> datos;
    bool es_maxima;

    //PRE: El indice debe ser válido.
    //POST: El elemento en la posición indice se mueve hacia arriba hasta cumplir
    //       con la condición del heap (de máxima o mínima).
    void ordenar_hacia_arriba(size_t indice);
    //PRE: El indice debe ser válido.
    //POST: El elemento en la posición indice se mueve hacia abajo hasta cumplir
    //       con la condición del heap (de máxima o mínima).
    void ordenar_hacia_abajo(size_t indice);

public:
    // Constructor default.
    Heap();

    // Constructor. El parámetro indica si el heap es de máxima o de mínima.
    // Si es de máxima, utiliza el operador >. Si es de mínima, utiliza el <.
    Heap(bool maxima);

    // Pre: -
    // Post: Agrega el dato al heap.
    void alta(T dato);

    // Pre: El heap no puede estar vacío.
    // Post: Elimina y devuelve el primer dato.
    T baja();

    // Pre: El heap no puede estar vacío.
    // Post: Devuelve el primer dato.
    T primero();

    // Pre: -
    // Post: Devuelve true si el heap está vacío.
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el heap.
    size_t tamanio();

    // Destructor.
    ~Heap();
};

template<typename T>
Heap<T>::Heap() {
    es_maxima = true;
}

template<typename T>
Heap<T>::Heap(bool maxima) {
    es_maxima = maxima;
}

template<typename T>
void Heap<T>::alta(T dato) {
    datos.alta(dato);
    ordenar_hacia_arriba(datos.tamanio() - 1);
}

template<typename T>
T Heap<T>::baja() {
    if (vacio()) {
        throw ExcepcionHeap("El heap esta vacio.");
    }
    T dato_eliminado = datos[0];

    datos[0] = datos[datos.tamanio() - 1];
    datos.baja();

    ordenar_hacia_abajo(0);
    return dato_eliminado;
}

template<typename T>
T Heap<T>::primero() {
    if (vacio()) {
        throw ExcepcionHeap("El heap esta vacio.");
    }
    return datos[0];
}

template<typename T>
bool Heap<T>::vacio() {
    return datos.vacio();
}

template<typename T>
size_t Heap<T>::tamanio() {
    return datos.tamanio();
}

template<typename T>
Heap<T>::~Heap() {
}

template<typename T>
void Heap<T>::ordenar_hacia_arriba(size_t indice) {
    size_t padre = (indice - 1) / 2;
    while (indice > 0 && (es_maxima ?  datos[indice] > datos[padre] : datos[indice] < datos[padre])) {
        T temp = datos[indice];
        datos[indice] = datos[padre];
        datos[padre] = temp;

        indice = padre;
        padre = (indice - 1) / 2;
    }
}

template<typename T>
void Heap<T>::ordenar_hacia_abajo(size_t indice) {
    size_t hijo_izq = 2 * indice + 1;
    size_t hijo_der = 2 * indice + 2;
    size_t hijo_prometedor = indice;

    if (hijo_izq < datos.tamanio() && (es_maxima ? datos[hijo_izq] > datos[hijo_prometedor] : datos[hijo_izq] < datos[hijo_prometedor])) {
        hijo_prometedor = hijo_izq;
    }

    if (hijo_der < datos.tamanio() && (es_maxima ? datos[hijo_der] > datos[hijo_prometedor] : datos[hijo_der] < datos[hijo_prometedor])) {
        hijo_prometedor = hijo_der;
    }

    if (hijo_prometedor != indice) {
        T temp = datos[indice];
        datos[indice] = datos[hijo_prometedor];
        datos[hijo_prometedor] = temp;
        ordenar_hacia_abajo(hijo_prometedor);
    }
}

#endif

