#include "Combate.hpp"
#include <iostream>
#include <algorithm>

Combate::Combate(PERSONAJE personaje_seleccionado, size_t poder_personaje, size_t cantidad_transformers)
{
    personaje = personaje_seleccionado;
    puntos = 0;
    energon = 1000;
}

Camino Combate::obtener_camino_combate(Grafo grafo, size_t personaje, size_t jefe_final)
{
    grafo.usar_dijkstra();
    resultado = grafo.obtener_camino_minimo(personaje, jefe_final);
    return resultado;
}

Vector<size_t> Combate::obtener_pesos_aristas(Grafo grafo, Vector<size_t> camino)
{
    size_t tamanio_camino = camino.tamanio();
    Vector<size_t> pesos;
    size_t elemento;
    size_t elemento_2;

    for (size_t i = 0; i < tamanio_camino - 1; i++)
    {
        elemento = camino[i];
        elemento_2 = camino[i + 1];
        pesos.alta(grafo.peso_entre_aristas(elemento, elemento_2));
    }

    return pesos;
}

void Combate::preparar_mapa_combate(Grafo grafo, size_t personaje, size_t jefe_final)
{
    Camino resultado = obtener_camino_combate(grafo, personaje, jefe_final);
    Vector<size_t> camino_resultado = resultado.camino;
    int costo_total = resultado.costo_total;

    Vector<size_t> pesos_aristas = obtener_pesos_aristas(grafo, camino_resultado);

    size_t tamanio_camino = camino_resultado.tamanio();

    combate = new size_t[tamanio_camino];

    for (size_t i = 0; i < tamanio_camino; i++)
    {
        combate[i] = camino_resultado[i];
        std::cout << camino_resultado[i] << std::endl;
        if (i < tamanio_camino - 1)
        {
            std::cout << " --> Coste Energon:" << pesos_aristas[i] << std::endl;
        }
    }
    std::cout << "COSTE TOTAL ENERGON;" << costo_total;
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
        grafo_transformers.agregar_arista(0, 1, static_cast<int>(peso_arista));
        // FALTA CALCULAR EL PESO DEL TRANSFORMER RIVAL MEGATRON U OPTIMUS
        grafo_transformers.agregar_arista(1, 2, static_cast<int>(peso_arista));
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
                    grafo_transformers.agregar_arista(nodo_anterior, nodo_actual, static_cast<int>(peso_arista));
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
                    grafo_transformers.agregar_arista(nodo_anterior, cantidad_transformers, static_cast<int>(peso_arista));
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
    if (rival.obtener_faccion() == static_cast<Faccion>(personaje))
    {
        costo = 30;
    }
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
    size_t tamanio = sizeof(combate) - 1;
    for (size_t i = 0; i < tamanio; i++)
    {
        std::cout << combate[i] << std::endl;
        // preguntar si transformarse o no.
    }
}

int analisis_combate(Transformer transformer, PERSONAJE personaje)
{
    //     int ventaja = 0;
    //     int ventaja_enemigo = 0;
    //     int resultado;

    //     if (personaje == OPTIMUS)
    //     {
    //         if (transformer.obtener_defensa() < optimus.obtener_defensa())
    //         {
    //             ventaja++;
    //         }
    //         else if (transformer.obtener_defensa() > optimus.obtener_defensa())
    //         {
    //             ventaja_enemigo++;
    //         }

    //         if (transformer.obtener_velocidad() < optimus.obtener_velocidad())
    //         {
    //             ventaja++;
    //         }
    //         else if (transformer.obtener_velocidad() > optimus.obtener_velocidad())
    //         {
    //             ventaja_enemigo++;
    //         }

    //         if (transformer.obtener_fuerza() < optimus.obtener_fuerza())
    //         {
    //             ventaja++;
    //         }
    //         else if (transformer.obtener_fuerza() > optimus.obtener_fuerza())
    //         {
    //             ventaja_enemigo++;
    //         }
    //     }
    //     if (personaje == MEGATRON)
    //     {
    //         if (transformer.obtener_defensa() < megatron.obtener_defensa())
    //         {
    //             ventaja++;
    //         }
    //         else if (transformer.obtener_defensa() > megatron.obtener_defensa())
    //         {
    //             ventaja_enemigo++;
    //         }
    //         if (transformer.obtener_velocidad() < megatron.obtener_velocidad())
    //         {
    //             ventaja++;
    //         }
    //         else if (transformer.obtener_velocidad() > megatron.obtener_velocidad())
    //         {
    //             ventaja_enemigo++;
    //         }
    //         if (transformer.obtener_fuerza() < megatron.obtener_fuerza())
    //         {
    //             ventaja++;
    //         }
    //         else if (transformer.obtener_fuerza() > megatron.obtener_fuerza())
    //         {
    //             ventaja_enemigo++;
    //         }
    //     }

    //     if (ventaja > ventaja_enemigo)
    //     {
    //         resultado = 1;
    //     }
    //     else if (ventaja == ventaja_enemigo)
    //     {
    //         resultado = 0;
    //     }
    //     else
    //     {
    //         resultado = -1;
    //     }
    //     return resultado;
    return -1;
}