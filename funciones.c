// funciones

#include <stdio.h>
int maxima(); //prototipo
void cambio();

//////////////////////////////////////////////////////////////////////
int main(){

  int x,y,max;
  x = 3;
  y = 10;

  max = maxima(x,y);
  printf("El valor maximo es %i\n",max );

  cambio(&x,&y); //paso por referencia & Direccion en memoria.
  printf("El valor de x es %i y el de y es %i\n",x,y);
  return 0;
}
//////////////////////////////////////////////////////////////////////
int maxima(int x,int y){
  int ban;

  if(x>y){ban=x;}
  else{ban=y;}

  return ban;
}
//////////////////////////////////////////////////////////////////////
void cambio(int *a, int *b){ // *punteros -> a direccion en memoria
  int aux;

  aux = *a;
  *a = *b;
  *b = aux;
}