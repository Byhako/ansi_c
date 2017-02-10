// Numeros primos

#include <stdio.h>

int main(){

  int n,i,ban;

  printf("Introduce un numero: ");
  scanf("%i",&n);

  // verifico si es primo
  for(i=2 ; i<=n/2 ; i++){
    ban = n%i;
    if(ban==0)break;
  }

  //salida
  if (ban==0){
    printf("%i no es primo. %i\n",n,i );
  }
  else {printf("%i si es primo. %i\n",n,i );}

  return 0;
}