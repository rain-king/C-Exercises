#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char s1[100], s2[100];

	fgets(s1, 100, stdin);
	fgets(s2, 100, stdin);

	if (strcmp(s1, s2) > 0)
		printf("La primer cadena es mayor que la segunda\n");
	if (strcmp(s1, s2) == 0)
		printf("Las cadenas son iguales\n");
	if (strcmp(s1, s2) < 0)
		printf("La primer cadena es menor que la segunda\n");

	return 0;
}
