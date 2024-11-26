[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mpISVoEK)
# AYED - TPG 2c2024 - Grupo NOMBRE

<p align="center">
   <img src="Banner.jpg" alt="TPG: La batalla final"><br>
</p>

## Integrantes:

### DE MATOS, TOMÁS ADRIANO - 112277 (Delegado)

### CANO, IVANA ABRIL - 109824

### GARCIA LOPEZ, PAUL GONZALO - 112363

### DONADEL WIDE, ROCÍO AYLÉN - 108242

### CANCINA, MATÍAS AGUSTÍN - 111735

## Entregables:

1. [Informe de complejidad algorítmica](https://www.enlaceaca.com/)
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
3. // COMPLETAR //
4. // COMPLETAR //
5. // COMPLETAR //

## Compilación

El proyecto se puede compilar manualmente por terminal con la siguiente línea:

> // COMPLETAR CON LINEA DE COMPILACIÓN //

O, alternativamente, con CMake, utilizando el archivo **CMakeLists.txt** presente en el directorio raíz.

## Aclaraciones adicionales:

// ACLARACIONES ADICIONALES PARA EL CORRECTOR, COMO DECISIONES O SUPUESTOS QUE CONSIDERARON //
