#include <stdio.h>

void recorreLaberinto(char lab[12][12], int pos[2], int *direccion);
void moverse(char lab[12][12], int pos[2], int *direccion);

void printLab(char lab[12][12]);

int main()
{
	char extLab[12][12] = {
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
	// moverse si no se encuentra en un extremo recorrido (marcado con x)
	if (!((pos[0] == 0 || pos[0] == 11 || pos[1] == 0 || pos[1] == 11) &&
			lab[pos[0]][pos[1]] == *"x")) {
		// si es la posicion inicial, marcarla e imprimirla
		if (lab[pos[0]][pos[1]] == *".") {
			lab[pos[0]][pos[1]] = *"x";
			printLab(lab);
		}

		moverse(lab, pos, direccion);
	}
}

void moverse(char lab[12][12], int pos[2], int *direccion)
{
	int i;
	int tempDir = *direccion;
	// 0 arriba, 1 derecha, 2 abajo, 3 izquierda
	// apunta al contenido del laberinto en esas direcciones
	char direcciones[4] = {
		lab[pos[0]-1][pos[1]],
		lab[pos[0]][pos[1]+1],
		lab[pos[0]+1][pos[1]],
		lab[pos[0]][pos[1]-1]
	};
	
	// recorre el contenido del laberinto alrededor de la pos actual dos
	// veces
	for (i = 0; i < 8; i++)
	{
		// inicialmente se tiene la direccion "*direccion"
		// sumando uno se gira a mano derecha la direccion
		// por cada loop se gira a mano izquierda restando "i"
		tempDir = (-i+*direccion+1)%4;
		// cuando la izquierda del modulo es negativo, se puede obtener
		// una direccion equivalente sumando 4
		if (tempDir < 0)
			tempDir = tempDir+4;

		// se ignoran en i=0,...,3 las posiciones marcadas
		// en i=4,...,7 se toma en cuenta las posiciones ya recorridas
		// al estar libre la posicion se toma esa direccion y se edita
		// la coordenada actual
		if (direcciones[tempDir] == *"." ||
				(i >= 4 && direcciones[tempDir] == *"x")) {
			*direccion = tempDir;
			switch (*direccion) {
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
			// se marca como recorrida la posicion
			if (lab[pos[0]][pos[1]] != *"x")
				lab[pos[0]][pos[1]] = *"x";
			printLab(lab);
			recorreLaberinto(lab, pos, direccion);
			return;
		}
	}
}
	
void printLab(char lab[12][12])
{
	int i, j;
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++)
			printf("%c ", lab[i][j]);
		printf("\n");
	}
	printf("\n");
}
