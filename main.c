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

void shellSort(array* a, int qnt ){

    int j,h;
    array aux;

    double tempo_exec = 0.0;
    clock_t begin = clock();
    
    for(h = 1; h < qnt; h = 3 * h+1);
    while (h>0)
    {
       h = (h-1) /3;
       for (int i = h; i < qnt; i++){
        aux = a[i];
        j = i;
        
            while (a[j-h].chave > aux.chave){
                a[j] = a[j-h];
                j = h;
                if (j < h){
                    break;
                }         
            }
            a[j] = aux;
        }
    }

    clock_t end = clock();
    tempo_exec += (double)(end - begin)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %fs",tempo_exec);
          
}

void bubbleSort(array* a, int qnt){
    int flag = 1;

    array temp; //objeto temp que será necessário para a execução 

    double tempo_exec = 0.0;
    clock_t begin = clock();

    for(int i = 0; i < qnt && flag == 1; i++){

        flag = 0;
        
        for(int j = 0; j < qnt-1; j++){

            if(a[j].chave < a[j+1].chave){

                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp; 

                flag = 1;
            }
        }

    }

    clock_t end = clock();
    tempo_exec += (double)(end - begin)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %fs",tempo_exec);

}

void printArray(array *a, int qnt){

    printf("\nInfo / Chave");
    for(int i = 0; i < qnt; i++){
    printf("\n%.2f - %d", a[i].info, a[i].chave);
    }
    
}

int main(void){

    int n = 10000;
    unsigned int seed = 22001640; 
    int tipo = 1;

    //declaração dos vetores
    array* umum =  (array*)malloc(n*sizeof(array));


    srand(seed); 
    //passando o valor da seed criada pelo tempo para a função srand
    //todos os numeros random serão baseados nessa seed agr.

    printf("\nA seed que voce esta executando e: %d\n", seed); //printa o valor da seed.

    if( tipo ==  1){
    //gerando aleatoriamente o valor da array de 10000.
    for(int i = 0; i < n ; i++){
        umum[i].info = rand()+100;  //valor float maior que 100
        umum[i].chave = rand();     //chave aleatoria int
    }}

    else if( tipo == 2){
    for(int i = 0; i < n ; i++){
        umum[0].chave = rand()%10000;
        umum[i].info = rand()+100; //valor float
        umum[i].chave = rand() + umum[i-1].chave; //chave aleator
    }}

    shellSort(umum,n);
    //printArray(umum,n);
    
    return 0;
}
