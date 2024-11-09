#ifndef BovedaManager_H
#define BovedaManager_H

#include <iostream>
#include <limits>
#include "BovedaCristales.hpp"
#include "FusionadorEnergon.hpp"

class BovedaManager
{
private:
    // Cristal para insertar en la boveda por defecto
    static const Cristal CRISTAL_COMUN;

    // Opcion seleccionada por el usuario en el chat
    int opcion;
    BovedaCristales boveda;
    FusionadorEnergon fusionador;

    // PRE: -
    // POST: Muestra las opciones que puede elegir el usuario de la boveda.
    void mostrar_opciones_boveda();
    // PRE: -
    // POST: Muestra las opciones para confirmar si se desea almacenar un cristal.
    void mostrar_confirmar_almacenar();
    // PRE: -
    // POST: Muestra los detalles del cristal obtenido.
    void mostrar_cristal_obtenido(Cristal cristal);
    // PRE: -
    // POST: Muestra interfaz y aniaade un cristal comun a la boveda.
    void aniadir_cristal_comun();
    // PRE: -
    // POST: Muestra interfaz y fusiona dos cristales de la boveda.
    void fusionar_cristales();
    // PRE: -
    // POST: Elimina un cristal de la boveda.
    void eliminar_cristal();
    // PRE: -
    // POST: Exporta los cristales de la boveda a un archivo csv.
    void exportar_cristales();

public:
    // Constructor
    BovedaManager();

    // PRE: -
    // POST: Muestra las opciones de la boveda y ejecuta la seleccion del usuario.
    void administrar_boveda(bool &continuar);
};

#endif
