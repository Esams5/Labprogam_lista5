#include <stdio.h>
#include <stdlib.h>

void somar(int *, int *, int *);
void mult(int *, int *, int *);


int main(int argc, char *argv[]){
    int num1, num2, op, res;
    if (argc != 4){
        printf("Formato: %s <num1> <num2> <operação>\n",*argv);
        exit(1);
    }
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    op = atoi(argv[3]);

    switch (op){
        case 1:
            somar(&num1,&num2,&res);
        break;
        case 2:
            mult(&num1,&num2,&res);
        break;
    }
    printf("O valor da operação é %d\n",res);

    return 0;
}

void somar(int *x1, int *x2, int *r){
    *r = *x1 + *x2;
}

void mult(int *x1, int *x2, int *r){
    *r = *x1 * *x2;
}
