#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "JuegoManager.hpp"
#include "Grafo.hpp"
#include "Vector.hpp"
#include "OptimusPrime.hpp"
#include "Megatron.hpp"

Camino resultado{};

class Combate
{

private:
    size_t *combate;

    static const size_t CANTIDAD_MAXIMA_NIVEL = 3;

    PERSONAJE personaje;

    size_t poder_personaje;

    size_t puntos;

    size_t energon;

public:
    Combate(PERSONAJE personaje_seleccionado, size_t poder_personaje, size_t cantidad_transformers);

    Camino obtener_camino_combate(Grafo grafo, size_t personaje, size_t jefe_final);

    void preparar_mapa_combate(Grafo grafo, size_t personaje, size_t jefe_final);

    void crear_grafo(size_t cantidad_transformers, size_t poder_personaje, Vector<Transformer> transformers);

    void conectar_vertices(size_t cantidad_transformers, Grafo grafo_transformers, Vector<Transformer> transformers);

    size_t calcular_energon(Transformer rival);

    size_t *obtener_pesos_aristas(Grafo grafo, Vector<size_t> camino);

    void simular_combate();
};
#endif