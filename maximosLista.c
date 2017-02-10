// saco los maximos de una lista, y digo cuantas veces estan.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void vaciar(char temp[]);
void copiar(float *a, float *b, int c);
void maximo(float *ma, float *a, int c);
int cuentoMaximo(float *a, float m, int c);
void posicionMaximo(float *x, float m, int c, int *pos);
void borroMaximo(float *y, float m, int cm,int ly);

/////////////////////////////////////////////////////////////
int main(){

	FILE *archivo;
	int i,j,cm,ly;
	float m;
	int cont = 0;
	char temp[25];
	float *x, *y;
	int *pos;


	// ---------------------------------------------------------
	archivo = fopen("dato1.txt","r");
	if(archivo==NULL){
		printf("El archivo no se abrio.\n");
		exit(1);
	}

	while(!feof(archivo)){  // cuento cuantas lineas tiene el archivo
		fgets(temp,25,archivo);
		cont++;
	}

	rewind(archivo);  // regresa el cursor al inicio del archivo

	// reservo memoria
	x = (float*)malloc(cont*sizeof(float));
	if(x==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}
	y = (float*)malloc(cont*sizeof(float));
	if(y==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}
	
	//leo el archivo
	for(i=0 ; !feof(archivo) ; i++){
		vaciar(temp);
		fgets(temp,25,archivo);
		//toma caracteres numericos, los pasa a float y los guarda
		x[i] = atof(temp);
	}

	fclose(archivo);
	// ---------------------------------------------------------

	copiar(x, y, cont);
	ly = cont; //longitud de y
	
	for(i=0 ; i<7 ; i++){ // 7 maximos a sacar
		
		maximo(&m,y,ly);
		cm = cuentoMaximo(x,m,cont);

		// reservo memoria
		pos = (int*)malloc(cm*sizeof(int));
		if(pos==NULL){
			printf("No se pudo reservar memoria.\n");
			exit(1);
		}
		
		posicionMaximo(x,m,cont,pos);
		borroMaximo(y,m,cm,ly);
		ly = ly - cm;
		
		printf("El numero %f esta en la posicion:\n",m);

		for(j=0 ; j<cm ; j++){
			printf("%i, ",pos[j]);
		}
		printf("\n");
	}

	free(x);
	free(y);
	free(pos);

	return 0;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

void vaciar(char temp[]){
	/*
	vacio variable temp
	*/
	int i;

	for(i=0 ; i<25 ; i++){
		temp[i] = '\0';
	}
}

/////////////////////////////////////////////////////////////

void copiar(float *a, float *b, int c){
	/*
	a -> vector origen
	b -> vector destino
	c -> tamano de los vectores
	*/
 int i;

	for(i=0 ; i<c ; i++){
		b[i] = a[i];
	}
}

/////////////////////////////////////////////////////////////

void maximo(float *ma, float *a, int c){
	/*
	ma -> direccion en memoria para guardar maximo
	a -> vector donde se busca
	c -> longitud de a
	*/
	int i;
	float j;
	for(i=1 ; i<c ; i++){
		if(a[i]>j){
			j = a[i];
		}
	}

	*ma = j;
}
/////////////////////////////////////////////////////////////

int cuentoMaximo(float *a, float m, int c){
	/*
	a -> vector donde busco
	m -> maximo a contar
	c -> longitud de a
	*/
	int i,j=0;
	for(i=0 ; i<c ; i++){
		if(a[i]==m){j++;}
	}
	return j;
}
/////////////////////////////////////////////////////////////

void posicionMaximo(float *x, float m, int c, int *pos){
	/*
	x -> vector donde busco
	m -> numero a buscar
	c -> longitud de x
	pos -> vector donde guardo las posiciones de m
	*/

	int i,j=0;
	
	for(i=0 ; i<c ; i++){
		if(x[i]==m){
			pos[j] = i;
			j++;
		}
	}

}

/////////////////////////////////////////////////////////////

void borroMaximo(float *y, float m, int cm,int l){
	/*
	y -> vector en el que borro m
	m -> numero a borrar
	cm -> cuantas m  debo borrar
	l -> longitud de y
	*/

	int lz,i,j=0;
	float *z;

	lz = l - cm;

	// reservo memoria
	z = (float*)malloc(lz*sizeof(float));
	if(z==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}
	
	for(i=0 ; i<l ; i++){
		if(y[i]!=m){
			z[j] = y[i];
			j++;
		}
	}
	
	// redimenciono y
	y = (float*)realloc(y,lz*sizeof(float));
	
	copiar(z,y,lz);
	
	free(z);
}
/////////////////////////////////////////////////////////////