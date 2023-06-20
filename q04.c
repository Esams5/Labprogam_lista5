//incompleto
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define MX 10
#define SFT 0

void imprimirVetor(int *, int);
void gerarVetor(int *, int );
void *getMenMai(int *, int, int);

int main(int argc, char *argv[]){
    
    if (argc != 2){
        printf("\tUse %s <tamanhoVetor>\n\n",argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    int *p;

    p = (int*) malloc(n * sizeof(int));
    int x;

    if (!p){
        puts("Não existe memória disponível. Tente novamente.");
        exit(1);
    }

    srand(time(NULL));
    gerarVetor(p, n);
    imprimirVetor(p, n);

    getMenMai(p,n,x);

    printf("%u\n",x);
    

    free(p);

    return 0;

}

void imprimirVetor(int *q, int tamanho){

    for (int k=0; k<tamanho; k++){
        printf("[%p] %u\n",q+k,*(q+k));
    }

}

void gerarVetor(int *q, int tamanho){
    for(int k=0; k<tamanho; k++){
        *(q+k) = SFT + rand() % MX; 
    }
}

void *getMenMai(int *p, int tamanho, int norma){
    int *pMenor = p;
    int *pMaior = p;
    for (int k=1; k<tamanho; k++){
        if (*pMenor > *(p+k)){
            pMenor = p+k;
        }
    }

    for (int k=1; k<tamanho; k++){
        if (*pMaior < *(p+k)){
            pMaior = p+k;
        }
    }
   
   norma = (tamanho - *pMenor)/(*pMaior -  *pMenor);

    
    
}