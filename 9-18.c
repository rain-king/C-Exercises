#include <stdio.h>
// se intenta introducir cadenas del usuario con comas
// resultado: se introducen como caracteres normales en la cadena

int main()
{
	char s[20];

	fgets(s, 20, stdin);

	printf("%s\n", s);

	return 0;
}
