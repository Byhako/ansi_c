#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Pareja Pareja;
typedef struct Diccionario Diccionario;
typedef struct Arreglo Arreglo;

struct Pareja{
  const char *llave;
  const char *valor;
};

struct Diccionario{
  Pareja **parejas;
  int tamano;
};

struct Arreglo{
  const char **arreglo;
  int tamano;
};

//////////////////////////////////////////////////////////////////////
Diccionario *nuevo_dic(void){
  Diccionario *D = (Diccionario *) malloc(sizeof(Diccionario));
  D->parejas = NULL;
  D->tamano = 0;
  return D;
}
//////////////////////////////////////////////////////////////////////
void muestra_dic(const Diccionario *D){
  int i;
  for(i=0 ; i<D->tamano ; i++){
    printf("%s: %s\n",D->parejas[i]->llave, D->parejas[i]->valor);
  }
}
//////////////////////////////////////////////////////////////////////
void inicializa_cotenido(Diccionario *D){
  int i;
  for(i=0 ; i<D->tamano ; i++){
    D->parejas[i] = (Pareja *) malloc(sizeof(Pareja));
    D->parejas[i]->llave = NULL;
    D->parejas[i]->valor = NULL;
  }
}
//////////////////////////////////////////////////////////////////////
void libera_dic(Diccionario *D){
  int i;
  for(i=0 ; i<D->tamano ; i++){
    free(D->parejas[i]);
  }
  free(D->parejas);
  free(D);
}
//////////////////////////////////////////////////////////////////////
void copia_dic(const Diccionario *Do, Diccionario *Dd, int unidades){
  int i;
  for(i=0 ; i<unidades ; i++){
    Dd->parejas[i]->llave = Do->parejas[i]->llave;
    Dd->parejas[i]->valor = Do->parejas[i]->valor;
  }
}
//////////////////////////////////////////////////////////////////////
void aumenta_dic(Diccionario **D, int unidades){
  Diccionario *E = nuevo_dic();
  E->tamano = (**D).tamano;
  E->parejas = (Pareja **) calloc(E->tamano, sizeof(Pareja));
  inicializa_cotenido(E);
  copia_dic(*D, E, E->tamano);
  libera_dic(*D);
  *D = nuevo_dic();
  (**D).tamano = E->tamano + unidades;
  (**D).parejas = (Pareja **) calloc((**D).tamano, sizeof(Pareja));
  inicializa_cotenido(*D);
  copia_dic(E, *D , E->tamano);
  libera_dic(E);
}
//////////////////////////////////////////////////////////////////////
void agrega_dic(Diccionario *D, const char *llave,const char *valor){
  aumenta_dic(&D,1);
  D->parejas[D->tamano - 1]->llave = llave;
  D->parejas[D->tamano - 1]->valor = valor;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
Arreglo *arreglo_nuevo(void){
  Arreglo *A = (Arreglo *) malloc(sizeof(Arreglo));
  A->arreglo = NULL;
  A->tamano = 0;
  return A;
}
//////////////////////////////////////////////////////////////////////
void arreglo_libera(Arreglo *A){
  free(A->arreglo);
  free(A);
}
//////////////////////////////////////////////////////////////////////
void arreglo_copia(const Arreglo *Ao, Arreglo *Ad,int unidades){
  int i;
  for(i=0 ; i<unidades ; i++){
    Ad->arreglo[i] = Ao->arreglo[i];
  }
}
//////////////////////////////////////////////////////////////////////
void arreglo_aumenta(Arreglo **A, int unidades){
  Arreglo *N = arreglo_nuevo();
  N->arreglo = (const char **) calloc((**A).tamano,sizeof(const char **));
  N->tamano = (**A).tamano;
  arreglo_copia(*A,N,N->tamano);
  arreglo_libera(*A);
  *A = arreglo_nuevo();
  (**A).tamano = N->tamano + unidades;
  (**A).arreglo = (const char **) calloc((**A).tamano, sizeof(const char **));
  arreglo_copia(N,*A,N->tamano);
  arreglo_libera(N);
}
//////////////////////////////////////////////////////////////////////
void arreglo_agrega(Arreglo *A, const char *palabra){
  arreglo_aumenta(&A,1);
  A->arreglo[A->tamano - 1] = palabra;
}
//////////////////////////////////////////////////////////////////////
void arreglo_muestra(const Arreglo *A){
  int i;
  for(i=0 ; i<A->tamano ; i++){
    printf("%s\n",A->arreglo[i]);
  }
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
Arreglo *llave_dic(const Diccionario *D, const char *llave){
  Arreglo *A = arreglo_nuevo();
  int i;
  for(i=0 ; i<D->tamano ; i++){
    if(D->parejas[i]->llave == llave){
      arreglo_agrega(A, D->parejas[i]->valor);
    }
  }
  return A;
}
//////////////////////////////////////////////////////////////////////
Arreglo *valor_dic(const Diccionario *D, const char *valor){
  Arreglo *A = arreglo_nuevo();
  int i;
  for(i=0 ; i<D->tamano ; i++){
    if(D->parejas[i]->valor == valor){
      arreglo_agrega(A, D->parejas[i]->llave);
    }
  }
  return A;
}
//////////////////////////////////////////////////////////////////////
int pos_dic(const Diccionario *D, const char *palabra){
  int i,aux;
  aux = 0;
  for(i=0 ; i<D->tamano && aux==0 ; i++){
    if(D->parejas[i]->valor == palabra || D->parejas[i]->llave == palabra){
      return i+1;
      aux = 1;
    }
  }
}
//////////////////////////////////////////////////////////////////////
#endif