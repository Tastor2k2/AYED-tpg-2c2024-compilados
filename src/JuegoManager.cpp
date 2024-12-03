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

void JuegoManager::administrar_boveda_transformers(bool &continuar)
{
    transformers_manager.administrar_transformers(continuar);
}

size_t JuegoManager::calcular_peso(Transformer rival)
{
    size_t peso;
    if (rival.obtener_faccion() == static_cast<Faccion>(personaje_seleccionado))
    {
        peso = PESO_ENERGON_ALIADO;
    }
    else
    {
        peso = PESO_ENERGON_ENEMIGO_BASE + (rival.obtener_poder()) - (poder_personaje);
        if (peso < PESO_ENERGON_ENEMIGO_MIN)
        {
            peso = PESO_ENERGON_ENEMIGO_MIN;
        }
        else if (peso > PESO_ENERGON_ENEMIGO_MAX)
        {
            peso = PESO_ENERGON_ENEMIGO_MAX;
        }
    }

    return peso;
}

Grafo JuegoManager::generar_mapa_combates()
{
    Vector<Transformer> transformers = transformers_manager.obtener_transformers_boveda();
    size_t cantidad_transformers = transformers.tamanio();

    Grafo grafo_caminos(transformers.tamanio() + 2);

    size_t filas = (cantidad_transformers + 2) / 3;

    // Conectar el personaje principal con todos los transformers en la primera fila
    size_t primera_fila = std::min(size_t(3), cantidad_transformers);
    for (size_t i = 0; i < primera_fila; i++)
    {
        grafo_caminos.agregar_arista(0, i + 1, static_cast<int>(calcular_peso(transformers[i])));
    }

    size_t inicio_actual, inicio_siguiente, tam_actual, tam_siguiente, origen, destino;

    // Conectar cada transformer con todos los transformers de la siguiente fila
    for (size_t fila = 0; fila < filas - 1; fila++)
    {
        inicio_actual = fila * 3;
        inicio_siguiente = (fila + 1) * 3;
        tam_actual = std::min(cantidad_transformers - inicio_actual, size_t(3));
        tam_siguiente = std::min(cantidad_transformers - inicio_siguiente, size_t(3));

        for (size_t col = 0; col < tam_actual; col++)
        {
            origen = inicio_actual + col + 1;
            for (size_t next_col = 0; next_col < tam_siguiente; next_col++)
            {
                destino = inicio_siguiente + next_col + 1;
                grafo_caminos.agregar_arista(origen, destino, static_cast<int>(calcular_peso(transformers[destino - 1])));
            }
        }
    }

    // Conectar el jefe final con todos los transformers de la última fila
    size_t inicio_ultima_fila = (filas - 1) * 3;
    size_t tam_ultima_fila = std::min(cantidad_transformers - inicio_ultima_fila, size_t(3));
    for (size_t i = 0; i < tam_ultima_fila; i++)
    {
        size_t nodo_ultima_fila = inicio_ultima_fila + i + 1;
        grafo_caminos.agregar_arista(nodo_ultima_fila, cantidad_transformers + 1, 0);
    }

    return grafo_caminos;
}

Vector<size_t> JuegoManager::obtener_pesos_vertices(Grafo mapa_combates, Camino camino)
{
    Vector<size_t> pesos;

    for (size_t i = 0; i < camino.camino.tamanio() - 1; i++)
    {
        pesos.alta(mapa_combates.peso_entre_vertices(camino.camino[i], camino.camino[i + 1]));
    }

    return pesos;
}

void JuegoManager::empezar_combate()
{
    Grafo mapa_combates = generar_mapa_combates();

    mapa_combates.usar_dijkstra();
    Camino camino = mapa_combates.obtener_camino_minimo(0, transformers_manager.obtener_cantidad_transformers() + 1);
    Vector<size_t> pesos = obtener_pesos_vertices(mapa_combates, camino);

}
