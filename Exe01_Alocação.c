#include <stdio.h>
#include <stdlib.h>

int main(){
    int ver,i,tamanho=5;
  
    int *vet = (int*) malloc(tamanho *sizeof(int));

    for(i=0;i<tamanho;i++){
	
        ver = scanf("%d",&vet[i]);
	if(ver==0){
	    free(vet);
	    return 0;
	}
		
	else{
	    if(i%5>0){
	        tamanho+=5;
		vet = (int*) realloc(vet, tamanho *sizeof(int));
	    }	
	}
	i++;
    }
  
  	return 0;
}
