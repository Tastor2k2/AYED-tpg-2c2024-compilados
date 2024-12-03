#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "Grafo.hpp"
#include "Vector.hpp"
#include "OptimusPrime.hpp"
#include "Megatron.hpp"

enum PERSONAJE
{
    OPTIMUS,
    MEGATRON
};

class Combate
{

private:
    Camino resultado{};

    size_t *combate;

    static const size_t CANTIDAD_MAXIMA_NIVEL = 3;

    PERSONAJE personaje;

    size_t poder_personaje;

    size_t puntos;

    size_t energon;

public:

    // Constructor.
    Combate(PERSONAJE personaje_seleccionado, size_t poder_personaje, size_t cantidad_transformers);

    // Pre: -
    // Post: Utiliza el algoritmo de camino minimo elegido para obtener la mejor ruta de combate.
    Camino obtener_camino_combate(Grafo grafo, size_t personaje, size_t jefe_final);

    // Pre: -
    // Post: Prepara el mapa de combate para mostrar sus datos.
    void preparar_mapa_combate(Grafo grafo, size_t personaje, size_t jefe_final);

    // Pre: -
    // Post: Crea el grafo en base al poder del personaje elegido y a los transformers presentes.
    void crear_grafo(size_t cantidad_transformers, size_t poder_personaje, Vector<Transformer> transformers);

    // Pre: -
    // Post: Conecta los caminos en base a los transformers presentes y sus niveles de poder.
    void conectar_vertices(size_t cantidad_transformers, Grafo grafo_transformers, Vector<Transformer> transformers);

    // Pre: -
    // Post: Calcula el energon comparando poderes del personbaje principal contra el transformer rival.
    size_t calcular_energon(Transformer rival); // REVISAR TEMA NUMEROS MAGICOS

    // Pre: -
    // Post: Obtiene el peso de las aristas usando un getter desde la clase grafo.
    Vector<size_t> obtener_pesos_aristas(Grafo grafo, Vector<size_t> camino);

    // Pre: -
    // Post: Simula los combates del personaje principal.
    void simular_combate();
};
#endif