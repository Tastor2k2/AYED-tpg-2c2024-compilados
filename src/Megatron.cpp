#include "Megatron.hpp"

const std::string Megatron::RESPUESTA_DESPRECIO = "Eres insignificante.";
const std::string Megatron::RESPUESTA_DESPRECIO_AUTOBOTS_PRIME = "Esos debiles seran aplastados bajo mi yugo.";
const std::string Megatron::RESPUESTA_DESPRECIO_CYBERTRON = "Cybertron sera mio, a cualquier costo.";
const std::string Megatron::RESPUESTA_MANIPULACION = "Puedo darte lo que buscas, si estas dispuesto a arrodillarte.";
const std::string Megatron::RESPUESTA_MANIPULACION_PODER = "Unete a mi, y juntos gobernaremos este universo.";
const std::string Megatron::RESPUESTA_MANIPULACION_FUERZA = "Solo el mas fuerte merece sobrevivir.";
const std::string Megatron::RESPUESTA_AMENAZA_1 = "No hay lugar para los debiles en mi imperio.";
const std::string Megatron::RESPUESTA_AMENAZA_2 = "Atrevete a desafiarme, y conoceras el verdadero terror.";
const std::string Megatron::SUGERENCIA_FUSION_DESPRECIO = "Fusiona cristales comunes para mejorar tus capacidades basicas.";
const std::string Megatron::SUGERENCIA_FUSION_MANIPULACION = "Fusiona cristales raros para obtener un poder significativo.";
const std::string Megatron::SUGERENCIA_FUSION_AMENAZA = "Realiza fusiones arriesgadas para obtener una ventaja poderosa.";

const size_t Megatron::PLUS_FUERZA_TANQUE = 30;
const size_t Megatron::PLUS_DEFENZA_TANQUE = 80;
const size_t Megatron::PLUS_VELOCIDAD_TANQUE = 10;

Megatron::Megatron()
{
  fuerza = 80;
  defensa = 50;
  velocidad = 10;
  transformado = false;
  intencion = "desprecio";
  mensaje_manager = new MensajeManager();
}

Megatron::~Megatron()
{
  delete mensaje_manager;
}

std::string Megatron::responder_desprecio(std::string mensaje)
{
  std::string respuesta = RESPUESTA_DESPRECIO;

  if (mensaje_manager->validar_mensaje(mensaje, "optimus prime") || mensaje_manager->validar_mensaje(mensaje, "autobots"))
  {
    respuesta = RESPUESTA_DESPRECIO_AUTOBOTS_PRIME;
  }
  else if (mensaje_manager->validar_mensaje(mensaje, "cybertron"))
  {
    respuesta = RESPUESTA_DESPRECIO_CYBERTRON;
  }
  return respuesta;
}

std::string Megatron::responder_manipulacion(std::string mensaje)
{
  std::string respuesta = RESPUESTA_MANIPULACION;

  if (mensaje_manager->validar_mensaje(mensaje, "poder") || mensaje_manager->validar_mensaje(mensaje, "aliado"))
  {
    respuesta = RESPUESTA_MANIPULACION_PODER;
  }
  else if (mensaje_manager->validar_mensaje(mensaje, "fuerza"))
  {
    respuesta = RESPUESTA_MANIPULACION_FUERZA;
  }
  return respuesta;
}

std::string Megatron::responder_amenaza()
{
  int random = rand() % 2;
  std::string respuesta = RESPUESTA_AMENAZA_1;

  if (random == 0)
    respuesta = RESPUESTA_AMENAZA_2;

  return respuesta;
}

void Megatron::responder(std::string mensaje)
{
  std::string respuesta;
  std::string mensaje_formateado = mensaje_manager->formatear_minusculas(mensaje);

  if (intencion == "desprecio")
  {
    respuesta = responder_desprecio(mensaje_formateado);
  }
  else if (intencion == "manipulacion")
  {
    respuesta = responder_manipulacion(mensaje_formateado);
  }
  else if (intencion == "amenaza")
  {
    respuesta = responder_amenaza();
  }

  std::cout << respuesta;
}

void Megatron::sugerir_fusion()
{
  if (intencion == "desprecio")
  {
    std::cout << SUGERENCIA_FUSION_DESPRECIO;
  }
  else if (intencion == "manipulacion")
  {
    std::cout << SUGERENCIA_FUSION_MANIPULACION;
  }
  else if (intencion == "amenaza")
  {
    std::cout << SUGERENCIA_FUSION_AMENAZA;
  }
}

void Megatron::cambiar_intencion(std::string intencion)
{
  this->intencion = intencion;
}

size_t Megatron::obtener_poder()
{
  return velocidad + fuerza + defensa;
}

void Megatron::transformar()
{
  if (!transformado)
  {
    this->transformado = true;
    this->fuerza += PLUS_FUERZA_TANQUE;
    this->defensa += PLUS_DEFENZA_TANQUE;
    this->velocidad = 0;
  }
  else
  {
    this->transformado = false;
    this->fuerza -= PLUS_FUERZA_TANQUE;
    this->velocidad += PLUS_VELOCIDAD_TANQUE;
    this->defensa -= PLUS_DEFENZA_TANQUE;
  }
}

void Megatron::aumentar_estadísticas(size_t fuerza, size_t defensa, size_t velocidad)
{
  this->fuerza += fuerza;
  this->velocidad += velocidad;
  this->defensa += defensa;
}
