/******************************************************************************

Faça um programa onde há uma matriz 4x3 preenchido com valores aleatórios.
O usuário deve indicar uma posição dentro da matriz, e o programa deve informar a soma dos valores
do ponto inicial (0,0) até ao ponto informado pelo usuário. A movimentação será deve ser feita por
linhas.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[4][3], lin, col, x, y, soma=0;
    
    //retorna o tempo atual;
    srand(time(NULL));
    
    //Atribuindo valores a matriz;
    for(lin=0; lin<4; lin++){
        for(col=0; col<3; col++){
            matriz[lin][col] = rand()%10;
        }
    }
    
    //Imprimindo a Matriz;
    printf("*Matriz gerada*\n");
    for(lin=0;lin<4;lin++){
        printf("\n");
       for(col=0; col<3; col++){
           printf("| %d |", matriz[lin][col]);
       }
   }
   
   //Obtendo uma coordenada do usuário;
   printf("\n\nDada a matriz acima, digite uma coordenada (x,y) para obter a somatoria dos indices anteriores.");
   printf("\nDigite o ponto X:"); scanf("%d", &x);
   printf("Digite o ponto Y:"); scanf("%d", &y);
   
   //Tratando a matriz para somar seus indices;
   for(lin=0; lin<x+1; lin++){
        if(lin==x){
            for(col=0; col<y+1; col++){
                soma = soma + matriz[lin][col];
            }
        }else{
            for(col=0; col<3; col++){
            soma = soma + matriz[lin][col];
            }
        }
    }
    //Imprimindo a soma 
    printf("\nA soma dos indices anteriores é: %d", soma);

    return 0;
}