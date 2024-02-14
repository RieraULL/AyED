# Problemas con matrices almacenadas sobre una estructura tipo vector

Ref. [code1](matrices/matrices.cpp)

Estos ejemplos ponen de manifiesto cómo, a través de la abstracción, podemos crear una estructura determinada que se gestiona internamente de forma ajena al conocimiento de la persona que la utiliza.
En concreto vamos a crear una matriz que estará gestionada sobre un vector. Esta estructura tiene utilidad cuando las matrices que utilizamos nos tienen muchos elementos nulos.

En este ejemplo podemos ver:

* Cómo repretar un vector a través de una clase
* Cómo representar una matriz organizada internamente mediante un vector, y cómo hacer corresponder cada elemento (i,j) de la matriz con su posición dentro del vector
* Cómo inicializar la matriz con valores aleatorios
* Cómo sumar ciertos elementos de la matriz: diagonal, triangular superior, ...
* Cómo efectuar ciertas operaciones con matrices (suma y producto)
