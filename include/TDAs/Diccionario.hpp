#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoDiccionario.hpp"
#include "Vector.hpp"
#include "Cola.hpp"

class ExcepcionDiccionario : public std::runtime_error {
public:
    ExcepcionDiccionario(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionDiccionario(): runtime_error("") {
    }
};

// La clave debe implementar el operator<() y el operator==().
// Las claves menores a la clave de la raíz iran al subárbol izquierdo,
// mientras que las mayores iran al derecho.
template<typename Clave, typename T>
class Diccionario {
private:
    NodoDiccionario<Clave, T>* raiz;
    std::size_t cantidad_datos;

    // Pre: -
    // Post: Devuelve el nodo encontrado en caso de hallarlo, o nullptr si no esta.
    NodoDiccionario<Clave, T>* buscar_clave(NodoDiccionario<Clave, T>* nodo, Clave clave);

    // Pre: -
    // Post: Recorre recursivamente hasta llegar a la posicion indicada para insertar.
    void alta_recursivo(NodoDiccionario<Clave, T>* nodo, Clave clave, T dato);

    // Pre: -
    // Post: Recorre recursivamente el diccionario en inorder
    void inorder_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T>& resultado);

    // Pre: -
    // Post: Recorre recursivamente el diccionario en preorder
    void preorder_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T>& resultado);

    // Pre: -
    // Post: Recorre recursivamente el diccionario en postorder
    void postorder_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T>& resultado);

    // Pre: -
    // Post: Recorre recursivamente el diccionario en ancho.
    void ancho_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T>& resultado);

    // Pre: -
    // Post: Elimina el elemento y lo devuelve.
    NodoDiccionario<Clave, T>* baja_recursivo(NodoDiccionario<Clave, T>* nodo, Clave clave);

    // Pre: -
    // Post: Devuelve el inmediato sucesor para el caso de eliminar nodo con dos hijos.
    NodoDiccionario<Clave, T>* inmediato_sucesor(NodoDiccionario<Clave, T>* nodo);

    // Pre: -
    // Post: Borra todos los nodos del subarbol izquierdo y derecho del nodo recibido, y libera su memoria.
    void eliminar_nodos(NodoDiccionario<Clave, T>* nodo);

public:

    // Constructor.
    Diccionario();

    // Pre: La clave no puede existir en el diccionario.
    // Post: Agrega el dato asociado a la clave al diccionario. Si no hay datos, crea una nueva raíz.
    void alta(Clave clave, T dato);

    // Pre: La clave debe existir en el diccionario.
    // Post: Elimina el dato asociado a la clave del diccionario y lo devuelve.
    // NOTA: El caso de baja con dos hijos se resuelve con sucesor inmediato. Se puede hacer swap del dato.
    T baja(Clave clave);

    // Pre: La clave debe existir en el diccionario.
    // Post: Devuelve una referencia al valor asociado a la clave.
    T& operator[](Clave clave);

    // Pre: -
    // Post: Devuelve el recorrido inorder.
    Vector<T> inorder();

    // Pre: -
    // Post: Devuelve el recorrido preorder.
    Vector<T> preorder();

    // Pre: -
    // Post: Devuelve el recorrido postorder.
    Vector<T> postorder();

    // Pre: -
    // Post: Devuelve el recorrido en ancho (por niveles).
    Vector<T> ancho();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el diccionario.
    std::size_t tamanio();

    // Pre: -
    // Post: Devuelve true si el diccionario está vacío.
    bool vacio();

    // El constructor de copia está deshabilitado.
    Diccionario(const Diccionario& diccionario) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Diccionario& diccionario) = delete;

    // Destructor.
    ~Diccionario();
};

template<typename Clave, typename T>
Diccionario<Clave, T>::Diccionario() {
    raiz = nullptr;
    cantidad_datos = 0;
}

template<typename Clave, typename T>
NodoDiccionario<Clave, T>* Diccionario<Clave, T>::buscar_clave(NodoDiccionario<Clave, T>* nodo, Clave clave) {
    if (nodo == nullptr || nodo->obtener_clave() == clave) {
        return nodo;
    }
    if (clave < nodo->obtener_clave()) {
        return buscar_clave(nodo->obtener_hijo_izquierdo(), clave);
    }
    return buscar_clave(nodo->obtener_hijo_derecho(), clave);

}

