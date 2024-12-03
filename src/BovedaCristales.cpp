#include "BovedaCristales.hpp"
#include <iostream>
#include <fstream>

const int BovedaCristales::MAXIMO_CRISTALES = 20;

BovedaCristales::BovedaCristales() {}

void BovedaCristales::almacenar_cristal(Cristal cristal_nuevo)
{
  if (cristales.tamanio() == MAXIMO_CRISTALES)
  {
    throw ExcepcionBovedaCristales("Boveda llena");
  }

  cristales.alta(cristal_nuevo);
}

void BovedaCristales::mostrar_cristal(size_t indice, Cristal cristal)
{
  std::string rareza_texto;
  switch (cristal.obtener_rareza())
  {
  case COMUN:
    rareza_texto = "Comun";
    break;
  case RARO:
    rareza_texto = "Raro";
    break;
  case EPICO:
    rareza_texto = "Epico";
    break;
  case LEGENDARIO:
    rareza_texto = "Legendario";
    break;
  }
  std::cout << "-Cristal " << indice << ": " << rareza_texto << std::endl;
  cristal.mostrar_estadisticas();
}

void BovedaCristales::mostrar_cristales()
{
  std::cout << "###################################" << std::endl;
  std::cout << "Boveda cristales" << std::endl;
  std::cout << "------------------" << std::endl;

  if (cristales.vacio())
  {
    std::cout << "No hay cristales en la boveda" << std::endl;
    std::cout << "------------------" << std::endl;
  }
  else
  {
    for (size_t i = 0; i < cristales.tamanio(); i++)
    {
      mostrar_cristal(i, cristales[i]);
    }
  }
  std::cout << "###################################" << std::endl;
}

Cristal BovedaCristales::obtener_cristal(size_t posicion)
{
  if (posicion >= cristales.tamanio())
  {
    throw ExcepcionBovedaCristales("Posicion invalida");
  }

  return cristales.baja(posicion);
}

size_t BovedaCristales::cantidad_cristales()
{
  return cristales.tamanio();
}

Rareza BovedaCristales::obtener_rareza_cristal(size_t posicion)
{
  if (posicion >= cristales.tamanio())
  {
    throw ExcepcionBovedaCristales("Posicion invalida");
  }

  return cristales[posicion].obtener_rareza();
}

void BovedaCristales::exportar_cristal(std::ofstream &archivo, Cristal cristal)
{
  Rareza rareza;
  Estadisticas estadisticas = cristal.obtener_estadisticas();

  rareza = cristal.obtener_rareza();

  archivo << rareza << "," << estadisticas.fuerza << "," << estadisticas.velocidad << "," << estadisticas.defensa << "\n";
}

void BovedaCristales::exportar_cristales(std::string ruta)
{
  std::ofstream archivo(ruta + ".csv");

  if (archivo.is_open())
  {

    for (size_t i = 0; i < cristales.tamanio(); i++)
    {
      exportar_cristal(archivo, cristales[i]);
    }

    archivo.close();

    std::cout << "Cristales exportados a " << ruta << ".csv exitosamente.\n";
  }
  else
  {
    throw ExcepcionBovedaCristales("Error al abrir el archivo: " + ruta);
  }
}

void BovedaCristales::mostrar_cristal_max_poder()
{
  if (cristales.tamanio() == 0)
  {
    throw ExcepcionBovedaCristales("La bóveda está vacía");
  }

  size_t posicion_max_poder = 0;
  size_t poder_max = cristales[0].obtener_poder();

  for (size_t i = 1; i < cristales.tamanio(); i++)
  {
    size_t poder_actual = cristales[i].obtener_poder();
    if (poder_actual > poder_max)
    {
      poder_max = poder_actual;
      posicion_max_poder = i;
    }
  }

  mostrar_cristal(posicion_max_poder, cristales[posicion_max_poder]);
}
