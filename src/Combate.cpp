#include "Combate.hpp"
#include <iostream>
#include <algorithm>

Combate::Combate(Personaje personaje_seleccionado, std::optional<Cristal> cristal_seleccionado)
{
    personaje = personaje_seleccionado;
    this->cristal_seleccionado = cristal_seleccionado;

    if (personaje == OPTIMUS)
    {
        estadisticas_personaje = optimus.obtener_estadisticas();
    }
    else
    {
        estadisticas_personaje = megatron.obtener_estadisticas();
    }

    if (cristal_seleccionado.has_value())
    {
        Estadisticas estadisticas_cristal = cristal_seleccionado.value().obtener_estadisticas();
        estadisticas_personaje.fuerza += estadisticas_cristal.fuerza;
        estadisticas_personaje.defensa += estadisticas_cristal.defensa;
        estadisticas_personaje.velocidad += estadisticas_cristal.velocidad;
    }

    puntos = 0;
}

void Combate::mostrar_mapa(Camino camino, Vector<size_t> pesos, Vector<Transformer> transformers)
{
    std::cout << "Coste total energon: [" << camino.costo_total << "]" << std::endl;

    size_t longitud_camino = camino.camino.tamanio();
    size_t posicion = 0;

    for (size_t i = 0; i < longitud_camino; i++)
    {
        if (i != 0)
        {
            std::cout << "   ↑" << std::endl;
        }
        posicion = longitud_camino - 1 - i;
        if (posicion - 1 < transformers.tamanio())
        {
            if (posicion > 0 && transformers[posicion - 1].obtener_faccion() == static_cast<Faccion>(personaje))
            {
                std::cout << "🦾 ";
            }
            else
            {
                std::cout << "😈 ";
            }
        }
        else if (posicion - 1 == transformers.tamanio())
        {
            std::cout << "👹 ";
        }
        else
        {
            std::cout << "🤖 ";
        }

        std::cout << camino.camino[posicion];

        if (posicion > 0)
        {
            std::cout << " <- (" << pesos[posicion - 1] << ")";
        }
        std::cout << std::endl;
    }
}

void Combate::iniciar_combate(Camino camino, Vector<size_t> pesos, Vector<Transformer> transformers)
{
    std::cout << "###################################" << std::endl;
    std::cout << "COMBATE INICIADO" << std::endl;
    mostrar_mapa(camino, pesos, transformers);
    std::cout << "###################################" << std::endl;

    for (size_t i = 0; i < camino.camino.tamanio(); i++)
    {
        simular_combate();
    }
}

void Combate::simular_combate()
{
}

int analisis_combate(Transformer transformer, Personaje personaje)
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