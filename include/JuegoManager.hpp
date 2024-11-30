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

enum PERSONAJE
{
    OPTIMUS,
    MEGATRON
};

class JuegoManager
{
private:
    std::string nombre_usuario;
    PERSONAJE personaje_seleccionado;
    std::optional<Cristal> cristal_seleccionado;
    BovedaManager boveda_manager;

    void mostrar_opciones_personajes();

public:
    // Constructor
    JuegoManager();

    // PRE: -
    // POST: Almmacenara el nombre del usuario.
    void pedir_nombre();

    // PRE: -
    // POST: Mostrara las opciones de seleccion de personaje y guardara el seleccionado
    void elegir_personaje();

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
};

#endif
