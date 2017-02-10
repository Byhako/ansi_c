// Hola mundo

#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Hola Mundo\n");
  getchar();
  int a,b;
  float c;
  a = 5.0;
  b = 2.0;
  c = 2.0;

  printf("%d   %f\n", a/b,a/c );
  printf("Resultado; %s\n", (a==5)?"cinco":"error" );

  return 0;
}