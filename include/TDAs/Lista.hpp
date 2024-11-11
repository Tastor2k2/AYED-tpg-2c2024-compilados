#ifndef LISTA_HPP
#define LISTA_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoLista.hpp"

class ExcepcionLista : public std::runtime_error {
public:
    ExcepcionLista(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionLista(): runtime_error("") {
    }
};

// La lista es 0-indexed (es decir, la primera posición es 0).
template<typename T>
class Lista {
private:
    NodoLista<T>* primer_nodo;
    NodoLista<T>* ultimo_nodo;
    NodoLista<T>* cursor;
    size_t cantidad_datos;

public:
    // Constructor.
    Lista();

    // Pre: -
    // Post: Agrega el dato al principio de la lista.
    void alta_principio(T dato);

    // Pre: -
    // Post: Agrega el dato al final de la lista.
    void alta_final(T dato);

    // Pre: La lista no puede estar vacía.
    // Post: Elimina el primer dato y lo devuelve.
    T baja_primero();

    // Pre: La lista no puede estar vacía.
    // Post: Elimina el último dato y lo devuelve.
    T baja_ultimo();

    // Pre: La posición debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada.
    // Ejemplo:
    //      >> 8 5 2 7 1
    // insertar(9, 2);
    //      >> 8 5 9 2 7 1
    void insertar(T dato, size_t posicion);

    // Pre: La posición debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada y lo devuelve.
    // Ejemplo:
    //      >> 8 5 2 7 1
    // eliminar(3);
    //      >> 8 5 2 1
    T eliminar(size_t posicion);

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve una referencia al primer dato de la lista.
    T& primero();

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve una referencia al último dato de la lista.
    T& ultimo();

    // Pre: -
    // Post: Reinicia el cursor al principio o al final de la lista, según lo indicado.
    void reiniciar_cursor(bool principio);

    // Pre: Se debe poder avanzar (es decir, el cursor debe apuntar a un nodo siguiente).
    // Post: Avanza el cursor al nodo siguiente del actual.
    void avanzar();

    // Pre: Se debe poder retroceder (es decir, el cursor debe apuntar a un nodo anterior).
    // Post: Retrocede el cursor al nodo anterior del actual.
    void retroceder();

    // Pre: El cursor debe apuntar a un nodo válido.
    // Post: Devuelve una referencia al dato actual (cursor).
    T& elemento();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la lista.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la lista esta vacía (es decir, si no hay datos).
    bool vacio();

    // El constructor de copia está deshabilitado.
    Lista(const Lista& lista) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Lista& lista) = delete;

    // Destructor.
    ~Lista();
};

template<typename T>
Lista<T>::Lista() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cursor = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void Lista<T>::alta_principio(T dato) {
    NodoLista<T>* nuevo_elemento = new NodoLista<T>(dato);
    if (vacio()) {
        primer_nodo = nuevo_elemento;
        ultimo_nodo = nuevo_elemento;
        cursor = primer_nodo;
    } else {
        nuevo_elemento->cambiar_siguiente(primer_nodo);
        primer_nodo->cambiar_anterior(nuevo_elemento);
        primer_nodo = nuevo_elemento;
    }
    cantidad_datos++;
}

template<typename T>
void Lista<T>::alta_final(T dato) {
    NodoLista<T>* nuevo_elemento = new NodoLista<T>(dato);
    if (vacio()) {
        primer_nodo = nuevo_elemento;
        ultimo_nodo = nuevo_elemento;
        cursor = ultimo_nodo;
    } else {
        nuevo_elemento->cambiar_anterior(ultimo_nodo);
        ultimo_nodo->cambiar_siguiente(nuevo_elemento);
        ultimo_nodo = nuevo_elemento;
    }
    cantidad_datos++;
}

template<typename T>
T Lista<T>::baja_primero() {
    if (vacio()) {
        throw ExcepcionLista("La lista esta vacia.");
    }
    NodoLista<T>* nodo_a_quitar = primer_nodo;
    T dato = nodo_a_quitar->obtener_dato();
    if (primer_nodo == ultimo_nodo) {
        primer_nodo = nullptr;
        ultimo_nodo = nullptr;
        cursor = nullptr;
    } else {
        primer_nodo = primer_nodo->obtener_siguiente();
        primer_nodo->cambiar_anterior(nullptr);
    }
    delete nodo_a_quitar;
    cantidad_datos--;
    return dato;
}

