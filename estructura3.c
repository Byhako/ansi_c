//punterroa a estructuras y funciones

#include <stdio.h>

typedef struct{
  int math,ingles,phy;
}notas;

//void darnotas(notas *not);
void darnotas(notas not[]);

/////////////////////////////////////////////////////////

int main(){

  notas nott,not[1];

  //darnotas(&nott);
  darnotas(not);

  printf("La nota de math es:   %i\n",not[0].math);
  printf("La nota de ingles es: %i\n",not[0].ingles);
  printf("La nota de phy es:    %i\n",not[0].phy);

  return 0;
}

//////////////////////////////////////////////////////////

//void darnotas(notas *nott){
void darnotas(notas not[]){
  printf("Introdusca la nota de math: ");
  //scanf("%i", &not->math);
  scanf("%i", &not[0].math);

  printf("Introdusca la nota de ingles: ");
  //scanf("%i", &(*not).ingles);
  scanf("%i", &not[0].ingles);

  printf("Introdusca la nota de phy: ");
  //scanf("%i", &not->phy);
  scanf("%i", &not[0].phy);
}
/*
Para apuntar a la direccion de memoria donde esta la variable colocamos un
& antes del nombre -- darnotas(&not) --

Cuando la usamos en una funcion colocamos un puntero * antes del nombre
-- void darnotas(notas *not){ --

si en el void tenemos una variabel como puntero void(*not), para acceder
a los metodos de las estructuras cambiamos el punto por una flecha.
  --  &not.phy -- &not->phy --

Tambien podriamos cambiar el punto, teniendo en cuenta que nuestra variable
es ahora un puntero de la siguiente forma.
-- &not.phy -- &(*not).phy --

Para un vector, cuando se pasa por referencia no hace falta usar & se
puede colocar solo el nombre del vector, y al llamarlo tampoco es necesario
el uso del puntero *, ni se usa la flecha.
*/