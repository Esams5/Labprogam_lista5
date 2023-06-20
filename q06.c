#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void estat(int*,int,float*,int*,int*);

void burble(int *,int);

int main(int argc,char **argv){
    if(argc != 2){
        printf("Formato: %s <num>\n",*argv);
        exit(1);
    }

    srand(time(NULL));

    int num = atoi(*(argv+1));

    int *v = calloc(num,sizeof(int));

    for(int i=0;i<num;i++){
        *(v+i) = rand()%20+1;
    }

    for(int i=0;i<num;i++){
        printf("%2d ",*(v+i));
    }
    printf("\n");

    float media;
    int moda,mediana;

    burble(v,num);

    estat(v,num,&media,&moda,&mediana);

    printf("Média: %.2f\nModa: %d\nMediana: %d\n",media,moda,mediana);

    return 0;
}

void estat(int *x,int tam, float *media,int *moda,int *mediana){
    float aux=0;
    for(int i=0;i<tam;i++)aux+=((float)*(x+i))/tam;
    *media = aux;

    if(!(tam%2)){
        *mediana = *(x+(tam/2));
    }
    else{
        *mediana = *(x+((tam-1)/2)+1);
    }

    int ocor[tam];

    for(int i=0;i<tam;i++){
        ocor[i]=0;
        for(int j=0;j<tam;j++){
            if(*(x+i)==*(x+j))ocor[i]++;
        }
    }

    int maior=ocor[0];
    int k=0;
    for(int i=1;i<tam;i++){
        if(ocor[i]>maior){
            maior=ocor[i];
            k = i;
        }
    }

    *moda = *(x+k);
}

void burble(int *x,int tam){
    for(int i=0;i<tam-1;i++){
        for(int j=i+1;j<tam;j++){
            if(x[i]>x[j]){
                x[i]=x[i]^x[j];
                x[j]=x[i]^x[j];
                x[i]=x[i]^x[j];
            }
        }
    }
}