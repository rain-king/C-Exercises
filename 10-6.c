#include <stdio.h>

int main()
{
	printf("\n");
	puts("	struct cliente");
	puts("	{");
	puts("		char apellido[15];");
	puts("		char nombre[15];");
	puts("		int numeroCliente;");
	puts("		struct");
	puts("		{");
	puts("			char numeroTelefonico[11];");
	puts("			char direccion[50];");
	puts("			char ciudad[15];");
	puts("			char estado[3];");
	puts("			char codigoPostal[6];");
	puts("		} personal;");
	puts("	} registroCliente, *ptrCliente;");
	puts("");
	puts("	ptrCliente = &registroCliente;");
	printf("\n");

	printf("a) \n");
	printf("	registroCliente.apellido\n");
	printf("b) \n");
	printf("	ptrCliente->apellido\n");
	printf("\n");

	printf("c) \n");
	printf("	registroCliente.apellido\n");
	printf("d) \n");
	printf("	ptrCliente->apellido\n");
	printf("\n");

	printf("e) \n");
	printf("	registroCliente.numeroCliente\n");
	printf("f) \n");
	printf("	ptrCliente->numeroCliente\n");
	printf("\n");

	printf("g) \n");
	printf("	registroCliente.personal.numeroTelefonico\n");
	printf("h) \n");
	printf("	ptrCliente->personal.numeroTelefonico\n");
	printf("\n");

	printf("i) \n");
	printf("	registroCliente.personal.direccion\n");
	printf("j) \n");
	printf("	ptrCliente->personal.direccion\n");
	printf("\n");

	printf("k) \n");
	printf("	registroCliente.personal.ciudad\n");
	printf("l) \n");
	printf("	ptrCliente->personal.ciudad\n");
	printf("\n");

	printf("m) \n");
	printf("	registroCliente.personal.estado\n");
	printf("n) \n");
	printf("	ptrCliente->personal.estado\n");
	printf("\n");

	printf("o) \n");
	printf("	registroCliente.personal.codigoPostal\n");
	printf("p) \n");
	printf("	ptrCliente->personal.codigoPostal\n");

	return 0;
}

