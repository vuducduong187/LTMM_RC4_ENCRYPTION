#include <stdio.h>
#include "rc4_init.h"

void init_S(int S[], int length_s) {
    for (int i = 0; i < length_s; i++) {
        S[i] = i;
    }
    printf("Khoi tao gia tri ban dau cua S !\n");
    for(int i = 0; i < length_s; i++){
        printf("%d ", S[i]);
    }
    printf("\n");
}

void init_T(int T[], int length_s, int K[], int length_k) {
    int tmp = 0;
    int length_t = 0;
    while(length_t < length_s){
        T[length_t++] = K[tmp++];
        if(tmp == length_k){
            tmp = 0;
        }
    }
    printf("Vector khoi tao T !\n");
    for(int i = 0; i < length_t; i++){
        printf("%d ", T[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void key_scheduling(int S[], int T[], int length_s) {
    printf("Vector hoan vi S !\n");
    int j = 0;
    for (int i = 0; i < length_s; i++) {
        j = (j + S[i] + T[i]) % length_s;
        swap(&S[i], &S[j]);
    }
    for(int i = 0; i < length_s; i++){
        printf("%d ", S[i]);
    }
    printf("\n");
}
