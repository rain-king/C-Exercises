#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
	int i;

	// 5 cada uno
	const char *articulo[] =
	{ "el", "la", "un", "algun", "cualquiera" };

	const char *sustantivo[] = 
	{ "nino", "nina", "perro", "pueblo", "carro" };

	const char *verbo[] =
	{ "condujo", "brinco", "corrio", "camino", "salto" };

	const char *preposicion[] =
	{ "hacia", "desde", "sobre", "bajo", "en" };

	char oracion[100], conLetraMayus[10];

	srand(time(NULL));

	for (i = 0; i < 20; i++)
	{
		sprintf(oracion, "%s %s %s %s %s %s.", 
			articulo[rand()%5], sustantivo[rand()%5],
			verbo[rand()%5],
			preposicion[rand()%5], articulo[rand()%5],
			sustantivo[rand()%5]);
		oracion[0] = toupper(oracion[0]);
		printf("%s ", oracion);
	}
	printf("\n");

	return 0;
}
