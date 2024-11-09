#include "OptimusPrime.hpp"

const std::string OptimusPrime::RESPUESTA_SERENO = "En que puedo ayudarte, humano?";
const std::string OptimusPrime::RESPUESTA_SERENO_MEGATRON = "La paz siempre es nuestra prioridad, pero no dudaremos en defendernos.";
const std::string OptimusPrime::RESPUESTA_SERENO_AUTOBOTS = "Los Autobots estan aqui para proteger a todos los seres vivos.";
const std::string OptimusPrime::RESPUESTA_SERENO_CYBERTRON = "Cybertron es nuestro hogar, pero nuestra mision esta aqui.";
const std::string OptimusPrime::RESPUESTA_DETERMINADO = "Nuestra lucha es por la libertad de todos los seres.";
const std::string OptimusPrime::RESPUESTA_DETERMINADO_MEGATRON = "Megatron sera detenido. No hay alternativa.";
const std::string OptimusPrime::RESPUESTA_DETERMINADO_AUTOBOTS = "Los Autobots son la luz en medio de la oscuridad.";
const std::string OptimusPrime::RESPUESTA_DETERMINADO_CYBERTRON = "Cybertron sobrevivira, como lo hemos hecho antes.";
const std::string OptimusPrime::RESPUESTA_ENFURECIDO = "La batalla es inminente. Preparate.";
const std::string OptimusPrime::RESPUESTA_ENFURECIDO_TRIVIALIDADES = "No tengo tiempo para estas trivialidades.";
const std::string OptimusPrime::SUGERENCIA_FUSION_SERENO = "Te recomiendo fusionar cristales comunes para comenzar a mejorar tu arsenal.";
const std::string OptimusPrime::SUGERENCIA_FUSION_DETERMINADO = "Te sugiero fusionar cristales raros para prepararte para la batalla.";
const std::string OptimusPrime::SUGERENCIA_FUSION_ENFURECIDO = "Fusiona cristales de alto riesgo para obtener una ventaja decisiva.";

OptimusPrime::OptimusPrime()
{
  animo = "sereno";
  mensaje_manager = new MensajeManager();
}

OptimusPrime::~OptimusPrime()
{
  delete mensaje_manager;
}

std::string OptimusPrime::responder_sereno(std::string mensaje)
{
  std::string respuesta = RESPUESTA_SERENO;

  if (mensaje_manager->validar_mensaje(mensaje, "megatron") || mensaje_manager->validar_mensaje(mensaje, "decepticons"))
  {
    respuesta = RESPUESTA_SERENO_MEGATRON;
  }
  else if (mensaje_manager->validar_mensaje(mensaje, "autobots"))
  {
    respuesta = RESPUESTA_SERENO_AUTOBOTS;
  }
  else if (mensaje_manager->validar_mensaje(mensaje, "cybertron"))
  {
    respuesta = RESPUESTA_SERENO_CYBERTRON;
  }
  return respuesta;
}

std::string OptimusPrime::responder_determinado(std::string mensaje)
{
  std::string respuesta = RESPUESTA_DETERMINADO;

  if (mensaje_manager->validar_mensaje(mensaje, "megatron") || mensaje_manager->validar_mensaje(mensaje, "decepticons"))
  {
    respuesta = RESPUESTA_DETERMINADO_MEGATRON;
  }
  else if (mensaje_manager->validar_mensaje(mensaje, "autobots"))
  {
    respuesta = RESPUESTA_DETERMINADO_AUTOBOTS;
  }
  else if (mensaje_manager->validar_mensaje(mensaje, "cybertron"))
  {
    respuesta = RESPUESTA_DETERMINADO_CYBERTRON;
  }
  return respuesta;
}

std::string OptimusPrime::responder_enfurecido()
{
  int random = rand() % 2;
  std::string respuesta = RESPUESTA_ENFURECIDO;

  if (random == 0)
    respuesta = RESPUESTA_ENFURECIDO_TRIVIALIDADES;

  return respuesta;
}
void OptimusPrime::responder(std::string mensaje)
{
  std::string respuesta;
  std::string mensaje_formateado = mensaje_manager->formatear_minusculas(mensaje);

  if (animo == "sereno")
  {
    respuesta = responder_sereno(mensaje_formateado);
  }
  else if (animo == "determinado")
  {
    respuesta = responder_determinado(mensaje_formateado);
  }
  else if (animo == "enfurecido")
  {
    respuesta = responder_enfurecido();
  }

  std::cout << respuesta;
}

void OptimusPrime::sugerir_fusion()
{
  if (animo == "sereno")
  {
    std::cout << SUGERENCIA_FUSION_SERENO;
  }
  else if (animo == "determinado")
  {
    std::cout << SUGERENCIA_FUSION_DETERMINADO;
  }
  else if (animo == "enfurecido")
  {
    std::cout << SUGERENCIA_FUSION_ENFURECIDO;
  }
}

void OptimusPrime::cambiar_animo(std::string animo)
{
  this->animo = animo;
}
