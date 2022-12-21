#include "../Headers/Funcoes.h"



int Conta_Linhas_do_Arquivo(char *nome_arquivo)
{
    FILE *arquivo_de_entrada;
    arquivo_de_entrada = fopen(nome_arquivo, "r");
    int contador_de_linhas = 0;
    char caractere, quebra_de_linha = '\n';
    char letra;

    while(!feof(arquivo_de_entrada)){
        caractere = fgetc(arquivo_de_entrada);
        if(caractere == quebra_de_linha){
            
            contador_de_linhas++;
            printf(">>%d", contador_de_linhas);
        }
    }
    contador_de_linhas += 1;

    //printf("\n\nN=%d", contador_de_linhas);
    return contador_de_linhas;

}


int operacoes(int resposta)
{
    int N;
    float tempoTOTAL;
    time_t tempoINICIAL, tempoFINAL;

    tempoINICIAL = time(NULL);

    switch (resposta)
    {
    

    case 10:
        N = 10;

        printf("\nAbrindo arquivo 'entrada10.txt'...\n");
        Recebe_Arquivo_ADJACENCIAS("entrada10.txt");

        break;
    
    case 15:
        N = 15;

        printf("\nAbrindo arquivo 'entrada15.txt'...\n");
        Recebe_Arquivo_ADJACENCIAS("entrada15.txt");

        break;

    case 20:
        N = 20;

        printf("\nAbrindo arquivo 'entrada20.txt'...\n");
        Recebe_Arquivo_ADJACENCIAS("entrada20.txt");

        break;

    case 30:
        N = 30;

        printf("\nAbrindo arquivo 'entrada30.txt'...\n");
        Recebe_Arquivo_ADJACENCIAS("entrada30.txt");

        break;

    case 40:
        N = 40;

        printf("\nAbrindo arquivo 'entrada40.txt'...\n");
        Recebe_Arquivo_ADJACENCIAS("entrada40.txt");

        break;


    case 99:
        N = Conta_Linhas_do_Arquivo("entrada_de_teste_do_usuario.txt");
        
        printf("\nAbrindo arquivo 'entrada_de_teste_do_usuario.txt'...\n");
        Recebe_Arquivo_ADJACENCIAS("entrada_de_teste_do_usuario.txt");

        break;

    case 0:
        printf("\n\tFinalizando o programa...");
        break;


    case 100:
        printf("\n\n\tAguarde a proxima DLC - talvez sera lancada quando computadores quanticos forem normais\n");
        break;

    default:
        break;
    }

    tempoFINAL = time(NULL);

    tempoTOTAL = difftime(tempoFINAL, tempoINICIAL);
    printf("\nTempo total gasto no processo: %.3f segundos\n", tempoTOTAL);


}

void menu()
{
    int resposta;
    
    printf("\n\nInsira o arquivo que deseja que o programa execute:\n");
    printf("\t================================================================\n");
    printf("\t| 10 - entrada10.txt ---------------------------------- N = 010|\n");
    printf("\t| 15 - entrada15.txt ---------------------------------- N = 015|\n");
    printf("\t| 20 - entrada20.txt ---------------------------------- N = 020|\n");
    printf("\t| 30 - entrada30.txt ---------------------------------- N = 030|\n");
    printf("\t| 40 - entrada40.txt ---------------------------------- N = 040|\n");
    printf("\t| 99 - arquivo_de_entrada_inserido_pelo_usuario.txt --- N = ???|\n");
    printf("\t|100 - entrada100.txt --------------------------------- N = 100|\n");
    printf("\t|                                                              |\n");
    printf("\t|                                                              |\n");
    printf("\t|  0 - finalizar testes--------------------------------        |\n");
    printf("\t================================================================\n");
    
    printf("\nResposta: ");
    scanf("%d", &resposta);

    operacoes(resposta);
}
