#include <stdio.h>
#include <stdlib.h>


typedef struct noh{
	int numero;
        char prioridade;
        struct noh *proximo;
} noh;

int senha_comum = 0;
int senha_prioridade = 300;

noh *cabeca = NULL;
noh *no_atual = NULL;
noh *no_anterior = NULL; 


int inserirSemPrioridade(noh *novo_no);
int inserirComPrioridade(noh *novo_no);
int inserir();
int imprimirFilaClientes();
int atenderCliente();
void limparTela();


int main (int argc, char *argv[]){

	int opcao;

	do {
		/*limparTela(); */
		printf("+-----------------------------+\n");
		printf("|----Atendimento Bancário-----|\n"); 
		printf("+-----------------------------+\n");
		printf("|1 - Adicionar Cliente à Fila |\n");
        	printf("|2 - Mostrar Clientes na Fila |\n");
        	printf("|3 - Chamar Cliente           |\n");
        	printf("|4 - Sair                     |\n");
		printf("+-----------------------------+\n");
		printf("=> ");
        	scanf("%d",&opcao);
		switch(opcao){
			case 1:inserir();
			       break;
                        case 2:imprimirFilaClientes();
			       break;
                        case 3:atenderCliente();
			       break;
                	case 4:break;
			default:printf("\nOpção Inválida!\n");
				continue;
		}
	} while (opcao != 4);

	return(0);
}

int inserir(){
	
	noh *novo_no;
	int op;
		limparTela();
		printf("+-----------------------------+\n");
		printf("|----Atendimento Bancário-----|\n");
                printf("+-----------------------------+\n");
                printf("|1 - Senha Comum (C)          |\n"); 
		printf("|2 - Senha Com Prioridade (P) |\n");
		printf("|3 - Voltar ao Menu Anterior  |\n");
		printf("+-----------------------------+\n");
		printf("=> ");
                scanf("%d",&op);
		switch(op){
			case 1:	novo_no = (noh *) malloc(sizeof(noh));
				novo_no->numero = ++senha_comum;			
				novo_no->prioridade = 'C';
				novo_no->proximo = NULL;
				if(cabeca == NULL){
					cabeca = (noh *) malloc(sizeof(noh));
					cabeca->numero = 0;
					cabeca->prioridade = 'I';
					cabeca->proximo = novo_no;
				} else {
					inserirSemPrioridade(novo_no);
				}
				break;
			case 2: novo_no = (noh *) malloc(sizeof(noh));
                                novo_no->numero = ++senha_prioridade;
                                novo_no->prioridade = 'P';
                                novo_no->proximo = NULL;
                                if(cabeca == NULL){
                                        cabeca = (noh *) malloc(sizeof(noh));
                                        cabeca->numero = 0;
                                        cabeca->prioridade = 'I';
                                        cabeca->proximo = novo_no;
                                } else {
                                        inserirComPrioridade(novo_no);
                                }
				break;
			case 3: break;
			default: printf("\nOpção de Prioridade Inválida!\n");
		}
	return(0);
}


int inserirComPrioridade(noh *no_incluir){

	no_atual = cabeca;
	
	if(no_atual->proximo == NULL){
		no_atual->proximo = no_incluir;
	}else{
		no_anterior = no_atual;
		no_atual = no_atual->proximo;
		do {
			if(no_atual->prioridade == 'C'){
				no_anterior->proximo = no_incluir;	
				no_incluir->proximo = no_atual;
			} else {
				while (no_atual->proximo != NULL){
					no_anterior = no_atual;
					no_atual = no_atual->proximo;
				}
				no_anterior->proximo = no_incluir;			
				no_incluir->proximo = no_atual;
			}
			
			no_atual = no_atual->proximo;
		} while (no_atual->proximo != NULL);

	}


	return(0);
}

int inserirSemPrioridade(noh *no_incluir){

        no_atual = cabeca;
	while (no_atual->proximo != NULL){
		no_atual = no_atual->proximo;
	}
	
	no_atual->proximo = no_incluir;

	return(0);
}


int imprimirFilaClientes(){
	
	limparTela();
        if(cabeca == NULL){
                printf("+-----------------------------+\n");
                printf("|----Atendimento Bancário-----|\n");
                printf("+-----------------------------+\n");
                printf("|Sem clientes na fila!        |\n");
                printf("+-----------------------------+\n");
	}else{
		no_atual = cabeca->proximo;
                printf("+-----------------------------+\n");
                printf("|----Atendimento Bancário-----|\n");
                printf("+-----------------------------+\n");
                printf("|Clientes Aguardando:         |\n");
		printf("|                             |\n");
		while (no_atual != NULL){
			printf("|Senha: %03d - Prioridade: %c   |\n", no_atual->numero, no_atual->prioridade);
			no_atual = no_atual->proximo;
		}
 		printf("+-----------------------------+\n");
	
	}
	
	return(0);
}


int atenderCliente(){

	limparTela();
        if(cabeca == NULL){
                printf("+-----------------------------+\n");
                printf("|----Atendimento Bancário-----|\n");
                printf("+-----------------------------+\n");
                printf("|Sem clientes para atender!   |\n");
                printf("+-----------------------------+\n");
        }else{
                no_atual = cabeca->proximo;
                printf("+-----------------------------+\n");
                printf("|----Atendimento Bancário-----|\n");
                printf("+-----------------------------+\n");
                printf("|                             |\n");
                printf("|                             |\n");
                printf("|Senha: %03d - Prioridade: %c   |\n", no_atual->numero, no_atual->prioridade);
		printf("|Dirigir-se ao Balcão         |\n");
		printf("|para atendimento!            |\n");	
                printf("+-----------------------------+\n");
	        
		if(no_atual -> proximo != NULL){
			cabeca->proximo = no_atual->proximo;	
		}else{
			cabeca = NULL;
			free(cabeca);
		}
		free(no_atual);
        }
	
	return(0);	
}





void limparTela(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}




