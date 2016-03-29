struct Node{
	int elem;
	struct Node *prox; //vai apontar para o prox. elemem.	
};
typedef struct Node node;

void push(node *pilha); //insere um elem.
void pop(node *pilha); //retira um elem.
void cria(node *pilha); //cria a pilha
int vazio(node *pilha); //verifica se está vazio
void imprime(node *pilha); //imprime na tela os elementos