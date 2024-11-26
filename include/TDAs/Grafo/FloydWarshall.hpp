#ifndef FLOYDWARSHALL_HPP
#define FLOYDWARSHALL_HPP

#include "CaminoMinimo.hpp"

class FloydWarshall : public CaminoMinimo {
private: 
    // PRE:
    // POST: Inicializa las matrices de distancias en base a la matriz de pesos e inicializa matriz recorridos.
    void inicializar_distancia_recorrido(Matriz<int> &matriz_pesos, Matriz<int> &distancias, Matriz<int> &recorridos, size_t vertices);

    // Pre: Las recorridos ya debe estar procesada.
    // La cantidad de vertices debe corresponder con el tamaño de las matrices.
    // Post: Devuelve el camino mínimo desde el vértice origen al destino, en base a la matriz de recorridos.
    Vector<size_t> obtener_camino(size_t origen, size_t destino, Matriz<int> recorridos);

public:
    // Constructor.
    FloydWarshall();

    // Pre: Las matrices deben ser cuadradas.
    // Origen y destino deben ser vértices válidos.
    // La cantidad de vertices debe corresponder con el tamaño de las matrices.
    // Post: Devuelve el camino mínimo desde el vértice origen al destino.
    Vector<size_t>
    calcular_camino_minimo(Matriz<bool>& matriz_adyacencia,
                           Matriz<int>& matriz_pesos,
                           size_t origen,
                           size_t destino,
                           size_t vertices) override;

    // Destructor.
    ~FloydWarshall() override;
};

#endif
