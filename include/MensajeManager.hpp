#ifndef MENSAJE_MANAGER_HPP
#define MENSAJE_MANAGER_HPP

#include <cctype>
#include <string>
class MensajeManager
{
public:
  // PRE: -
  // POST: Devuelve el mensaje formateado en minusculas.
  std::string formatear_minusculas(std::string mensaje);

  // PRE: -
  // POST: Devuelve true si la palabra se encuentra en el mensaje, false en caso contrario.
  bool validar_mensaje(std::string mensaje, std::string palabra);
};

#endif