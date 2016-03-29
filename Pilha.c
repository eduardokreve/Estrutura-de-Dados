#include <stdio.h>
#include <stdlib.h>
#include "pi.h"


void cria(node *pilha){
	pilha->prox == NULL; //prox aponta para o fim da pilha	
}

void imprime(node *pilha){
	if(vazio(pilha) == 1){
		printf("Nenhum elemento inserido!\n\n");
	}
	else{
		node *search = pilha->prox;

		while(search != NULL){
			printf("%d ",search->elem); //search esta apontando para o elem. na estrutura
			search = search->prox; //search aponta para o prox elemento para depois imprimir
		}
		printf("\n");
	}
}

int vazio(node *pilha){
	if(pilha->prox == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void push(node *pilha){ //aloca o novo elemento na pilha
	node *new = (node*) malloc(sizeof(node));
	if(new == NULL){
		printf("Nao foi possivel alocar\n\n");
		exit(1);
	}
	else{
		printf("\nDigite o elemento: ");
		scanf("%d",&new->elem); //vai alocar o elemento
		new->prox == NULL; //o ultimo elem. adicion. aponta para o fim da pilha

		if(vazio(pilha) == 1){ //se a pilha for vazia o ultimo elem. fica no final
			pilha->prox = new; //prox aponta para o novo elemento 
		}
		else{ //senao vai precisar o ultimo elem. adicionado
			node *search = pilha->prox; //o pont. para procurar o ultimo elem.

			while(search->prox != NULL){ //o loop para quando achar o final da pilha
				search = search->prox;
			}
			search->prox = new; //quando o loop acabar, search esta apontando para o ultimo elem.
		}
	}
}

void pop(node *pilha){
	if(pilha->prox == NULL){ //se o prox. elemento for o fim da pilha, nenhum elem. foi inserido
		printf("Nenhum elemento inserido\n\n");
	}
	else{ //
		node *ultimo, *penultimo;

		ultimo = pilha->prox;
		penultimo = pilha;

		while(ultimo->prox != NULL){ 
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		penultimo->prox = NULL;

		free(penultimo->prox);
	}
}

int main(){
	int opc = 0;

	node *pilha = (node*) malloc(sizeof(node));//criacao da pilha
	if(pilha == NULL){
		printf("Nao foi alocado\n\n");
		exit(1);
	}
	else{
		cria(pilha);
	}

	while(1){
		printf("\n\nDigite zero para sair\n");
		printf("Digite 1 para inserir elementos.\n");
		printf("Digite 2 para imprimir os elementos\n");
		printf("Digite 3 para retirar elementos\n");
		printf("Digite a opcao: ");
		scanf("%d",&opc);

		if(opc == 1){
			push(pilha);
		}
		else if(opc == 2){
			imprime(pilha);
		}
		else if(opc == 3){
			pop(pilha);
		}

		else if(opc == 0){
			return 0;
		}
	}
	return 0;
}
