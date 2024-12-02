#include "ChatManager.hpp"

ChatManager::ChatManager() {}

void ChatManager::mostrar_opciones()
{
  std::cout << "\n******************************";
  std::cout << "\n|Menu Principal|";
  std::cout << "\n1- Cambiar de personaje";
  std::cout << "\n2- Interactuar con personaje";
  std::cout << "\n3- Administrar Boveda de Cristales";
  std::cout << "\n4- Administrar Transformers";
  std::cout << "\n5- Iniciar Batalla";
  std::cout << "\n6- Tabla de Clasificacion";
  std::cout << "\n7- Salir";

  std::cout << "\n******************************";
  std::cout << "\n- ";
}

void ChatManager::mostrar_opciones_animo()
{
  std::cout << "\n******************************";
  std::cout << "\nIngrese el animo de Optimus:";
  std::cout << "\n1- Sereno";
  std::cout << "\n2- Determinado";
  std::cout << "\n3- Enfurecido";
  std::cout << "\n******************************";
  std::cout << "\n- ";
}

void ChatManager::mostrar_opciones_intencion()
{
  std::cout << "\n******************************";
  std::cout << "\nIngrese la intencion de Megatron:";
  std::cout << "\n1- Desprecio";
  std::cout << "\n2- Manipulacion";
  std::cout << "\n3- Amenaza";
  std::cout << "\n******************************";
  std::cout << "\n- ";
}

void ChatManager::selector_chat(int &opcion, bool &continuar)
{
  mostrar_opciones();
  std::cin >> opcion;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (opcion)
  {
  case 1:
    seleccionar_personaje();
    break;
  case 2:
    interactuar_personaje();
    break;
  case 3:
    administrar_boveda();
    break;
  case 4:
    administrar_transformers();
    break;
  case 5:
    juego_manager.empezar_combate(transformers_manager.obtener_transformers_boveda());
    break;
  case 7:
    continuar = false;
    break;
  default:
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nOpción inválida";
    break;
  }

  opcion = -1;
}

void ChatManager::seleccionar_personaje()
{
  juego_manager.elegir_personaje();

  PERSONAJE personaje = juego_manager.obtener_personaje();

  if (personaje == OPTIMUS)
  {
    juego_manager.cambiar_poder(optimus.obtener_poder());
  }
  else
  {
    juego_manager.cambiar_poder(megatron.obtener_poder());
  }
}

void ChatManager::iniciar_chat()
{
  int opcion = -1;
  bool continuar = true;

  juego_manager.pedir_nombre();

  juego_manager.elegir_personaje();

  while (continuar)
  {
    selector_chat(opcion, continuar);
  }
}

// INTERACTUAR CON PERSONAJE

void ChatManager::interactuar_optimus()
{
  int opcion = -1;
  std::cout << "\n******************************";
  std::cout << "\n1- Optimus";
  std::cout << "\n2- Pedir consejo de fusion a Optimus";
  std::cout << "\n3- Cambiar animo de Optimus";
  std::cout << "\n******************************";
  std::cout << "\n- ";
  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (opcion)
  {
  case 1:
    iniciar_chat_optimus();
    break;
  case 2:
    optimus.sugerir_fusion();
    break;
  case 3:
    cambiar_animo_optimus();
    break;
  default:
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nOpción inválida";
  }
}

void ChatManager::interactuar_megatron()
{
  int opcion = -1;
  std::cout << "\n******************************";
  std::cout << "\n1- Megatron";
  std::cout << "\n2- Pedir consejo de fusion a Megatron";
  std::cout << "\n3- Cambiar intencion de Megatron";
  std::cout << "\n******************************";
  std::cout << "\n- ";
  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (opcion)
  {
  case 1:
    iniciar_chat_megatron();
    break;
  case 2:
    megatron.sugerir_fusion();
    break;
  case 3:
    cambiar_intencion_megatron();
    break;
  default:
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nOpción inválida";
  }
}

void ChatManager::interactuar_personaje()
{
  PERSONAJE personaje = juego_manager.obtener_personaje();
  if (personaje == OPTIMUS)
  {
    interactuar_optimus();
  }
  else
  {
    interactuar_megatron();
  }
}

// CRISTALES

void ChatManager::administrar_boveda()
{
  bool continuar = true;

  std::cout << "\n|Administrar Boveda|";
  while (continuar)
  {
    juego_manager.administrar_boveda_cristales(continuar);
  }
}

// TRANSFORMERS
void ChatManager::administrar_transformers()
{
  bool continuar = true;

  std::cout << "\n|Administrar Transformers|";
  while (continuar)
  {
    transformers_manager.administrar_transformers(continuar);
  }
}

// CHATS
void ChatManager::iniciar_chat_optimus()
{
  bool continuar_chat = true;
  std::string oracion;

  std::cout << "\n|Chat Optimus|";
  while (continuar_chat)
  {
    std::cout << "\nUsuario- ";
    std::getline(std::cin, oracion);

    if (oracion == "salir")
    {
      continuar_chat = false;
    }
    else
    {
      std::cout << "Optimus- ";
      optimus.responder(oracion);
    }
  }
}

void ChatManager::iniciar_chat_megatron()
{
  bool continuar_chat = true;
  std::string oracion;

  std::cout << "\n|Chat Megatron|";
  while (continuar_chat)
  {
    std::cout << "\nUsuario- ";
    std::getline(std::cin, oracion);

    if (oracion == "salir")
    {
      continuar_chat = false;
    }
    else
    {
      std::cout << "Megatron- ";
      megatron.responder(oracion);
    }
  }
}

// ANIMO / INTENCION
void ChatManager::cambiar_animo_optimus()
{
  int opcion;
  std::string animo = "";

  mostrar_opciones_animo();

  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (opcion)
  {
  case 1:
    animo = "sereno";
    break;
  case 2:
    animo = "determinado";
    break;
  case 3:
    animo = "enfurecido";
    break;
  default:
    std::cout << "\nOpción invalida";
    return;
  }

  if (animo != "")
  {
    optimus.cambiar_animo(animo);
    std::cout << "\n------------------";
    std::cout << "\nAnimo cambio a " << animo;
    std::cout << "\n------------------";
  }
}

void ChatManager::cambiar_intencion_megatron()
{
  int opcion;
  std::string intencion = "";

  mostrar_opciones_intencion();

  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (opcion)
  {
  case 1:
    intencion = "desprecio";
    break;
  case 2:
    intencion = "manipulacion";
    break;
  case 3:
    intencion = "amenaza";
    break;
  default:
    std::cout << "\nOpción invalida";
    return;
  }

  if (intencion != "")
  {
    megatron.cambiar_intencion(intencion);
    std::cout << "\n------------------";
    std::cout << "\nIntencion cambio a " << intencion;
    std::cout << "\n------------------";
  }
}
