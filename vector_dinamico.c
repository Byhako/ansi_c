#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio(int *vector, int N);

///////////////////////////////////////////////////////////////////
int main(){

  int i,j,k;
  int N = 10;
  int *vector;

  //vector = (int*)calloc(N,sizeof(int)); // vector inicializado con ceros
  vector = (int*)malloc(N*sizeof(int)); //declarar tamano vector
  // sizeof(char)   -> son 1 byte
  // sizeof(int)    -> son 4 bytes
  // sizeof(double) -> son 8 bytes
  // maloc(x) -> reserva x bytes en memoria ram
  // si maloc pide mas memoria de la disponible le asigna NULL

  if(vector==NULL){
    printf("No se pudo reservar memoria.\n");
  }
  else{
    aleatorio(vector,N);
    printf("\n");

    for(i=0 ; i<N ; i++){
      j = i+1;
      while(j<N){
        if(*(vector+i)==*(vector+j)){
          for(k=j ; k+1<N ; k++){
            *(vector+k) = *(vector+k+1);
          }
          N--; //redusco valor de N
        }
        else{j++;}
      }
    }

    vector = (int*)realloc(vector,N*sizeof(int));
//realloc -> redimenciona vector conservando sus valores.
//realloc(a,b):
// a -> vector a redimencionar
// b -> tamaño de memoria a reservar

    for(i=0 ; i<N ; i++){
      printf("%i, ",*(vector+i));
    }
    printf("\n");
  }

  free(vector);  // libero memoria
  vector = NULL; // valor de puntero liberado a NULL
  return 0;
}

///////////////////////////////////////////////////////////////////

void aleatorio(int *vector, int N){
  int i;
  srand(time(NULL));

  for (i=0 ; i<N ; i++){
    *(vector+i) = rand() % 3;
    printf("%i, ",*(vector+i));
  }
}

///////////////////////////////////////////////////////////////////
/*

*(vector + i) = vector[i]

Para liberar memoria asignada con calloc se debe usar cfree

*/