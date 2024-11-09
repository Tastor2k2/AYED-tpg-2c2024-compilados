#ifndef FUSIONADORENERGON_HPP
#define FUSIONADORENERGON_HPP

#include "GeneradorAleatorio.hpp"
#include "Cristal.hpp"
#include <stdexcept>

class ExcepcionFusionadorEnergon : public std::runtime_error
{
public:
  ExcepcionFusionadorEnergon(std::string mensaje) : runtime_error(mensaje)
  {
  }

  ExcepcionFusionadorEnergon() : runtime_error("")
  {
  }
};

class FusionadorEnergon
{
private:
  GeneradorAleatorio generador;

  // PRE: -
  // POST: Devuelve el cristal resultante de la fusion usando el generador por parametro.
  Cristal manejar_fusion(Rareza rareza, GeneradorAleatorio &generador);

  // PRE: -
  // POST  Devuelve el cristal resultante de la fusion teniendo en cuenta los intentos realizados.
  Cristal manejar_creacion_cristal(Rareza rareza, int &intentos, GeneradorAleatorio &generador);

  // PRE: -
  // POST: Devuelve el porcentaje de exito de una fusion segun la rareza.
  size_t obtener_porcentaje_fusion(Rareza rareza);

  // Contadores
  int intentos_comun;
  int intentos_raro;
  int intentos_epico;

public:
  // Constructor
  FusionadorEnergon();

  // PRE: -
  // POST: Devuelve el cristal resultante de la fusion de cristal_1 y cristal_2.
  Cristal fusionar(Cristal cristal_1, Cristal cristal_2);

  // PRE: -
  // POST: Devuelve el cristal resultante de la fusion de cristal_1 y cristal_2, usando el generador por parametro.
  Cristal fusionar(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio &generador);
};

#endif
