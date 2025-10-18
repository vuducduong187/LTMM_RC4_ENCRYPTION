#include "rc4_init.h"
#include "rc4_stream.h"
#include<stdio.h>

void generate_key_stream(int S[], int length_s, int key_stream[], int p_length) {
    int idx_key_stream = 0;
    int m = 0, n = 0;
    while(m < p_length){
        m = (m + 1) % length_s;
        n = (n + S[m]) % length_s;
        int tmp3 = S[m];
        S[m] = S[n];
        S[n] = tmp3; 
        int t = (S[n] + S[m]) % length_s;
        int k = S[t];
        key_stream[idx_key_stream++] = k;
    }
    printf("Dong khoa la: ");
    for(int i = 0; i < idx_key_stream; i++){
        printf("%d ", key_stream[i]);
    }
    printf("\n");
}
