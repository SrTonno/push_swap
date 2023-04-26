# push_swap
El proyecto Push_Swap consiste en ordenar un conjunto de números utilizando dos pilas y un conjunto de instrucciones permitidas. El objetivo es ordenar los números en la pila A en orden ascendente utilizando la pila B como espacio auxiliar y las siguientes operaciones:

# Movimientos
- `sa` : swap a - intercambia los dos primeros elementos en la pila A.
- `sb` : swap b - intercambia los dos primeros elementos en la pila B.
- ss : swap a + swap b.
- `pa` : push a - mueve el primer elemento de la pila B a la pila A.
- `pb` : push b - mueve el primer elemento de la pila A a la pila B.
- `ra` : rotate a - mueve el primer elemento de la pila A al final de la misma.
- `rb` : rotate b - mueve el primer elemento de la pila B al final de la misma.
- `rr` : rotate a + rotate b.
- `rra` : reverse rotate a - mueve el último elemento de la pila A al principio de la misma.
- `rrb` : reverse rotate b - mueve el último elemento de la pila B al principio de la misma.
- `rrr` : reverse rotate a + reverse rotate b.

# Algoritmo
Uso el algoritmo de ordenación radix es un método de ordenación que ordena los elementos por posición. En la versión binaria del algoritmo, se recorre cada bit de los elementos a ordenar, agrupándolos por 0 o 1 en función del bit correspondiente. Esto se repite tantas veces como bits tenga el elemento más grande. Al finalizar el proceso, los elementos estarán ordenados. El algoritmo radix no utiliza comparaciones entre elementos, lo que lo hace muy eficiente.

# Compilación
Para compilar el programa, simplemente ejecuta `make` en la raíz del proyecto. Esto generará un ejecutables, push_swap.

#Uso
El ejecutable `push_swap` acepta una lista de números como argumentos y devuelve una lista de operaciones que se deben realizar en las pilas para ordenar los números. Por ejemplo:

````
$ ./push_swap 2 1 3 6 5 8
sa
rra
pb
ra
pa
```
