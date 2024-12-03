#ifndef COMBATE_HPP
#define COMBATE_HPP

#include <optional>
#include "Grafo.hpp"
#include "Vector.hpp"
#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "Cristal.hpp"
#include "Transformer.hpp"

enum PERSONAJE
{
    OPTIMUS,
    MEGATRON
};

class Combate
{

private:
    static const size_t PUNTAJE_BATALLA = 50;
    static const size_t PUNTAJE_EMPATE = 0;
    static const size_t COSTE_TRANSFORMACION = 10;

    PERSONAJE personaje;

    Estadisticas estadisticas_personaje{};
    size_t puntos;

    OptimusPrime optimus;
    Megatron megatron;

    std::optional<Cristal> cristal_seleccionado;

    void mostrar_mapa(Camino camino, Vector<size_t> pesos);

    void simular_combate();

public:
    Combate(PERSONAJE personaje_seleccionado, std::optional<Cristal> cristal_seleccionado);

    void iniciar_combate(Camino camino, Vector<size_t> pesos, Vector<Transformer> transformers);
};
#endif