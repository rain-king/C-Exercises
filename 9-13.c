#include <stdio.h>
#include <string.h>
#include <ctype.h>

float celsius(float fahrenheit);
float fahrenheit(float celsius);

int main()
{
	int i, j;
	char s[15];

	printf("Fahrenheit -> Celsius\n");
	for (i = 0; i <= 212; i++)
		if (celsius(i) < 0)
			printf("%10d %10.3f\n", i, celsius(i));
		else
		{
			printf("%10d ", i);
			sprintf(s, "%10.3f", celsius(i));
			for (j = 0; j < 15; j++)
			{
				if (isgraph(s[j+1]) && isspace(s[j]))
				{
					printf("+");
				}
				else if (isprint(s[j]))
					printf("%c", s[j]);
			}
			printf("\n");
		}
	return 0;
}

float celsius(float fahrenheit)
{
	return (fahrenheit-32)*5/9;
}

float fahrenheit(float celsius)
{
	return celsius*9/5+32;
}
