/* Transformada de fourier 1D para señal con parte real y compleja.

================================
Ruben E Acosta
eldragondera1@gmail.com
Universidad de Antioquia
================================

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define real 0
#define imag 1

void frecuencias(float *x, int N, float dt);

///////////////////////////////////////////////////////////////////
int main()
{
	int i, c, j, N;
	int filas = 0, columnas = 2;
	float *f = NULL;
	float **h = NULL;
	char temp[10];
	char aux, aux1, aux2;

	FILE *datos = NULL;
	FILE *pf = NULL;

	fftw_complex *in = NULL;
	fftw_complex *out = NULL;
	fftw_plan fwd_plan, bck_plan;

	

//------------------------------------------------------------------------
	datos = fopen("funcion2.dat","r");
	if(datos==NULL){
		printf("El archivo no se abrio.\n");
		exit(1);
	}

	// cuento cuantas lineas tiene el archivo
	aux = 0;
	while(aux!=EOF){
		aux = fgetc(datos);
		if(aux=='\n'){filas++;}
	}

	rewind(datos);  // regresa el cursor al inicio del archivo

	// reservo memoria

	h = (float**)malloc(filas*sizeof(float*));
	if(h==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}

	for(i=0 ; i<filas ; i++){
		h[i] = (float*)malloc(columnas*sizeof(float));
		if(h[i]==NULL){
			printf("No se pudo reservar espacio. ");
			exit(1);
		}
	}

	//Cargo archivo

	for(i=0 ; i<filas ; i++){
		aux1 = 0;
		aux = ' ';
		c = 0;
		j = 0;

		while(aux1!='\n'){
			aux1 = fgetc(datos);
			aux2 = aux;

			if(aux1!=' ' && aux1!='\n'){
				temp[j] = aux1;
				j++; 
			}

			if(aux1==' ' && aux2!=' '){
				h[i][c] = atof(temp);
				c++;
				j = 0;
			}

			if(aux1=='\n'){
				h[i][c] = atof(temp);
				c++;
				j = 0;
			}

			aux = aux1;
		}
	}

	fclose(datos);
//------------------------------------------------------------------------

	N = filas;

	in   = (fftw_complex *) fftw_malloc(N*sizeof(fftw_complex));
	out  = (fftw_complex *) fftw_malloc(N*sizeof(fftw_complex));
	//******** DO FORWARD FFT ********//
	fwd_plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	printf("\nForward FFTW plan :");

	// asigno valores a la intrada
	for(i=0 ; i<N ; i++){
		in[i][real] = h[i][real];
		in[i][imag] = h[i][imag];
	}

	fftw_execute(fwd_plan);
	printf("DONE.\n");

	f = (float*)malloc(N*sizeof(float));
	frecuencias(f, N, dt);

	//-----------------------------------------------------
	pf = fopen("directa.dat","w");
	for(i=0; i<N; i++) 
		fprintf(pf,"%.3e\n",out[i][real]); 
	fclose(pf);
	//-----------------------------------------------------

	fftw_destroy_plan(fwd_plan);


	//******** DO BACKWARD FFT ********//

	bck_plan = fftw_plan_dft_1d(N, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
	printf("\nBackward FFTW plan :");

	fftw_execute(bck_plan); 
	printf("DONE.\n");
	//-----------------------------------------------------
	pf = fopen("inversa.dat","w");
	for(i=0; i<N; i++)
		fprintf(pf,"%.3e\n",in[i][real]/N); 
	fclose(pf);
	printf("\n");
	//-----------------------------------------------------

	fftw_destroy_plan(bck_plan);


	free(h);
	fftw_free(in);
	fftw_free(out);
	return 0;
}

/////////////////////////////////////////////////////////////

void frecuencias(float *x, int N, float dt){
	float i, df, fmax, fmin;
	int con = 0;
	
	df = 1/(N*dt);
	fmax = 1/(2*dt);
	fmin = df - fmax;

	for(i=0 ; i<fmax+df ; i=i+df){
		x[con] = i;
		con++;
	}
	
	for(i=fmin ; i<0 ; i=i+df){
		x[con] = i;
		con++;
	}

}
/////////////////////////////////////////////////////////////