#include <stdio.h>
#include <stdlib.h>

void inicializaTabuleiro(int tabuleiro[][10])
{
    int linha, coluna;
        for(linha=0 ; linha < 10; linha++ )
            for(coluna=0 ; coluna < 10 ; coluna++ )
                tabuleiro[linha][coluna]=-1;
}

void mostraTabuleiro(int tabuleiro[][10]){
    int linha, coluna;
        for(coluna=1;coluna<=10;coluna++){
            printf("\t%d",coluna);
        }
        printf("\n");
        for(linha=0 ; linha < 10 ; linha++ ){
            printf("%c",linha+65);
            for(coluna=0 ; coluna < 10 ; coluna++ ){
                if(tabuleiro[linha][coluna]==-1){
                    printf("\t~");
                }else if(tabuleiro[linha][coluna]==0){
                    printf("\t*");
                }else if(tabuleiro[linha][coluna]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

    }
void mostraTabuleirop(int tabuleiro[][10]){
    int linha, coluna;
        for(coluna=1;coluna<=10;coluna++){
            printf("\t%d",coluna);
        }
        printf("\n");
        for(linha=0 ; linha < 10 ; linha++ ){
            printf("%c",linha+65);
            for(coluna=0 ; coluna < 10 ; coluna++ ){
                if(tabuleiro[linha][coluna]==-1){
                    printf("\t~");
                }else if(tabuleiro[linha][coluna]==0){
                    printf("\t*");
                }else if(tabuleiro[linha][coluna]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

    }

void iniciaNavios(int navios[][2]){
        srand(time(NULL));
        int navio, anterior;

        for(navio=0 ; navio < 5 ; navio++){
            navios[navio][0]= rand()%10;
            navios[navio][1]= rand()%10;
            navios[navio][2]= rand()%10;
            navios[navio][3]= rand()%10;
            navios[navio][4]= rand()%10;
            for(anterior=0 ; anterior < navio ; anterior++){
                if( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) )
                    do{
                        navios[navio][0]= rand()%10;
                        navios[navio][1]= rand()%10;
                    }while( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) );
            }

        }
    }
void geraNavios(int naviosp[][2]){
        int navio;
        printf("Digite a posicao do primeiro navio: ");
        scanf("%d", &naviosp[navio][0]);
        printf("Digite a posicao do segundo navio: ");
        scanf("%d", &naviosp[navio][1]);
        printf("Digite a posicao do terceiro navio: ");
        scanf("%d", &naviosp[navio][2]);
        printf("Digite a posicao do quarto navio: ");
        scanf("%d", &naviosp[navio][3]);
        printf("Digite a posicao do quinto navio: ");
        scanf("%d", &naviosp[navio][4]);
}
void darTiro(int tiro[2])
{

        printf("Linha: ");
        scanf("%d",&tiro[0]);
        tiro[0]--;

        printf("Coluna: ");
        scanf("%d",&tiro[1]);
        tiro[1]--;

}
void Tirocpu(int tirocpu[2]){
        tirocpu[0]=rand()%10;
        tirocpu[0]--;
        tirocpu[1]=rand()%10;
        tirocpu[1]--;
}

int acertou(int tiro[2], int navios[][2])
{
    int navio;

        for(navio=0 ; navio < 5 ; navio++){
            if( tiro[0]==navios[navio][0] && tiro[1]==navios[navio][1]){
                printf("Você acertou o tiro (%d,%d)\n",tiro[0]+1,tiro[1]+1);
                return 1;
            }
        }
        return 0;
    }
int acertoucpu(int tirocpu[2], int naviosp[][2]){
          int navio;
          for(navio=0 ; navio<5; navio++){
            if( tirocpu[0]==naviosp[navio][0] && tirocpu[1]==naviosp[navio][1]){
                return 1;
            }
        }
        return 0;
}
void dica(int tiro[2], int navios[][2], int tentativa){
        int linha=0,
            coluna=0,
            fila;
        for(fila=0 ; fila < 3 ; fila++){
            if(navios[fila][0]==tiro[0])
                linha++;
            if(navios[fila][1]==tiro[1])
                coluna++;
        }
        printf("\nDica %d: \nlinha %d -> %d navios\ncoluna %d -> %d navios\n",tentativa,tiro[0]+1,linha,tiro[1]+1,coluna);
}

void alteraTabuleiro(int tiro[2], int navios[][2], int tabuleiro[][10]){
        if(acertou(tiro,navios))
            tabuleiro[tiro[0]][tiro[1]]=1;
        else
            tabuleiro[tiro[0]][tiro[1]]=0;
}
void alteraTabuleirop(int tiro[2], int navios[][2], int tabuleiro[][10]){
        if(acertou(tiro,navios))
            tabuleiro[tiro[0]][tiro[1]]=1;
        else
            tabuleiro[tiro[0]][tiro[1]]=0;
    }

int main() {
        int tabuleiro[10][10];
        int tabuleirop[10][10];
        int navios[5][2];
        int naviosp[5][2];
        int tiro[2];
        int tirocpu[2];
        int aux=0;
        int aux2=0;
        int tentativas=0,
            acertos=0;
        int acertoscpu=0;
        int choice;
        printf("Olá, como voce deseja jogar?\n 1 - Sozinho.\n 2 - Contra a CPU.\n 3 - Dois jogadores. ");
        scanf("%d",&choice);
        inicializaTabuleiro(tabuleiro);
        iniciaNavios(navios);
        inicializaTabuleiro(tabuleirop);
        switch (choice){
              case 1: do{
                            mostraTabuleiro(tabuleiro);
                            darTiro(tiro);
                            tentativas++;
                            if(acertou(tiro,navios)){
                                dica(tiro,navios,tentativas);
                                acertos++;
                            }
                            else{
                                dica(tiro,navios,tentativas);
                            }
                                alteraTabuleiro(tiro,naviosp,tabuleiro);

                        }while(acertos!=5);
                        printf("\n\n\nJogo terminado. Você acertou os 5 navios em %d tentativas", tentativas);
                        mostraTabuleiro(tabuleiro);

                case 2:
                            geraNavios(naviosp);
                            do{
                                printf("CPU:\n");
                                mostraTabuleiro(tabuleiro);
                                printf("\nPlayer:\n");
                                Tirocpu(tirocpu);
                                mostraTabuleirop(tabuleirop);
                                darTiro(tiro);
                                tentativas++;
                                aux=acertou(tiro,navios);
                                aux2=acertoucpu(tirocpu,naviosp);
                            if(aux==1){
                                dica(tiro,navios,tentativas);
                                acertos++;
                            }
                            alteraTabuleiro(tiro,navios,tabuleiro);
                            if(aux2==1){
                                acertoscpu++;
                            }
                                 alteraTabuleirop(tirocpu,navios,tabuleirop);
                        }while(acertos!=5 && acertoscpu!=5);
                        if (aux>aux2){
                            printf("Voce venceu");
                        }
                        else{
                            printf("A CPU venceu");
                        }
        }
    }
