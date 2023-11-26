#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h> 

typedef struct dado{    // estrutura de dados
    float info;
    int chave;  
} array;

typedef struct resultados{  //estrutura dos resultados
    char sort[20];
    int tipo;
    int tamanho;
    double tempos[10];
} results;

void insertionSort(array* a, int n){    //insertion sort
    int i, j, k;
    for(i = 1; i < n; i++){
        for(j = i - 1, k = a[i].chave; j >= 0 && a[j].chave < k; a[j + 1].chave = a[j].chave, j--);
        a[j + 1].chave = k;
    }
}

void heapify(array* a, int n, int i) {  //auxiliar do heap sort
    array aux;
    int menor = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq < n && a[esq].chave < a[menor].chave)
        menor = esq;

    if (dir < n && a[dir].chave < a[menor].chave)
        menor = dir;

    if (menor != i) {
        aux = a[i];
        a[i] = a[menor];
        a[menor]=aux;
        heapify(a, n, menor);
    }
}

void heapSort(array* a, int n) {    //heap sort
    array aux;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i=n-1; i>=0; i--) {
        aux = a[0];
        a[0] = a[i];
        a[i]=aux;
        heapify(a, i, 0);
    }
}

void merge(array vet[], array left[], array right[], int l_len, int r_len) {    //auxiliar do merge sort
    int i = 0, j = 0, k = 0;

    while (i < l_len && j < r_len) {
        if (left[i].chave >= right[j].chave) {
            vet[k] = left[i];
            i++;
        } else {
            vet[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < l_len) {
        vet[k] = left[i];
        i++;
        k++;
    }

    while (j < r_len) {
        vet[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(array vet[], int len) {  //merge sort
    if (len == 1) return;

    int l_len = len / 2, r_len = len - len / 2;
    array *left = (array *)malloc(l_len * sizeof(array));
    array *right = (array *)malloc(r_len * sizeof(array));

    for (int i = 0; i < l_len; i++) {
        left[i] = vet[i];
    }

    for (int i = 0; i < r_len; i++) {
        right[i] = vet[l_len + i];
    }

    mergeSort(left, l_len);
    mergeSort(right, r_len);

    merge(vet, left, right, l_len, r_len);

    free(left);
    free(right);
}

int particaoPivoLS(array* a, int li, int ls){   //auxiliar do LS

    array aux, pivo;
    int xi, xs;
    xi = li, xs = ls;
    pivo = a[xs]; 

     while(xi < xs) {    
        
        while ((xi < ls) && (a[xi].chave > pivo.chave)) {
        xi++;
        }
        while ((xs > li)  && (a[xs].chave <= pivo.chave)) {
        xs--;
        }
        if(xi<xs){  
            
            aux=a[xi];
            a[xi]=a[xs];    
            a[xs]=aux;          

        }
    }

    aux = a[ls];    
    a[ls]=a[xi];    
    a[xi]=aux;    

    return xi; 

}

void quickSortPivoLS(array* receb, int li, int ls){ //quicksortLS

if(li<ls){  

    int p;  
    p = particaoPivoLS(receb,li,ls);  
    quickSortPivoLS(receb,li,p-1);
    quickSortPivoLS(receb,p+1,ls);
    }

}

int particao(array* receb, int li, int ls){ //auxiliar quick0

    array aux, pivo;   
    int xi, xs;        
    xi = li, xs = ls;  
    pivo = receb[xi]; 

    while(xi < xs) {    
        
        while ((xi < ls) && (receb[xi].chave >= pivo.chave)) {
        xi++;
        }

        while ((xs > li)  && (receb[xs].chave < pivo.chave)) {
        xs--;
        }

        if(xi<xs){  
            
            aux=receb[xi];
            receb[xi]=receb[xs];    
            receb[xs]=aux;         

        }
    }

    aux = receb[li];    
    receb[li]=receb[xs];   
    receb[xs]=aux;

    return xs; 
}

void quickSortPivo0(array* receb, int li, int ls){   //quicksort0

if(li<ls){  

    int p;  
    p = particao(receb,li,ls);  
    quickSortPivo0(receb,li,p-1);
    quickSortPivo0(receb,p+1,ls);
    }

}


int particaoMeio(array *v, int LI, int LS) { //auxliar meio
    int meio = (LI + LS) / 2;
    array aux, pivo;
    pivo = v[meio];
    int xi = LI, xs = LS;
    while (xi < xs) {
        while ((xi < LS) && (v[xi].chave >= pivo.chave)) {
            xi++;
        }
        while ((xs > LI)  && (v[xs].chave <= pivo.chave)) {
            xs--;
        }
        if (xi < xs) {
            aux = v[xi];
            v[xi] = v[xs];
            v[xs] = aux;
        }
    }
    if(xi>meio){
        aux = v[meio];
        v[meio] = v[xs];
        v[xs]=aux;
        return xs;
    }  else{
        aux = v[meio];
        v[meio] = v[xi];
        v[xi] = aux;
        return xi;
    }
}
void quickSortPivoMeio(array *v, int LI, int LS) {  //quicksort meio
    if (LI < LS) {
        int p;
        p = particaoMeio(v, LI, LS);
        quickSortPivoMeio(v, LI, p - 1);
        quickSortPivoMeio(v, p + 1, LS);
    }
}


void shellSort(array* a, int qnt ){ //shellsort
  
    int i,j,h; 
    array aux; 
    
    for(h = 1; h < qnt; h = 3*h +1); 
    while (h>0) 
    {
       h = (h-1) /3;
       for (i = h; i < qnt; i++){ 
        aux = a[i];
        j = i;
        
        while (a[j-h].chave < aux.chave){ 
            a[j] = a[j-h]; 
            j -= h;
            if (j < h){
            break;
            }         
        }
        a[j] = aux;
        }
    }

}

void bubbleSort(array* a, int qnt){ //bubble sort
    int flag = 1;

    array temp;  

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
}

void printArray(array *a, int qnt){ //funcao de printar array

    printf("\nInfo / Chave");
    for(int i = 0; i < qnt; i++){
    printf("\n%.2f - %d", a[i].info, a[i].chave);
    }
    
}

array* gerarArray(int n, int tipo){ //funcao de gerar array

    array* aux =  (array*)malloc(n*sizeof(array));

    if( tipo ==  1){

    for(int i = 0; i < n ; i++){
        aux[i].info = rand()+100;  
        aux[i].chave = rand();     
    }}

    else if( tipo == 2){
    for(int i = 0; i < n ; i++){
        aux[0].chave = rand()%10000;
        aux[i].info = rand()+100; 
        aux[i].chave = rand() + aux[i-1].chave; 
    }}

    return aux;
}