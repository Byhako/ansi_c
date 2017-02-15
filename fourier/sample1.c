/* Transformada de fourier 1D para señal con solo parte real
	 y completado.

================================
Ruben E Acosta
eldragondera1@gmail.com
Universidad de Antioquia
================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <fftw3.h>


///////////////////////////////////////////////////////////////////
int main(){
	int r,N,cont=0;
	float *h;
	char temp[10];
	char aux;

	FILE *datos;
	FILE *pf;

	fftw_complex *in;
	fftw_complex *out;
	fftw_plan fwd_plan, bck_plan;

// Cargar datos en array
//------------------------------------------------------------------------
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

	// Verifico si cont es potencia de 2, si no, busco numero par mas cercano.
	r = ceil(sqrt(cont));
	if(r%2 != 0){r++;}

	N = r*r;  // numero de datos de entrada.

	// reservo memoria
	h = (float*)calloc(N,sizeof(float));
	//h = (float*)malloc(N*sizeof(float));
	if(h==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}

	for(int i=0 ; i<cont ; i++){
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
//------------------------------------------------------------------------
//------------------------------------------------------------------------


	in   = (fftw_complex *) fftw_malloc(N*sizeof(fftw_complex));
	out  = (fftw_complex *) fftw_malloc(N*sizeof(fftw_complex));
	//******** DO FORWARD FFT ********//
	fwd_plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	printf("\nForward FFTW plan :\n");

	// asigno valores a la intrada
	for(int i=0 ; i<N ; i++){
		in[i][0] = h[i];
		in[i][1] = 0.0;
	}

	fftw_execute(fwd_plan);

	//-----------------------------------------------------
	pf = fopen("forwardValues.dat","w");
	for(i=0; i<N; i++) 
		fprintf(pf,"%.3e %.3e \n",out[i][0], out[i][1]); 
	fclose(pf);
	//-----------------------------------------------------

	fftw_destroy_plan(fwd_plan);


	//******** DO BACKWARD FFT ********//

	bck_plan = fftw_plan_dft_1d(NSAMPLES, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
	printf("\nBackward FFTW plan :\n");

	fftw_execute(bck_plan); 

	//-----------------------------------------------------
	pf = fopen("inverseValues.dat","w");
	for(i=0; i<N; i++)
		fprintf(pf,"%.3e %.3e \n",in[i][0], in[i][1]); 
	fclose(pf);
	printf("\n");
	//-----------------------------------------------------

	fftw_destroy_plan(bck_plan);



	cfree(h);
	fftw_free(in);
	fftw_free(out);
	return 0;
}

/////////////////////////////////////////////////////////////

/*

Los datos de entrada estan en un array donde:
  
  in[i][0] -> parte real
  in[i][1] -> parte compleja



FFTW_MEASURE: find the optimal plan by actually computing several FFTs 
FFTW_ESTIMATE: do not run any FFT and provide a "reasonable" plan
FFTW_OUT_OF_PLACE: a plan assumes that the in and out are distinct 
FFTW_IN_PLACE: a plan assumes that the in and out are same
*/