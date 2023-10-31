#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct dado{
    float info;
    int chave;  //criando a estrutura dado
} array;


    //oq é o bubble sort? ele faz diversas passagens pela array e checa os valores adjacentes, se for necessário 
    //ele troca os valores adjacentes, ele repete esse percurso tantas vezes que troca todos os valores adjacentes
    //e ordena a array inteira


void bubbleSort(array* a, int qnt){

    array temp; //objeto temp que será necessário para a execução 

    double tempo_exec = 0.0;
    clock_t begin = clock();

    for(int i = 0; i < qnt; i++){

        for(int j = 0; j < qnt-1; j++){

            if(a[j].info < a[j+1].info){

                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;

            }
        }
    }

    clock_t end = clock();
    tempo_exec += (double)(end - begin)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %fs",tempo_exec);

}

void printArray(array *a, int qnt){

    printf("Info / Chave");
    for(int i = 0; i < qnt; i++){
    printf("\n%.f - %d", a[i].info, a[i].chave);
    }
    
}

int main(void){

    int n = 1000000;
    unsigned int seed = 1698710382; 

    //declaração dos vetores
    array* umum =  (array*)malloc(n*sizeof(array));


    srand(seed); 
    //passando o valor da seed criada pelo tempo para a função srand
    //todos os numeros random serão baseados nessa seed agr.

    printf("\nA seed que voce esta executando e: %d\n", seed); //printa o valor da seed.


    //gerando aleatoriamente o valor da array de 10000.
    for(int i = 0; i < n ; i++){
        umum[i].info = rand()+100;  //valor float maior que 100
        umum[i].chave = rand();     //chave aleatoria int
    }

    bubbleSort(umum,n);
    //printArray(umumptr,n);
    
    return 0;
}
