#include <stdio.h>

typedef struct noh{
	int numero;
        char prioridade[1];
        struct noh *proximo;
} noh;

int inserirSemPrioridade();
int inserirComPrioridade();
int inserir();
int imprimirFilaClientes();
int atenderCliente();

int main (int argc, char *argv[]){

	printf("teste\n");
	



	return(0);
}

