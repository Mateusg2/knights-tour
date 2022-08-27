#include <stdio.h>
#include <stdlib.h>
#define N 8

void result_tabuleiro(int tabuleiro[N][N]);
int movimento_valido(int posicao_x , int posicao_y, int tabuleiro[N][N]);
int backtracking(int posicao_x, int posicao_y, int completo, int tabuleiro[N][N], int horizontal[], int vertical[], unsigned long int *casas, unsigned long int *retorno);
void contador_casas(unsigned long int contador_casas);
void contador_retrocedidas(unsigned long int contador_retrocedidas);

int main(){
	int tabuleiro[N][N];
	// contador das casas
	unsigned long int casas_visitadas=0, casas_retrocedidas=0;
	
	//ponteiros para os contadores
	unsigned long int *pont_casas;
	unsigned long int *pont_retrocedidas;
	
	pont_casas=&casas_visitadas;
    pont_retrocedidas=&casas_retrocedidas;
	
	for(int i=0;i<N;i++)
    	for(int j=0;j<N;j++)
            tabuleiro[i][j]=-1;
            
   	int mover_horizontal[]={-1,-2,-2,-1,1,2,2,1};
   	int mover_vertical[]={2,1,-1,-2,-2,-1,1,2};
   	
   	tabuleiro[0][0]=0;
	
       if(backtracking(0,0,1,tabuleiro,mover_horizontal,mover_vertical,pont_casas,pont_retrocedidas)==0){
            printf("Sem solução.\n");
       	    return 0;
   	    }else
            result_tabuleiro(tabuleiro);
    
    printf("\nCasas Visitadas:%lu\nCasas Retrocedidas:%lu\n",casas_visitadas,casas_retrocedidas);
	return 0;
}  
    	
int backtracking(int posicao_x, int posicao_y, int completo, int tabuleiro[N][N], int horizontal[], int vertical[], unsigned long int *casas, unsigned long int *retorno){
	int  horizontal1, vertical1;
	unsigned long int contador_casas=0, contador_retrocedidas=0;
	if(completo==N*N)
    	return 1;
	for(int n=0; n<N ;n++){
        horizontal1=posicao_x+horizontal[n];
        vertical1=posicao_y+vertical[n];
        if(movimento_valido(horizontal1,vertical1,tabuleiro)){
            tabuleiro[horizontal1][vertical1]=completo;
        	if(backtracking(horizontal1, vertical1, completo+1, tabuleiro, horizontal, vertical, casas, retorno)==1){
        	    *casas=*casas+1;
                return 1;
        	}
        	else{
        	    *retorno=*retorno+1;
              tabuleiro[horizontal1][vertical1]=-1;
        	}
        	}
	}
}
 
int movimento_valido(int posicao_x , int posicao_y, int tabuleiro[N][N]){
	if(posicao_x >=0 && posicao_x<N && posicao_y>=0 && posicao_y<N && tabuleiro[posicao_x][posicao_y] == -1)
    	return 1;
	else	
    	return 0;
}
 
void result_tabuleiro(int tabuleiro[N][N]){
	//funcao que imprime o tabuleiro
	for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++)
            printf(" %2d ", tabuleiro[i][j]);
        printf("\n");
	}
}