template<typename T>
T Lista<T>::baja_ultimo() {
    if (vacio()) {
        throw ExcepcionLista("La lista esta vacia.");
    }
    NodoLista<T>* nodo_a_quitar = ultimo_nodo;
    T dato = nodo_a_quitar->obtener_dato();
    if (primer_nodo == ultimo_nodo) {
        primer_nodo = nullptr;
        ultimo_nodo = nullptr;
        cursor = nullptr;
    } else {
        ultimo_nodo = ultimo_nodo->obtener_anterior();
        ultimo_nodo->cambiar_siguiente(nullptr);
    }
    delete nodo_a_quitar;
    cantidad_datos--;
    return dato;
}

template<typename T>
void Lista<T>::insertar(T dato, size_t posicion) {
    if (posicion > tamanio()) {
        throw ExcepcionLista("Posición fuera de rango.");
    }
    if (posicion == 0) {
        alta_principio(dato);
    } else if (posicion == tamanio() - 1) {
        alta_final(dato);
    } else {
        if (cursor == nullptr || posicion <= tamanio() / 2) {
            reiniciar_cursor(true);
            for (size_t i = 0; i < posicion; i++) {
                avanzar();
            }
        } else {
            reiniciar_cursor(false);
            for (size_t i = tamanio() - 1; i > posicion; i--) {
                retroceder();
            }
        }
        NodoLista<T>* nuevo_elemento = new NodoLista<T>(dato);
        NodoLista<T>* siguiente = cursor;
        NodoLista<T>* anterior = cursor->obtener_anterior();
        anterior->cambiar_siguiente(nuevo_elemento);
        nuevo_elemento->cambiar_anterior(anterior);
        nuevo_elemento->cambiar_siguiente(siguiente);
        if (siguiente != nullptr) {
            siguiente->cambiar_anterior(nuevo_elemento);
        }
        cursor = nuevo_elemento;
    }
    cantidad_datos++;
}

template<typename T>
T Lista<T>::eliminar(size_t posicion) {
    if (vacio()) {
        throw ExcepcionLista("La lista está vacía.");
    }
    if (posicion >= tamanio()) {
        throw ExcepcionLista("Posición fuera de rango.");
    }
    if (cursor == nullptr || posicion <= tamanio() / 2) {
        reiniciar_cursor(true);
        for (size_t i = 0; i < posicion; i++) {
            avanzar();
        }
    } else {
        reiniciar_cursor(false);
        for (size_t i = tamanio() - 1; i > posicion; i--) {
            retroceder();
        }
    }
    T dato = cursor->obtener_dato();
    NodoLista<T>* nodo_a_eliminar = cursor;
    if (cursor->obtener_anterior()) {
        cursor->obtener_anterior()->cambiar_siguiente(cursor->obtener_siguiente());
    } else {
        primer_nodo = cursor->obtener_siguiente();
    }
    if (cursor->obtener_siguiente()) {
        cursor->obtener_siguiente()->cambiar_anterior(cursor->obtener_anterior());
    } else {
        ultimo_nodo = cursor->obtener_anterior();
    }
    cursor = cursor->obtener_siguiente();
    delete nodo_a_eliminar;
    cantidad_datos--;
    return dato;
}

template<typename T>
T& Lista<T>::primero() {
    if (vacio()) {
        throw ExcepcionLista("La lista está vacía, no tiene primer elemento.");
    }
    return primer_nodo->obtener_dato();
}

template<typename T>
T& Lista<T>::ultimo() {
    if (vacio()) {
        throw ExcepcionLista("La lista está vacía, no tiene ultimo elemento.");
    }
    return ultimo_nodo->obtener_dato();
}

template<typename T>
void Lista<T>::reiniciar_cursor(bool principio) {
    if (principio) {
        cursor = primer_nodo;
    } else {
        cursor = ultimo_nodo;
    }
}

template<typename T>
void Lista<T>::avanzar() {
    if (cursor == nullptr) {
        throw ExcepcionLista("No es posible avanzar, limite alcanzado.");
    }
    if (cursor != ultimo_nodo) {
        cursor = cursor->obtener_siguiente();
    }
}

template<typename T>
void Lista<T>::retroceder() {
    if (cursor == nullptr) {
        throw ExcepcionLista("No es posible retroceder, limite alcanzado.");
    } if (cursor != primer_nodo) {
        cursor = cursor->obtener_anterior();
    }
}

template<typename T>
T& Lista<T>::elemento() {
    if (cursor == nullptr) {
        throw ExcepcionLista("Cursor fuera de los limites de la lista");
    }
    return cursor->obtener_dato();
}

template<typename T>
size_t Lista<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Lista<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
Lista<T>::~Lista() {
    NodoLista<T>* actual = primer_nodo;
    NodoLista<T>* siguiente;
    while (actual != nullptr) {
        siguiente = actual->obtener_siguiente();
        delete actual;
        actual = siguiente;
    }
}

#endif
