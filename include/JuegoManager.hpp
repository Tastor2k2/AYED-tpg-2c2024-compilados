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
#include "BovedaTransformers.hpp"
#include "TransformersManager.hpp"
#include "ChatManager.hpp"

enum PERSONAJE
{
    OPTIMUS,
    MEGATRON
};

class JuegoManager
{
private:
    size_t poder_personaje;
    std::string nombre_usuario;
    PERSONAJE personaje_seleccionado;
    std::optional<Cristal> cristal_seleccionado;
    BovedaManager boveda_manager;
    TransformersManager transformers_manager;

    void mostrar_opciones_personajes();

public:
    // Constructor
    JuegoManager();

    // PRE: -
    // POST: Almmacenara el nombre del usuario.
    void pedir_nombre();

    // PRE: -
    // POST: Mostrara las opciones de seleccion de personaje y guardara el seleccionado
    PERSONAJE elegir_personaje();

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

    void empezar_combate(Vector<Transformer> transformers);

    size_t obtener_poder();

    void cambiar_poder(size_t poder);
};

#endif
