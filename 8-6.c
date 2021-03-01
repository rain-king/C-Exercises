#include <stdio.h>
#include <ctype.h>

int main()
{
	int i;
	char s[100];

	//fgets(s, 100, stdin);
	gets(s);

	printf("\n");

	for (i = 0; i < 100; i++)
	{
		putchar(toupper(s[i]));
		if (s[i] == '\0')
		{
			printf("\n");
			break;
		}
	}

	for (i = 0; i < 100; i++)
	{
		putchar(tolower(s[i]));
		if (s[i] == '\0')
		{
			printf("\n");
			break;
		}
	}
	return 0;
}
