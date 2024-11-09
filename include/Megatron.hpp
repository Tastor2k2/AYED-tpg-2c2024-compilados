#ifndef MEGATRON_HPP
#define MEGATRON_HPP

#include <string>
#include <iostream>
#include "MensajeManager.hpp"

class Megatron
{
private:
  // Valores: desprecio, manipulacion, amenaza
  std::string intencion;
  // Permite interpretar y formatear los mensajes
  MensajeManager *mensaje_manager;
  // PRE: -
  // POST: Devuelve la respuesta de Megatron con intencion desprecio, en base al mensaje recibido.
  std::string responder_desprecio(std::string mensaje);
  // PRE: -
  // POST: Devuelve la respuesta de megatron con intencion manipulacion, en base al mensaje recibido.
  std::string responder_manipulacion(std::string mensaje);
  // PRE: -
  // POST: Devuelve una respuesta de amenaza aleatoria.
  std::string responder_amenaza();

  // Respuestas de Megatron
  static const std::string RESPUESTA_DESPRECIO;
  static const std::string RESPUESTA_DESPRECIO_AUTOBOTS_PRIME;
  static const std::string RESPUESTA_DESPRECIO_CYBERTRON;
  static const std::string RESPUESTA_MANIPULACION;
  static const std::string RESPUESTA_MANIPULACION_PODER;
  static const std::string RESPUESTA_MANIPULACION_FUERZA;
  static const std::string RESPUESTA_AMENAZA_1;
  static const std::string RESPUESTA_AMENAZA_2;

  // Sugerencias de fusion
  static const std::string SUGERENCIA_FUSION_DESPRECIO;
  static const std::string SUGERENCIA_FUSION_MANIPULACION;
  static const std::string SUGERENCIA_FUSION_AMENAZA;

public:
  // Constructor
  Megatron();
  // Destructor
  ~Megatron();

  // PRE: -
  // POST: Devuelve la respuesta de Megatron segun la intencion y el mensaje recibido.
  void responder(std::string mensaje);

  // PRE: -
  // POST: Sugiere una fusion segun la intencion de Megatron.
  void sugerir_fusion();

  // PRE: -
  // POST: Cambia la intencion de Megatron al valor del parametro recibido.
  void cambiar_intencion(std::string intencion);
};

#endif
