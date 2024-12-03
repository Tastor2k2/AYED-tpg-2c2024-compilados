#include "Combate.hpp"
#include <iostream>
#include <algorithm>

Combate::Combate(Personaje personaje_seleccionado, std::optional<Cristal> cristal_seleccionado)
{
    personaje = personaje_seleccionado;
    this->cristal_seleccionado = cristal_seleccionado;

    if (personaje == OPTIMUS)
    {
        estadisticas_personaje = optimus.obtener_estadisticas();
    }
    else
    {
        estadisticas_personaje = megatron.obtener_estadisticas();
    }

    if (cristal_seleccionado.has_value())
    {
        Estadisticas estadisticas_cristal = cristal_seleccionado.value().obtener_estadisticas();
        estadisticas_personaje.fuerza += estadisticas_cristal.fuerza;
        estadisticas_personaje.defensa += estadisticas_cristal.defensa;
        estadisticas_personaje.velocidad += estadisticas_cristal.velocidad;
    }

    puntos = 0;
}

void Combate::mostrar_mapa(Camino camino, Vector<size_t> pesos, Vector<Transformer> transformers)
{
    std::cout << "Coste total energon: [" << camino.costo_total << "]" << std::endl;

    size_t longitud_camino = camino.camino.tamanio();
    size_t posicion = 0;

    for (size_t i = 0; i < longitud_camino; i++)
    {
        if (i != 0)
        {
            std::cout << "   ↑" << std::endl;
        }
        posicion = longitud_camino - 1 - i;
        if (posicion - 1 < transformers.tamanio())
        {
            if (posicion > 0 && transformers[posicion - 1].obtener_faccion() == static_cast<Faccion>(personaje))
            {
                std::cout << "🦾 ";
            }
            else
            {
                std::cout << "😈 ";
            }
        }
        else if (posicion - 1 == transformers.tamanio())
        {
            std::cout << "👹 ";
        }
        else
        {
            std::cout << "🤖 ";
        }

        std::cout << camino.camino[posicion];

        if (posicion > 0)
        {
            std::cout << " <- (" << pesos[posicion - 1] << ")";
        }
        std::cout << std::endl;
    }
}

size_t Combate::iniciar_combate(Camino camino, Vector<size_t> pesos, Vector<Transformer> transformers)
{
    std::cout << "###################################" << std::endl;
    std::cout << "COMBATE INICIADO" << std::endl;
    mostrar_mapa(camino, pesos, transformers);
    std::cout << "###################################" << std::endl;

    for (size_t i = 1; i < camino.camino.tamanio(); i++)
    {
        simular_combate(i, transformers);
    }

    std::cout << "Puntaje Final: |" << puntos << "|" << std::endl;
    std::cout << "###################################" << std::endl;

    return puntos;
}

