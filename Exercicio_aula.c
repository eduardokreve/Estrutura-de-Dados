#include <stdio.h>
#include <stdlib.h>

int main(){
  int i=0,j=0,linhas;
	
  printf("Digite a quant. de linhas: ");
  scanf("%d",&linhas);

  int colunas[linhas];
  int **matriz =malloc(linhas * sizeof (int));
	
  for(i=0;i<linhas;i++){
    printf("\nNumero de colunas: ");
    scanf("%d",&colunas[i]);
		
    matriz[i] = malloc(colunas[i] * sizeof (int));
    for(j=0;j<colunas[i];j++){
      matriz[i][j] = rand()%100;
     //	printf("%p ",&matriz[i]); //imprime o endereço de cada valor
      printf("%d  ",matriz[i][j]);
    }
  } 
  printf("\n");
  return 0;
}
