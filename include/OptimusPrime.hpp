#ifndef OPTIMUSPRIME_HPP
#define OPTIMUSPRIME_HPP

#include <iostream>
#include <string>
#include "MensajeManager.hpp"
#include "Transformer.hpp"

class OptimusPrime
{
private:
  // Valores: sereno, determinado, enfurecido
  std::string animo;
  // Permite interpretar y formatear los mensajes
  MensajeManager *mensaje_manager;
  // PRE:
  // POST: Devuelve la respuesta de Optimus Prime con animo sereno, en base al mensaje recibido.
  std::string responder_sereno(std::string mensaje);
  // PRE: -
  // POST: Devuelve la respuesta de Optimus Prime con animo determinado, en base al mensaje recibido.
  std::string responder_determinado(std::string mensaje);
  // PRE: -
  // POST: Devuelve una respuesta de enfurecido aleatoria.
  std::string responder_enfurecido();

  // Respuestas de Optimus Prime
  static const std::string RESPUESTA_SERENO;
  static const std::string RESPUESTA_SERENO_MEGATRON;
  static const std::string RESPUESTA_SERENO_AUTOBOTS;
  static const std::string RESPUESTA_SERENO_CYBERTRON;
  static const std::string RESPUESTA_DETERMINADO;
  static const std::string RESPUESTA_DETERMINADO_MEGATRON;
  static const std::string RESPUESTA_DETERMINADO_AUTOBOTS;
  static const std::string RESPUESTA_DETERMINADO_CYBERTRON;
  static const std::string RESPUESTA_ENFURECIDO;
  static const std::string RESPUESTA_ENFURECIDO_TRIVIALIDADES;

  // Sugerencias de fusión
  static const std::string SUGERENCIA_FUSION_SERENO;
  static const std::string SUGERENCIA_FUSION_DETERMINADO;
  static const std::string SUGERENCIA_FUSION_ENFURECIDO;

  // Estadísticas

  size_t fuerza, defensa, velocidad;
  bool transformado;
  std::string nombre = "OptimusPrime";
  Faccion faccion = AUTOBOT;
  Vehiculo vehiculo = CAMION;

  static const size_t PLUS_FUERZA_CAMION;
  static const size_t PLUS_DEFENZA_CAMION;
  static const size_t PLUS_VELOCIDAD_CAMION;

public:
  // Constructor
  OptimusPrime();
  // Destructor
  ~OptimusPrime();
  // PRE: -
  // POST: Devuelve la respuesta de Optimus Prime segun el animo y el mensaje recibido.
  void responder(std::string mensaje);

  // PRE: -
  // POST: Sugiere una fusion segun el animo de Optimus Prime.
  void sugerir_fusion();

  // PRE: -
  // POST: Cambia el animo de Optimus Prime al valor del parametro recibido.
  void cambiar_animo(std::string animo);

  size_t obtener_poder();

  void transformar();
};

#endif
