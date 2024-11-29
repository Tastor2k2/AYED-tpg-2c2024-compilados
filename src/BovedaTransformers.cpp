#include "BovedaTransformers.hpp"

const size_t BovedaTransformers::CANTIDAD_ATRIBUTOS = 7;

BovedaTransformers::BovedaTransformers() {
    cargar_transformers();
}

BovedaTransformers::~BovedaTransformers() {
    exportar_transformers();
}

Faccion BovedaTransformers::cadena_a_faccion(const std::string& faccion) {
    if (faccion == "AUTOBOT") {
        return AUTOBOT;
    }
    if (faccion == "DECEPTICON") {
        return DECEPTICON;
    }
    throw ExcepcionBovedaTransformers("Faccion desconocida.");
}

std::string BovedaTransformers::faccion_a_cadena(Faccion faccion) {
    return (faccion == AUTOBOT) ? "AUTOBOT" : "DECEPTICON";
}

Vehiculo BovedaTransformers::cadena_a_vehiculo(const std::string& vehiculo) {
    if (vehiculo == "AUTO") {
        return AUTO;
    }
    if (vehiculo == "CAMION") {
        return CAMION;
    }
    if (vehiculo == "AVION") {
        return AVION;
    }
    if (vehiculo == "TANQUE") {
        return TANQUE;
    }
    throw ExcepcionBovedaTransformers("Error al obtener el vehiculo.");
}

std::string BovedaTransformers::vehiculo_a_cadena(Vehiculo vehiculo) {
    switch (vehiculo) {
        case AUTO:
            return "AUTO";
        case CAMION:
            return "CAMION";
        case TANQUE:
            return "TANQUE";
        case AVION:
            return "AVION";
        default:
            throw ExcepcionBovedaTransformers("Vehiculo desconocido.");
    }
}

bool BovedaTransformers::cadena_a_booleano(const std::string& booleano) {
    return booleano == "SI";
}

void BovedaTransformers::exportar_transformers() {
    std::ofstream archivo("archivos_csv/transformers.csv");
    std::string linea;
    Vector<std::string> lineas;
    if (archivo.is_open()) {
        if (boveda_transformers.vacio()) {
            std::cout << "No hay transformers en la boveda para exportar" << std::endl;
            std::cout << "------------------" << std::endl;
        } else {
            for (size_t i = 0; i < boveda_transformers.tamanio(); i++) {
                archivo << boveda_transformers[i].obtener_nombre() << ","
                    << boveda_transformers[i].obtener_fuerza() << ","
                    << boveda_transformers[i].obtener_defensa() << ","
                    << boveda_transformers[i].obtener_velocidad() << ","
                    << faccion_a_cadena(boveda_transformers[i].obtener_faccion()) << ","
                    << vehiculo_a_cadena(boveda_transformers[i].obtener_vehiculo()) << ","
                    << (boveda_transformers[i].esta_transformado() ? "SI" : "NO") <<"\n";
            }
        }
        archivo.close();
    } else {
        throw ExcepcionBovedaTransformers("Error al abrir archivo");
    }
}

void BovedaTransformers::cargar_transformers() {
    std::ifstream archivo("archivos_csv/transformers.csv");
    std::string linea, nombre;
    Vector<std::string> transformers_atributos_archivo;
    size_t fuerza, defensa, velocidad;
    Faccion faccion;
    Vehiculo vehiculo;
    bool transformado;
    if (archivo.is_open()) {
        std::istringstream ss;
        while (getline(archivo, linea)) {
            if (!linea.empty()) {
                ss.str(linea);
                ss.clear();
                while (getline(ss, linea, ',')) {
                    transformers_atributos_archivo.alta(linea);
                }
                nombre = transformers_atributos_archivo[0];
                fuerza = std::stoul(transformers_atributos_archivo[1]);
                defensa = std::stoul(transformers_atributos_archivo[2]);
                velocidad = std::stoul(transformers_atributos_archivo[3]);
                faccion = cadena_a_faccion(transformers_atributos_archivo[4]);
                vehiculo = cadena_a_vehiculo(transformers_atributos_archivo[5]);
                transformado = cadena_a_booleano(transformers_atributos_archivo[6]);
                boveda_transformers.alta(Transformer(nombre, fuerza, defensa, velocidad, faccion, vehiculo, transformado));
                for (size_t i = 0; i < CANTIDAD_ATRIBUTOS; i++) {
                    transformers_atributos_archivo.baja();
                }
            }
        }
        archivo.close();
    } else {
        throw ExcepcionBovedaTransformers("Error al abrir archivo");
    }
}

void BovedaTransformers::almacenar_transformer(Transformer transformer) {
    for (size_t i = 0; i < boveda_transformers.tamanio(); i++) {
        if (boveda_transformers[i].obtener_nombre() == transformer.obtener_nombre()) {
            throw ExcepcionBovedaTransformers("No se pueden almacenar 2 transformers con el mismo nombre.");
        }
    }
    boveda_transformers.alta(transformer);
}

size_t BovedaTransformers::cantidad_transformers() {
    return boveda_transformers.tamanio();
}

void BovedaTransformers::mostrar_transformer(size_t posicion) {
    if (posicion >= boveda_transformers.tamanio()) {
        throw ExcepcionBovedaTransformers("Posicion fuera de rango al mostrar el transformer.");
    } else {
        Transformer transformer = boveda_transformers[posicion];
        std::string faccion = faccion_a_cadena(transformer.obtener_faccion());
        std::string vehiculo = vehiculo_a_cadena(transformer.obtener_vehiculo());
        std::string transformado = (transformer.esta_transformado() ? "SI" : "NO");
        std::cout << "Nombre: " << transformer.obtener_nombre() << "\nFuerza: " << transformer.obtener_fuerza() <<
            "\nDefensa: " << transformer.obtener_defensa() << "\nVelocidad: " << transformer.obtener_velocidad() <<
                "\nFaccion: " << faccion << "\nVehiculo: " << vehiculo <<
                    "\n¿Esta transformado?: " << transformado << std::endl;
    }
}

void BovedaTransformers::mostrar_transformers() {
    std::cout << "###################################" << std::endl;
    std::cout << "Boveda Transformers" << std::endl;
    std::cout << "------------------" << std::endl;
    if (boveda_transformers.vacio()) {
        std::cout << "No hay transformers en la boveda para mostrar" << std::endl;
        std::cout << "------------------" << std::endl;
    } else {
        for (size_t i = 0; i < boveda_transformers.tamanio(); i++) {
            mostrar_transformer(i);
            std::cout << "###################################" << std::endl;
        }
    }
}


Transformer BovedaTransformers::obtener_transformer(size_t posicion) {
    if (posicion >= boveda_transformers.tamanio()) {
        throw ExcepcionBovedaTransformers("Posicion fuera de rango.");
    }
    return boveda_transformers.baja(posicion);
}

Faccion BovedaTransformers::obtener_faccion_transformer(size_t posicion) {
    if (posicion >= boveda_transformers.tamanio()) {
        throw ExcepcionBovedaTransformers("Posicion fuera de rango.");
    }
    return boveda_transformers[posicion].obtener_faccion();
}