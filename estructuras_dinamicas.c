
// Estructuras Dinamicas realizando un Juego de Batallas por turno donde se
// enfrentan un Heroe contra una serie de Malos.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
  int salud,mana,fuerza,magia;
}heroe;

typedef struct{
  int salud, fuerza;
}malo;

heroe yo;
malo *otros;

void introduceyo();
void introducemalo(int N);
void asignamem(int *N);

////////////////////////////////////////////////////////////////

int main(){

  int op,i,objetivo,pegar;
  int cont = 0;
  int N = 0;

  introduceyo();  //inicializamos heroe

  asignamem(&N);  //asigna memoria a malos

  printf("\n");
  do{
    do{
      printf("(1) Atacar. \n");
      printf("(2) Magia. \n" );
      scanf("%i",&op);
    }while(op<1 || op>2);

    printf("Elige al malo que deseas atacar:\n");
    for(i=0 ; i<N ; i++){
      printf("Malo %i tiene una vida de %i.\n",i,otros[i].salud);
    }
    scanf("%i", &objetivo);
    printf("\n");

    if(otros[objetivo].salud>0){
      switch(op){
        case 1:{
          pegar = yo.fuerza;
          printf("He pegado %i: \n",pegar);
          otros[objetivo].salud -= pegar;
          printf("La salud del malo %i es %i.\n",
                objetivo,otros[objetivo].salud);

          break;
        }
        case 2:{
          if(yo.mana>0){
            pegar = yo.magia*(rand()%10);
            printf("He pegado %i: \n",pegar);
            otros[objetivo].salud -= pegar;
            printf("La salud del malo %i es %i.\n",
                  objetivo,otros[objetivo].salud);
          }
          else{
            printf("No tienes mana!!\n");
          }
          break;
        }
      }
    }
    else{
      printf("Deja a los cadaveres!!\n");
    }

    printf("\n");
    printf("Truno de los malos: \n");
    for(i=0 ; i<N ; i++){
      if(otros[i].salud>0){
        pegar = otros[i].fuerza*(rand()%10);
        printf("El malo %i me a pegado %i.\n",i,pegar);
        yo.salud -= pegar;
        printf("Te queda una salud de %i:\n\n",yo.salud);
      }
    }

    if((cont%2)==0){
      otros = (malo*)realloc(otros,(N+1)*sizeof(malo));
      if(otros==NULL){
        printf("No se ha podido reservar memoria. \n");
        exit(1);
      }
      introducemalo(N);
      N++;
    }
    cont++;
  }while(yo.salud>0);

  free(op);
  free(i);
  free(objetivo);
  free(pegar);
  free(cont);
  free(N);
  return 0;
}

////////////////////////////////////////////////////////////////

void introduceyo(){
  yo.salud = 1000;
  yo.mana = 100;
  yo.fuerza = 50;
  yo.magia = 10;
}

////////////////////////////////////////////////////////////////

void introducemalo(int N){
  otros[N].salud = 100;
  otros[N].fuerza = 5;
}

////////////////////////////////////////////////////////////////

void asignamem(int *N){
  otros = (malo*)malloc((*N+1)*sizeof(malo));
  if(otros==NULL){
    printf("No se pudo resevar memoria.");
    exit(1);
  }
  introducemalo(*N);
  (*N)++;
}

////////////////////////////////////////////////////////////////