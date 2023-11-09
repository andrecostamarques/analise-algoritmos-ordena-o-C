#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct dado{
    float info;
    int chave;  //criando a estrutura dado
} array;

void insertionsort(int *vet, int n){
    int i, j, k;
    for(i = 1; i < n; i++){
        for(j = i - 1, k = vet[i]; j >= 0 && vet[j] < k; vet[j + 1] = vet[j], j--);
        vet[j + 1] = k;
    }
}



void merge(array vet[], array left[], array right[], int l_len, int r_len) {
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

void mergeSort(array vet[], int len) {
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

int particaoPivoLS(array* a, int li, int ls){

    array aux, pivo;
    int xi, xs;
    xi = li, xs = ls;
    pivo = a[xs]; //o pivo é o limite direito

     while(xi < xs) {    //enquanto xi for menor que xs, isso é, enquanto eles não se superarem, o codigo ocorrerá
        
        while((a[xi].chave > pivo.chave) && (xi<ls)){
        //se chave de xi é maior  o pivo, xi aponta para o proximo indice
        xi++;
        }
        while((a[xs].chave <= pivo.chave) && (xs>li)){
        //se a chave de xs é menor ou igual que o pivo, xs aponta para o indice anterior
        xs--;
        }
        if(xi<xs){  //se eles não tiverem se cruzados vai ocorrer a substituição
            
            aux=a[xi];
            a[xi]=a[xs];    //é usado o objeto auxiliar para realizar a troca
            a[xs]=aux;          //é realizada a troca do item a esquerda que é menor do que o pivo com o item a direita que é maior que o pivo

        }
    }

    aux = a[ls];    
    a[ls]=a[xi];    //o pivo é colocado no local que deve estar, no meio de todos os valores
    a[xi]=aux;

    return xi;  //o indice do pivo é retornado na função

}
void quickSortPivoLS(array* receb, int li, int ls){

if(li<ls){  //se os limites forem corretos o codigo será executado

    int p;  //p salva o indice do pivo recebido da função acima.
    p = particaoPivoLS(receb,li,ls);  //depois de receber o pivo, é executado o quicksort para cada filho restante dele
    quickSortPivoLS(receb,li,p-1);
    quickSortPivoLS(receb,p+1,ls);
    }

}

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


int particaoMeio(array *v, int LI, int LS) { //faz parte do quicksortmeio
    int meio = (LI + LS) / 2;
    array aux, pivo;
    pivo = v[meio];
    int e = LI, d = LS;
    while (e < d) {
        while ((e < LS) && (v[e].chave >= pivo.chave)) {
            e++;
        }
        while ((d > LI)  && (v[d].chave <= pivo.chave)) {
            d--;
        }
        if (e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    if(e>meio){
        aux = v[meio];
        v[meio] = v[d];
        v[d]=aux;
        return d;
    }  else{
        aux = v[meio];
        v[meio] = v[e];
        v[e] = aux;
        return e;
    }
}
void quickSortPivoMeio(array *v, int LI, int LS) {
    if (LI < LS) {
        int p;
        p = particaoMeio(v, LI, LS);
        quickSortPivoMeio(v, LI, p - 1);
        quickSortPivoMeio(v, p + 1, LS);
    }
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
    // função que se utiluza saltos para fazer comparação entre os elementos do array
    int i,j,h; // inicio os parametros que iram auxiliar nos saltos
    array aux; // auxiliar que ira fazer a comparação entre os elementos
    
    for(h = 1; h < qnt; h = 3*h +1); // inicia o valor do salto 
    while (h>0) 
    {
       h = (h-1) /3;
       for (i = h; i < qnt; i++){ // realiza os saltos e recebe o valor deles no auxiliar 
        aux = a[i];
        j = i;
        
        while (a[j-h].chave < aux.chave){ //faz a comparação dos valores de acordo com o valor do salto definido no for anterior
            a[j] = a[j-h]; // se o valor que é usado para percorrer for maior ele vai alocar ele para a traz
            j -= h;
            if (j < h){
            break;
            }         
        }
        a[j] = aux;// quando o valor verificado for maior q o auxiliar ele realiza a troca pois ordena de forma decrescente 
        }
    }

}

void bubbleSort(array* a, int qnt){
    int flag = 1;

    array temp; //objeto temp que será necessário para a execução 

    for(int i = 0; i < qnt && flag == 1; i++){  //percorre a array 

        flag = 0;   //seta a flag como 0, ou seja, não houve nenhuma troca
        
        for(int j = 0; j < qnt-1; j++){ //percorra o item que está percorrido na array com o seu proxximo

            if(a[j].chave < a[j+1].chave){  //compara o item percorrido com o proximo da array

                temp = a[j];
                a[j] = a[j+1];  //se eles forem menores realizar a troca, senão percorrer a array continuamente
                a[j+1] = temp; 

                flag = 1;   //utilização de flag para otimizar a função -> não percorre a array desneecssáriamente
                //seta a flag como 1, ou seja, teve alguma troca, ou seja, a array ainda não está organizada
            }
        }

    }
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

    int n = 1000;                        //defina o tamanho da array
    unsigned int seed = 22001640;           //defina a seed dos numeros random 
    int tipo = 1;                           //defina o tipo da array

    srand(seed); 
    printf("\nA seed que voce esta executando e: %d\n", seed); //printa o valor da seed.

    array* umum = gerarArray(n,tipo);
    
    double tempo_exec = 0.0;
    clock_t begin = clock();

    //-================================== SELECIONE O SORT QUE QUISER ==================================-//


    //bubbleSort(umum,n);
    //shellSort(umum,n);
    //quickSortPivo0(umum,0,n-1);   
    //quickSortPivo0(umum,0,n-1);   
    quickSortPivoMeio(umum,0,n-1);

    clock_t end = clock();
    tempo_exec += (double)(end - begin)/CLOCKS_PER_SEC;

    printArray(umum,n);
    printf("\nTempo de execucao: %fs",tempo_exec);
    
    return 0;
}
