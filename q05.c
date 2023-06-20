#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char **argv){
    if(argc != 2){
        printf("Formato: %s <num>\n",*argv);
        exit(1);
    }

    srand(time(NULL));

    int num = atoi(*(argv+1));

    float *v = calloc(num,sizeof(float));

    for(int i=0;i<num;i++){
        *(v+i) = ((float)(rand()%100))/100+1;
    }

    for(int i=0;i<num;i++){
        printf("%2.2f ",*(v+i));
    }
    printf("\n");

    float aux=0;
    for(int i=0;i<num;i++){
        aux+=*(v+i);
    }

    printf("A soma resulta em: %.2f.\n",aux);

    return 0;
}