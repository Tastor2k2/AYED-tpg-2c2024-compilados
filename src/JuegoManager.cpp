#include "JuegoManager.hpp"

JuegoManager::JuegoManager()
{
}

void JuegoManager::mostrar_opciones_personajes()
{
    std::cout << "\n******************************";
    std::cout << "\n|Elegir Personaje|";
    std::cout << "\n1. Optimus Prime";
    std::cout << "\n2. Megatron";
    std::cout << "\n******************************";
    std::cout << "\n- ";
}

void JuegoManager::pedir_nombre()
{
    std::cout << "\n|Bienvenido a Transformers Edicion Compilados inc.|";
    std::cout << "\nIngrese su nombre: ";
    std::getline(std::cin, nombre_usuario);
}

std::string JuegoManager::obtener_personaje_string()
{
    std::string nombre = "Megatron";
    if (personaje_seleccionado == OPTIMUS)
    {
        nombre = "Optimus Prime";
    }

    return nombre;
}

PERSONAJE JuegoManager::obtener_personaje()
{
    return personaje_seleccionado;
}

void JuegoManager::elegir_personaje()
{
    int opcion = -1;

    while (opcion != 1 && opcion != 2)
    {
        mostrar_opciones_personajes();

        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcion != 1 && opcion != 2)
        {
            std::cout << "Opcion no valida";
        }
    }

    personaje_seleccionado = static_cast<PERSONAJE>(opcion - 1);
}

std::optional<Cristal> JuegoManager::obtener_cristal()
{
    if (cristal_seleccionado.has_value())
    {
        cristal_seleccionado.value().mostrar_estadisticas();
    }

    return cristal_seleccionado;
};

void JuegoManager::administrar_boveda_cristales(bool &continuar)
{

    boveda_manager.administrar_boveda(continuar, cristal_seleccionado);
    obtener_cristal();
}

size_t JuegoManager::obtener_poder()
{
    return poder_personaje;
}

void JuegoManager::cambiar_poder(size_t poder)
{
    this->poder_personaje = poder;
}

void JuegoManager::empezar_combate(Vector<Transformer> transformers)
{
    size_t cantidad_transformers = transformers_manager.obtener_cantidad_transformers();
    Combate combate(personaje_seleccionado, poder_personaje, cantidad_transformers);
    combate.crear_grafo(cantidad_transformers, poder_personaje, transformers);
}