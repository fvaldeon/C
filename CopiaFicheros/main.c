#include <stdio.h>
#include <stdlib.h>

void copiarFicheroCadena(char* origen, char* destino);
void copiarFicheroCaracter(char* origen, char* destino);

int main(int argc, char *argv[]) {

	char origen[] = "ficheroip.txt";
	char destino1[] = "ficheroip_copiaChar.txt";
	char destino2[] = "ficheroip_copiaString.txt";
	
	puts("Copiando fichero por caracteres...\n");
	copiarFicheroCaracter(origen,destino1);
	
	puts("\nCopiando fichero por cadenas...\n");
	copiarFicheroCadena(origen, destino2);

}

void copiarFicheroCadena(char* origen, char* destino){
	FILE* fp, *fout;
	
	fp = fopen(origen, "r");
	fout = fopen(destino, "w");
	
	if(fp == NULL || fout == NULL){
		puts("Error al abrir ficheros");
		return;
	}
	char cadena[255];
	while(fgets(cadena, sizeof(cadena), fp) != NULL){
		
		fputs(cadena, fout);
		printf("%s", cadena);
	}
	
	fclose(fp);
	fclose(fout);
}

void copiarFicheroCaracter(char* origen, char* destino){
		FILE* fp, *fout;
	
	fp = fopen(origen, "r");
	fout = fopen(destino, "w");
	
	if(fp == NULL || fout == NULL){
		puts("Error al abrir ficheros");
		return;
	}
	char car;
	while( (car = fgetc(fp)) != EOF ){
		
		fputc(car, fout);
		putchar(car);
	}
	
	fclose(fp);
	fclose(fout);
}
