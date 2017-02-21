#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float funcion(float x);

///////////////////////////////////////////////////////////////////
int main(){

	int n = 128;     // numero de puntos
	float D,e1,e2;   // paso, extremo1, extremo2
	float ti,t,h;
	
	FILE *escribir, *escriba;

	e1 = 0.0;
	e2 = 16.0;
	D = (e2 - e1)/n;

	escribir = fopen("graficar.dat","w");
	escriba = fopen("funcion.dat","w");
		if(escribir==NULL){
		printf("El archivo no se abrio.\n");
		exit(1);
	}

	for(int i=0 ; i<n ; i++){
		ti = i*D;
		t = ti;
		h =funcion(ti-6);
		fprintf(escribir, "%7.4lf   %7.4lf\n",t,h);
		fprintf(escriba, "%7.4lf\n",h);
	}

	fclose(escriba);
	fclose(escribir);

	return 0;
}

///////////////////////////////////////////////////////////////////

float funcion(float x){
	float y;
	//y = (x+4)*(x+1)*(x-5)*(x-8)-100;
	y = sin(x);
	return y;
}

///////////////////////////////////////////////////////////////////