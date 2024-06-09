#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20
#define BOMAX 10
#define AVMAX 5
#define SUMAX 5
#define E1MAX 4
#define E2MAX 4
#define PAMAX 2

int main()
{
    /// Trabalho (parte 1) da disciplina de algoritmos.

    char coluna;
    char vet[TAM][TAM];
    char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};
    int i,j,k,l,m;
    int linha;
    int menu,voltar_sair,finalizar,opcao,virar,voltar_sair2 = 0,voltar_sair3 = 0;
    int boia = 0, aviao = 0, submarino = 0, espiao_1 = 0, espiao_2 = 0, porta_avioes = 0; // Variavél de cada elemento do jogo.
    srand(time(NULL));

    do{
        do{
            printf("Trabalho de Algoritmos.\nBatalha Naval.\n\n");  // Menu.
            printf("------------------\n");
            printf("[1] Jogar\n");
            printf("[2] Sair\n------------------\n");
            printf("Feito por Joao Augusto Kruger Geronimo.\n\n");
            scanf("%d",&menu);
            system("cls"); // Limpa o console
        }while(menu<1 || menu>3);

        switch(menu){

            case 1:
                for(i=0; i<TAM; i++){
                    for(j = 0; j<TAM; j++){  // Inicializa a matriz como '*'.
                        vet[i][j] = '*';
                    }
                }
                do{ // Loop principal
                    voltar_sair2=0;
                    voltar_sair=0;

                    l = 0;
                    k = 65;
                    printf("   ");

                    while(k<=84){
                        printf("%c ",k); // Imprime a primeira linha com letras de A-T (com uso da tabela ASCII) para cada posição y.
                        k++;
                    }
                    printf("\n");

                    for(i=0; i<TAM; i++){
                        if(l<10){
                            printf(" ");
                        }
                        printf("%d",l);
                        l++; // Imprime a primeira coluna com números de 0-19 para cada posição x.

                        for(j=0; j<TAM; j++){
                            printf(" ");            // Imprime a matriz.
                            printf("%c",vet[i][j]);
                            }
                    printf("\n");
                    }
                    if(boia == BOMAX && aviao == AVMAX && submarino == SUMAX && espiao_1 == E1MAX && espiao_2 == E2MAX && porta_avioes == PAMAX){ // Condição de parada do loop.
                        printf("\n");
                        printf("A Frota maritima foi posicinada com sucesso!\n");
                        printf("Jogar novamente?\n");
                        printf("[1] Sim\n");
                        printf("[2] Nao\n");
                        scanf("%d",&voltar_sair3);
                        if(voltar_sair3==1){
                            voltar_sair=1;       // Reseta as variaveis para que o jogo recomece.
                            voltar_sair2=1;
                            boia = 0, aviao = 0, submarino = 0, espiao_1 = 0, espiao_2 = 0, porta_avioes = 0;
                            break;
                        }
                        else{
                            printf("Obrigado por jogar!\n");
                            return 0;
                        }
                    }
                    do{
                        do{
                            printf("\n");
                            printf("Escolha uma opcao para posicionar:\n");
                            printf("[1] Boia\n");
                            printf("[2] Aviao\n");
                            printf("[3] Submarino\n");     // Opções
                            printf("[4] Espiao 1\n");
                            printf("[5] Espiao 2\n");
                            printf("[6] Porta-Avioes\n");
                            printf("[7] Voltar\n"); // Volta para o menu principal
                            printf("[8] Aleatorizar\n");
                            printf("[9] Finalizar o jogo\n");
                            scanf("%d",&opcao);
                            if(opcao==7){
                                voltar_sair=1;
                                voltar_sair2=1;
                                boia = 0, aviao = 0, submarino = 0, espiao_1 = 0, espiao_2 = 0, porta_avioes = 0;
                            }
                            if(opcao<1 || opcao>9){
                                printf("\n");
                                printf("Opcao invalida. Tente novamente.\n");
                            }
                        }while(opcao<1||opcao>9);
                        virar = 0; // reseta a variável 'virar'
                    }while(virar==5 || virar==3);

                    printf("\n");

                    switch(opcao){ // switch-case da opção escolhida pelo usuário.
                        case 1:  // Boia.
                            do{ // Laço de repetição.
                                printf("Digite a linha e coluna para a Boia: ");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){
                                        coluna = m;
                                    }
                                }
                                if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                    printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                }
                                if(boia==BOMAX){
                                    printf("Quantidade maxima de Boias atingida.\n");
                                }
                                else if(linha>=0 && linha<TAM && coluna>=0 && coluna<TAM){
                                    if(vet[linha][coluna] != '*'){
                                        printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                }
                                    else{
                                        vet[linha][coluna] = '0';
                                        boia++;
                                    }
                                }
                            }while(linha>19 || coluna>19 || linha<0 || coluna<0);
                        break;

                        case 2: // Avião.
                            do{ // Laço de repetição.
                                printf("Escolha o posicionamento do Aviao:\n");
                                printf("[1] Normal\n");
                                printf("[2] Rotacionar 90 graus para a direita\n");
                                printf("[3] Rotacionar 90 graus para a esquerda\n");
                                printf("[4] Rotacionar 180 graus\n");
                                printf("[5] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar>5){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar>5);
                            if(virar==5){
                                system("cls");
                                break;
                            }

                            do{ // Laço de repetição.
                                printf("Digite a linha e coluna parao Aviao: ");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){
                                        coluna = m;
                                    }
                                }
                                if(aviao==AVMAX){
                                    printf("Quantidade maxima de Avioes atingida.\n");
                                }
                                else{
                                    switch(virar){ // rotação do elemento.
                                        case 1: // Opcão padrão:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>18){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha-1][coluna+1] != '*'){ // Verifica se há algum elemento na posição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha+1][coluna+1] = '1';
                                                    vet[linha-1][coluna+1] = '1';
                                                    aviao++;
                                                    }
                                            }
                                        break;

                                        case 2: // Opção virar 90° para a direita:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>19 || coluna>17){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha][coluna+2] != '*'){
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha-1][coluna+1] = '1';
                                                    vet[linha][coluna+2] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;

                                        case 3: // Opção virar 90° para a esquerda:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>18 || coluna>17){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*'){
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha][coluna+2] = '1';
                                                    vet[linha+1][coluna+1] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;

                                        case 4: // Opcao virar 180°
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18   || coluna>18){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*'){  // Verifica se há algum elemento na posição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha+1][coluna] = '1';
                                                    vet[linha-1][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna>19 || linha<0 || coluna<0);
                        break;

                        case 3: // Submarino.
                            do{ // Laço de repetição.
                                printf("Escolha o posicionamento do Submarino:\n");
                                printf("[1] Normal\n");
                                printf("[2] Rotacionar 90 graus\n");
                                printf("[3] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar>3){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar>3);
                            if(virar==3){
                                system("cls");
                                break;
                            }
                            do{ // Laço de repetição.
                                printf("Digite a linha e coluna para o Submarino: ");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){
                                        coluna = m;
                                    }
                                }
                                if(submarino==SUMAX){
                                    printf("Quantidade maxima de Submarinos atingida.\n");
                                }
                                else{
                                    switch(virar){
                                        case 1: // Opcão padrão:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(coluna>16){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '2';
                                                    vet[linha][coluna+1] = '2';
                                                    vet[linha][coluna+2] = '2';
                                                    vet[linha][coluna+3] = '2';
                                                    submarino++;
                                                }
                                            }
                                        break;

                                        case 2: // Opcão rotacionar 90 graus.
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>16){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*'){
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '2';
                                                    vet[linha+1][coluna] = '2';
                                                    vet[linha+2][coluna] = '2';
                                                    vet[linha+3][coluna] = '2';
                                                    submarino++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna > 19 || linha<0 || coluna<0);
                        break;

                        case 4: // Espião 1.
                            do{ // Laço de repetição.
                                printf("Escolha o posicionamento do Espiao 1:\n");
                                printf("[1] Normal\n");
                                printf("[2] Rotacionar 90 graus para a direita\n");
                                printf("[3] Rotacionar 90 graus para a esquerda\n");
                                printf("[4] Rotacionar 180 graus\n");
                                printf("[5] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar > 5){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar > 5);
                            if(virar==5){
                                system("cls");
                                break;
                            }
                            do{ // Laço de repetição.
                                printf("Digite a linha e coluna para o Espiao 1: ");
                                scanf("%d %c",&linha,&coluna);

                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){
                                        coluna = m;
                                    }
                                }
                                if(espiao_1==E1MAX){
                                    printf("Quantidade maxima de Espioes 1 atingida.\n");
                                }

                                else{
                                    switch(virar){
                                        case 1:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>16){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha+1][coluna] = '3';
                                                    vet[linha-1][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha][coluna+3] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 2:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>16 || coluna>17){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha+1][coluna+1] = '3';
                                                    vet[linha+2][coluna+1] = '3';
                                                    vet[linha+3][coluna+1] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 3:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<3 || coluna>17){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha-1][coluna+1] = '3';
                                                    vet[linha-2][coluna+1] = '3';
                                                    vet[linha-3][coluna+1] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 4:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>16){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha-1][coluna+3] != '*' || vet[linha+1][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha][coluna+3] = '3';
                                                    vet[linha-1][coluna+3] = '3';
                                                    vet[linha+1][coluna+3] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna>19 || linha<0 || coluna<0);
                        break;

                        case 5: // Espião 2.
                            do{ // Laço de repetição.
                                printf("Escolha o posicionamento do Espiao 2:\n");
                                printf("[1] Normal\n");
                                printf("[2] Rotacionar 90 graus para a direita\n");     // Opções para virar o elemento.
                                printf("[3] Rotacionar 90 graus para a esquerda\n");
                                printf("[4] Rotacionar 180 graus\n");
                                printf("[5] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar > 5){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar > 5);
                            if(virar==5){
                                system("cls");
                                break;
                            }
                            do{ // Laço de repetição.
                                printf("Digite a linha e coluna para o Espiao 2: ");
                                scanf("%d %c",&linha,&coluna);

                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){
                                        coluna = m;
                                    }
                                }
                                if(espiao_2==E2MAX){
                                    printf("Quantidade maxima de Espioes 2 atingida.\n");
                                }

                                else{
                                    switch(virar){
                                        case 1:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>16){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha+1][coluna] = '4';
                                                    vet[linha-1][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha][coluna+3] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 2:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>16 || coluna>17){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha+1][coluna+1] = '4';
                                                    vet[linha+2][coluna+1] = '4';
                                                    vet[linha+3][coluna+1] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 3:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<3 || coluna>17){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha-1][coluna+1] = '4';
                                                    vet[linha-2][coluna+1] = '4';
                                                    vet[linha-3][coluna+1] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 4:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>16){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha-1][coluna+3] != '*' || vet[linha+1][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha][coluna+3] = '4';
                                                    vet[linha-1][coluna+3] = '4';
                                                    vet[linha+1][coluna+3] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna > 19 || linha<0 || coluna<0);
                        break;

                        case 6: // Porta-aviões.
                            do{ // Laço de repetição.
                                printf("Escolha o posicionamento do Porta-avioes:\n");
                                printf("[1] Normal\n");
                                printf("[2] Rotacionar 90 graus\n");     // Opções para virar o elemento.
                                printf("[3] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar>3){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar > 3);
                            if(virar==3){
                                system("cls");
                                break;
                            }
                            do{ // Laço de repetição.
                                printf("Digite a linha e coluna para o Porta-avioes: ");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){
                                        coluna = m;
                                    }
                                }
                                if(submarino==PAMAX){
                                    printf("Quantidade maxima de Porta-avioes atingida.\n"); // Limitar a quantidade.
                                }
                                else{
                                    switch(virar){
                                        case 1: // Opcão padrão:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(coluna>15 || linha>18){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha][coluna+4] != '*' || vet[linha+1][coluna] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+1][coluna+2] != '*' || vet[linha+1][coluna+3] != '*' || vet[linha+1][coluna+4] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '5';
                                                    vet[linha][coluna+1] = '5';
                                                    vet[linha][coluna+2] = '5';
                                                    vet[linha][coluna+3] = '5';
                                                    vet[linha][coluna+4] = '5';
                                                    vet[linha+1][coluna] = '5';
                                                    vet[linha+1][coluna+1] = '5';
                                                    vet[linha+1][coluna+2] = '5';
                                                    vet[linha+1][coluna+3] = '5';
                                                    vet[linha+1][coluna+4] = '5';
                                                    porta_avioes++;
                                                }
                                            }
                                        break;

                                        case 2: // Opcão rotacionar 90 graus.
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>15 || coluna>18){
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*' || vet[linha+4][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*' || vet[linha+4][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '5';
                                                    vet[linha+1][coluna] = '5';
                                                    vet[linha+2][coluna] = '5';
                                                    vet[linha+3][coluna] = '5';
                                                    vet[linha+4][coluna] = '5';
                                                    vet[linha][coluna+1] = '5';
                                                    vet[linha+1][coluna+1] = '5';
                                                    vet[linha+2][coluna+1] = '5';
                                                    vet[linha+3][coluna+1] = '5';
                                                    vet[linha+4][coluna+1] = '5';
                                                    porta_avioes++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna > 19 || linha<0 || coluna<0);
                        break;

                        case 9:
                            printf("Obrigado por jogar!\n");
                            return 0;
                            break;
                        case 8: // Case da opção aleatorizar.
                            do{ // Sortear boias aleatoriamente
                                linha = rand()%20;
                                coluna = rand()%20;

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                    }
                                    if(boia==BOMAX){
                                    }
                                    else if(linha>=0 && linha<TAM && coluna>=0 && coluna<TAM){
                                        if(vet[linha][coluna] != '*'){
                                    }
                                        else{
                                            vet[linha][coluna] = '0';
                                            boia++;
                                        }
                                    }
                            }while(boia<BOMAX);

                            do{ // Sortear aviões aleatoriamente
                                linha = rand()%20;
                                coluna = rand()%20;
                                virar = (rand()%4) + 1;

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                }
                                if(aviao==AVMAX){
                                }
                                else{
                                    switch(virar){ // switch case para rotação do elemento.
                                        case 1: // Opcão padrão:
                                            if(linha<1 || linha>18 || coluna>18){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha-1][coluna+1] != '*'){
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha+1][coluna+1] = '1';
                                                    vet[linha-1][coluna+1] = '1';
                                                    aviao++;
                                                    }
                                            }
                                        break;

                                        case 2: // Opção virar 90° para a direita:
                                            if(linha<1 || linha>19 || coluna>17){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha][coluna+2] != '*'){
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha-1][coluna+1] = '1';
                                                    vet[linha][coluna+2] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;

                                        case 3: // Opção virar 90° para a esquerda:
                                            if(linha>18 || coluna>17){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*'){
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha][coluna+2] = '1';
                                                    vet[linha+1][coluna+1] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;

                                        case 4: // Opcao virar 180°
                                            if(linha<1 || linha>18   || coluna>18){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*'){  // Verifica se há algum elemento na posição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha+1][coluna] = '1';
                                                    vet[linha-1][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(aviao<AVMAX);

                            do{ // Sortear submarinos aleatoriamente
                                linha = rand()%20;
                                coluna = rand()%20;
                                virar = (rand()%2) + 1;

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                }
                                if(submarino==SUMAX){
                                }
                                else{
                                    switch(virar){
                                        case 1: // Opcão padrão:
                                            if(coluna>16){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '2';
                                                    vet[linha][coluna+1] = '2';
                                                    vet[linha][coluna+2] = '2';
                                                    vet[linha][coluna+3] = '2';
                                                    submarino++;
                                                }
                                            }
                                        break;

                                        case 2: // Opcão rotacionar 90 graus.
                                            if(linha>16){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '2';
                                                    vet[linha+1][coluna] = '2';
                                                    vet[linha+2][coluna] = '2';
                                                    vet[linha+3][coluna] = '2';
                                                    submarino++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(submarino<SUMAX);

                            do{ // Sortear espião 1 aleatoriamente
                                linha = rand()%20;
                                coluna = rand()%20;
                                virar = (rand()%4) + 1;

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                }
                                if(espiao_1==E1MAX){
                                }

                                else{
                                    switch(virar){
                                        case 1:
                                            if(linha<1 || linha>18 || coluna>16){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha+1][coluna] = '3';
                                                    vet[linha-1][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha][coluna+3] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 2:
                                            if(linha>16 || coluna>17){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha+1][coluna+1] = '3';
                                                    vet[linha+2][coluna+1] = '3';
                                                    vet[linha+3][coluna+1] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 3:
                                            if(linha<3 || coluna>17){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha-1][coluna+1] = '3';
                                                    vet[linha-2][coluna+1] = '3';
                                                    vet[linha-3][coluna+1] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 4:
                                            if(linha<1 || linha>18 || coluna>16){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha-1][coluna+3] != '*' || vet[linha+1][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha][coluna+3] = '3';
                                                    vet[linha-1][coluna+3] = '3';
                                                    vet[linha+1][coluna+3] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(espiao_1<E1MAX);

                            do{ // Sortear espião 2 aleatoriamente
                                linha = rand()%20;
                                coluna = rand()%20;
                                virar = (rand()%4) + 1;

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                }
                                if(espiao_2==E2MAX){
                                }

                                else{
                                    switch(virar){
                                        case 1:
                                            if(linha<1 || linha>18 || coluna>16){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha+1][coluna] = '4';
                                                    vet[linha-1][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha][coluna+3] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 2:
                                            if(linha>16 || coluna>17){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha+1][coluna+1] = '4';
                                                    vet[linha+2][coluna+1] = '4';
                                                    vet[linha+3][coluna+1] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 3:
                                            if(linha<3 || coluna>17){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha-1][coluna+1] = '4';
                                                    vet[linha-2][coluna+1] = '4';
                                                    vet[linha-3][coluna+1] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 4:
                                            if(linha<1 || linha>18 || coluna>16){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha-1][coluna+3] != '*' || vet[linha+1][coluna+3] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha][coluna+3] = '4';
                                                    vet[linha-1][coluna+3] = '4';
                                                    vet[linha+1][coluna+3] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(espiao_2<E2MAX);

                            do{ // Sortear porta-aviões aleatoriamente
                                linha = rand()%20;
                                coluna = rand()%20;
                                virar = (rand()%2) + 1;
                                if(linha>19 || coluna>19 || linha<0 || coluna<0){
                                }
                                if(submarino==PAMAX){
                                }
                                else{
                                    switch(virar){
                                        case 1: // Opcão padrão:
                                            if(coluna>15 || linha>18){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha][coluna+4] != '*' || vet[linha+1][coluna] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+1][coluna+2] != '*' || vet[linha+1][coluna+3] != '*' || vet[linha+1][coluna+4] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '5';
                                                    vet[linha][coluna+1] = '5';
                                                    vet[linha][coluna+2] = '5';
                                                    vet[linha][coluna+3] = '5';
                                                    vet[linha][coluna+4] = '5';
                                                    vet[linha+1][coluna] = '5';
                                                    vet[linha+1][coluna+1] = '5';
                                                    vet[linha+1][coluna+2] = '5';
                                                    vet[linha+1][coluna+3] = '5';
                                                    vet[linha+1][coluna+4] = '5';
                                                    porta_avioes++;
                                                }
                                            }
                                        break;

                                        case 2: // Opcão rotacionar 90 graus.
                                            if(linha>15 || coluna>18){
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*' || vet[linha+4][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*' || vet[linha+4][coluna+1] != '*'){ // Condição para impedir sobreposição.
                                                }
                                                else{
                                                    vet[linha][coluna] = '5';
                                                    vet[linha+1][coluna] = '5';
                                                    vet[linha+2][coluna] = '5';
                                                    vet[linha+3][coluna] = '5';
                                                    vet[linha+4][coluna] = '5';
                                                    vet[linha][coluna+1] = '5';
                                                    vet[linha+1][coluna+1] = '5';
                                                    vet[linha+2][coluna+1] = '5';
                                                    vet[linha+3][coluna+1] = '5';
                                                    vet[linha+4][coluna+1] = '5';
                                                    porta_avioes++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(porta_avioes<PAMAX);
                        break;
                    }
                }while(voltar_sair2==0);

                break;


            case 2: // Opção sair.
                printf("Obrigado por jogar!\n");
                return 0;
                break;
            default:
                printf("\n");
                printf("Opcao invalida.\n");
        }
        system("cls");
    }while(voltar_sair==1);

    return 0;
}
