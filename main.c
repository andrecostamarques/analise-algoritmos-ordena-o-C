#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct dado{
    float info;
    int chave;
} array;

int main(void){

    //declaração dos vetores

    array umum[10000];
    // array umdois[10000];	
    array doisum[50000];	
    // array doisdois[50000];
    array tresum[100000];
    // array tresdois[100000];
    array quatroum[500000];	
    // array quatrodois[500000];	
    array cincoum[1000000];
    // array cincodois[1000000];

    unsigned int seed = (unsigned int) time(0); //salvando a seed pela função tempo
    srand(seed); //passando o valor da seed criada pelo tempo para a função srand -> 
    //todos os numeros random serão baseados nessa seed agr.
    printf("%d", seed);

    for(int i = 0; i < 10000 ; i++){
        umum[i].info = rand()+100;
        umum[i].chave = rand();
    }
        printf("\n%d", umum[0].chave);
    for(int i = 0; i < 50000 ; i++){
        doisum[i].info = rand()+100;
        doisum[i].chave = rand();
    }
    
    printf(" %d", doisum[0].chave);
    for(int i = 0; i < 100000 ; i++){
        tresum[i].info = rand()+100;
        tresum[i].chave = rand();
    }
    
    printf(" %d", tresum[0].chave);
    for(int i = 0; i < 500000 ; i++){
        quatroum[i].info = rand()+100;
        quatroum[i].chave = rand();
    }
    
    printf(" %d", quatroum[0].chave);
    for(int i = 0; i < 1000000 ; i++){
        cincoum[i].info = rand()+100;
        cincoum[i].chave = rand();
    }

    printf(" %d", cincoum[0].chave);










    return 0;
}