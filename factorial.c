#include <stdio.h>
void pm();  // funcion imprimir matriz

/////////////////////////////////////////////////////////////////////
int main(){
  int x,a,i;

  printf("Ingresa un numero: ");
  scanf("%i",&x);

  a = 1;
  for (i=1 ; i<=x ; i++){
    a *= i;
  }

  printf("El factorial de %i es %i\n\n",x,a);

  int matriz1[3][3] = {1,2,3,4,5,6,7,9,8};
  int matriz2[3][3] = {{1,2,3},{4,5,6},{7,9,8}};

  pm(matriz1);
  pm(matriz2);
  return 0;
}

/////////////////////////////////////////////////////////////////////
void pm(int m[3][3]){
  int i,j;

  for(i=0 ; i<3 ; i++){
    for(j=0 ; j<3 ; j++){
      printf("%i ",m[i][j] );
    }
    printf("\n");
  }
  printf("\n");
}