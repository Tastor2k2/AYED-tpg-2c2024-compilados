#include "BovedaTransformers.hpp"

const size_t BovedaTransformers::CANTIDAD_ATRIBUTOS = 7;

BovedaTransformers::BovedaTransformers()
{
    cargar_transformers();
}

BovedaTransformers::~BovedaTransformers()
{
    exportar_transformers();
}

void BovedaTransformers::exportar_transformers()
{
    std::ofstream archivo("archivos_csv/transformers.csv");
    std::string linea;
    Vector<std::string> lineas;
    if (archivo.is_open())
    {
        if (transformers.vacio())
        {
            std::cout << "\n--------------------------------";
            std::cout << "\nNo hay transformers en la boveda para exportar";
            std::cout << "\n--------------------------------";
        }
        else
        {
            for (size_t i = 0; i < transformers.tamanio(); i++)
            {
                archivo << transformers[i].obtener_nombre() << ","
                        << transformers[i].obtener_fuerza() << ","
                        << transformers[i].obtener_defensa() << ","
                        << transformers[i].obtener_velocidad() << ","
                        << transformers[i].obtener_faccion() << ","
                        << transformers[i].obtener_vehiculo() << ","
                        << transformers[i].esta_transformado() << "\n";
            }
        }
        archivo.close();
    }
    else
    {
        throw ExcepcionBovedaTransformers("Error al abrir archivo");
    }
}

void BovedaTransformers::cargar_transformers()
{
    std::ifstream archivo("archivos_csv/transformers.csv");
    std::string linea;

    if (!archivo.is_open())
    {
        throw ExcepcionBovedaTransformers("Error al abrir archivo");
    }

    while (getline(archivo, linea))
    {
        transformers.alta(Transformer(linea));
    }

    archivo.close();
}

void BovedaTransformers::almacenar_transformer(Transformer transformer)
{
    int posicion = obtener_posicion_transformer(transformer.obtener_nombre());
    std::cout << "\n--------------------------------";
    if (posicion < 0)
    {
        std::cout << "\nTransformer añadido";
        transformers.alta(transformer);
    }
    else
    {
        std::cout << "\nTransformer actualizado";
        transformers[static_cast<size_t>(posicion)] = transformer;
    }
    std::cout << "\n--------------------------------";
}

void BovedaTransformers::mostrar_transformer(size_t posicion)
{
    if (posicion >= transformers.tamanio())
    {
        throw ExcepcionBovedaTransformers("Posicion fuera de rango al mostrar el transformer.");
    }
    else
    {
        Transformer transformer = transformers[posicion];
        transformer.mostrar_detalle();
    }
}

void BovedaTransformers::mostrar_transformers()
{
    std::cout << "\n###################################";
    std::cout << "\nMostrar Transformers";
    if (transformers.vacio())
    {
        std::cout << "\nNo hay transformers en la boveda para mostrar";
        std::cout << "\n--------------------------------";
    }
    else
    {
        for (size_t i = 0; i < transformers.tamanio(); i++)
        {
            Transformer transformer = transformers[i];
            std::cout << "\n--------------------------------";
            transformer.mostrar_detalle();
        }
        std::cout << "\n--------------------------------";
        std::cout << "\n###################################";
    }
}

int BovedaTransformers::obtener_posicion_transformer(std::string nombre)
{
    int posicion = -1;
    size_t i = 0;
    while (i < transformers.tamanio() && posicion == -1)
    {
        if (transformers[i].obtener_nombre() == nombre)
        {
            posicion = static_cast<int>(i);
        }
        i++;
    }

    return posicion;
}

Transformer BovedaTransformers::eliminar_transformer(size_t posicion)
{
    return transformers.baja(posicion);
}

size_t BovedaTransformers::cantidad_transformers()
{
    return transformers.tamanio();
}