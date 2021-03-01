#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
        char s[20], *ptr, copy[20];
	long numTel;
	int codArea;
	char cadenaNumTel[8];

	// (123) 456-789
        fgets(s, 20, stdin);
	strcpy(copy, s);

	// obteniendo codigo de area
        ptr = strtok(s, " ");
	ptr = strtok(ptr, "(");
	ptr = strtok(ptr, ")");
	codArea = atoi(ptr); //

	strcpy(s, copy);

	// obteniendo numero telefonico
	ptr = strtok(s, " ");
	ptr = strtok(NULL, " ");
	ptr = strtok(ptr, "-");
	// guarda primeros tres numeros
	strcpy(cadenaNumTel, ptr);
	ptr = strtok(NULL, "-");
	// concatena los ultimos cuatro numeros a los primeros tres
	strcat(cadenaNumTel, ptr);
	numTel = atol(cadenaNumTel); //

	printf("Codigo de area: %d\n", codArea);
	printf("Numero telefonico: %ld\n", numTel);

        return 0;
}
