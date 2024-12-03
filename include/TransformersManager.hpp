#ifndef TransformersManager_H
#define TransformersManager_H

#include <iostream>
#include <limits>
#include "Transformer.hpp"
#include "BovedaTransformers.hpp"

class TransformersManager
{
private:
    // Opcion seleccionada por el usuario en el chat
    int opcion;
    BovedaTransformers boveda_transformers;

    // PRE: -
    // POST: Muestra las opciones que puede elegir el usuario.
    void mostrar_opciones_transformers();

    // PRE: -
    // POST: Muestra interfaz y aniaade un transformer
    void aniadir_transformer();

    // PRE: -
    // POST: Busca un transformer y muestra su detalle si lo encuentra.
    void buscar_transformer();

    // PRE: -
    // POST: Busca y elimina un transformer si lo encuentra.
    void eliminar_transformer();

    // PRE: -
    // POST: Transforma un transformer si lo encuentra.
    void transformar();

public:
    // Constructor
    TransformersManager();

    // PRE: -
    // POST: Muestra las opciones de los trasnformers secundarios y ejecuta la seleccion del usuario.
    void administrar_transformers(bool &continuar);

    // PRE: -
    // POST: Devuelve la cantidad de transformers. 
    size_t obtener_cantidad_transformers();

    // PRE: -
    // POST: Devuelve el vector transformer.
    Vector<Transformer> obtener_transformers_boveda();
};

#endif
