#include "../Headers/ARRANJO.h"

#define MAX 250

void ARRANJO(int N, int matriz[N][N])
{
    int LINHA_MATRIZ = N;
    int COLUNA_MATRIZ = N;
    int *num;
    int cont = 0;

    char str[MAX] ;

    char K[] = {'A', 'B'};
    int tamanho_K, i, j, x, y, aux ;

    //printf("N para este arranjo: %d\n", N);



    tamanho_K = strlen(K) ;
    j = 0;
    str[0] = 0 ;
    for ( i = 0; i < tamanho_K; i++ ) {
        if ( strchr(str, K[i]) == NULL ) {
            str[j] = K[i] ;
            j++ ;
            str[j] = 0 ;
        }
    }
    strcpy(K, str) ;
    tamanho_K = strlen(K) ;

    //printf("\n tamanho de k: %d\n", tamanho_K);
    
    num = (int *) calloc( (N+1), sizeof(int)) ;
    if ( num == NULL ) {
        perror("calloc") ;
        return;
    }

    
    int contador = 0;
    //int oi;
    while ( num[N] == 0 ) {
        for ( i = 0; i < tamanho_K; i++ ) {
            /* processo de mapeamento. */
            for ( j = 0, aux = N-1; j < N; j++ ) {
                str[aux] = K[num[j]] ;
                aux-- ;
            }
            
            str[N] = 0 ;
            cont++;
            //printf("%d: %s\n", cont, str);

           

            //aqui esta percorrendo toda a matriz a cada arranjo gerado
            for(x = 0; x < LINHA_MATRIZ; x++){
                for(j = 0; j < COLUNA_MATRIZ; j++){
                    
                    if(matriz[x][j] == -1){
                        
                        contador++;
                        
                    }
                    if(matriz[x][j] == 0){
                        
                        contador++;
                        
                        if(str[x] == str[j]){
                        
                            contador = 0;
                            
                            break;
                        }
                    }
                    if(matriz[x][j] == 1){
                        
                        if(str[x] == str[j]){
                            contador = 0;
                            break;
                        }
                        else{
                            
                            
                            contador++;
                        }

                    
                        }
                    if(contador >= N){
                            //printf("ACHEI\n");
                            //scanf("%d", &oi);
                            printf("\nO arranjo %s possivelmente serve para a linha %d da matriz!\n", str, x);
                            contador = 0; //reinicia o contador para poder analisar o proximo arranjo
                            
                    }

                }
            }

            num[0]++;
        }
        
        

        /* Muda de "casa" e lança os vai uns. */ 
        for ( i = 0; i < N; i++ ) {
            if ( num[i] == tamanho_K ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }
    
}
