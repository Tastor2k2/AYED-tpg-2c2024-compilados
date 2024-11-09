#include "BovedaManager.hpp"
#include <iostream>

const Cristal BovedaManager::CRISTAL_COMUN;

BovedaManager::BovedaManager()
{
  opcion = -1;
}

void BovedaManager::mostrar_opciones_boveda()
{
  std::cout << "\n******************************";
  std::cout << "\nCant: " << boveda.cantidad_cristales() << "/20";
  std::cout << "\n******************************";
  std::cout << "\nQue accion desea realizar?";
  std::cout << "\n1- Añadir cristal comun";
  std::cout << "\n2- Listar cristales";
  std::cout << "\n3- Fusionar cristales";
  std::cout << "\n4- Eliminar cristal";
  std::cout << "\n5- Exportar a csv";
  std::cout << "\n6- Salir";
  std::cout << "\n******************************";
  std::cout << "\n- ";
}

void BovedaManager::mostrar_confirmar_almacenar()
{
  std::cout << "\n******************************";
  std::cout << "\nAlmacenar en la boveda?";
  std::cout << "\n******************************";
  std::cout << "\n1- Si";
  std::cout << "\n2- No";
  std::cout << "\n******************************";
  std::cout << "\n- ";
}

void BovedaManager::mostrar_cristal_obtenido(Cristal cristal)
{
  std::cout << "\n||||||||||||||||||||||||" << std::endl;

  std::cout << "\nCristal obtenido: ";
  switch (cristal.obtener_rareza())
  {
  case 0:
    std::cout << "Comun" << std::endl;
    break;
  case 1:
    std::cout << "Raro" << std::endl;
    break;
  case 2:
    std::cout << "Unico" << std::endl;
    break;
  case 3:
    std::cout << "Legendario" << std::endl;
    break;
  }
  cristal.mostrar_estadisticas();
  std::cout << "\n||||||||||||||||||||||||" << std::endl;
}

void BovedaManager::administrar_boveda(bool &continuar)
{
  opcion = -1;
  mostrar_opciones_boveda();
  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (opcion)
  {
  case 1:
    aniadir_cristal_comun();
    break;
  case 2:
    boveda.mostrar_cristales();
    break;
  case 3:
    fusionar_cristales();
    break;
  case 4:
    eliminar_cristal();
    break;
  case 5:
    exportar_cristales();
    break;
  case 6:
    continuar = false;
    break;
  default:
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nOpción inválida";
    break;
  }
}

void BovedaManager::aniadir_cristal_comun()
{
  if (boveda.cantidad_cristales() == 20)
  {
    std::cout << "\nBoveda llena";
  }
  else
  {
    boveda.almacenar_cristal(CRISTAL_COMUN);
  };
}

void BovedaManager::fusionar_cristales()
{
  Cristal cristal_a, cristal_b, nuevo_cristal;
  if (boveda.cantidad_cristales() < 2)
  {
    std::cout << "\n--------------------------------";
    std::cout << "\nNo hay suficientes cristales para fusionar";
    std::cout << "\n--------------------------------";
  }
  else
  {
    boveda.mostrar_cristales();

    std::cout << "\nIngrese el indice del cristal A: ";
    size_t indice_a;
    std::cin >> indice_a;

    std::cout << "\nIngrese el indice del cristal B: ";
    size_t indice_b;
    std::cin >> indice_b;

    if (indice_a >= boveda.cantidad_cristales() || indice_b >= boveda.cantidad_cristales())
    {
      std::cout << "\n--------------------------------";
      std::cout << "\nIndices invalido";
      std::cout << "\n--------------------------------";
    }
    else
    {

      if (boveda.obtener_rareza_cristal(indice_a) == boveda.obtener_rareza_cristal(indice_b))
      {
        cristal_a = boveda.obtener_cristal(indice_a);
        cristal_b = boveda.obtener_cristal(indice_a < indice_b ? indice_b - 1 : indice_b);
        nuevo_cristal = fusionador.fusionar(cristal_a, cristal_b);

        mostrar_cristal_obtenido(nuevo_cristal);

        mostrar_confirmar_almacenar();

        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcion == 1)
        {
          boveda.almacenar_cristal(nuevo_cristal);
        }
      }
      else
      {
        std::cout << "\n--------------------------------";
        std::cout << "No se pueden fusionar cristales de distinta rareza";
        std::cout << "\n--------------------------------";
      }
    }
  }
}

void BovedaManager::eliminar_cristal()
{
  size_t indice;

  if (boveda.cantidad_cristales() == 0)
  {
    std::cout << "\n--------------------------------";
    std::cout << "\nNo hay cristales para eliminar";
    std::cout << "\n--------------------------------";
  }
  else
  {
    boveda.mostrar_cristales();
    std::cout << "\nIngrese el indice del cristal a eliminar: ";
    std::cin >> indice;

    if (indice >= boveda.cantidad_cristales())
    {
      std::cout << "\n--------------------------------";
      std::cout << "\nIndice invalido";
      std::cout << "\n--------------------------------";
    }
    else
    {
      boveda.obtener_cristal(indice);
      std::cout << "\n--------------------------------";
      std::cout << "\nCristal " << indice << " Eliminado";
      std::cout << "\n--------------------------------";
    }
  }
}
void BovedaManager::exportar_cristales()
{
  std::string ruta;
  std::cout << "\nIngrese nombre del archivo para exportar: ";
  std::getline(std::cin, ruta);
  boveda.exportar_cristales(ruta);
}
