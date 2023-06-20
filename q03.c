#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 100
#define SFT 0

void imprimirVetor(unsigned int *, int);
void gerarVetor(unsigned *, int );
void *getMenMai(unsigned *, int);

int main(int argc, char *argv[]){
    
    if (argc != 2){
        printf("\tUse %s <tamanhoVetor>\n\n",argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    unsigned int *p;

    p = (unsigned int*) malloc(n * sizeof(unsigned int));

    if (!p){
        puts("Não existe memória disponível. Tente novamente.");
        exit(1);
    }

    srand(time(NULL));
    gerarVetor(p, n);
    imprimirVetor(p, n);

    getMenMai(p,n);
    

    free(p);

    return 0;

}

void imprimirVetor(unsigned int *q, int tamanho){

    for (int k=0; k<tamanho; k++){
        printf("[%p] %u\n",q+k,*(q+k));
    }

}

void gerarVetor(unsigned *q, int tamanho){
    for(int k=0; k<tamanho; k++){
        *(q+k) = SFT + rand() % MX; 
    }
}

void *getMenMai(unsigned *p, int tamanho){
    unsigned *pMenor = p;
    unsigned *pMaior = p;
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
    printf("Endereço do menor elemento do vetor gerado é: %p\n",pMenor);
    printf("Endereço do maior elemento do vetor gerado é: %p\n",pMaior);
    
    
}