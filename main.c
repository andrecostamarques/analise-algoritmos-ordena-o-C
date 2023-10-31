#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct dado{
    float info;
    int chave;  //criando a estrutura dado
} array;

int main(void){

    //declaração dos vetores
    // array umum[10000];
    // array umdois[10000];	
    // //vai ser uma array de dois tipos, cada vez que executar o código (ou terão vários codigos) será uma array 
    // //diferente para não ter problema de memória

    // unsigned int seed = 1698710382; //salvando a seed pela função tempo -> peguei em algum dia um numero random
    // srand(seed); //passando o valor da seed criada pelo tempo para a função srand -> 
    // //todos os numeros random serão baseados nessa seed agr.
    // printf("%d", seed);

    // for(int i = 0; i < 10000 ; i++){
    //     umum[i].info = rand()+100;  //valor float maior que 100
    //     umum[i].chave = rand();     //chave aleatoria int
    // }
    // printf("\n%d", umum[0].chave);

    // for(int i = 0; i < 10000 ; i++){    
    //     umdois[i].info = rand()+100;    //valor float maior que 100
    //     umdois[i].chave = i;            //chave int ordem crescente
    // }
    // printf("\n%d", umdois[0].chave);

    array teste[5];
    teste[0].chave = 0;
    teste[1].chave = 1;
    teste[2].chave = 2;
    teste[3].chave = 3;
    teste[4].chave = 4;

    teste[0].info = 7;
    teste[1].info = 19;
    teste[2].info = 1;
    teste[3].info = 22;
    teste[4].info = 13;

    array temp;




    //bubble sort que é mais fácil ----------------------------------------------------------------
    //oq é o bubble sort? ele faz diversas passagens pela array e checa os valores adjacentes, se for necessário 
    //ele troca os valores adjacentes, ele repete esse percurso tantas vezes que troca todos os valores adjacentes
    //e ordena a array inteira

    for(int i = 0; i < 5; i++){

            printf("\nNova run maior\n");

        for(int j = 0; j < 5-1; j++){

                printf("Chave: %d/ ", teste[j].chave);
                printf("Info: %.f/ \n", teste[j].info);


            if(teste[j].info > teste[j+1].info){

                printf("\nTroca realizada: de %d com %d\n",teste[j].chave, teste[j+1].chave);

                

                temp = teste[j];
                teste[j] = teste[j+1];
                teste[j+1] = temp;

            }

        }

    }

    printf("Info / Chave");
    for(int i = 0; i < 5; i++){
    printf("\n%.f - %d", teste[i].info, teste[i].chave);
    }

    return 0;
}