template<typename Clave, typename T>
void Diccionario<Clave, T>::alta_recursivo(NodoDiccionario<Clave, T>* nodo, Clave clave, T dato) {
    if (nodo == nullptr) {
        NodoDiccionario<Clave, T>* nuevo_nodo = new NodoDiccionario<Clave, T>(clave, dato);
        nuevo_nodo->cambiar_padre(nodo->obtener_padre());
    } else if (clave < nodo->obtener_clave()) {
        if (nodo->obtener_hijo_izquierdo() == nullptr) {
            NodoDiccionario<Clave, T>* nuevo_nodo = new NodoDiccionario<Clave, T>(clave, dato);
            nodo->cambiar_hijo_izquierdo(nuevo_nodo);
            nuevo_nodo->cambiar_padre(nodo);
        } else {
            alta_recursivo(nodo->obtener_hijo_izquierdo(), clave, dato);
        }
    } else {
        if (nodo->obtener_hijo_derecho() == nullptr) {
            NodoDiccionario<Clave, T>* nuevo_nodo = new NodoDiccionario<Clave, T>(clave, dato);
            nodo->cambiar_hijo_derecho(nuevo_nodo);
            nuevo_nodo->cambiar_padre(nodo);
        } else {
            alta_recursivo(nodo->obtener_hijo_derecho(), clave, dato);
        }
    }
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::alta(Clave clave, T dato) {
    if (buscar_clave(raiz, clave)) {
        throw ExcepcionDiccionario("La clave ya existe en el diccionario.");
    }
    if (vacio()) {
        NodoDiccionario<Clave, T>* nuevo_nodo = new NodoDiccionario<Clave, T>(clave, dato);
        raiz = nuevo_nodo;
    } else {
        alta_recursivo(raiz, clave, dato);
    }
    cantidad_datos++;
}

template<typename Clave, typename T>
NodoDiccionario<Clave, T>* Diccionario<Clave, T>::baja_recursivo(NodoDiccionario<Clave, T>* nodo, Clave clave) {
    if (nodo == nullptr) {
        return nodo;
    }
    if (clave < nodo->obtener_clave()) {
        nodo->cambiar_hijo_izquierdo(baja_recursivo(nodo->obtener_hijo_izquierdo(), clave));
    } else if (clave > nodo->obtener_clave()) {
        nodo->cambiar_hijo_derecho(baja_recursivo(nodo->obtener_hijo_derecho(), clave));
    } else {
        if (nodo->obtener_hijo_izquierdo() == nullptr) {
            NodoDiccionario<Clave, T>* temp = nodo->obtener_hijo_derecho();
            delete nodo;
            return temp;
        } else if (nodo->obtener_hijo_derecho() == nullptr) {
            NodoDiccionario<Clave, T>* temp = nodo->obtener_hijo_izquierdo();
            delete nodo;
            return temp;
        }
        NodoDiccionario<Clave, T>* temp = inmediato_sucesor(nodo->obtener_hijo_derecho());
        nodo->cambiar_clave(temp->obtener_clave());
        nodo->cambiar_dato(temp->obtener_dato());
        nodo->cambiar_hijo_derecho(baja_recursivo(nodo->obtener_hijo_derecho(), temp->obtener_clave()));
    }
    return nodo;
}

template<typename Clave, typename T>
NodoDiccionario<Clave, T>* Diccionario<Clave, T>::inmediato_sucesor(NodoDiccionario<Clave, T>* nodo) {
    while (nodo->obtener_hijo_izquierdo() != nullptr) {
        nodo = nodo->obtener_hijo_izquierdo();
    }
    return nodo;
}

template<typename Clave, typename T>
T Diccionario<Clave, T>::baja(Clave clave) {
    NodoDiccionario<Clave, T>* nodo = buscar_clave(raiz, clave);
    if (nodo == nullptr) {
        throw ExcepcionDiccionario("No existe la clave en el diccionario.");
    }
    T dato = nodo->obtener_dato();
    raiz = baja_recursivo(raiz, clave);
    cantidad_datos--;
    return dato;
}

template<typename Clave, typename T>
T& Diccionario<Clave, T>::operator[](Clave clave) {
    NodoDiccionario<Clave, T>* nodo = buscar_clave(raiz, clave);
    if (nodo == nullptr) {
        throw ExcepcionDiccionario("Clave no encontrada en el diccionario");
    }
    return nodo->obtener_dato();
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::inorder_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T> &resultado) {
    if (nodo != nullptr) {
        inorder_recursivo(nodo->obtener_hijo_izquierdo(), resultado);
        resultado.alta(nodo->obtener_dato());
        inorder_recursivo(nodo->obtener_hijo_derecho(), resultado);
    }
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::inorder() {
    Vector<T> resultado;
    inorder_recursivo(raiz, resultado);
    return resultado;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::preorder_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T> &resultado) {
    if (nodo != nullptr) {
        resultado.alta(nodo->obtener_dato());
        preorder_recursivo(nodo->obtener_hijo_izquierdo(), resultado);
        preorder_recursivo(nodo->obtener_hijo_derecho(), resultado);
    }
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::preorder() {
    Vector<T> resultado;
    preorder_recursivo(raiz, resultado);
    return resultado;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::postorder_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T> &resultado) {
    if (nodo != nullptr) {
        postorder_recursivo(nodo->obtener_hijo_izquierdo(), resultado);
        postorder_recursivo(nodo->obtener_hijo_derecho(), resultado);
        resultado.alta(nodo->obtener_dato());
    }
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::postorder() {
    Vector<T> resultado;
    postorder_recursivo(raiz, resultado);
    return resultado;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::ancho_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T>& resultado) {
    if (nodo != nullptr) {
        Cola<NodoDiccionario<Clave, T>*> cola;
        cola.alta(nodo);
        while (!cola.vacio()) {
            NodoDiccionario<Clave, T>* nodo_actual = cola.baja();
            resultado.alta(nodo_actual->obtener_dato());
            if (nodo_actual->obtener_hijo_izquierdo() != nullptr) {
                cola.alta(nodo_actual->obtener_hijo_izquierdo());
            }
            if (nodo_actual->obtener_hijo_derecho() != nullptr) {
                cola.alta(nodo_actual->obtener_hijo_derecho());
            }
        }
    }
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::ancho() {
    Vector<T> resultado;
    ancho_recursivo(raiz, resultado);
    return resultado;
}

template<typename Clave, typename T>
std::size_t Diccionario<Clave, T>::tamanio() {
    return cantidad_datos;
}

template<typename Clave, typename T>
bool Diccionario<Clave, T>::vacio() {
    return cantidad_datos == 0;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::eliminar_nodos(NodoDiccionario<Clave, T> *nodo) {
    if (nodo != nullptr) {
        eliminar_nodos(nodo->obtener_hijo_izquierdo());
        eliminar_nodos(nodo->obtener_hijo_derecho());
        delete nodo;
    }
}

template<typename Clave, typename T>
Diccionario<Clave, T>::~Diccionario() {
    eliminar_nodos(raiz);
}

#endif
