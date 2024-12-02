#include "Combate.hpp"
#include <iostream>
#include <algorithm>

Combate::Combate(PERSONAJE personaje_seleccionado, size_t poder_personaje, size_t cantidad_transformers)
{
    personaje = personaje_seleccionado;
    puntos = 0;
    energon = 1000;
}

void Combate::obtener_camino_combate(Grafo grafo, size_t personaje, size_t jefe_final)
{
    grafo.usar_dijkstra();
    resultado = grafo.obtener_camino_minimo(personaje, jefe_final);
    Vector<size_t> camino_obtenido = resultado.camino;
    int coste_total = resultado.costo_total;
    imprimir_mapa_combate(camino_obtenido, coste_total);
}

void Combate::imprimir_mapa_combate(Vector<size_t> camino, int coste_total)
{
    size_t elemento;
    size_t tamaño_camino = camino.tamanio();
    for (size_t i = 0; i < tamaño_camino; i++)
    {
        std::cout << camino[i] << " --- "; // FALTA IMPRIMER ADEMÁS, EL COSTE DE ESE CAMINO,
        // HAY QUE VER LA FORMA DE TOMAR AL PESO DE LA ARISTA CON EL CAMINO RESULTANTE.
    }
    std::cout << "COSTE TOTAL ENERGON;" << coste_total;
}

void Combate::crear_grafo(size_t cantidad_transformers, size_t poder_personaje, Vector<Transformer> transformers)
{
    Grafo grafo_transformers(cantidad_transformers);
    conectar_vertices(cantidad_transformers, grafo_transformers, transformers);
}

void Combate::conectar_vertices(size_t cantidad_transformers, Grafo grafo_transformers, Vector<Transformer> transformers)
{
    size_t inicio_nivel_anterior = 0;
    size_t fin_nivel_anterior = 1;

    size_t inicio_nivel_actual = 1;
    size_t fin_nivel_actual = 1;

    size_t peso_arista;

    if (cantidad_transformers == 3)
    { // caso especia, solo 3 transformers.
        peso_arista = calcular_energon(transformers[0]);
        grafo_transformers.agregar_arista(0, 1, peso_arista);
        // FALTA CALCULAR EL PESO DEL TRANSFORMER RIVAL MEGATRON U OPTIMUS
        grafo_transformers.agregar_arista(1, 2, peso_arista);
    }
    else
    {
        for (size_t i = inicio_nivel_actual; i < cantidad_transformers; i++)
        {
            size_t cantidad_nodos_actual = (cantidad_transformers - inicio_nivel_actual < CANTIDAD_MAXIMA_NIVEL) ? cantidad_transformers - inicio_nivel_actual : CANTIDAD_MAXIMA_NIVEL;
            fin_nivel_actual = inicio_nivel_actual + cantidad_nodos_actual;

            // Conecta cada nodo del nivel actual con todos los nodos del nivel anterior.
            for (size_t nodo_actual = inicio_nivel_actual; nodo_actual < fin_nivel_actual; nodo_actual++)
            {
                for (size_t nodo_anterior = inicio_nivel_anterior; nodo_anterior < fin_nivel_anterior; nodo_anterior++)
                {
                    peso_arista = calcular_energon(transformers[nodo_actual]);
                    grafo_transformers.agregar_arista(nodo_anterior, nodo_actual, peso_arista);
                }
            }
            if (inicio_nivel_actual < cantidad_transformers)
            { // asigno el próximo nivel, sino
                inicio_nivel_anterior = inicio_nivel_actual;
                fin_nivel_anterior = fin_nivel_actual;
                inicio_nivel_actual = fin_nivel_actual;
            }
            else
            { // estoy en el caso de no hay más nodos más que el top, por ello conecto con los demás
                for (size_t nodo_anterior = inicio_nivel_anterior; nodo_anterior < fin_nivel_anterior; nodo_anterior++)
                {
                    peso_arista = calcular_energon(transformers[nodo_anterior]);
                    grafo_transformers.agregar_arista(nodo_anterior, cantidad_transformers, peso_arista);
                }
            }
        }
    }
}

/*

FALTA CALCULAR COSTE DE ENERGON CUANDO EL RIVAL ES EL JEFE FINAL (OPTIMUS O MEGATRON) A IMPLEMENTAR

*/

size_t Combate::calcular_energon(Transformer rival)
{
    size_t costo;
    if (rival.obtener_faccion() == personaje)
    {
        costo = 30;
    }
    /*if (rival.obtener_faccion() == AUTOBOT && personaje == OPTIMUS || rival.obtener_faccion() == DECEPTICON && personaje == MEGATRON )
    {
        costo = 30
    }*/
    else
    {
        costo = 50 + (rival.obtener_poder()) - (poder_personaje);
        if (costo < 10)
        {
            costo = 10;
        }
        else if (costo > 100)
        {
            costo = 100;
        }
    }
    return costo;
}

void Combate::simular_combate()
{
}