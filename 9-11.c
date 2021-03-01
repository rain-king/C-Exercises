#include <stdio.h>
#include <math.h>

void redondeaAEntero(float numero);
void redondeaADecimas(float numero);
void redondeaACentesimas(float numero);
void redondeaAMilesimas(float numero);
void redondeaADiezMilesimas(float numero);

int main()
{
	float numero = 100.453627;

	printf("%f\n", numero);

	redondeaAEntero(numero);
	redondeaADecimas(numero);
	redondeaACentesimas(numero);
	redondeaAMilesimas(numero);
	redondeaADiezMilesimas(numero);

	printf("\n");

	return 0;
}

void redondeaAEntero(float numero)
{
	printf("%.0f\n", floor(numero+0.5));
}

void redondeaADecimas(float numero)
{
	printf("%.1f\n", floor(numero*10+0.5)/10);
}

void redondeaACentesimas(float numero)
{
	printf("%.2f\n", floor(numero*100+0.5)/100);
}

void redondeaAMilesimas(float numero)
{
	printf("%.3f\n", floor(numero*1000+0.5)/1000);
}


void redondeaADiezMilesimas(float numero)
{
	printf("%.4f\n", floor(numero*10000+0.5)/10000);
}
