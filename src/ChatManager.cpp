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

  switch (opcion - 1)
  {
  case SELECCIONAR_PERSONAJE:
    seleccionar_personaje();
    break;
  case INTERACTUAR_PERSONAJE:
    interactuar_personaje();
    break;
  case ADMINISTRAR_BOVEDA:
    administrar_boveda();
    break;
  case ADMINISTRAR_TRANSFORMERS:
    administrar_transformers();
    break;
  case INICIAR_BATALLA:
    juego_manager.empezar_combate();
    break;
  case TABLA_CLASIFICACION:
    juego_manager.mostrar_puntajes();
    break;
  case SALIR:
    continuar = false;
    break;
  default:
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nOpción inválida";
  }

  opcion = -1;
}

void ChatManager::seleccionar_personaje()
{
  juego_manager.elegir_personaje();

  Personaje personaje = juego_manager.obtener_personaje();

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

  switch (opcion - 1)
  {
  case CHATEAR:
    iniciar_chat_optimus();
    break;
  case PEDIR_CONSEJO_FUSION:
    optimus.sugerir_fusion();
    break;
  case CAMBIAR_ANIMO_INTENCION:
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

  switch (opcion - 1)
  {
  case CHATEAR:
    iniciar_chat_megatron();
    break;
  case PEDIR_CONSEJO_FUSION:
    megatron.sugerir_fusion();
    break;
  case CAMBIAR_ANIMO_INTENCION:
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
  Personaje personaje = juego_manager.obtener_personaje();
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
    juego_manager.administrar_boveda_transformers(continuar);
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

  switch (opcion - 1)
  {
  case SERENO:
    animo = "sereno";
    break;
  case DETERMINADO:
    animo = "determinado";
    break;
  case ENFURECIDO:
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

  switch (opcion - 1)
  {
  case DESPRECIO:
    intencion = "desprecio";
    break;
  case MANIPULACION:
    intencion = "manipulacion";
    break;
  case AMENAZA:
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
