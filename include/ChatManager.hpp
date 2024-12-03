#ifndef CHATMANAGER_H
#define CHATMANAGER_H

#include <iostream>
#include <limits>
#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "JuegoManager.hpp"

class ChatManager
{
private:
  enum OpcionesPrincipales
  {
    SELECCIONAR_PERSONAJE,
    INTERACTUAR_PERSONAJE,
    ADMINISTRAR_BOVEDA,
    ADMINISTRAR_TRANSFORMERS,
    INICIAR_BATALLA,
    TABLA_CLASIFICACION,
    SALIR
  };

  enum OpcionesInteraccion
  {
    CHATEAR,
    PEDIR_CONSEJO_FUSION,
    CAMBIAR_ANIMO_INTENCION,
  };

  enum Animo
  {
    SERENO,
    DETERMINADO,
    ENFURECIDO
  };

  enum Intencion
  {
    DESPRECIO,
    MANIPULACION,
    AMENAZA
  };

  OptimusPrime optimus;
  Megatron megatron;
  JuegoManager juego_manager;

  // PRE: -
  // POST: Inicia el chat entre el Usuario y Optimus Prime.
  void iniciar_chat_optimus();
  // PRE: -
  // POST: Inicia el chat entre el Usuario y Megatron.
  void iniciar_chat_megatron();
  // PRE: -
  // POST: Inicia el chat administrativo de la boveda.
  void administrar_boveda();
  // PRE: -
  // POST: Inicia el chat administrativo de los transformers.
  void administrar_transformers();
  // PRE: -
  // POST: Muestra las opciones de seleccion.
  void mostrar_opciones();
  // PRE: -
  // POST: Muestra las opciones de seleccion de animo.
  void mostrar_opciones_animo();
  // PRE: -
  // POST: Muestra las opciones de seleccion de intencion.
  void mostrar_opciones_intencion();
  // PRE: - option y continuar previamente declarados
  // POST: Ejecutara la accion correspondiente a la opcion seleccionada, en caso de seleccionar la opcion de salir, continuar sera false
  void selector_chat(int &opcion, bool &continuar);
  // PRE: -
  // POST: Cambia el animo de Optimus Prime.
  void cambiar_animo_optimus();
  // PRE: -
  // POST: Cambia el animo de Optimus Prime.
  void cambiar_intencion_megatron();

  // PRE: -
  // POST: Interactua con el personaje seleccionado.
  void interactuar_personaje();

  // PRE: -
  // POST: Muestra las opciones e Interactua con Optimus Prime.
  void interactuar_optimus();

  // PRE: -
  // POST: Muestra las opciones e Interactua con Megatron.
  void interactuar_megatron();

  // PRE: -
  // POST: Muestra las opciones e Interactua con el personaje seleccionado.
  void seleccionar_personaje();

public:
  // Constructor
  ChatManager();
  // PRE: -
  // POST: Inicia el ciclo de chat desde el menu de seleccion.
  void iniciar_chat();
};

#endif
