[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mpISVoEK)
# AYED - TPG 2c2024 - Grupo Compilados

<p align="center">
   <img src="Banner.jpg" alt="TPG: La batalla final"><br>
</p>

## Integrantes:

### DE MATOS, TOMÁS ADRIANO - 112277 (Delegado)

### GARCIA LOPEZ, PAUL GONZALO - 112363

### DONADEL WIDE, ROCÍO AYLÉN - 108242

### CANCINA, MATÍAS AGUSTÍN - 111735

## Entregables:

1. [Informe de complejidad algorítmica](https://docs.google.com/document/d/13TDQOgicwrRM_FvfyqVqIjJZ4llM3OECTTcOZllaljE/edit?tab=t.0)
2. [Video de demostración del programa](https://www.enlaceaca.com/)

## Justificación de las estructuras de datos y algoritmos

1. Implementacion de Lista:
   - Al añadir al inicio se actualiza el cursor para que apunte al siguiente del primer elemento en caso de que haya mas de un elemento), se reasignan los punteros al primer nodo, y luego se            reinicia el cursor para que apunte al nuevo elemento. Si se añade al final, el cursor apunta al anterior del ultimo elemento (tambien en caso de que haya mas de 1 elemento), se reasignan          los punteros al ultimo nodo, y se vuelve a ubicar el cursor al nuevo elemento añadido.
   - Al eliminar al inicio se ubica el cursor obteniendo el siguiente del primero (en caso de que haya mas de un elemento), y si se elimina al final se ubica el cursor para que apunte al anterior       del ultimo (tambien en caso de que haya mas de 1 elemento).
   - Ubicar cursor tiene como objetivo optimizar los recorridos de la lista. Si la posicion que recibe es mayor a la mitad del tamanio accesible (posicion_maxima), se reinicia al final de la            lista y se recorre retrocediendo el cursor hasta encontrar la posicion. caso contrario, se reinicia al inicio y se recorre avanzando el cursor hasta la posicion indicada. Este metodo es           privado ya que lo controlan exclusivamente los metodos insertar y eliminar, y no se usa en otros metodos. Este metodo está para optimizar los recorridos de la lista, partiendo desde el            final o desde el inicio segun corresponda.
2. Implementacion de Diccionario:
   - Buscar clave recibe una clave y el nodo raiz. Busca recursivamente hasta encontrar el nodo que tiene esa clave que se busca y lo retorna. En caso de que no este la clave, se retorna nullptr.       Este metodo se usa en baja, operator[] y  alta. Es usado mas que nada para arrojar excepciones si no está la clave.
   - Todos los metodos de mostrado tienen un metodo privado con su mismo nombre seguido de un "_recursivo" y se llaman hasta que terminan de mostrar los datos del diccionario.
      En el caso de ancho_recursivo, se utilizó una cola para mostrar adecuadamente los datos recorriendo desde la raiz hasta llegar a los nodos hoja.
   - Para asegurar que no haya perdidas de memoria, el destructor llama a eliminar_nodos, que recibe la raiz, y elimina primer el subarbol izquierdo y luego el derecho.
3. Implementacion de Heap:
   - Esta basado en un árbol binario que mantiene una propiedad fundamental: en un heap de máxima, el valor de cada nodo padre es mayor o 
     igual al de sus hijos; en un heap de mínima, el valor de cada nodo padre es menor o igual al de sus hijos. Esta propiedad lo hace especialmente útil en la implementación de colas de prioridad, ya 
     que permite acceder al elemento de mayor o menor prioridad en 𝑂(1) y realizar inserciones o eliminaciones eficientes en 𝑂(log n).
   - En la inserción, el elemento se añade al final del arreglo para preservar la estructura del árbol binario completo.El método de ordenar hacia arriba garantiza que, después de insertar un elemento, 
     este se coloque en una posición que respete la propiedad del heap. Durante este proceso, se compara iterativamente el nodo con su padre y se intercambian si no cumplen la propiedad.
   - En la eliminación del elemento raíz (el máximo en un heap de máxima o el mínimo en un heap de mínima), se sustituye el elemento de la raíz por el último elemento del arreglo para mantener la 
    estructura del árbol. Luego, se "ordena hacia abajo" intercambiándolo con el hijo más prometedor (el mayor o menor, dependiendo del tipo de heap) hasta que se restaure la propiedad. Este proceso 
    también tiene complejidad 𝑂(log𝑛) y asegura que el árbol conserve su estructura de heap binario completo.
5. Implementacion de Cola:
   - La estructura de datos Cola es una abstracción que sigue el principio FIFO (First In, First Out). Se implementa mediante una lista enlazada, donde cada elemento (nodo) contiene un dato y un puntero 
     al siguiente nodo en la cola. Esta implementación tiene varias ventajas, como la eficiencia en la inserción y eliminación de elementos, ya que ambas operaciones ocurren en 𝑂(1) al añadir un nuevo 
     nodo al final o al eliminar el primer nodo.
   - El método Alta() agrega el dato al final de de la cola y Baja() elimina el primer elemento de la cola. Para que esto funcione la cola no debe estar vacía.
6. Implementación de Pila:
   La pila se organiza según LIFO (Last in, first out) Último en entrar, primero en salir. 
   Pila utiliza NodoLista y hace uso de puntero a siguiente.
   Cada nodo tiene su dato y un puntero al siguiente. 
   La función alta agrega un elemento al inicio de la pila y actualiza el último nodo para que apunte al nuevo nodo, baja elimina el primer elemento de la pila y asigna como último nodo el anterior, devuelve el dato eliminado. Primero devuelve el último nodo, o sea el que está al inicio de la pila.
8. DIJKSTRA: Elegimos usar Dijkstra porque este algoritmo encuentra el camino de menor coste desde un nodo inicial fijo a los demás nodos en un grafo. En cambio, el algoritmo de Floyd-Warshall calcula el camino de menor coste entre todos los pares de nodos del grafo. 
Dado que el programa requiere encontrar el camino mínimo desde un nodo inicial específico hasta un nodo destino, no solo no es relevante e innecesario obtener información sobre los caminos mínimos entre otros nodos intermedios sino que es ineficiente ya que implica una mayor complejidad algorítmica. Por estas razones, Dijkstra resulta ser la opción más eficiente y adecuada.

   - Explicación del Dijkstra: 
El algoritmo de Dijkstra se utiliza para encontrar el camino más corto entre un nodo de origen y un nodo destino. Su principal objetivo es optimizar el costo buscando una ruta de costo mínimo.
Utiliza la matriz de adyacencia y la matriz de pesos del grafo para identificar las conexiones entre vértices y sus respectivos costos.
   - Utiliza tres vectores principales:
Visitados: Es un vector que indica con true o false si un vértice ha sido visitado.
Distancias: Almacena las distancias desde el nodo inicial a los demás nodos, actualizándolas a medida que se encuentra un camino más corto.
Predecesores: Registra los nodos anteriores en el camino más corto, permitiendo reconstruir la ruta al final.
   - Proceso:
Se asigna una distancia inicial de 0 al nodo de origen y una distancia infinita a todos los demás nodos.
Se marca al nodo de origen como visitado. Se inicia con nodo origen
Se busca el nodo vecino al nodo actual con la menor distancia, se asigna como nuevo nodo actual.
Si se encuentra un camino más corto desde nodo actual (teniendo en cuenta la distancia acumulada) hacia un vecino, se actualiza su coste en el vector de distancias y se guarda el nodo actual como el predecesor.
Luego se elige el nodo vecino no visitado del nodo actual con el menor coste y se lo asigna como el nuevo nodo actual.
El proceso se repite hasta que se visita el nodo destino o ya no quedan nodos accesibles que no hayan sido visitados.
En el vector predecesores se encuentra la información necesaria para reconstruir el camino más corto desde el nodo de origen hasta el nodo destino.


## Compilación

El proyecto se puede compilar manualmente por terminal con la siguiente línea:

> // COMPLETAR CON LINEA DE COMPILACIÓN //

O, alternativamente, con CMake, utilizando el archivo **CMakeLists.txt** presente en el directorio raíz.

## Aclaraciones adicionales:

// ACLARACIONES ADICIONALES PARA EL CORRECTOR, COMO DECISIONES O SUPUESTOS QUE CONSIDERARON //
