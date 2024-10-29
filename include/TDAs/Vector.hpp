#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <stdexcept>

class ExcepcionVector : public std::runtime_error {
public:
    ExcepcionVector(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionVector(): runtime_error("") {
    }
};

template<typename T>
class Vector {
private:
    T* datos;
    size_t tamanio_logico;
    size_t tamanio_fisico;

public:
    // Constructor.
    Vector();

    // PRE: -
    // POST: Agrega el dato al final del vector.
    void alta(T dato);

    // PRE: El índice debe ser menor o igual que la cantidad de datos.
    // POST: Agrega el dato en el índice indicado,
    // moviendo todos los elementos siguientes.
    // Ejemplo:
    //      >> 1 3 2 7 0
    // alta(9, 2);
    //      >> 1 3 9 2 7 0
    void alta(T dato, size_t indice);

    // PRE: El vector no puede estar vacío.
    // POST: Elimina el último dato y lo devuelve.
    T baja();

    // PRE: El índice debe ser menor que la cantidad de datos.
    // POST: Elimina el dato en la posición indicada,
    // moviendo todos los elementos siguientes, y lo devuelve.
    // Ejemplo:
    //      >> 1 3 2 7 0
    // baja(1);
    //      >> 1 2 7 0
    T baja(size_t indice);

    // PRE: -
    // POST: Devuelve true si el vector está vacío (es decir, si no hay datos).
    bool vacio();

    // PRE: -
    // POST: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // PRE: El índice debe ser menor que la cantidad de datos.
    // POST: Devuelve una referencia al dato indicado.
    T& operator[](size_t indice);

    // Constructor de copia (ya implementado).
    Vector(const Vector& vector);

    // Operador de asignación (ya implementado).
    Vector& operator=(const Vector& vector);

    // Destructor.
    ~Vector();
};

template<typename T>
Vector<T>::Vector() {
}

template<typename T>
void Vector<T>::alta(T dato) {
}

template<typename T>
void Vector<T>::alta(T dato, size_t indice) {
}

template<typename T>
T Vector<T>::baja() {
}

template<typename T>
T Vector<T>::baja(size_t indice) {
}

template<typename T>
bool Vector<T>::vacio() {
}

template<typename T>
size_t Vector<T>::tamanio() {
}

template<typename T>
T& Vector<T>::operator[](size_t indice) {
}

template<typename T>
Vector<T>::~Vector() {
}

template<typename T>
Vector<T>::Vector(const Vector& vector) {
    datos = nullptr;
    tamanio_logico = vector.tamanio_logico;
    tamanio_fisico = vector.tamanio_fisico;
    if (tamanio_fisico) {
        datos = new T[tamanio_fisico];
        for (size_t i = 0; i < tamanio_logico; i++) {
            datos[i] = vector.datos[i];
        }
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector) {
    if (this != &vector) {
        delete[] datos;
        datos = nullptr;
        tamanio_logico = vector.tamanio_logico;
        tamanio_fisico = vector.tamanio_fisico;
        if (tamanio_fisico) {
            datos = new T[tamanio_fisico];
            for (size_t i = 0; i < tamanio_logico; i++) {
                datos[i] = vector.datos[i];
            }
        }
    }
    return *this;
}

#endif
