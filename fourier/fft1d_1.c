/* Transformada de fourier 1D para señal con solo parte real.

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
int main(){
	int N, i, j, cont = 0;
	float dt;
	float *h = NULL;
	float *f = NULL;
	char temp[10];
	char aux;

	FILE *datos = NULL;
	FILE *pf = NULL;

	fftw_complex *in = NULL;
	fftw_complex *out = NULL;
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

	N = cont;   // numero de datos de entrada.

	// reservo memoria
	//h = (float*)calloc(N,sizeof(float));
	h = (float*)malloc(N*sizeof(float));
	if(h==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}

	for(i=0 ; i<cont ; i++){
		aux = 0;

		for(j=0 ; aux!='\n' ; j++){
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

	dt = 0.08/N;

	in   = (fftw_complex *) fftw_malloc(N*sizeof(fftw_complex));
	out  = (fftw_complex *) fftw_malloc(N*sizeof(fftw_complex));
	//******** DO FORWARD FFT ********//
	fwd_plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	printf("\nForward FFTW plan :");

	// asigno valores a la intrada
	for(i=0 ; i<N ; i++){
		in[i][real] = h[i];
		in[i][imag] = 0.0;
	}

	fftw_execute(fwd_plan);
	printf("DONE.\n");

	f = (float*)malloc(N*sizeof(float));
	frecuencias(f, N, dt);

	//-----------------------------------------------------
	pf = fopen("directa.dat","w");
	for(i=0; i<N; i++) 
		fprintf(pf,"%0.3lf  %12.3lf\n",f[i],out[i][real]); 
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
		fprintf(pf,"%lf\n",in[i][real]/N); 
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

/*

Los datos de entrada estan en un array donde:
  
  in[i][0] -> parte real
  in[i][1] -> parte compleja



FFTW_MEASURE: find the optimal plan by actually computing several FFTs 
FFTW_ESTIMATE: do not run any FFT and provide a "reasonable" plan
FFTW_OUT_OF_PLACE: a plan assumes that the in and out are distinct 
FFTW_IN_PLACE: a plan assumes that the in and out are same
*/