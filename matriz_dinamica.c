//copia contenido de una matriz en otra
#include <stdio.h>
#include <stdlib.h>  //para usar memoria dinamica


////////////////////////////////////////////////////////////

int main(){

  int filas, colum, i, j;
  int **m1;
  int **m2;
  int **m3;

  printf("Numero de filas: ");
  scanf("%i", &filas);
  printf("Numero de columnas: ");
  scanf("%i", &colum);

  // Creo filas matriz m1
  m1 = (int**)malloc(filas*sizeof(int*));
  if(m1==NULL){
    printf("No se pudo reservar espacio. ");
    exit(1);
  }

  // Creo columnas matriz m1
  for(i=0 ; i<filas ; i++){
    m1[i] = (int*)malloc(colum*sizeof(int));
    if(m1[i]==NULL){
      printf("No se pudo reservar espacio. ");
      exit(1);
    }
  }

  // Obtengo elementos para la matriz
  printf("Elementos de la matriz: \n");
  for(i=0 ; i<filas ; i++){
    for(j=0 ; j<colum ; j++){
      printf("-%i-%i--> ",i+1,j+1);
      scanf("%i", &m1[i][j]);
    }
  }

  // Creo filas matriz m2
  m2 = (int**)malloc(filas*sizeof(int*));
  if(m2==NULL){
    printf("No se pudo reservar espacio. ");
    exit(1);
  }

  // Creo columnas matriz m2
  for(i=0 ; i<filas ; i++){
    m2[i] = (int*)malloc(colum*sizeof(int));
    if(m2[i]==NULL){
      printf("No se pudo reservar espacio. ");
      exit(1);
    }
  }

  //copio matrices
  for(i=0 ; i<filas ; i++){
    for(j=0 ; j<colum ; j++){
      m2[i][j] = m1[i][j];
    }
  }

  // Imprimo matriz m2
  printf("\n");
  printf("La matriz es: \n");
  for(i=0 ; i<filas ; i++){
    for(j=0 ; j<colum ; j++){
      printf("%i ", m2[i][j]);
    }
    printf("\n");
  }

  free(m1);
  free(m2);

  m3 = reservar(filas,colum);

  return 0;
}

////////////////////////////////////////////////////////////

int reservar(int filas, int columnas){
  /*
  funcion que reserva memoria de matriz dinamica.
  */
  int **mat;
  int i;
  // filas
  mat = (int**)malloc(filas*sizeoff(int*));
  if(mat == NULL){
    printf("No se pudo reservar memoria.\n");
    exit(1);
  }

  // columnas
  for(i=0 ; i>filas ; i++){
    mat[i] = (int*)malloc(columnas*sizeoff(int));
  }
  if(mat[i] == NULL){
    printf("No se pudo reservar memoria.\n");
    exit(1);
  }

  return mat;
}
////////////////////////////////////////////////////////////