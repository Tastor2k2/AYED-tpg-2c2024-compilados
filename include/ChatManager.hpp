#ifndef CHATMANAGER_H
#define CHATMANAGER_H

#include <iostream>
#include <limits>
#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "BovedaCristales.hpp"
#include "BovedaManager.hpp"

class ChatManager
{
private:
  OptimusPrime optimus;
  Megatron megatron;
  BovedaManager boveda_manager;
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

public:
  // Constructor
  ChatManager();
  // PRE: -
  // POST: Inicia el ciclo de chat desde el menu de seleccion.
  void iniciar_chat();
};

#endif
