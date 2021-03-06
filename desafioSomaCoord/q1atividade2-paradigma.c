/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define pessoas 2 // constante para número de entrevistados;

typedef struct{
    
    int idade;
    int residentes;
    char sexo;
    char infecCovid[4];
    char testCovid[4];
 
}Habitante; //nome da estrutura;
    
int main()
{
    //Declarando os contadores para quantificar os resultados;
    int i, teveCovid=0, nTeveCovid=0, fezTeste=0, nFezTeste=0, resideQuant=0, quantMasc=0, quantFem=0;
    float mediaPPC; //media de Pessoas Por Casas;
    Habitante registro[pessoas];
    
    printf(" ____________________________________\n");
    printf("\n RELATÓRIO DE PESSOAS ENTREVISTADAS\n");
    printf(" ____________________________________\n\n");
    printf(" Dados pessoais:\n");
    
    //entrada com os dado dos entrevistados;
    for(i=0; i<pessoas; i++){
 
        printf("\n Entrevistado [%d]\n", i+1);
        printf(" Qual sua idade?.............................: "); scanf("%d", &registro[i].idade);
        printf(" Quantas pessoas moram na sua residencia?....: "); scanf("%d", &registro[i].residentes);
        printf(" Qual seu sexo? (M ou F).....................: "); scanf(" %c", &registro[i].sexo);
        printf(" Contraiu o vírus da Covid-19? (sim ou não)..: "); scanf("%s", registro[i].infecCovid);
        printf(" Realizou teste de Covid? (sim ou não).......: "); scanf("%s", registro[i].testCovid);
    
    }

    for(i=0; i<pessoas; i++){
        //Para armazenar o numero de infectados e nao infectados;
        if(strcmp(registro[i].infecCovid,"SIM") || strcmp(registro[i].infecCovid,"sim")){
            teveCovid++;
        }else if(strcmp(registro[i].infecCovid,"NÃO") || strcmp(registro[i].infecCovid,"não")){
            nTeveCovid++;
        }
        
        //Para armazenar o numero de pessoas que fizeram e nao fizeram testes de covid;
        if(strcmp(registro[i].testCovid,"SIM") || strcmp(registro[i].infecCovid,"sim")){
            fezTeste++;
        }else if(strcmp(registro[i].testCovid,"NÃO") || strcmp(registro[i].infecCovid,"não")){
            nFezTeste++;
        }
        
        //Para armazenar o numero de pessoas de cada sexo masc e fem;
        if(registro[i].sexo == 'M'){
            quantMasc++;
        }else if(registro[i].sexo == 'F'){
            quantFem++;
        }

        //Armazenando o numero de residentes de todas as casas;
        if(registro[i].residentes > 0){
            resideQuant+= registro[i].residentes;
        }
     
    }
    //media de moradores por residencia;
    mediaPPC = (float) resideQuant/pessoas;
    //relatorio com o resultado dos entrevistados;
    printf("\n\n ############ Finalizada as entrevistas ############## ");
    printf("\n _____________________________________________________\n");
    printf("\n Dados do Ralatório final a partir dos %d entrevistos:", pessoas);
    printf("\n _____________________________________________________\n");
    printf("\n Número de pessoas que JÁ tiveram covid-19..............: %d", teveCovid);
    printf("\n Número de pessoas que NÃO tiveram covid-19.............: %d", nTeveCovid);
    printf("\n Número de pessoas que JÁ fizeram o teste para covid-19.: %d", fezTeste); 
    printf("\n Número de pessoas que NÃO fizeram o teste para covid-19: %d", nFezTeste);
    printf("\n Média de pessoas por moradia...........................: %.2f", mediaPPC);
    printf("\n Número de pessoas do sexo MASCULINO....................: %d", quantMasc);
    printf("\n Número de pessoas do sexo FEMININO.....................: %d", quantFem);
    
    return 0;
}
