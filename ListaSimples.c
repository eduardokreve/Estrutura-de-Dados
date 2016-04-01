#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
    struct lista *ant;
}TpLista;

TpLista *inicializa(){ //inicializa a lista com NULL
	return NULL;
}

TpLista *insereini(TpLista *I, int e){
	TpLista *novo = (TpLista*) malloc (sizeof(TpLista));
	novo->info = e;
	novo->prox = I; 
	return novo;
}

void imprime(TpLista *I){
  TpLista *p;
	for(p=I; p!= NULL; p = p->prox){
		printf("Conteudo: %d\n",p->info);
	}
}

int evazia(TpLista *I){
	if(I == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

TpLista *busca(TpLista *I, int e){
	TpLista *p;
	for(p = I; p != NULL; p=p->prox){
		if(p->info == e){
			return p;
		}
	}
	return NULL;
}

TpLista * exclui(TpLista * I, int e){
	TpLista * anterior = NULL;
	TpLista * p = I;

	while((p != NULL) && (p->info != e)){
		anterior = p;
		p = p->prox;
	}

	if(p == NULL){
		return I;
	}

	if(anterior == NULL){
		I = p->prox;
	}
	else{
		anterior->prox = p->prox;
	}
	free(p);
	return I;
}

TpLista inseremeio(TpLista *I, int e, int f){
	TpLista *novo, *anterior, *tmp;

	anterior = NULL;
	tmp = I;

	while((tmp != NULL) && (tmp->info != e)){
			anterior = tmp;
			tmp = tmp->prox;
	}
	novo = (TpLista *)malloc(sizeof(I));
	novo->info  = f;
	if (anterior == NULL) {
		novo->prox = I;
		I = novo;
	}
	else {
		novo->prox = anterior->prox;
		anterior->prox = novo;
	}
	return *I;
}

int main(){
	TpLista* I;

	I = inicializa();
    I = insereini(I, 10);
	I = insereini(I, 15);
	I = insereini(I, 24);
   *I = inseremeio(I, 10, 12);
   *I = inseremeio(I, 33, 32);
	I = insereini(I, 1);


	imprime(I);

	I = exclui(I, 24);

	printf("DEPOIS \n");

	imprime(I);

	return 0;
}
