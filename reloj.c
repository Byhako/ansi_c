// Cronometro

#include <stdio.h>
#include <unistd.h>
//#include <windows.h>

int main (){

	int h, min, seg, t;

	t = 1000000;

	for(h=0 ; h<24 ; h++){
		for(min=0 ; min<60 ; min++){
			for(seg=0 ; seg<60 ; seg++){
				printf("%02i:%02i:%02i\n",h,min,seg);
				//Sleep(t);
				usleep(t); // Duerme el equipo t microsegundos.
			}
		}
	}
}