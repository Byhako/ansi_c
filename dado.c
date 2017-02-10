#include <stdio.h>
void lanzar(int a[6]);

int main(){

  int i;
  int d[6] = {0,0,0,0,0,0};

  lanzar(d);

  for(i=0 ; i<6 ; i++){
	printf ("La probabilidad de %i es %0.2f\n",i+1,d[i]/10000.0);
  }	

  return 0;	
}

///////////////////////////////////////////////////////////////////

void lanzar(int a[6]){
  
  int i,aux;

  for(i=0 ; i<10000 ; i++){
    
    aux = rand()%6;

	switch(aux){

		case 0:{
			a[aux] +=1;		
			break;
		}

		case 1:{
			a[aux] +=1;		
			break;
		}

		case 2:{
			a[aux] +=1;		
			break;
		}

		case 3:{
			a[aux] +=1;		
			break;
		}

		case 4:{
			a[aux] +=1;		
			break;
		}

		case 5:{
			a[aux] +=1;		
			break;
    	}
	}  
  }
}
