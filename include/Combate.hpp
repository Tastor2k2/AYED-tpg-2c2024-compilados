#ifndef COMBATE_HPP
#define COMBATE_HPP

#include <optional>
#include "Grafo.hpp"
#include "Vector.hpp"
#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "Cristal.hpp"
#include "Transformer.hpp"

enum Personaje
{
    OPTIMUS,
    MEGATRON
};

class Combate
{

private:
    static const size_t PUNTAJE_BATALLA = 50;
    static const size_t PUNTAJE_ALIADO = 25;
    static const size_t COSTE_TRANSFORMACION = 10;

    Personaje personaje;

    Estadisticas estadisticas_personaje{};
    size_t puntos;

    OptimusPrime optimus;
    Megatron megatron;

    std::optional<Cristal> cristal_seleccionado;

    // Pre: -
    // Post: Muestra el mapa del camino.
    void mostrar_mapa(Camino camino, Vector<size_t> pesos, Vector<Transformer> transformers);

    // Pre: -
    // Post: Simula los combates del personaje principal.
    void simular_combate(size_t posicion, Vector<Transformer> transformers);

    int analisis_combate(Estadisticas estadisticas_jugador, Estadisticas estadisticas_enemigo);

public:
    Combate(Personaje personaje_seleccionado, std::optional<Cristal> cristal_seleccionado);

    // Pre: -
    // Post: Inicia el combate. Y retorna el puntaje final al finalizar.
    size_t iniciar_combate(Camino camino, Vector<size_t> pesos, Vector<Transformer> transformers);
};
#endif