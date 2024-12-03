#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP

#include "Vector.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>

class ExcepcionTransformer : public std::runtime_error
{
    // Excepcion para errores dentro de la clase transformer.
public:
    ExcepcionTransformer(std::string mensaje) : runtime_error(mensaje) {}

    ExcepcionTransformer() : runtime_error("") {}
};

struct Estadisticas
{
    size_t fuerza;
    size_t defensa;
    size_t velocidad;

    void operator+=(const Estadisticas &otra)
    {
        fuerza = fuerza + otra.fuerza;
        defensa = defensa + otra.defensa;
        velocidad = velocidad + otra.velocidad;
    }
};

enum Faccion
{
    AUTOBOT,
    DECEPTICON
};

enum Vehiculo
{
    AUTO,
    CAMION,
    TANQUE,
    AVION
};

class Transformer
{
private:
    static const size_t PLUS_FUERZA_AUTO;
    static const size_t PLUS_DEFENZA_AUTO;
    static const size_t PLUS_VELOCIDAD_AUTO;
    static const size_t PLUS_FUERZA_CAMION;
    static const size_t PLUS_DEFENZA_CAMION;
    static const size_t PLUS_VELOCIDAD_CAMION;
    static const size_t PLUS_FUERZA_AVION;
    static const size_t PLUS_DEFENZA_AVION;
    static const size_t PLUS_VELOCIDAD_AVION;
    static const size_t PLUS_FUERZA_TANQUE;
    static const size_t PLUS_DEFENZA_TANQUE;
    static const size_t PLUS_VELOCIDAD_TANQUE;
    static const std::string facciones[];
    static const std::string vehiculos[];
    Faccion faccion;
    Vehiculo vehiculo;
    std::string nombre;
    size_t fuerza, defensa, velocidad;
    bool transformado;

    // Pre: -
    // Post: Devuelve cero si a la hora de cambiar estadisticas el calculo arroja un numero negativo.
    size_t limitar_valores(int calculo);

public:
    // Constructor por defecto
    Transformer();

    // Constructor por atributos
    Transformer(std::string nombre, size_t fuerza, size_t defensa, size_t velocidad, Faccion faccion, Vehiculo vehiculo, bool transformado);

    // Constructor por atributos en formato csv
    Transformer(std::string atributos_csv);

    // Pre: -
    // Post: Invierte el valor de transformado.
    void transformar();

    // Pre: -
    // Post: Getter del nombre del transformer.
    std::string obtener_nombre();

    // PRE: -
    // POST: Devuelve las estadisticas del transformer.
    Estadisticas obtener_estadisticas();

    // Pre: -
    // Post: Getter de la faccion del transformer.
    Faccion obtener_faccion();

    // Pre: -
    // Post: Getter de la faccion del transformer en formato string.
    std::string obtener_cadena_faccion();

    // Pre: -
    // Post: Getter del vehiculo del transformer.
    Vehiculo obtener_vehiculo();

    // Pre: -
    // Post: Getter del vehiculo del transformer en formato string.
    std::string obtener_cadena_vehiculo();

    // Pre: -
    // Post: Retorna true si esta transformado.
    bool esta_transformado();

    // Pre: -
    // Post: Muestra los detalles del transformer en consola.
    void mostrar_detalle();

    // Pre: -
    // Post: Getter del poder del transformer (suma de sus atributos).
    size_t obtener_poder();
};

#endif
