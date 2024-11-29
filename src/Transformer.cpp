#include "Transformer.hpp"

const size_t Transformer::PLUS_FUERZA_AUTO = 30;
const size_t Transformer::PLUS_DEFENZA_AUTO = 15;
const size_t Transformer::PLUS_VELOCIDAD_AUTO = 60;
const size_t Transformer::PLUS_FUERZA_CAMION = 20;
const size_t Transformer::PLUS_DEFENZA_CAMION = 55;
const size_t Transformer::PLUS_VELOCIDAD_CAMION = 35;
const size_t Transformer::PLUS_FUERZA_AVION = 100;
const size_t Transformer::PLUS_DEFENZA_AVION = 100;
const size_t Transformer::PLUS_VELOCIDAD_AVION = 20;
const size_t Transformer::PLUS_FUERZA_TANQUE = 30;
const size_t Transformer::PLUS_DEFENZA_TANQUE = 80;
const size_t Transformer::PLUS_VELOCIDAD_TANQUE = 100;

Transformer::Transformer() : Transformer("BOT", 15, 10, 20, AUTOBOT, AUTO, false) {}

Transformer::Transformer(std::string nombre, size_t fuerza, size_t defensa, size_t velocidad, Faccion faccion, Vehiculo vehiculo, bool transformado) {
    if (faccion == AUTOBOT && (vehiculo == TANQUE || velocidad == AVION)) {
        throw ExcepcionTransformer("No se puede crear un autobot que sea tanque o avion.");
    } else if (faccion == DECEPTICON && (vehiculo == AUTO || velocidad == CAMION)) {
        throw ExcepcionTransformer("No se puede crear un decepticon que sea auto o camion.");
    }
    this->nombre = nombre;
    this->fuerza = fuerza;
    this->defensa = defensa;
    this->velocidad = velocidad;
    this->faccion = faccion;
    this->vehiculo = vehiculo;
    this->transformado = transformado;
}

size_t Transformer::limitar_valores(int calculo) {
    if (calculo < 0) {
        return 0;
    }
    return calculo;
}


void Transformer::transformar() {
    if (!esta_transformado()) {
        this->transformado = true;
        switch (vehiculo) {
            case AUTO:
                this->fuerza = limitar_valores(static_cast<int>(fuerza - PLUS_FUERZA_AUTO));
                this->defensa = limitar_valores(static_cast<int>(defensa - PLUS_DEFENZA_AUTO));
                this->velocidad = limitar_valores(static_cast<int>(velocidad + PLUS_VELOCIDAD_AUTO));
                break;
            case CAMION:
                this->fuerza = limitar_valores(static_cast<int>(fuerza - PLUS_FUERZA_CAMION));
                this->defensa = limitar_valores(static_cast<int>(defensa + PLUS_DEFENZA_CAMION));
                this->velocidad = limitar_valores(static_cast<int>(velocidad - PLUS_VELOCIDAD_CAMION));
                break;
            case TANQUE:
                this->fuerza = limitar_valores(static_cast<int>(fuerza + PLUS_FUERZA_TANQUE));
                this->defensa = limitar_valores(static_cast<int>(defensa + PLUS_DEFENZA_TANQUE));
                this->velocidad = limitar_valores(static_cast<int>(velocidad - PLUS_VELOCIDAD_TANQUE));
                break;
            case AVION:
                this->fuerza = limitar_valores(static_cast<int>(fuerza + PLUS_FUERZA_AVION));
                this->defensa = limitar_valores(static_cast<int>(defensa - PLUS_DEFENZA_AVION));
                this->velocidad = limitar_valores(static_cast<int>(velocidad + PLUS_VELOCIDAD_AVION));
                break;
        }
    } else {
        this->transformado = false;
        switch (vehiculo) {
            case AUTO:
                this->fuerza = limitar_valores(static_cast<int>(fuerza + PLUS_FUERZA_AUTO));
                this->defensa = limitar_valores(static_cast<int>(defensa + PLUS_DEFENZA_AUTO));
                this->velocidad = limitar_valores(static_cast<int>(velocidad - PLUS_VELOCIDAD_AUTO));
                break;
            case CAMION:
                this->fuerza = limitar_valores(static_cast<int>(fuerza + PLUS_FUERZA_CAMION));
                this->defensa = limitar_valores(static_cast<int>(defensa - PLUS_DEFENZA_CAMION));
                this->velocidad = limitar_valores(static_cast<int>(velocidad + PLUS_VELOCIDAD_CAMION));
                break;
            case TANQUE:
                this->fuerza = limitar_valores(static_cast<int>(fuerza - PLUS_FUERZA_TANQUE));
                this->defensa = limitar_valores(static_cast<int>(defensa - PLUS_DEFENZA_TANQUE));
                this->velocidad = limitar_valores(static_cast<int>(velocidad + PLUS_VELOCIDAD_TANQUE));
                break;
            case AVION:
                this->fuerza = limitar_valores(static_cast<int>(fuerza - PLUS_FUERZA_AVION));
                this->defensa = limitar_valores(static_cast<int>(defensa + PLUS_DEFENZA_AVION));
                this->velocidad = limitar_valores(static_cast<int>(velocidad - PLUS_VELOCIDAD_AVION));
                break;
        }
    }
}

std::string Transformer::obtener_nombre() {
    return nombre;
}

size_t Transformer::obtener_fuerza() {
    return fuerza;
}

size_t Transformer::obtener_defensa() {
    return defensa;
}

size_t Transformer::obtener_velocidad() {
    return velocidad;
}

Faccion Transformer::obtener_faccion() {
    return faccion;
}

Vehiculo Transformer::obtener_vehiculo() {
    return vehiculo;
}

bool Transformer::esta_transformado() {
    return transformado;
}