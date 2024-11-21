#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP

#include "Vector.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>

class ExcepcionTransformer : public std::runtime_error {
    // Excepcion para errores dentro de la clase transformer.
    public:
    ExcepcionTransformer(std::string mensaje) : runtime_error(mensaje) {}

    ExcepcionTransformer(): runtime_error("") {}
};

enum Faccion {
    AUTOBOT,
    DECEPTICON
};

enum Vehiculo {
    AUTO,
    CAMION,
    TANQUE,
    AVION
};

class Transformer {
private:
    const size_t CANTIDAD_ATRIBUTOS = 7;
    Faccion faccion;
    Vehiculo vehiculo;
    std::string nombre;
    size_t fuerza, defensa, velocidad;
    bool transformado; // si es true, esta en su forma de vehiculo.
    Vector<std::string> transformers_atributos;
    Vector<Vector <std::string> > transformers;
public:
    // Constructor
    Transformer(std::string nombre, size_t fuerza, size_t defensa, size_t velocidad, Faccion faccion, Vehiculo vehiculo, bool transformado);
    // Pre: -
    // Post: Transforma al transformer en su vehiculo o en su forma robotica segun corresponda.
    void transformar(); // los numeros de las stats pueden ser contantes, valores a definir.
    // Pre: -
    // Post: Exporta los transformers creados al archvo "transformers.csv"
    void exportar_transformer();
    // Pre: -
    // Post: Carga los transformers del archivo "transformers.csv" en un vector de vectores.
    Vector<Vector <std::string> > cargar_transformers();
};

#endif
