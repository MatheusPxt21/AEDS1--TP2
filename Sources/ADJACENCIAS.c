#include "../Headers/ADJACENCIAS.h"

void Recebe_Arquivo_ADJACENCIAS(char *nome_arquivo_de_entrada){

    int n = 0;
    char *p;

    
    FILE *arquivo_de_entrada;
    int var_auxiliar = 0;
    int control = 0;
    int var;
    arquivo_de_entrada = fopen(nome_arquivo_de_entrada, "r");

    if(arquivo_de_entrada==NULL){
        printf("\n\tErro na arbertura do arquivo!\n");
        return;
    }

    
    
    printf("\n\tArquivo aberto com sucesso!\n");

    
    char string_suporte[1000];
    
    while(!(feof(arquivo_de_entrada))){

    fgets(string_suporte,1000,arquivo_de_entrada);
    n +=1;

}

    fseek(arquivo_de_entrada,0,SEEK_SET);
    
    int LINHA = n;
    int COLUNA = n;
    
    int matriz[n][n];
    int i, j;



    //insere -1 na diagonal principal da matriz
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            if(i == j){
                matriz[i][j] = -1;
            }
            else{
                matriz[i][j] = 0;
            }
        }
    }
    

    
    fseek(arquivo_de_entrada,0,SEEK_SET);
    char string_definitiva[n][1000];
    
    

    while(!(feof(arquivo_de_entrada))){

        fgets(string_definitiva[var_auxiliar],1000,arquivo_de_entrada);
        var_auxiliar+=1;

    }

    for(int i = 0;i<var_auxiliar;i++){

        p = strtok(string_definitiva[i]," ,!-;");
        while(p!=NULL){

                
                

                var = atoi(p);

                if(n<10){


                        matriz[i][var] = 1;
                        p = strtok(NULL," -,!");

                }else{


                        if(var!=i){


                            matriz[i][var] = 1;
                            

                        }

                        p = strtok(NULL," -,!");
                          
                    }

                }
                     
            }

    for(int i = 0;i<n;i++){
        printf("[");
        for(int j = 0;j<n;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("]\n");
    }


    ARRANJO(n, matriz);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(((i==j)&(matriz[i][j]== 1))){
                control +=1;
            }
        }
    }
}