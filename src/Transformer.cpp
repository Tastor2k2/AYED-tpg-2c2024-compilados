#include "Transformer.hpp"

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

void Transformer::transformar() {
    if (!transformado) {
        this->transformado = true;
        switch (vehiculo) {
            case AUTO:
                this->fuerza = fuerza - 30;
                this->defensa = defensa - 10;
                this->velocidad = velocidad + 60;
                break;
            case CAMION:
                this->fuerza = fuerza - 10;
                this->defensa = defensa + 50;
                this->velocidad = velocidad - 35;
                break;
            case TANQUE:
                this->fuerza = fuerza + 30;
                this->defensa = defensa + 80;
                this->velocidad = velocidad - 100;
                break;
            case AVION:
                this->fuerza = fuerza + 100;
                this->defensa = defensa - 100;
                this->velocidad = velocidad + 20;
                break;
        }
    } else {
        this->transformado = false;
        switch (vehiculo) {
            case AUTO:
                this->fuerza = fuerza + 30;
                this->defensa = defensa + 10;
                this->velocidad = velocidad - 60;
                break;
            case CAMION:
                this->fuerza = fuerza + 10;
                this->defensa = defensa - 50;
                this->velocidad = velocidad + 35;
                break;
            case TANQUE:
                this->fuerza = fuerza - 30;
                this->defensa = defensa - 80;
                this->velocidad = velocidad + 100;
                break;
            case AVION:
                this->fuerza = fuerza - 100;
                this->defensa = defensa + 100;
                this->velocidad = velocidad - 20;
                break;
        }
    }
}

void Transformer::exportar_transformer() {
    std::ofstream archivo("archivos_csv/transformers.csv", std::ios::app);
    if (archivo.is_open()) {
        archivo << nombre << ","
                << fuerza << ","
                << defensa << ","
                << velocidad << ","
                << (faccion == AUTOBOT ? "AUTOBOT" : "DECEPTICON") << ","
                << (vehiculo == AUTO ? "AUTO" : (vehiculo == CAMION ? "CAMION" : (vehiculo == TANQUE ? "TANQUE" : "AVION"))) << ","
                << (transformado ? "SI" : "NO") <<"\n";
        archivo.close();
    } else {
        throw ExcepcionTransformer("Error al abrir archivo");
    }
}

Vector<Vector <std::string> > Transformer::cargar_transformers() {
    std::ifstream archivo("archivos_csv/transformers.csv");
    std::string linea;
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            while (getline(archivo, linea, ',')) {
                transformers_atributos.alta(linea);
            }
            transformers.alta(transformers_atributos);
            for (size_t i = 0; i < CANTIDAD_ATRIBUTOS; i++) {
                transformers_atributos.baja();
            }
        }
        return transformers;
    } else {
        throw ExcepcionTransformer("Error al abrir archivo");
    }
}

