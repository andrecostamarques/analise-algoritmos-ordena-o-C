#include "metodos.h"

int main(void){

    FILE *file;

    file = fopen("data.csv", "w");

    if(file == NULL){
        printf("Error opening data file");
        return 1;
    }

    int vetores[5] = {10000, 50000, 100000, 500000, 1000000};
    results* arrayResultados = (results*)malloc(79*sizeof(results));
    unsigned int seed = 22001640;           //defina a seed dos numeros random 
    srand(seed);
    int m = 0;

    for(int j = 1; j < 6; j++){
        
        int sort = j;    //0 - 8 escolhe qual sort ele vai utilizar 

        for(int l = 1; l < 3; l++){

            int tipo = l; //define o tipo da array gerada
            
            for (int k = 0; k < 5; k++){

                int n = vetores[k]; //defina o tamanho da array gerada           
                 
                for(int i = 0; i < 10; i++){

                    printf("\nA seed que voce esta executando e: %d\n", seed); //printa o valor da seed.

                    array* umum = gerarArray(n,tipo);
                    
                    double tempo_exec = 0.0;
                    clock_t begin = clock();

                    switch (sort){
                        case 0:
                        quickSortPivoLS(umum,0,n-1);
                        strcpy(arrayResultados[m].sort, "quickLS");
                        break;
                        case 1:
                        quickSortPivo0(umum,0,n-1);
                        strcpy(arrayResultados[m].sort, "quick0");
                        break;
                        case 2:
                        quickSortPivoMeio(umum,0,n-1);
                        strcpy(arrayResultados[m].sort, "quickM");
                        break;
                        case 3:
                        shellSort(umum,n);
                        strcpy(arrayResultados[m].sort, "shellSort");                       
                        break;
                        case 4:
                        mergeSort(umum,n);
                        strcpy(arrayResultados[m].sort, "mergeSort");                        
                        break;
                        case 5:
                        heapSort(umum,n);
                        strcpy(arrayResultados[m].sort, "heapSort");
                        break;
                        case 6:
                        bubbleSort(umum,n);
                        strcpy(arrayResultados[m].sort, "bubbleSort");
                        break;
                        case 7:
                        insertionSort(umum,n);
                        strcpy(arrayResultados[m].sort, "isnertionSort");
                        break;
                    }

                    clock_t end = clock();
                    tempo_exec += (double)(end - begin)/CLOCKS_PER_SEC;

                    arrayResultados[m].tipo = tipo;
                    arrayResultados[m].tamanho = n;
                    arrayResultados[m].tempos[i]=tempo_exec;

                    free(umum);

                    printf("\nArray %d:Tempo de execucao: %f s do metodo %s, tipo %d, com %d elementos.",m,arrayResultados[m].tempos[i],arrayResultados[m].sort,arrayResultados[m].tipo,arrayResultados[m].tamanho);
                }

                m++;

            }
        }
    }


    fprintf(file,"indice,metodo,tipo,tamanho,tempo1,tempo2,tempo3,tempo4,tempo5,tempo6,tempo7,tempo8,tempo9,tempo10\n");
    for(int i = 0; i < 50; i++){
            fprintf(file,"%d,%s,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
            i,
            arrayResultados[i].sort,
            arrayResultados[i].tipo,
            arrayResultados[i].tamanho, 
            arrayResultados[i].tempos[0],
            arrayResultados[i].tempos[1],
            arrayResultados[i].tempos[2],
            arrayResultados[i].tempos[3],
            arrayResultados[i].tempos[4],
            arrayResultados[i].tempos[5],
            arrayResultados[i].tempos[6],
            arrayResultados[i].tempos[7],
            arrayResultados[i].tempos[8],
            arrayResultados[i].tempos[9]);
    }
    
    return 0;
}
