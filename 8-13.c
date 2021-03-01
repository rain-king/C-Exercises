#include <stdio.h>
#include <ctype.h>
#include <string.h>

void imprimePalabraLatin(const char *palabra);

int main()
{
        int i;
        char s[200], *ptr;

        fgets(s, 200, stdin);

	ptr = strtok(s, " ");
	while (ptr != NULL)
	{
		imprimePalabraLatin(ptr);
		printf(" ");
		ptr = strtok(NULL, " ");
	}

	printf("\n");

	return 0;
}

void imprimePalabraLatin(const char *palabra)
{
	char palabraLatin[20];
	int i;

	for (i = 0; i < 20; i++)
	{
		if (palabra[i+1] != '\n' && palabra[i+1] != '\0')
			printf("%c", palabra[i+1]);
		else
		{
			printf("%c", palabra[0]);
			break;
		}
	}
	printf("%s", "ay");
}
