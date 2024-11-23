#include "FloydWarshall.hpp"
#include <iostream>

FloydWarshall::FloydWarshall()
{
}

Vector<size_t> FloydWarshall::calcular_camino_minimo(Matriz<bool> &matriz_adyacencia, Matriz<int> &matriz_pesos,
                                                     size_t origen, size_t destino, size_t vertices)
{
    Matriz<int> distancias(vertices, vertices, INFINITO);
    Matriz<int> recorridos(vertices, vertices, -1);

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

    for (size_t k = 0; k < vertices; k++)
    {
        for (size_t i = 0; i < vertices; i++)
        {
            for (size_t j = 0; j < vertices; j++)
            {
                if (distancias(i, k) != INFINITO && distancias(k, j) != INFINITO)
                {
                    int nueva_distancia = distancias(i, k) + distancias(k, j);
                    if (nueva_distancia < distancias(i, j))
                    {
                        distancias(i, j) = nueva_distancia;
                        recorridos(i, j) = static_cast<int>(k);
                    }
                }
            }
        }
    }

    Vector<size_t> camino;

    if (recorridos(origen, destino) == -1)
    {
        return camino;
    }

    size_t actual = origen;

    while (actual != destino)
    {
        camino.alta(actual);
        actual = static_cast<size_t>(recorridos(actual, destino));
    }

    camino.alta(destino);

    return camino;
}

FloydWarshall::~FloydWarshall() = default;
