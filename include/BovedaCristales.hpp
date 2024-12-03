#ifndef BOVEDACRISTALES_HPP
#define BOVEDACRISTALES_HPP

#include <Cristal.hpp>
#include <Vector.hpp>
#include <stdexcept>
#include <string>

class ExcepcionBovedaCristales : public std::runtime_error
{
public:
  ExcepcionBovedaCristales(std::string mensaje) : runtime_error(mensaje)
  {
  }

  ExcepcionBovedaCristales() : runtime_error("")
  {
  }
};

class BovedaCristales
{
private:
  Vector<Cristal> cristales;
  // Cantidad maxima de cristales que puede tener la boveda
  static const int MAXIMO_CRISTALES;

public:
  // Constructor
  BovedaCristales();

  // PRE: La cantidad de cristales en la boveda tiene que ser menor al MAXIMO_CRISTALES
  // POST: Almacena un cristal en la boveda.
  void almacenar_cristal(Cristal cristal_nuevo);

  // PRE: -
  // POST: Muestra los cristales almacenados en la boveda por consola.
  void mostrar_cristales();

  // PRE: -
  // POST: Muestra el cristal pasado por parametro, y su posicion en la boveda.
  void mostrar_cristal(size_t indice, Cristal cristal);

  // PRE: La posicion debe ser menor que el maximo logico de cristales y al MAXIMO_CRISTALES.
  // POST: Devuelve el cristal en la posicion indicada.
  Cristal obtener_cristal(size_t posicion);

  // PRE: La posicion debe ser menor que el maximo logico de cristales y al MAXIMO_CRISTALES.
  // POST: Devuelve la rareza del cristal en la posicion indicada.
  Rareza obtener_rareza_cristal(size_t posicion);

  // PRE: -
  // POST: Devuelve la cantidad de cristales almacenados en la boveda.
  size_t cantidad_cristales();

  // PRE: -
  // POST: Exporta los cristales de la boveda a un archivo .csv con el nombre indicado.
  void exportar_cristales(std::string ruta);

  // PRE: archivo debe estar abierto.
  // POST: Exporta el cristal de la boveda a un archivo .csv pasado por parametro.
  void exportar_cristal(std::ofstream &archivo, Cristal cristal);

  // PRE: La bóveda debe tener cristales, no estar vacía.
  // POST: Muestra el cristal con mayor poder entre los cristales del inventario.
  void mostrar_cristal_max_poder();  

};
#endif
