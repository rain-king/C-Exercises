#include <stdio.h>

void recorreLaberinto(char lab[12][12], int pos[2], int *direccion);
void moverse(char lab[12][12], int pos[2], int *direccion);
void printLab(char lab[12][12]);

int main()
{
	char extLab[12][12] =
	{
	"############",
	"#...#......#",
	"..#.#.####.#",
	"###.#....#..",
	"#....###.#.#",
	"####.#.#.#.#",
	"#..#.#.#.#.#",
	"##.#.#.#.#.#",
	"#........#.#",
	"######.###.#",
	"#......#...#",
	"############"
	};
	int inicio[2] = {2, 0};

	// 0 arriba, 1 izquierda, 2 abajo, 3 derecha 
	int direccion = 3;

	recorreLaberinto(extLab, inicio, &direccion);
	printf("Se marca con X mayuscula la posicion recorrida mas de una "
			"vez\n");

	return 0;
}

void recorreLaberinto(char lab[12][12], int pos[2], int *direccion)
{
	// Si no se encuentra en el final, moverse
	if (!((pos[0] == 0 || pos[0] == 11 || pos[1] == 0 || pos[1] == 11) &&
			lab[pos[0]][pos[1]] == *"x"))
	{
		// Si se encuentra en la posición inicial, imprimirla
		if (lab[pos[0]][pos[1]] == *".")
		{
			printf("Posicion inicial.\n");
			lab[pos[0]][pos[1]] = *"x";
			printLab(lab);
		}

		moverse(lab, pos, direccion);
	}
	else
	{
		if (lab[pos[0]][pos[1]] == *"X")
			printf("Se volvió al inicio del laberinto.\n");
		else
			printf("Se encontró el final del laberinto en la "
				"posición [%d, %d]\n", pos[0], pos[1]);
	}
}

void moverse(char lab[12][12], int pos[2], int *direccion)
{
	printf("Llamada moverse():\n");

	int i;
	// 0 arriba, 1 izquierda, 2 abajo, 3 derecha
	// apunta al contenido del arreglo en esas direcciones
	char direcciones[4] =
	{
		lab[pos[0]-1][pos[1]],
		lab[pos[0]][pos[1]-1],
		lab[pos[0]+1][pos[1]],
		lab[pos[0]][pos[1]+1]
	};

	// Se mueve a la primer posicion disponible girando contrareloj desde 
	// la mano derecha.
	
	// +3 es un movimiento horario (-90 grados)
	*direccion = (*direccion+2)%4;
	for (i = 0; i < 8; i++)
	{
		// +i recorre en sentido horario las direcciones
		*direccion = (*direccion+1)%4;
		printf("Nueva direccion: %d\n", *direccion);

		if (direcciones[*direccion] != *"#")
		{
			printf("\n");
			switch (*direccion)
			{
				case 0:
					pos[0]--;
					break;
				case 1:
					pos[1]--;
					break;
				case 2:
					pos[0]++;
					break;
				case 3:
					pos[1]++;
					break;
			}
			// se marca como x si se recorre una vez
			// y como X si se recorre más de una vez
			if (lab[pos[0]][pos[1]] == *".")
				lab[pos[0]][pos[1]] = *"x";
			else
				lab[pos[0]][pos[1]] = *"X";

			printLab(lab);
			printf("moverse() termina en coordenada "
					"[%d, %d] y direccion %d\n\n",
					pos[0], pos[1], *direccion);

			recorreLaberinto(lab, pos, direccion);
			return;
		}
		else
		{
			printf("Espacio ocupado\n\n");
		}
	}
	printf("No se encontró dirección a la cual moverse\n");
}
	
void printLab(char lab[12][12])
{
	int i, j;
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 11; j++)
			printf("%c ", lab[i][j]);
		printf("%c", lab[i][j]);
		printf("\n");
	}
}
