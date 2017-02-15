#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void vaciar(char temp[]);

///////////////////////////////////////////////////////////////////
int main(){
	int r,cont=0;
	float n;
	float *h;
	char temp[10];
	char aux;

	FILE *datos;

	datos = fopen("funcion.dat","r");
	if(datos==NULL){
		printf("El archivo no se abrio.\n");
		exit(1);
	}

	// cuento cuantas lineas tiene el archivo
	aux = 0;
	while(aux!=EOF){
		aux = fgetc(datos); // lee caracter a caracter
		if(aux=='\n'){cont++;}
	}

	rewind(datos);  // regresa el cursor al inicio del archivo
	printf("Numero de lineas: %i\n",cont);

	// Verifico si cont es potencia de 2, si no, busco numero par mas cercano.
	r = ceil(sqrt(cont));
	if(r%2 != 0){r++;}

	// reservo memoria
	h = (float*)calloc(r*r,sizeof(float));
	//h = (float*)malloc(r*r*sizeof(float));
	if(h==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}

	for(int i=0 ; i<cont ; i++){
		vaciar(temp);  // vacio variable temp
		aux = 0;

		for(int j=0 ; aux!='\n' ; j++){
			aux = fgetc(datos);
			if(aux!='\n'){
				temp[j] = aux; 
			}
		}

		h[i] = atof(temp);
	}
	
	fclose(datos);

	for(int i=0 ; i<r*r ; i++){
		printf("%lf\n",h[i]);
	}

	cfree(h);
	return 0;
}

/////////////////////////////////////////////////////////////

void vaciar(char temp[]){
	int i;

	for(i=0 ; i<10 ; i++){
		temp[i] = '\0';
	}
}

/////////////////////////////////////////////////////////////
