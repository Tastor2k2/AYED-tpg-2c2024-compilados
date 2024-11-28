#ifndef BOVEDA_FORMERS_HPP
#define BOVEDA_FORMERS_HPP

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Transformer.hpp"

class ExcepcionBovedaTransformers : public std::runtime_error
{
    // Excepcion para errores dentro de la clase BovedaTransformers.
public:
    ExcepcionBovedaTransformers(std::string mensaje) : runtime_error(mensaje) {}

    ExcepcionBovedaTransformers() : runtime_error("") {}
};

class BovedaTransformers
{
private:
    static const size_t CANTIDAD_ATRIBUTOS;
    Vector<Transformer> transformers;

    // Pre: -
    // Post: Carga todos los transformers del archivo "transformers.csv" en el vector "vec_transformers".
    void cargar_transformers();

    // Pre: -
    // Post: Exporta los transformers almacenados en "vec_transformers" al archvo "transformers.csv".
    void exportar_transformers();

public:
    // Constructor.
    BovedaTransformers();

    // Destructor.
    ~BovedaTransformers();

    // Pre: -
    // Post: Crea o actualiza en base al nombre un transformer en la boveda.
    void almacenar_transformer(Transformer transformer);

    // Pre: -
    // Post: Devuelve la cantidad de transformers almacenados en la boveda.
    size_t cantidad_transformers();

    // Pre: La posicion debe ser menor al tamanio actual de la boveda.
    // Post: Muestra el transformer en la posicion indicada.
    void mostrar_transformer(size_t posicion);

    // Pre: -
    // Post: Muestra los transformers en la boveda.
    void mostrar_transformers();

    // Pre: -
    // Post: Devuelve la posicion del transformer con ese nombre, o -1 de no encontrarse
    int obtener_posicion_transformer(std::string nombre);

    // Pre: La posicion debe ser menor al tamanio actual de la boveda.
    // Post: Transforma el transformer en la posicion indicada.
    void transformar(size_t posicion);

    // Pre: La posicion debe ser menor al tamanio actual de la boveda.
    // Post: Elimina y devuelve el transformer en la posicion indicada.
    Transformer eliminar_transformer(size_t posicion);

    // Pre: -
    // Post: Devuelve un vector de transformers de la boveda.
    Vector<Transformer> obtener_transformers();
};

#endif
