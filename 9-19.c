#include <stdio.h>

int main()
{
	printf("printf(\"Hola%%c\\n\", \"?\");\n");
	printf("Hola%c\n\n", "?");

	printf("printf(\"Hola%%c\\n\", *\"?\");\n");
	printf("Hola%c\n\n", *"?");

	printf("printf(\"Hola%%s\\n\", \"?\");\n");
	printf("Hola%s\n\n", "?");

	printf(
"Como se puede ver, solo se imprime \"?\" si se desreferencia el caracter o se "
"\n"
"usa el especificador de conversion \"%%s\"\n"
	);
}