void Combate::simular_combate(size_t posicion, Vector<Transformer> transformers)
{
    std::string nombre_enemigo = "";
    std::string nombre_transformer = "";
    Estadisticas estadisticas_enemigo = {0, 0, 0};

    size_t rounds = 1;

    bool es_optimus = personaje == OPTIMUS;
    bool es_aliado = false;
    bool es_final = false;

    if (posicion - 1 < transformers.tamanio())
    {
        Transformer transformer = transformers[posicion - 1];
        es_aliado = transformer.obtener_faccion() == static_cast<Faccion>(personaje);
        nombre_enemigo = transformer.obtener_nombre();
        estadisticas_enemigo = transformer.obtener_estadisticas();
    }
    else
    {
        nombre_enemigo = es_optimus ? megatron.obtener_personaje_string() : optimus.obtener_personaje_string();
        estadisticas_enemigo = es_optimus ? megatron.obtener_estadisticas() : optimus.obtener_estadisticas();

        rounds = 3;
        es_aliado = false;
        es_final = true;
    }

    nombre_transformer = es_optimus ? optimus.obtener_personaje_string() : megatron.obtener_personaje_string();
    estadisticas_personaje = es_optimus ? optimus.obtener_estadisticas() : megatron.obtener_estadisticas();

    if (es_final)
    {
        std::cout << "---------- " << rounds << " ROUNDS" << " ---------------" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    std::cout << nombre_transformer << " VS " << nombre_enemigo << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Puntaje: |" << puntos << "|" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "***********************************" << std::endl;
    std::cout << "Fuerza: " << estadisticas_enemigo.fuerza << std::endl;
    std::cout << "Velocidad: " << estadisticas_enemigo.velocidad << std::endl;
    std::cout << "Defensa: " << estadisticas_enemigo.defensa << std::endl;
    std::cout << "***********************************" << std::endl;

    if (es_aliado)
    {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Es un aliado, continua con tu camino" << std::endl;
        std::cout << "-----------------------------------" << std::endl;

        puntos += PUNTAJE_ALIADO;
        std::cout << "###################################" << std::endl;
        std::cin.get();
    }
    else
    {

        transformar_jugador(es_optimus);

        for (size_t i = 0; i < rounds; i++)
        {
            if (es_final)
            {
                transformar_enemigo(es_optimus, estadisticas_enemigo);
            }

            int resultado = analisis_combate(estadisticas_enemigo);

            mostrar_resultado_combate(resultado, es_final);

            std::cout << "-----------------------------------" << std::endl;
            std::cin.get();
        }
    }
    std::cout << "###################################" << std::endl;
}

void Combate::mostrar_resultado_combate(int resultado, bool es_final)
{
    std::string mensaje = "🤝 EMPATE 🤝";
    std::cout << "-----------------------------------" << std::endl;
    if (resultado == 1)
    {
        puntos += PUNTAJE_BATALLA;

        mensaje = es_final ? " 🏆 GANASTE EL ROUND 🏆 " : " 🏆 GANASTE LA PELEA 🏆 ";
    }
    else if (resultado == -1)
    {
        puntos = PUNTAJE_BATALLA > puntos ? 0 : puntos - PUNTAJE_BATALLA;
        mensaje = es_final ? " 😵 PERDISTE EL ROUND 😵 " : " 😵 PERDISTE LA PELEA 😵 ";
    }

    std::cout << mensaje << std::endl;
}

void Combate::transformar_enemigo(bool es_optimus, Estadisticas &estadisticas_enemigo)
{
    bool transformar = generador_aleatorio.generar_chance_porcentual(50);
    if (transformar)
    {
        es_optimus ? megatron.transformar() : optimus.transformar();
        estadisticas_enemigo = es_optimus ? megatron.obtener_estadisticas() : optimus.obtener_estadisticas();

        std::cout << "*** *** *** *** *** *** *** *** ***" << std::endl;
        std::cout << " 🤖 EL ENEMIGO SE TRANSFORMO! 🤖 " << std::endl;
        std::cout << "*** *** *** *** *** *** *** *** ***" << std::endl;
    }
}

void Combate::transformar_jugador(bool es_optimus)
{
    int opcion = -1;

    while (opcion != 1 && opcion != 2)
    {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Desea transformar? (Coste: " << COSTE_TRANSFORMACION << ")" << std::endl;
        std::cout << "1- TRANSFORMAR!" << std::endl;
        std::cout << "2- No" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "- ";
        std::cin >> opcion;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (opcion == 1)
    {
        if (puntos < COSTE_TRANSFORMACION)
        {
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "No tienes suficiente energon para transformar" << std::endl;
            std::cout << "-----------------------------------" << std::endl;
            opcion = 2;
        }
        else
        {
            puntos -= COSTE_TRANSFORMACION;
        }

        es_optimus ? optimus.transformar() : megatron.transformar();
        estadisticas_personaje = es_optimus ? optimus.obtener_estadisticas() : megatron.obtener_estadisticas();

        if (cristal_seleccionado.has_value())
        {
            estadisticas_personaje += cristal_seleccionado.value().obtener_estadisticas();
        }
    }
}

int Combate::analisis_combate(Estadisticas estadisticas_enemigo)
{
    size_t contador_jugador = 0;
    size_t contador_enemigo = 0;

    if (estadisticas_personaje.fuerza > estadisticas_enemigo.fuerza)
    {
        contador_jugador++;
    }
    else if (estadisticas_personaje.fuerza < estadisticas_enemigo.fuerza)
    {
        contador_enemigo++;
    }

    if (estadisticas_personaje.velocidad > estadisticas_enemigo.velocidad)
    {
        contador_jugador++;
    }
    else if (estadisticas_personaje.velocidad < estadisticas_enemigo.velocidad)
    {
        contador_enemigo++;
    }

    if (estadisticas_personaje.defensa > estadisticas_enemigo.defensa)
    {
        contador_jugador++;
    }
    else if (estadisticas_personaje.defensa < estadisticas_enemigo.defensa)
    {
        contador_enemigo++;
    }

    if (contador_jugador >= 2)
    {
        return 1;
    }
    else if (contador_enemigo >= 2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}