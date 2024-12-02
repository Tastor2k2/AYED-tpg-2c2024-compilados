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
  case 0:
    rareza_texto = "Comun";
    break;
  case 1:
    rareza_texto = "Raro";
    break;
  case 2:
    rareza_texto = "Unico";
    break;
  case 3:
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
  int fuerza, velocidad, defensa;

  rareza = cristal.obtener_rareza();
  defensa = cristal.obtener_defensa();
  velocidad = cristal.obtener_velocidad();
  fuerza = cristal.obtener_fuerza();

  archivo << rareza << "," << fuerza << "," << velocidad << "," << defensa << "\n";
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

void BovedaCristales::mostrar_cristal_max_poder(){  
  if (cristales.tamanio() == 0){
    throw ExcepcionBovedaCristales("La bóveda está vacía");
  }
  Rareza rareza_max_actual = COMUN; 
  Rareza rareza_actual;
  size_t posicion_rareza_max = 0;
  for (size_t i = 0; i < cristales.tamanio(); i++) {
    rareza_actual = cristales[i].obtener_rareza();
    if (rareza_max_actual < rareza_actual){
      rareza_max_actual = rareza_actual;
      posicion_rareza_max = i;
    }
  }
  mostrar_cristal(posicion_rareza_max, cristales[posicion_rareza_max]);
}  