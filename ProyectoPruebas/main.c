#include <stdio.h>
//#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int var = 7;
	puts("hola mundo");
	char cadena[100];
	
	puts("\nintroduce valor:");
	scanf("hola%2d", &var);
	printf("resultado = %d\n", var);
	
	puts("Introduce cadena");
	scanf("%s", cadena);
	puts(cadena);
	fgets(cadena, sizeof(cadena), stdin);
	printf("residuo: %s", cadena);
	
	
	
	return 0;
}
