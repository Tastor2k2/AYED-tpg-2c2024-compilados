#include "Cristal.hpp"
#include <iostream>

Cristal::Cristal()
{
  fuerza = 10;
  defensa = 10;
  velocidad = 10;
  rareza = COMUN;
}

Cristal::Cristal(Rareza rareza)
{
  int multiplicador = rareza + 1;

  fuerza = 10 * multiplicador;
  defensa = 10 * multiplicador;
  velocidad = 10 * multiplicador;

  this->rareza = rareza;
}

bool Cristal::operator==(Rareza rareza)
{
  return this->rareza == rareza;
}

Rareza Cristal::obtener_rareza()
{
  return rareza;
}

void Cristal::mostrar_estadisticas()
{
  std::cout << "------------------" << std::endl;
  std::cout << "Fuerza: " << fuerza << std::endl;
  std::cout << "Defensa: " << defensa << std::endl;
  std::cout << "Velocidad: " << velocidad << std::endl;
  std::cout << "------------------" << std::endl;
}

int Cristal::obtener_defensa()
{
  return defensa;
}

int Cristal::obtener_fuerza()
{
  return fuerza;
}

int Cristal::obtener_velocidad()
{
  return velocidad;
}