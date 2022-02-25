/******************************************************************************

ATIVIDADE AVALIATIVA (INDIVIDUAL OU EM DUPLA).

▪ Desenvolver o famoso jogo da forca.
▪ O jogador pode escolher os níveis easy (até 10 letras), medium (20 letras), hard (30 letras).
▪ (Opcional nível insane com 50 letras).
▪ Ao final do jogo, deve ser informado a pontuação do jogador (o programador deve
desenvolver a metodologia de pontos).

▪ Data de entrega sem penalização: 24/Fev/2022
▪ Deve ser utilizado o paradigma estruturado!
▪ Entregar o código e uma apresentação explicando os principais trechos de código e a metodologia de pontuação utilizada.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void forca(int estado){
    if(estado==0){
        printf("\n _____________ ");
        printf("\n |/           |");
        printf("\n |             ");
        printf("\n |             ");
        printf("\n |             ");
        printf("\n |             ");
        printf("\n_|__           ");
    }else if(estado==1){
        printf("\n _____________ ");
        printf("\n |/           |");
        printf("\n |            0");
        printf("\n |             ");
        printf("\n |             ");
        printf("\n |             ");
        printf("\n_|__           ");
    }else if(estado==2){
        printf("\n _____________ ");
        printf("\n |/           |");
        printf("\n |            0");
        printf("\n |            |");
        printf("\n |             ");
        printf("\n |             ");
        printf("\n_|__           ");
    }else if(estado==3){
        printf("\n _____________");
        printf("\n |/           |");
        printf("\n |            0");
        printf("\n |           /|");
        printf("\n |             ");
        printf("\n |             ");
        printf("\n_|__           ");
    }else if(estado==4){
        printf("\n _____________");
        printf("\n |/           |");
        printf("\n |            0");
        printf("\n |           /|\\");
        printf("\n |             ");
        printf("\n |             ");
        printf("\n_|__           ");
    }else if(estado==5){
        printf("\n _____________");
        printf("\n |/           |");
        printf("\n |            0");
        printf("\n |           /|\\");
        printf("\n |           / ");
        printf("\n |             ");
        printf("\n_|__           ");
    }else if(estado==6){
        printf("\n _____________");
        printf("\n |/           |");
        printf("\n |            0");
        printf("\n |           /|\\");
        printf("\n |           / \\");
        printf("\n |             ");
        printf("\n_|__           ");
    }
}

int main(void){
    int numErros = 0, pontos=0;
    char p_sec[100];
    char letra;
    int certeza = 0;
    
    printf("\n#######################");
    printf("\n#    JOGO DA FORCA    #");
    printf("\n#######################");
    
    printf("\nREGRAS DO JOGO:");
    printf("\nO objetivo deste jogo é descobrir uma palavra adivinhando as letras que ela possui."); 
    printf("\nA cada rodada, os jogadores irão simultaneamente escolher uma letra que suspeitem fazer parte da palavra."),
    printf("\nCaso a palavra contenha esta letra, será mostrado em que posição(ões) ela está.");
    printf("\nEntretanto, caso esta letra não exista na palavra, será desenhada uma parte do corpo do boneco do jogador."); 
    printf("\nSe todas as 6 partes do corpo do boneco estiverem desenhadas, o jogador estará mortinho da silva.");

    
    while(certeza == 0){
        printf("\n\nJOGADOR 1:");
        printf("\nPalavra secreta: ");
        fgets(p_sec, 100, stdin);
        printf("\nA palavra secreta é: %s", p_sec);
        printf("\nA palavra tem %li caracteres", strlen(p_sec)-1);
        printf("\n\nCONFIRMA ESSA PALAVRA? \n(Digite 1 para confirmar ou 0 para digitar novamente)\n->");
        scanf("%d", &certeza);
    }
    //pula linhas
    for(int i=0;i<100;i++){
        printf("\n");
    }
    
    //retira o ultimo caracter de p_sec que esta a mais devido a captura ser fgets()
    p_sec[strlen(p_sec)-1]='\0';
    char p_tela[100];
    strcpy(p_tela, p_sec);
    //Substitui letras por underline
    for(int i=0; i<strlen(p_tela); i++){
        p_tela[i] = '_';
    }
    
    while(1){
        //imprimir a forca
        forca(numErros);
        //imprimir os underline para cada letra da palavra secreta
        printf("\nAdivinhe: ");
        for(int i=0;i<strlen(p_tela);i++){
            printf("%c ", p_tela[i]);
        }
        //recebe a letra
        printf("\nLetra: ");scanf(" %c", &letra); //espaço no scanf devido o bug na idl web..
        
        //se letra certa atualiza palavra na tela
        int errou=1;//1=sim 2=nao
        for(int i=0; i<strlen(p_tela); i++){
            if(letra==p_sec[i]){
                p_tela[i]=letra;
                errou=0;
            }
        }
        //senao, incrementa erros
        if(errou==1){
            numErros++;
        }
        //verifica se o jogo acabou
        //verifica se ganhou
        //veifica se a p_sec é igual a p_tela
        if(strcmp(p_tela, p_sec)==0){
            pontos = (5-numErros)*100;
            printf("\nAcertou: %s", p_sec);
            printf("\n\n        Parabéns!\n");
            printf("      Você venceu!!!\n");
            printf("     pontuação: %dpts    \n", pontos);
            printf("       ___________      \n");
    		printf("      '._==_==_=_.'     \n");
    		printf("      .-\\:      /-.    \n");
    		printf("     | (|:.     |) |    \n");
    		printf("      '-|:.     |-'     \n");
    		printf("        \\::.    /      \n");
    		printf("         '::. .'        \n");
    		printf("           ) (          \n");
    		printf("         _.' '._        \n");
    		printf("        '-------'       \n\n");
            break;
        }
        
        //veifica se perdeu
        if(numErros==6){
            //perdeu
            for(int i=0;i<100;i++){
            printf("\n");
            }
            forca(numErros);
            printf("\n\n  Puxa, você foi enforcado!");
            printf("\n  A palavra era: %s", p_sec);
            printf("\n    _______________         \n");
    		printf("   /               \\       \n"); 
    		printf("  /                 \\      \n");
    		printf("//                   \\/\\  \n");
    		printf("\\|   XXXX     XXXX   | /   \n");
    		printf(" |   XXXX     XXXX   |/     \n");
    		printf(" |   XXX       XXX   |      \n");
    		printf(" |                   |      \n");
    		printf(" \\__      XXX      __/     \n");
    		printf("   |\\     XXX     /|       \n");
    		printf("   | |           | |        \n");
    		printf("   | I I I I I I I |        \n");
    		printf("   |  I I I I I I  |        \n");
    		printf("   \\_             _/       \n");
    		printf("     \\_         _/         \n");
    		printf("       \\_______/           \n");
            break;
        }
        
        for(int i=0;i<100;i++){
        printf("\n");
        }
    }
    
    
    return 0;
}















