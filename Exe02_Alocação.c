//Ainda não foi terminado

#include <stdio.h>
#include <stdlib.h>

int uniao(int *v1,int n1,int *v2, int n2){
	int soma,j,i;
	
	soma=n1+n2;
	printf("SOMA:%d\n",soma);
	int vet[soma];
	
	for(j=0;j<n1;j++){
		vet[j]=v1[j];
    }
    for(i=0;i<n2;i++){
		vet[i+n1]=v2[i];
	}
	
//	for(i=0;i<soma;i++){
//		printf("%d ",vet[i]);
//	 } 
     
     int *retorna=vet;
     
	 return *retorna;
}

int main(){
	int a,b,i;
	int *c,*d,*e;
	
	printf("Tamanho dos vetores iniciais: ");
	scanf("%d %d",&a,&b);
	
	c = (int *) malloc(a*sizeof(int));//alocação dos dois vetores iniciais
    d = (int *) malloc(b*sizeof(int));
    
    printf("Digite os valores do primeiro vetor\n");
    for(i=0;i<a;i++){
		scanf("%d",&c[i]);
	}
	printf("\nDigite os valores do segundo vetor\n");
	for(i=0;i<b;i++){
		scanf("%d",&d[i]);
	}
	e = (int *) malloc((a+b)*sizeof(int));
	
    e = uniao(c,a,d,b);//chamada da função
    
    for(i=0;i<(a+b);i++){
		
		printf("%d ",e[i]);
    }
	
	return 0;
}
