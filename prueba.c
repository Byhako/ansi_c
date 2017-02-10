#include <stdio.h>
#include <string.h>

void cambio(char a[]);

////////////////////////////////////////////
int main(){

	char a[20];
	int x;

	printf("mi nombre: ");
	setbuf(stdin,NULL);
	fgets(a,20,stdin);
	while(getchar()!='\n');

	cambio(a);
	printf("cadena original: %s\n",a);
	
	x =strlen(a); // longitud de a

	char cadena[x],s;

	strcpy(cadena,a);

	printf("cadena : %s\n",cadena[0]);

	return 0;
}

////////////////////////////////////////////

void cambio(char a[]){
	int n;

	n = strlen(a);
	a[n-1]='\0';
	
}
////////////////////////////////////////////