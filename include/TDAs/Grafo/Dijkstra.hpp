#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "CaminoMinimo.hpp"

const size_t NO_ALCANZABLE = SIZE_MAX; 

class Dijkstra : public CaminoMinimo {

private:

  bool* visitados;
  int* distancias;
  size_t* predecesores;

public:
    // Constructor.
    Dijkstra();

    /*
    PRE: Vertices no puede ser negativo y debe ser válido(no puede ser mayor a la cantidad de nodos en el grafo).
    POST: Inicializa los vectores con tamaño igual a la cantidad de vértices.
    */
    void inicializar(size_t vertices);

    /*
    PRE: Vertices, origen y destino no pueden ser negativos. Origen y destino deben ser menor o igual a la cantidad de vertices
    Matriz_adyacencia y matriz_pesos son cuadradas y su tamaño lo define la cantidad de vértices. 
    POST: Devuelve el mínimo camino desde el origen hacia destino según algoritmo Dijkstra. 
    */
    Vector<size_t>
    calcular_camino_minimo(Matriz<bool>& matriz_adyacencia,
                           Matriz<int>& matriz_pesos,
                           size_t origen,
                           size_t destino,
                           size_t vertices) override;

    /*
    PRE: Vértices no puede ser negativa y debe ser válida(no puede ser mayor a la cantidad de nodos en el grafo).
    POST: Devuelve la posición del nodo adyacente con el menor peso de arista.
    */
    size_t seleccionar_nodo_minimo(size_t vertices);

    /*
    PRE: Vertices y nodo actual no pueden ser negativo y deben ser válidos(no pueden ser mayor a la cantidad de nodos en el grafo).
    Matriz_adyacencia y matriz_pesos son cuadradas y su tamaño lo define la cantidad de vértices. 
    POST:
    */
    void actualizar_distancias(size_t nodo_actual, size_t vertices, Matriz<bool> &matriz_adyacencia, Matriz<int> &matriz_pesos);

    /*
    PRE: Recibe la posicion del nodo destino, no puede ser negativa y no puede ser mayor a la cantidad
    de vértices y recibe el vector de nodos predecesores.
    POST: Devuelve el camino a recorrer desde el origen hacia destino. 
    */
    Vector<size_t> construir_camino(size_t destino, size_t* predecesores);

    // Destructor.
    ~Dijkstra() override;
};

#endif
