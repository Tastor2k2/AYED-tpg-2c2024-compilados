#ifndef CRISTAL_HPP
#define CRISTAL_HPP

#include <cstddef>
#include <Transformer.hpp>

enum Rareza
{
  COMUN,
  RARO,
  EPICO,
  LEGENDARIO
};

class Cristal
{
private:
  size_t fuerza;
  size_t defensa;
  size_t velocidad;
  Rareza rareza;

public:
  // Constructor
  Cristal();

  // PRE: -
  // POST: Crea un cristal con estadisticas segun la rareza.
  Cristal(Rareza rareza);

  // PRE: -
  // POST: Devuelve la rareza del cristal.
  Rareza obtener_rareza();

  // PRE: -
  // POST: Muestra las estadisticas del cristal por consola.
  void mostrar_estadisticas();

  // PRE: -
  // POST: Devuelve el poder del cristal, siendo la sumatoria de sus estadisticas.
  size_t obtener_poder();

  // PRE: -
  // POST: Devuelve true si la rareza del cristal es igual a la rareza pasada por parametro.
  bool operator==(Rareza rareza);

  // PRE: -
  // POST: Devuelve las estadisticas del cristal.
  Estadisticas obtener_estadisticas();
};

#endif
