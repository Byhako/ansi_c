#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cambio(char c3[]);
void cambiaL(char c1[]);

////////////////////////////////////////////////////
int main(){

  char c1[5],c2[5];

  printf("Introduce una frase: ");
  //scanf("%s",&vector); // termina la captura por teclado al poner espacio
  //gets(vector); // sobre escribe partes de la memora que no son de el
  //fflush(stdin)  vacia boofer en windows
  setbuf(stdin,NULL); // vaciar el boofer inicialmente
  fgets(c1,5,stdin); //donde guarda,tamano,de donde los toma.
                     //stdin -> entrada estandar,  osea el teclado
  while(getchar()!='\n'); // vaciar el boofer

  printf("Segunda frase: ");

  fgets(c2,5,stdin);
  while(getchar()!='\n'); // vaciar el boofer

  // c1 == c2  no compara string, compara direccions de memoria
  // strcmp(c1,c2) compara los string y retorna 0 si son iguales.
  if ( strcmp(c1,c2) == 0 ){
     printf("Los dos strings son iguales.\n");
   }
  else{printf("No son iguales.\n");}

  // *** ACCEDER A ELEMENTOS DEL STRING ***************

  char c3[10];
  printf("Introduce una frase: ");

  fgets(c3,10,stdin);
  while(getchar()!='\n'); // vaciar el boofer
  
  cambio(c3);

  printf("%s\n",c3);

  // *** CAMBIO LETRA A POR ESPACIO  *******************

  char c4[] = "me gusta mucho programar";

  cambiaL(c4);
  printf("%s\n",c4);

  // ***** STRING DINAMICOS **********************

  char *libro;
  char aux[50];

  printf("Introduce el nombre del libro:\n");
  fgets(aux,50,stdin);
  cambio(aux);

  libro = (char*)malloc((strlen(aux))*sizeof(char));
  if(libro==NULL){
    printf("Error de asignacion.\n");
    exit(1); // sale del programa
  }

  strcpy(libro,aux);

  printf("Mi libro %s\n",libro);

  free(libro);
  return 0;
}

////////////////////////////////////////////

void cambio(char c3[]){
  int n;

  n = strlen(c3);
  c3[n-1]='\0';
  
}

//normalmente los strings terminan en \0, pero con fgets
//la cadena termina en \n, por eso esta esta funcion
//para corregir esto
////////////////////////////////////////////

void cambiaL(char c1[]){
  int limite,i;

  limite = strlen(c1);

  for(i=0 ; i<limite ; i++){
    if(c1[i]=='a'){c1[i]=' ';}
  }
}
///////////////////////////////////////////