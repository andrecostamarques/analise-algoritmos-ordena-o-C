#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct dado{
    float info;
    int chave;  //criando a estrutura dado
} array;


// int particao(array* receb, int li, int ls){

//     array aux, pivo;
//     int xi, xs;
//     xi = li, xs = ls;
//     pivo = receb[xi]; //o pivo é o limite esquerdo
//     printf("\nXi = %d, xs = %d, pivo = %d\n",xi, xs, pivo.chave);

//     while(xi < xs) {
        
//         while((receb[xi].chave >= pivo.chave) && (xi<ls)){
//         printf("\nXi(%d) eh maior que %d entao:",receb[xi].chave,pivo.chave);
//         xi++;
//         printf("\nXi i++: xi = %d",xi);
//         printf(" --> xi agora aponta para %d",receb[xi].chave);}
//         while((receb[xs].chave < pivo.chave) && (xs>li)){
//         printf("\nXs(%d) eh menor que %d entao:",receb[xs].chave,pivo.chave);
//         xs--;
//         printf("\nXs--: xs = %d",xs);}
//         if(xi<xs){
            
//             printf("\n\nXi(%d) eh menor que o pivo(%d) e xs(%d) eh maior que o pivo(%d), entao eles foram trocados",receb[xi].chave, pivo.chave, receb[xs].chave,pivo.chave);
//            aux=receb[xi];
//            receb[xi]=receb[xs];
//            receb[xs]=aux; 
//            printf("\nFoi realizada a troca de xi e xs, trocaram os valores %d, %d, dos indices %d, %d\n", receb[xi].chave, receb[xs].chave, xs,xi);
//            printf("\nA array esta assim agora:");
//            printf("\nInfo / Chave");
//     for(int i = 0; i < 5; i++){
//     printf("\n%.f - %d", receb[i].info, receb[i].chave);
//     }
//     printf("\n\n");
//         }
//     }

//     aux = receb[li];    
//     receb[li]=receb[xs];
//     receb[xs]=aux;

//     printf("\nO novo pivo foi colocado em seu lugar");
//     printf("\nO novo pivo fica em %d(%d)",xs,receb[xs].chave);

//     printf("\nInfo / Chave");
//     for(int i = 0; i < 5; i++){
//     printf("\n%.f - %d", receb[i].info, receb[i].chave);
//     }
//     return xs;
// }

// void quickSort(array* receb, int li, int ls){

//     ls--;

// if(li<ls){

//     int p;
//     printf("\nA execucao do quick vai comecar agora!");
//     p = particao(receb,li,ls);
//     printf("\n -------------- Primeira particao feita ----------------\n");
//     quickSort(receb,li,p-1);
//     quickSort(receb,p+1,ls);
//     }

// }

int particaoPivoLS(array* a, int li, int ls){

    array aux, pivo;
    int xi, xs;
    xi = li, xs = ls;
    pivo = a[xs]; //o pivo é o limite direito

     while(xi < xs) {    //enquanto xi for menor que xs, isso é, enquanto eles não se superarem, o codigo ocorrerá
        
        while((a[xi].chave > pivo.chave) && (xi<ls)){
        //se chave de xi é maior ou igual o pivo, xi aponta para o proximo indice
        xi++;
        }
        while((a[xs].chave <= pivo.chave) && (xs>li)){
        //se a chave de xs é menor que o pivo, xs aponta para o indice anterior
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
    teste[0].info = 0;
    teste[1].info = 1;
    teste[2].info = 2;
    teste[3].info = 3;
    teste[4].info = 4;

    teste[0].chave = 7;
    teste[1].chave = 19;
    teste[2].chave = 1;
    teste[3].chave = 22;
    teste[4].chave = 13;

    array* testeptr = teste;



    //bubble sort que é mais fácil ----------------------------------------------------------------
    //oq é o bubble sort? ele faz diversas passagens pela array e checa os valores adjacentes, se for necessário 
    //ele troca os valores adjacentes, ele repete esse percurso tantas vezes que troca todos os valores adjacentes
    //e ordena a array inteira

    quickSortPivoLS(testeptr,0,4);

    printf("Info / Chave");
    for(int i = 0; i < 5; i++){
    printf("\n%.f - %d", teste[i].info, teste[i].chave);
    }

    return 0;
}