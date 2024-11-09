#include "MensajeManager.hpp"

bool MensajeManager::validar_mensaje(std::string mensaje, std::string palabra)
{
  return mensaje.find(palabra) != std::string::npos;
}

std::string MensajeManager::formatear_minusculas(std::string mensaje)
{
  for (size_t i = 0; i < mensaje.size(); ++i)
  {
    mensaje[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(mensaje[i])));
  }
  return mensaje;
}