#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct dado{
    float info;
    int chave;  //criando a estrutura dado
} array;

int particao(array* receb, int li, int ls){

    array aux, pivo;   //cria 2 objetos de array que vao auxiliar
    int xi, xs;        //xs e xi são os indices para percorrer a array
    xi = li, xs = ls;  //li = limite infeior | ls = limite superior
    pivo = receb[xi]; //o pivo é o limite esquerdo  //pívo recebe o limite infeiror, ou seja, ele recebe o array0

    while(xi < xs) {    //enquanto xi for menor que xs, isso é, enquanto eles não se superarem, o codigo ocorrerá
        
        while((receb[xi].chave >= pivo.chave) && (xi<ls)){
        //se chave de xi é maior ou igual o pivo, xi aponta para o proximo indice
        xi++;
        }
        while((receb[xs].chave < pivo.chave) && (xs>li)){
        //se a chave de xs é menor que o pivo, xs aponta para o indice anterior
        xs--;
        }
        if(xi<xs){  //se eles não tiverem se cruzados vai ocorrer a substituição
            
            aux=receb[xi];
            receb[xi]=receb[xs];    //é usado o objeto auxiliar para realizar a troca
            receb[xs]=aux;          //é realizada a troca do item a esquerda que é menor do que o pivo com o item a direita que é maior que o pivo

        }
    }

    aux = receb[li];    
    receb[li]=receb[xs];    //o pivo é colocado no local que deve estar, no meio de todos os valores
    receb[xs]=aux;

    return xs;  //o indice do pivo é retornado na função
}

void quickSortPivo0(array* receb, int li, int ls){

if(li<ls){  //se os limites forem corretos o codigo será executado

    int p;  //p salva o indice do pivo recebido da função acima.
    p = particao(receb,li,ls);  //depois de receber o pivo, é executado o quicksort para cada filho restante dele
    quickSortPivo0(receb,li,p-1);
    quickSortPivo0(receb,p+1,ls);
    }

}

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

array* gerarArray(int n, int tipo){

    array* aux =  (array*)malloc(n*sizeof(array));

    if( tipo ==  1){
    //gerando aleatoriamente o valor da array de 10000.
    for(int i = 0; i < n ; i++){
        aux[i].info = rand()+100;  //valor float maior que 100
        aux[i].chave = rand();     //chave aleatoria int
    }}

    else if( tipo == 2){
    for(int i = 0; i < n ; i++){
        aux[0].chave = rand()%10000;
        aux[i].info = rand()+100; //valor float
        aux[i].chave = rand() + aux[i-1].chave; //chave aleator
    }}

    return aux;
}

int main(void){

    int n = 10000;
    unsigned int seed = 22001640; 
    int tipo = 1;

    srand(seed); 
    printf("\nA seed que voce esta executando e: %d\n", seed); //printa o valor da seed.

    array* umum = gerarArray(n,tipo);
    
    double tempo_exec = 0.0;
    clock_t begin = clock();

    //bubbleSort(umum,n);
    //shellSort(umum,n);
    quickSortPivo0(umum,0,n-1);

    clock_t end = clock();
    tempo_exec += (double)(end - begin)/CLOCKS_PER_SEC;

    printArray(umum,n);
    printf("\nTempo de execucao: %fs",tempo_exec);
    
    return 0;
}
