//Realizar un programa para controlar varias bibliotecas usando estructuras dentro de estructuras

#include <stdio.h>
#include <string.h>
#define N 50

void vacio();
void cambio(char palabra[N]);
void anadebi();
void anadelib();
void consulta();

typedef struct{
  char nombre_lib[N];
  char autor[N];
  int lleno_lib;  // 0->vacio  1->lleno
}libro;

typedef struct{
  char nombre_bi[N];
  libro lib[10];
  int lleno_bi;
}biblioteca;

biblioteca bi[3];

/////////////////////////////////////////////////////////////////////

int main(){
  int op;
  char key;

  vacio();

  do{
    do{
      printf("Elige una opcion a realizar: \n");
      printf("(1) Añadir una nueva biblioteca.\n");
      printf("(2) Añadir un libro a una biblioteca.\n");
      printf("(3) Consultar un libro.\n");
      printf("--> ");
      scanf("%i",&op);

    }while(op<1 || op>3);

    switch(op){
      case 1:{
        anadebi();
        break;
      }
      case 2:{
        anadelib();
        break;
      }
      case 3:{
        consulta();
        break;
      }
    }

    printf("Quieres realizar alguna operacion mas? (S/N): ");
    scanf(" ");
    scanf("%c",&key);

  }while(key=='S' || key=='s');

  return 0;
}

//////////////////////////////////////////////////////////////

void vacio(){
  int i,j;
  for (i=0 ; i<3 ; i++){
    bi[i].lleno_bi = 0;
    for (j=0 ; j<10 ; j++){
      bi[i].lib[j].lleno_lib = 0;
    }
  }
}

//////////////////////////////////////////////////////////////

void cambio(char palabra[N]){
  int i;

  for (i=0 ; i<N ; i++){
    if (palabra[i] == '\n'){
      palabra[i] = '\0';
    }
  }
}

//////////////////////////////////////////////////////////////

void anadebi(){
  int i,aux;

  aux = 0;

  for(i=0 ; i<3 && aux==0 ; i++){
    if(bi[i].lleno_bi==0){
      printf("Introduce un nombre para la biblioteca: ");
      scanf(" ");
      fgets(bi[i].nombre_bi,N,stdin);
      cambio(bi[i].nombre_bi);

      bi[i].lleno_bi = 1;
      aux = 1;
    }
  }

  if(aux==0){
    printf("La biblioteca esta llena.\n");
  }
}

//////////////////////////////////////////////////////////////

void anadelib(){
  int i,op,aux,ban;

  aux = 0;  // para salir de ciclo for
  ban = 0;  // para saber si no hay bibliotecas

  printf("En cual biblioteca: \n");

  for(i=0 ; i<3 ; i++){
    if(bi[i].lleno_bi==1){
      printf("(%i) %s.\n",i+1,bi[i].nombre_bi);
      ban = 1;
    }
  }

  if(ban==0){
    printf("No hay ninguna biblioteca. Crea una.\n");
    aux = 1;
  }

  printf("--> ");
  scanf("%i",&op);

  for(i=0 ; i<10 && aux==0 ; i++){
    if(bi[op].lib[i].lleno_lib == 0){
      printf("Introduce el nombre del libro: ");
      scanf(" ");
      fgets(bi[op].lib[i].nombre_lib,N,stdin);
      cambio(bi[op].lib[i].nombre_lib);

      printf("Introduce el nombre del autor: ");
      scanf(" ");
      fgets(bi[op].lib[i].autor,N,stdin);
      cambio(bi[op].lib[i].autor);

      bi[op].lib[i].lleno_lib = 1;
      aux = 1;
    }
  }
}

//////////////////////////////////////////////////////////////

void consulta(){
  int i,j,aux,op,ban;
  char buscar[N];

  ban = 0; // para verificar si hay libros

  for (i=0 ; i<3 ; i++){
    for (j=0 ; j<10 ; j++){
      if(bi[i].lib[j].lleno_lib == 1){ban=1;};
    }
  }

  if(ban==0){
    printf("No hay ningun libro.\n");
  }
  else{
    do{
      printf("Que deseas buscar? libro/autor: \n");
      printf("(1) Nombre libro.\n");
      printf("(2) Nombre autor.\n");
      printf("--> ");
      scanf("%i", &op);
    }while(op<1 || op>2);

    switch(op){
      case 1:{
        printf("Nombre del libro: ");
        scanf(" ");
        fgets(buscar,N,stdin);
        cambio(buscar);

        for(i=0 ; i<3 ; i++){
          aux = 1;
          for(j=0 ; j<10 ; j++){
            aux = strcmp(buscar,bi[i].lib[j].nombre_lib);
            if(aux==0){
              printf("El libro %s esta en la biblioteca %s.\n",
                    buscar,bi[i].nombre_bi);
              printf("El autor del libro es %s.\n",bi[i].lib[j].autor);
            }
          }
        }
        break;
      }

      case 2:{
        printf("Nombre del autor: ");
        scanf(" ");
        fgets(buscar,N,stdin);
        cambio(buscar);

        for(i=0 ; i<3 ; i++){
          aux = 1;
          for(j=0 ; j<10 ; j++){
            aux = strcmp(buscar,bi[i].lib[j].autor);
            if(aux==0){
              printf("El libro %s esta en la biblioteca %s.\n",
                    bi[i].lib[j].nombre_lib,bi[i].nombre_bi);
              printf("El autor del libro es %s.\n",bi[i].lib[j].autor);
            }
          }
        }
        break;
      }
    }
  }
}