#include <stdio.h>
#define N 8

int movement(int move_x, int move_y, int movimento, int pos1, int pos2, int board[N][N]);
int valid(int pos_x, int pos_y, int move_x, int move_y, int board[N][N]);

int main()
{
    /*problema: passar por todas as casas de um tabuleiro usando somente os movimentos do knight. 
    Pode não haver solução para certas posições. A mesma casa não pode ser visitada duas vezes no passeio
    e não é possível sair do tabuleiro.*/
    
    //para criar os oito movimentos diferentes do cavalo, estritamente tradados como
    //m1,m2,m3,m4,m5,m6,m7,m8, será usado dois vetores: move_x e move_y
    int move_x[]={-1,-2,-2,-1,1,2,2,1};
    int move_y[]={2,1,-1,-2,-2,-1,1,2};
    /* a combinaçao de um elemento de move_x com o respectivo elemento de move_y resulta
    em um movimento do cavalo. Ex: move_x[0] e move_y[0] sao o movimento m1 */
    
    //preenche o tabuleiro com zeros para evitar lixo de memória e distinguir posiçoes vazias
    int board[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=0;
        }
    }
    /*
    do{
        if(movimento_mX == válido)
            do movimento_mX
        else    
            do movimento_mY
    }while(there are possible movements);
    */
    movement(move_x, move_y, 1, 0, 0, board);

    for(int m=0;m<N;m++){
        for(int n=0;n<N;n++){
            printf("%d ",board[m][n]);
        }
        printf("\n");
    }
    
    return 0;
}
//faz o movimento consultando a função valid
int movement(int move_x, int move_y, int movimento, int pos1, int pos2, int board[N][N])
{

}
//valid retorna 1 se o movimento for valido e retorna 0 do contrário
int valid(int pos_x, int pos_y, int move_x, int move_y, int board[N][N])
{

}