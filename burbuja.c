#include <stdio.h>

/////////////////////////////////////////////////////////
int main(){
	const int c=10;
	int aux,n,i,j;
	int v[c];

	printf("Ingresa los valores:\n");
	
	for(i=0 ; i<c ; i++){

		scanf("%i",&n);
		v[i] = n;
	}
	printf("vertor desordenado:\n");

	for(i=0 ; i<c ; i++){  // muestro el vector
		printf(" %i ",v[i]);
	}
	printf("\n");

	for(i=c ; i>0 ; i--){   // limite ultima cifra

		for(j=0 ; j<i-1 ; j++){

			if(v[j]>v[j+1]){  // comparo y ordeno
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}

	printf("vertor ordenado:\n");

	for(i=0 ; i<c ; i++){
		printf(" %i ",v[i]);
	}
	printf("\n");

	return 0;
}

/////////////////////////////////////////////////////////