#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void formatear(int ip, int mascara, int ipred, int cidr);
void obtenerMascara(int cidr, int* mascara);

int main(){

	FILE* fp = fopen("ficheroip.txt", "r");
	//Variables de lectura de valores
	
	int byte1, byte2, byte3, byte4, cidr;
	//Variables donde codificaré las ips en binario
	int ipbin , mascara , red ;
		
	char* bytes;
	while(fscanf(fp ,"%d.%d.%d.%d/%d", &byte1, &byte2, &byte3, &byte4, &cidr) != EOF){
		ipbin = mascara = red = 0;
	
		bytes = (char* )&ipbin;
		bytes[0] = byte1;
		bytes[1] = byte2;
		bytes[2] = byte3;
		bytes[3] = byte4;
		
		obtenerMascara(cidr, &mascara);
		int red = ipbin & mascara;
		formatear(ipbin, mascara, red, cidr);	
	}
	fclose(fp);
	return 0;
}

void obtenerMascara( int cidr, int* mascara){
	char* bytes = (char*)mascara;
	
	//Calculo cuantos bytes de la mascara estan a 1
	int numBytes = cidr / 8;
	int i;
	for(i = 0; i < numBytes; i++){
		bytes[i] = (unsigned char)255;
	}
		
	//Relleno los bits restantes (si hay)
	int numBits = cidr % 8;
	if(numBits > 0){
		//calculo cuantos estan a 1
		int valor = (1 << numBits) -1;
		//desplazo tanto como esten a 0
		int desplazamiento = 8 - numBits;
		bytes[numBytes] = valor << desplazamiento;
	}
}

void formatear(int ip, int mascara, int ipred, int cidr){
	char* bytes = (char * )&ip;
	printf("Linea leida %u.%u.%u.%u/%u\n", (unsigned char)bytes[0], (unsigned char)bytes[1], (unsigned char)bytes[2], (unsigned char)bytes[3], cidr);
	printf("ip: %u.%u.%u.%u - ", (unsigned char)bytes[0], (unsigned char)bytes[1], (unsigned char)bytes[2], (unsigned char)bytes[3]);
	
	bytes = (char * )&mascara;
	printf("mascara: %u.%u.%u.%u - ", (unsigned char)bytes[0], (unsigned char)bytes[1], (unsigned char)bytes[2], (unsigned char)bytes[3]);
	
	bytes = (char * )&ipred;
	printf("red: %u.%u.%u.%u -\n", (unsigned char)bytes[0], (unsigned char)bytes[1], (unsigned char)bytes[2], (unsigned char)bytes[3]);
	puts("---------------------");
}
