// vector y matriz

#include <stdio.h>
void vector();
void ordenar();

////////////////////////////////////////////////////
int main(){
  int i;
  float v[10];

  for(i=0 ; i<10 ; i++){
    v[i] =  i + 0.5;
  }

  for(i=0 ; i<10 ; i++){
    printf("%0.1f, ", v[i] );
  }
  printf("\n");

  // vector a traves de funcion
  printf("Otro vector: \n" );

  vector(v); // llamo funcion

  for(i=0 ; i<10 ; i++){
    printf("%0.1f, ", v[i] );
  }
  printf("\n");

  // Ordenamos un vector de mayor a menor
  printf("Vector ordenado: \n" );

  float a[10] = {4,5,2,3,6,17,8,6,2,1};

  ordenar(a); // llamar a la funcion ordenar

  for(i=0 ; i<10 ; i++){
    printf("%0.1f, ", a[i] );
  }
  printf("\n");

  return 0;
}

////////////////////////////////////////////////////

void vector(float a[]){
  int i;

  for(i=0 ; i<10 ; i++){
    a[i] =  i - 0.5;
  }
}

////////////////////////////////////////////////////

void ordenar(float b[]){
  int i,j;
  float aux;
  for(i=0 ; i<10 ; i++){
    for(j=i ; j<10 ; j++){
      if(b[i]>b[j]){
        aux = b[i];
        b[i] = b[j];
        b[j] = aux;
      }
    }
  }
}

////////////////////////////////////////////////////
