#include "FloydWarshall.hpp"
#include <iostream>

FloydWarshall::FloydWarshall()
{
}

Vector<size_t> FloydWarshall::obtener_camino(size_t origen, size_t destino, Matriz<int> recorridos) {
    Vector<size_t> camino;
    bool inalcanzable = recorridos(origen, destino) == -1;

    if (!inalcanzable)
    {
        size_t actual = origen;
        while (actual != destino)
        {
            camino.alta(actual);
            actual = static_cast<size_t>(recorridos(actual, destino));
        }

        camino.alta(destino);
    }

    return camino;
}

void FloydWarshall::inicializar_distancia_recorrido(Matriz<int> &matriz_pesos, Matriz<int> &distancias, Matriz<int> &recorridos, size_t vertices)
{
    for (size_t i = 0; i < vertices; ++i)
    {
        for (size_t j = 0; j < vertices; ++j)
        {
            if (i == j)
            {
                distancias(i, j) = 0;
                recorridos(i, j) = -1;
            }
            else
            {
                distancias(i, j) = matriz_pesos(i, j);
                recorridos(i, j) = static_cast<int>(j);
            }
        }
    }
}

Vector<size_t> FloydWarshall::calcular_camino_minimo(Matriz<bool> &matriz_adyacencia, Matriz<int> &matriz_pesos,
                                                     size_t origen, size_t destino, size_t vertices)
{
    Matriz<int> distancias(vertices, vertices, INFINITO);
    Matriz<int> recorridos(vertices, vertices, -1);
      
    inicializar_distancia_recorrido(matriz_pesos, distancias, recorridos, vertices);


    for (size_t k = 0; k < vertices; k++)
    {
        for (size_t i = 0; i < vertices; i++)
        {
            for (size_t j = 0; j < vertices; j++)
            {
                if (
                  // previene sumas innecesarias
                  distancias(i, k) != INFINITO
                  && distancias(k, j) != INFINITO
                  // evita las diagonales y punto de intersección
                  && i != k
                  && j != k 
                  && i != j
                  )
                {
                    int nueva_distancia = distancias(i, k) + distancias(k, j);
                    if (nueva_distancia < distancias(i, j))
                    {
                        distancias(i, j) = nueva_distancia;
                        recorridos(i, j) = recorridos(i,k);
                    }
                }
            }
        }
    }

    return obtener_camino(origen, destino, recorridos);
}

FloydWarshall::~FloydWarshall() = default;
