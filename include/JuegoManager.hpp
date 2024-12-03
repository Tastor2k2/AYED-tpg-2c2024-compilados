#ifndef JUEGOMANAGER_H
#define JUEGOMANAGER_H

#include <iostream>
#include <limits>
#include <optional>
#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "BovedaCristales.hpp"
#include "BovedaManager.hpp"
#include "TransformersManager.hpp"
#include "Cristal.hpp"
#include "Combate.hpp"

class JuegoManager
{
private:
    static const size_t CANTIDAD_MAXIMA_NIVEL = 3;
    static const size_t PESO_ENERGON_ALIADO = 30;
    static const size_t PESO_ENERGON_ENEMIGO_BASE = 50;
    static const size_t PESO_ENERGON_ENEMIGO_MIN = 10;
    static const size_t PESO_ENERGON_ENEMIGO_MAX = 100;
    static const size_t PUNTAJE_BATALLA = 50;
    static const size_t PUNTAJE_TRANSFORMACION = 10;
    static const size_t PUNTAJE_EMPATE = 0;

    std::string nombre_usuario;
    PERSONAJE personaje_seleccionado;
    size_t poder_personaje;
    std::optional<Cristal> cristal_seleccionado;

    BovedaManager boveda_manager;
    TransformersManager transformers_manager;

    // Pre: -
    // Post: Muestra las opciones para elegir el personaje principal.
    void mostrar_opciones_personajes();

    // Pre: -
    // Post: Calcula el coste de energon entre el personaje principal y el transformer rival.
    size_t calcular_peso(Transformer rival);

    // Pre: -
    // Post: Genera el mapa de combate considerando los transformers presentes y los limites de 3 por nivel.
    Grafo generar_mapa_combates();

public:

    // Constructor
    JuegoManager();

    // PRE: -
    // POST: Almmacenara el nombre del usuario.
    void pedir_nombre();

    // PRE: -
    // POST: Mostrara las opciones de seleccion de personaje y guardara el seleccionado
    void elegir_personaje();

    // Pre: -
    // Post: Getter de cristal.
    std::optional<Cristal> obtener_cristal();

    // PRE: -
    // POST: Devuelve el nombre del personaje seleccionado
    std::string obtener_personaje_string();

    // PRE: -
    // POST: Devuelve el nombre del personaje seleccionado
    PERSONAJE obtener_personaje();

    // PRE: -
    // POST: Muestra las opciones de la boveda y ejecuta la seleccion del usuario.
    void administrar_boveda_cristales(bool &continuar);

    // Pre: -
    // Post: Llama al metodo "administrar_transformers" de TransformersManager para administrar la boveda.
    void administrar_boveda_transformers(bool &continuar);

    // Pre: -
    // Post: Comienza el combate.
    void empezar_combate();

    // Pre: -
    // Post: Devuelve el poder del personaje principal.
    size_t obtener_poder();

    // Pre: -
    // Post: Guarda el poder del personaje principal al cambiar su poder.
    void cambiar_poder(size_t poder);

    // Pre: -
    // Post: Llama al getter del grafo "obtener_pesos_vertices" y añade los diferentes pesos en un vector.
    Vector<size_t> obtener_pesos_vertices(Grafo mapa_combates, Camino camino);
};

#endif
