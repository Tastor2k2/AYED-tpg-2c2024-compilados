#ifndef BOVEDATRANSFORMERS_HPP
#define BOVEDATRANSFORMERS_HPP

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Transformer.hpp"

class ExcepcionBovedaTransformers : public std::runtime_error {
    // Excepcion para errores dentro de la clase BovedaTransformers.
public:
    ExcepcionBovedaTransformers(std::string mensaje) : runtime_error(mensaje) {}

    ExcepcionBovedaTransformers(): runtime_error("") {}
};

class BovedaTransformers {
private:
    static const size_t CANTIDAD_ATRIBUTOS;
    Vector<Transformer> boveda_transformers;

    // Pre: -
    // Post: Convierte las cadenas a datos de tipo enum faccion.
    Faccion cadena_a_faccion(const std::string& faccion);

    // Pre: -
    // Post: Convierte el tipo del dato faccion a tipo string.
    std::string faccion_a_cadena(Faccion faccion);

    // Pre: -
    // Post: Convierte las cadenas a datos de tipo enum vehiculo.
    Vehiculo cadena_a_vehiculo(const std::string& vehiculo);

    // Pre: -
    // Post: Convierte el tipo del dato vehiculo a tipo string.
    std::string vehiculo_a_cadena(Vehiculo vehiculo);

    // Pre: -
    // Post: Convierte las cadenas a datos de tipo booleano.
    bool cadena_a_booleano(const std::string& booleano);

    // Pre: -
    // Post: Exporta los transformers almacenados en "vec_transformers" al archvo "transformers.csv".
    void exportar_transformers();

    // Pre: -
    // Post: Carga todos los transformers del archivo "transformers.csv" en el vector "vec_transformers".
    void cargar_transformers();

public:

    // Constructor
    BovedaTransformers();

    ~BovedaTransformers();

    // Pre: No se pueden almacenar transformers que tengan el mismo nombre.
    // Post: Almacena el transformer recibido por parametro en la boveda.
    void almacenar_transformer(Transformer transformer);

    // Pre: -
    // Post: Devuelve la cantidad de transformers almacenados en la boveda.
    size_t cantidad_transformers();

    // Pre: La posicion debe ser menor al tamanio actual de la boveda.
    void mostrar_transformer(size_t posicion);

    // Pre: -
    // Post: Muestra los transformers en la boveda.
    void mostrar_transformers();

    // Pre: La posicion debe ser menor al tamanio actual de la boveda.
    // Post: Devuelve el transformer en la posicion indicada y lo quita de la boveda.
    Transformer obtener_transformer(size_t posicion);

    // Pre: La posicion debe ser menor al tamanio actual del vector y mayor a cero.
    // Post: Devuelve la faccion del transformer en la posicion indicada.
    Faccion obtener_faccion_transformer(size_t posicion);
};

#endif
