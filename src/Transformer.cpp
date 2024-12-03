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
const std::string Transformer::facciones[] = {"AUTOBOT", "DECEPTICON"};
const std::string Transformer::vehiculos[] = {"AUTO", "CAMION", "TANQUE", "AVION"};

Transformer::Transformer() : Transformer("BOT", 15, 10, 20, AUTOBOT, AUTO, false) {}

Transformer::Transformer(std::string nombre, size_t fuerza, size_t defensa, size_t velocidad, Faccion faccion, Vehiculo vehiculo, bool transformado)
{
    if (nombre.empty())
    {
        throw ExcepcionTransformer("Nombre no puede ser de al menos un caracter.");
    }

    if (faccion == AUTOBOT && (vehiculo == TANQUE || vehiculo == AVION))
    {
        throw ExcepcionTransformer("No se puede crear un autobot que sea tanque o avion.");
    }

    if (faccion == DECEPTICON && (vehiculo == AUTO || vehiculo == CAMION))
    {
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

Transformer::Transformer(std::string atributos_csv)
{
    if (atributos_csv.empty())
    {
        throw ExcepcionTransformer("Atributos no pueden ser vacios.");
    }

    std::istringstream ss(atributos_csv);
    std::string valor;
    Vector<std::string> atributos;

    while (std::getline(ss, valor, ','))
    {
        atributos.alta(valor);
    }

    this->nombre = atributos[0];
    this->fuerza = std::stoul(atributos[1]);
    this->defensa = std::stoul(atributos[2]);
    this->velocidad = std::stoul(atributos[3]);
    this->faccion = static_cast<Faccion>(std::stoul(atributos[4]));
    this->vehiculo = static_cast<Vehiculo>(std::stoul(atributos[5]));
    this->transformado = std::stoul(atributos[6]);
}

size_t Transformer::limitar_valores(int calculo)
{
    if (calculo < 0)
    {
        return 0;
    }
    return static_cast<size_t>(calculo);
}

void Transformer::transformar()
{
    if (!esta_transformado())
    {
        this->transformado = true;
        switch (vehiculo)
        {
        case AUTO:
            this->fuerza = limitar_valores(static_cast<int>(fuerza - PLUS_FUERZA_AUTO));
            this->defensa = limitar_valores(static_cast<int>(defensa - PLUS_DEFENZA_AUTO));
            this->velocidad = limitar_valores(static_cast<int>(velocidad + PLUS_VELOCIDAD_AUTO));
            break;
        case CAMION:
            this->fuerza = limitar_valores(static_cast<int>(fuerza + PLUS_FUERZA_CAMION));
            this->defensa = limitar_valores(static_cast<int>(defensa + PLUS_DEFENZA_CAMION));
            this->velocidad = limitar_valores(static_cast<int>(velocidad - PLUS_VELOCIDAD_CAMION));
            break;
        case TANQUE:
            this->fuerza = limitar_valores(static_cast<int>(fuerza + PLUS_FUERZA_TANQUE));
            this->defensa = limitar_valores(static_cast<int>(defensa + PLUS_DEFENZA_TANQUE));
            this->velocidad = limitar_valores(static_cast<int>(velocidad - velocidad));
            break;
        case AVION:
            this->fuerza = limitar_valores(static_cast<int>(fuerza + PLUS_FUERZA_AVION));
            this->defensa = limitar_valores(static_cast<int>(defensa - defensa));
            this->velocidad = limitar_valores(static_cast<int>(velocidad + PLUS_VELOCIDAD_AVION));
            break;
        }
    }
    else
    {
        this->transformado = false;
        switch (vehiculo)
        {
        case AUTO:
            this->fuerza = limitar_valores(static_cast<int>(fuerza + PLUS_FUERZA_AUTO));
            this->defensa = limitar_valores(static_cast<int>(defensa + PLUS_DEFENZA_AUTO));
            this->velocidad = limitar_valores(static_cast<int>(velocidad - PLUS_VELOCIDAD_AUTO));
            break;
        case CAMION:
            this->fuerza = limitar_valores(static_cast<int>(fuerza - PLUS_FUERZA_CAMION));
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

std::string Transformer::obtener_nombre()
{
    return nombre;
}

Faccion Transformer::obtener_faccion()
{
    return faccion;
}

std::string Transformer::obtener_cadena_faccion()
{
    return facciones[faccion];
}

Vehiculo Transformer::obtener_vehiculo()
{
    return vehiculo;
}

std::string Transformer::obtener_cadena_vehiculo()
{
    return vehiculos[vehiculo];
}

bool Transformer::esta_transformado()
{
    return transformado;
}

void Transformer::mostrar_detalle()
{
    Estadisticas estadisticas = obtener_estadisticas();
    std::cout
        << "\nNombre: " << obtener_nombre()
        << "\nFuerza: " << estadisticas.fuerza
        << "\nDefensa: " << estadisticas.defensa
        << "\nVelocidad: " << estadisticas.velocidad
        << "\nFaccion: " << obtener_cadena_faccion()
        << "\nVehiculo: " << obtener_cadena_vehiculo()
        << "\nTransformado: " << (esta_transformado() ? "SI" : "NO");
}

size_t Transformer::obtener_poder()
{
    return velocidad + fuerza + defensa;
}

Estadisticas Transformer::obtener_estadisticas()
{
    return {fuerza, defensa, velocidad};
}