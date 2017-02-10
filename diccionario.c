#include <arreglo.h>
#include <stdio.h>

int main(void){

  Diccionario *D = nuevo_dic();
  agrega_dic(D, "Ubuntu", "Debian");
  agrega_dic(D, "Susse", "Unix");
  agrega_dic(D, "MacOs", "Unix");
  agrega_dic(D, "Windows", "MSDOS");
  //muestra_dic(D);

  printf("%i\n",D->tamano);
  printf("\n");

  Arreglo *linuz = llave_dic(D,"Windows");
  arreglo_muestra(linuz);

  Arreglo *sistema = valor_dic(D,"Unix");
  arreglo_muestra(sistema);

  int x = pos_dic(D,"MacOs");
  printf("%i\n",x);




  return 0;
}