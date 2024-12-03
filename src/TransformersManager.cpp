#include "TransformersManager.hpp"
#include <iostream>

TransformersManager::TransformersManager()
{
  opcion = -1;
}

void TransformersManager::mostrar_opciones_transformers()
{
  std::cout << "\n******************************";
  std::cout << "\nQue accion desea realizar?";
  std::cout << "\n1- Añadir trasformer";
  std::cout << "\n2- Mostrar Transformers";
  std::cout << "\n3- Buscar Transformer";
  std::cout << "\n4- Eliminar Transformer";
  std::cout << "\n5- Transformar";
  std::cout << "\n6- Salir";
  std::cout << "\n******************************";
  std::cout << "\n- ";
}

void TransformersManager::aniadir_transformer()
{
  std::cout << "\nIngrese el nombre: ";
  std::string nombre;
  std::cin >> nombre;

  std::cout << "\nIngrese el fuerza: ";
  size_t fuerza;
  std::cin >> fuerza;

  std::cout << "\nIngrese el defensa: ";
  size_t defensa;
  std::cin >> defensa;

  std::cout << "\nIngrese el velocidad: ";
  size_t velocidad;
  std::cin >> velocidad;

  int faccion_num = -1;
  while (faccion_num < 0 || faccion_num > 1)
  {
    std::cout << "\nIngrese la faccion: ";
    std::cout << "\n0- Autobot";
    std::cout << "\n1- Decepticon";
    std::cout << "\n- ";
    std::cin >> faccion_num;
  }

  Faccion faccion = static_cast<Faccion>(faccion_num);

  std::cout << faccion;

  Vehiculo vehiculo;
  size_t vehiculo_num;
  std::cout << "\nIngrese el vehiculo:";
  if (faccion == AUTOBOT)
  {
    // implementar loop
    std::cout << "\n0- Auto";
    std::cout << "\n1- Camion";
    std::cout << "\n- ";
    std::cin >> vehiculo_num;
    vehiculo = static_cast<Vehiculo>(vehiculo_num < 2 ? vehiculo_num : 0);
  }
  else
  {
    // implementar loop
    std::cout << "\n0- Tanque";
    std::cout << "\n1- Avion";
    std::cout << "\n- ";
    std::cin >> vehiculo_num;
    vehiculo = static_cast<Vehiculo>(vehiculo_num < 2 ? vehiculo_num + 2 : 2);
  }

  Transformer transformer = Transformer(nombre, fuerza, defensa, velocidad, faccion, vehiculo, false);
  boveda_transformers.almacenar_transformer(transformer);
}

void TransformersManager::eliminar_transformer()
{
  boveda_transformers.mostrar_transformers();
  std::cout << "\nEliminar Transformer";
  std::cout << "\n--------------------------------";
  std::cout << "\nIngrese el nombre: ";
  std::string nombre;
  std::cin >> nombre;

  int posicion = boveda_transformers.obtener_posicion_transformer(nombre);

  if (posicion == -1)
  {
    std::cout << "\n--------------------------------";
    std::cout << "\nTransformer no encontrado";
    std::cout << "\n--------------------------------";
  }
  else
  {
    Transformer eliminado = boveda_transformers.eliminar_transformer(static_cast<size_t>(posicion));

    std::cout << "\n--------------------------------";
    std::cout << "\nTransformer " << eliminado.obtener_nombre() << " Eliminado";
    std::cout << "\n--------------------------------";
    eliminado.mostrar_detalle();
    std::cout << "\n--------------------------------";
  }
}

void TransformersManager::buscar_transformer()
{
  std::cout << "\n###################################";
  std::cout << "\nBuscar Transformer";
  std::cout << "\n--------------------------------";
  std::cout << "\nIngrese el nombre: ";
  std::string nombre;
  std::cin >> nombre;

  int posicion = boveda_transformers.obtener_posicion_transformer(nombre);

  if (posicion == -1)
  {
    std::cout << "\n--------------------------------";
    std::cout << "\nTransformer no encontrado";
    std::cout << "\n--------------------------------";
  }
  else
  {
    std::cout << "\n--------------------------------";
    boveda_transformers.mostrar_transformer(static_cast<size_t>(posicion));
    std::cout << "\n--------------------------------";
  }
}

void TransformersManager::transformar()
{
  boveda_transformers.mostrar_transformers();
  std::cout << "\nTransformar Transformer";
  std::cout << "\n--------------------------------";
  std::cout << "\nIngrese el nombre: ";
  std::string nombre;
  std::cin >> nombre;

  int posicion = boveda_transformers.obtener_posicion_transformer(nombre);

  if (posicion == -1)
  {
    std::cout << "\n--------------------------------";
    std::cout << "\nTransformer no encontrado";
  }
  else
  {
    boveda_transformers.transformar(static_cast<size_t>(posicion));
  }
  std::cout << "\n--------------------------------";
}

void TransformersManager::administrar_transformers(bool &continuar)
{
  opcion = -1;
  mostrar_opciones_transformers();
  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (opcion)
  {
  case 1:
    aniadir_transformer();
    break;
  case 2:
    boveda_transformers.mostrar_transformers();
    break;
  case 3:
    buscar_transformer();
    break;
  case 4:
    eliminar_transformer();
    break;
  case 5:
    transformar();
    break;
  case 6:
    continuar = false;
    break;
  default:
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nOpción inválida";
  }
}

size_t TransformersManager::obtener_cantidad_transformers()
{
  return boveda_transformers.cantidad_transformers();
}

Vector<Transformer> TransformersManager::obtener_transformers_boveda()
{
  return boveda_transformers.obtener_transformers();
}