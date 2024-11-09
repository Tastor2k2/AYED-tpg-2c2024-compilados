#ifndef CRISTAL_HPP
#define CRISTAL_HPP

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
  int fuerza;
  int defensa;
  int velocidad;
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
  // POST: Devuelve la fuerza del cristal.
  int obtener_fuerza();

  // PRE: -
  // POST: Devuelve la defensa del cristal.
  int obtener_defensa();

  // PRE: -
  // POST: Devuelve la velocidad del cristal.
  int obtener_velocidad();

  // PRE: -
  // POST: Muestra las estadisticas del cristal por consola.
  void mostrar_estadisticas();

  // PRE: -
  // POST: Devuelve true si la rareza del cristal es igual a la rareza pasada por parametro.
  bool operator==(Rareza rareza);
};

#endif
