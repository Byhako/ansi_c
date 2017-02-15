#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *nombre;
	int edad;
}trabajador;

trabajador *trab;

void vaciar(char temp[]);
void copiar(char temp[], int i);

/////////////////////////////////////////////////////////////
int main(){

	int num;
	char aux;
	char aux2[100];
	FILE *archivo;

	printf("   USO DE fgetc:\n");
// ---------------------------------------------------------
	archivo = fopen("datos.txt","r");
	if(archivo==NULL){
		printf("No se pudo abrir el archivo.\n");
		exit(1);
	}
	
	aux = 0;
	while(aux!=EOF){
		aux = fgetc(archivo); // lee caracter a caracter
		printf("%c",aux);
	}
	printf("\n\n");
	
	fclose(archivo);
// ---------------------------------------------------------

	printf("   USO DE fgets:\n");
// ---------------------------------------------------------
	archivo = fopen("datos.txt","r");
	if(archivo==NULL){
		printf("No se pudo abrir el archivo.\n");
		exit(1);
	}

	while(!feof(archivo)){
		fgets(aux2,100,archivo);  // lee toda la linea
		printf("%s",aux2);
	}
	printf("\n\n");

	fclose(archivo);
// ---------------------------------------------------------
// TOMAR DATOS DE TRABAJADORES.TXT Y METERLOS A UNA ESTRUCTURA

	printf("****** TRABAJADORES ******\n\n");
	char temp[50];
	int i,j,cont = 0;
	FILE *f;

// ---------------------------------------------------------
	f = fopen("trabajadores.txt","r");

	if(f==NULL){
		printf("El archivo no se abrio.\n");
		exit(1);
	}

	while(!feof(f)){  // cuento cuantas lineas tiene el archivo
		fgets(temp,50,f);
		cont++;
	}

	rewind(f);  // regresa el cursor al inicio del archivo
	
	// reservo memoria
	trab = (trabajador*)malloc(cont*sizeof(trabajador));
	if(trab==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}

// leo archivo
	for(i=0 ; !feof(f) ; i++){
		vaciar(temp);  // vacio variable temp
		aux = 0;

		// leo caracteres 1-1 para hacer el nombre
		for(j=0 ; aux!=' ' ; j++){
			aux = fgetc(f);
			if(aux!=' '){
				temp[j] = aux; // guardo 1-1 los caracteres hasta end nombre
			}
		}

		copiar(temp,i);

		//continuo lectura para hacer la edad
		fgets(temp,5,f);
		//toma caracteres numericos, las pasa a int y los guarda
		trab[i].edad = atoi(temp);

		printf("Nombre : %s, Edad : %i.\n",trab[i].nombre,trab[i].edad);

	}
	fclose(f);
// ---------------------------------------------------------

// ESCRIBIR EN UN FICHERO DE TEXTO

	FILE *lapiz;
// ---------------------------------------------------------
	lapiz = fopen("Nuevo.dat","w");
	if(lapiz==NULL){
		printf("El archivo no se abrio.\n");
		exit(1);
	}

	printf("Dame un numero: ");
	scanf("%i",&num);

	fprintf(lapiz, "%i\n",num);

	fclose(lapiz);
	// ---------------------------------------------------------

	return 0;
}
/////////////////////////////////////////////////////////////

void vaciar(char temp[]){
	int i;

	for(i=0 ; i<50 ; i++){
		temp[i] = '\0';
	}
}

/////////////////////////////////////////////////////////////

void copiar(char temp[], int i){
	int N = strlen(temp) + 0;
	trab[i].nombre = (char*)malloc(N*sizeof(char));
	if(trab[i].nombre==NULL){
		printf("No se pudo reservar memoria.\n");
		exit(1);
	}

	strcpy(trab[i].nombre,temp);
}

/////////////////////////////////////////////////////////////

/*
El ultimo caracter que lee del fichero es EOF
*/