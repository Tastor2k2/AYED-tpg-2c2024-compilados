#include "FusionadorEnergon.hpp"
#include <iostream>

FusionadorEnergon::FusionadorEnergon()
{
  generador = GeneradorAleatorio();
  intentos_comun = 0;
  intentos_raro = 0;
  intentos_epico = 0;
}

size_t FusionadorEnergon::obtener_porcentaje_fusion(Rareza rareza)
{
  size_t porcentaje = 50;

  if (rareza == RARO)
  {
    porcentaje = 30;
  }
  else if (rareza == EPICO)
  {
    porcentaje = 10;
  }

  return porcentaje;
}

Cristal FusionadorEnergon::manejar_creacion_cristal(Rareza rareza, int &intentos, GeneradorAleatorio &generador)
{
  Rareza nueva_rereza;
  Cristal nuevo_cristal;
  bool exito = intentos == 3 || generador.generar_chance_porcentual(obtener_porcentaje_fusion(rareza));

  if (exito)
  {
    nueva_rereza = static_cast<Rareza>(rareza + 1);
    nuevo_cristal = Cristal(nueva_rereza);
    intentos = 0;
  }
  else
  {
    nueva_rereza = rareza == COMUN ? rareza : static_cast<Rareza>(rareza - 1);
    nuevo_cristal = Cristal(nueva_rereza);
    intentos++;
  }
  return nuevo_cristal;
}

Cristal FusionadorEnergon::manejar_fusion(Rareza rareza, GeneradorAleatorio &generador)
{
  Cristal nuevo_cristal;

  if (rareza == LEGENDARIO)
  {
    throw ExcepcionFusionadorEnergon("No se puede fusionar cristales legendarios");
  }
  if (rareza == EPICO)
  {
    nuevo_cristal = manejar_creacion_cristal(rareza, intentos_epico, generador);
  }
  else if (rareza == RARO)
  {
    nuevo_cristal = manejar_creacion_cristal(rareza, intentos_raro, generador);
  }
  else if (rareza == COMUN)
  {
    nuevo_cristal = manejar_creacion_cristal(rareza, intentos_comun, generador);
  }

  return nuevo_cristal;
}

Cristal FusionadorEnergon::fusionar(Cristal cristal_1, Cristal cristal_2)
{
  if (cristal_1 == cristal_2.obtener_rareza())
  {

    return manejar_fusion(cristal_1.obtener_rareza(), generador);
  }
  else
  {
    throw ExcepcionFusionadorEnergon("Los cristales no son del mismo tipo");
  }
}

Cristal FusionadorEnergon::fusionar(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio &generador)
{
  if (cristal_1 == cristal_2.obtener_rareza())
  {
    return manejar_fusion(cristal_1.obtener_rareza(), generador);
  }
  else
  {
    throw ExcepcionFusionadorEnergon("Los cristales no son del mismo tipo");
  }
}
