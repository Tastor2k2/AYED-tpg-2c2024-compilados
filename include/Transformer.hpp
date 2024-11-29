#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP

#include "Vector.hpp"
#include <stdexcept>

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

    // Constructor
    Transformer(std::string nombre, size_t fuerza, size_t defensa, size_t velocidad, Faccion faccion, Vehiculo vehiculo, bool transformado);

    // Pre: -
    // Post: Transforma al transformer en su vehiculo o en su forma robotica segun corresponda.
    void transformar();

    // Pre: -
    // Post: Getter del nombre del transformer.
    std::string obtener_nombre();

    // Pre: -
    // Post: Getter del atributo fuerza del transformer.
    size_t obtener_fuerza();

    // Pre: -
    // Post: Getter del atributo defensa del transformer.
    size_t obtener_defensa();

    // Pre: -
    // Post: Getter del atributo velocidad del transformer.
    size_t obtener_velocidad();

    // Pre: -
    // Post: Getter de la faccion del transformer.
    Faccion obtener_faccion();

    // Pre: -
    // Post: Getter del vehiculo del transformer.
    Vehiculo obtener_vehiculo();

    // Pre: -
    // Post: Retorna true si esta transformado en su vehiculo, false si esta en su forma robotica.
    bool esta_transformado();
};

#endif
