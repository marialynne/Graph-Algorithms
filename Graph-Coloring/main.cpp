/*
Ningún grafo adyacente debe tener el mismo color
Cualquier gráfo se puede pintar con solo 4 colores
Pero hay una teoría de 5 colores, pero no es aceptada porque ganó el de 4 colores al final

- Colores distintos si conparten un arco
- Polnomio cromatico
    Diferentes formas de combinar los colores
- Coloración secuencial básica
- Coloración de Wesh y Powell -> Menor grado o mayor grado, depende el caso uno ocupa menos colores
- Coloración de Matula, Marble, Isaacson: "el de menor grado el último"
- Coloración de Brelaz -> Más cabron pero más acertado (perron) -> Haremos este juju
    Suma de los vecinos, luego suma de la sumatoria más el grado del nodo

    Wesh Powel
    Nodes   Edges   Order   |   Colors


    Brelaz
    Nodes   Edges   Sum     Order   |   Colors
     A        3
     B        3
     C        2
     D        2
     E        2
     G        1
*/

#include <bits/stdc++.h>
#include "brelaz.h"
using namespace std;

int main()
{

    return 0;
}