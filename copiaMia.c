#include <stdio.h>

//direccion[0] arriba, direccion[1] derecha, direccion[2] abajo,
//direccion[3] izquierda
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
	// 0 arriba, 1 derecha, 2 abajo, 3 izquierda
	int direccion = 1;

	recorreLaberinto(extLab, inicio, &direccion);

	return 0;
}

void recorreLaberinto(char lab[12][12], int pos[2], int *direccion)
{
	if (!((pos[0] == 0 || pos[0] == 11 || pos[1] == 0 || pos[1] == 11) &&
			lab[pos[0]][pos[1]] == *"x"))
	{
		if (lab[pos[0]][pos[1]] == *".")
		{
			printf("Posicion inicial.\n");
			lab[pos[0]][pos[1]] = *"x";
			printLab(lab);
		}

		moverse(lab, pos, direccion);
	}
	else
		printf("Se encontró el final en [%d, %d]\n", pos[0], pos[1]);
}

void moverse(char lab[12][12], int pos[2], int *direccion)
{
	printf("Llamada moverse():\n");

	int i;
	int tempDir = *direccion;
	// 0 arriba, 1 derecha, 2 abajo, 3 izquierda
	// apunta al contenido del arreglo en esas direcciones
	char direcciones[4] =
	{
		lab[pos[0]-1][pos[1]],
		lab[pos[0]][pos[1]+1],
		lab[pos[0]+1][pos[1]],
		lab[pos[0]][pos[1]-1]
	};

	// checa si se puede mover a derecha o se mueve 
	// a la primer posicion disponible girando contrareloj
	for (i = 0; i < 8; i++)
	{
		printf("i: %d\n", i);
		printf("Direccion: %d\n", *direccion);
		tempDir = (-i+*direccion+1)%4;
		if (tempDir < 0)
			tempDir = 4+tempDir;
		printf("Nueva direccion: %d\n", tempDir);


		if (direcciones[tempDir] == *"." ||
				(i >= 4 && direcciones[tempDir] == *"x"))
		{
			*direccion = tempDir;
			switch (*direccion)
			{
				case 0:
					pos[0]--;
					break;
				case 1:
					pos[1]++;
					break;
				case 2:
					pos[0]++;
					break;
				case 3:
					pos[1]--;
					break;
			}
			if (lab[pos[0]][pos[1]] != *"x")
				lab[pos[0]][pos[1]] = *"x";
			printLab(lab);
			printf("moverse() termina en direccion: %d\n", *direccion);
			printf("moverse() termina en coordenada "
				"[%d, %d]\n\n", pos[0], pos[1]);
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
		for (j = 0; j < 12; j++)
			printf("%c ", lab[i][j]);
		printf("\n");
	}
	printf("\n");
}
