#include "Dijkstra.hpp"
#include "CaminoMinimo.hpp"

Dijkstra::Dijkstra() { 
  visitados = nullptr;
  distancias = nullptr;
  predecesores = nullptr;
}

void Dijkstra::inicializar(size_t vertices){  
  visitados = new bool[vertices];  
  distancias = new int[vertices];  
  predecesores = new size_t[vertices];  

  for (size_t i = 0; i < vertices; i++) {
    visitados[i] = false;
    distancias[i] = INFINITO;  
    predecesores[i] = NO_ALCANZABLE;
  }
}

Vector<size_t> Dijkstra::calcular_camino_minimo(Matriz<bool> &matriz_adyacencia, Matriz<int> &matriz_pesos,
                                                size_t origen, size_t destino, size_t vertices) {
  inicializar(vertices);
  distancias[origen] = 0;
  Vector<size_t> camino;
  size_t nodos_procesados = 0;
  bool continuar = true;
  size_t nodo_actual;

  while (nodos_procesados < vertices && continuar) {
    nodo_actual = seleccionar_nodo_minimo(vertices);
    if (nodo_actual == NO_ALCANZABLE) {
      continuar = false;
    } 
    else {
      visitados[nodo_actual] = true;
      nodos_procesados++;
      actualizar_distancias(nodo_actual, vertices, matriz_adyacencia, matriz_pesos);
    }
  }
  if (distancias[destino] != INFINITO) {
    camino = construir_camino(destino, predecesores);
  }
  return camino;
} 

size_t Dijkstra::seleccionar_nodo_minimo(size_t vertices) {
  size_t nodo_minimo = NO_ALCANZABLE;
  for (size_t j = 0; j < vertices; j++) {
    if (!visitados[j] && (nodo_minimo == NO_ALCANZABLE || distancias[j] < distancias[nodo_minimo])) {
      nodo_minimo = j;
    }
  }
  return nodo_minimo;
}

void Dijkstra::actualizar_distancias(size_t nodo_actual, size_t vertices, Matriz<bool> &matriz_adyacencia, Matriz<int> &matriz_pesos) {
  int peso_arista;
  int nueva_distancia;
  for (size_t vecino = 0; vecino < vertices; vecino++) {
    if (matriz_adyacencia(nodo_actual, vecino) && !visitados[vecino]) {
      peso_arista = matriz_pesos(nodo_actual, vecino);
      nueva_distancia = distancias[nodo_actual] + peso_arista;
      if (nueva_distancia < distancias[vecino]) {
        distancias[vecino] = nueva_distancia;
        predecesores[vecino] = nodo_actual;
      }
    }
  }
}

Vector<size_t> Dijkstra::construir_camino(size_t destino, size_t* predecesores){
  Vector<size_t> camino;
  for (size_t nodo = destino; nodo != NO_ALCANZABLE; nodo = predecesores[nodo]) {
    camino.alta(nodo,0);
  }
  return camino;
}

Dijkstra::~Dijkstra() {
  if (visitados != nullptr) {
    delete[] visitados;
    visitados = nullptr;
  }
  if (distancias != nullptr) {
    delete[] distancias;
    distancias = nullptr;
  }
  if (predecesores != nullptr) {
    delete[] predecesores;
    predecesores = nullptr;
  }
}