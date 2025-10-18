#include <stdio.h>
#include <stdlib.h>
#include "rc4_init.h"
#include "rc4_stream.h"
#include "rc4_encrypt.h"

int main() {
    int length_s;
    do {
        printf("Nhap do dai cua vector S: ");
        scanf("%d", &length_s);
    } while (length_s <= 0 || length_s >= 257);

    int S[length_s];
    init_S(S, length_s);

    printf("Nhap do dai cua khoa K: ");
    int length_k;
    scanf("%d", &length_k);
    int K[length_k];

    printf("Nhap gia tri cua K:\n");
    for (int i = 0; i < length_k; i++) scanf("%d", &K[i]);

    int T[length_s];
    init_T(T, length_s, K, length_k);

    key_scheduling(S, T, length_s);

    //printf("Nhap chieu dai chuoi Plaintext: ");
    int p_length;
    do{
        printf("Nhap chieu dai chuoi Plaintext: ");
        scanf("%d", &p_length);
    }while(p_length <= 0 || p_length >= length_s);
    //scanf("%d", &p_length);
    getchar();

    char Plain[p_length + 1];
    printf("Nhap Plaintext: ");
    for (int i = 0; i < p_length; i++) scanf("%c", &Plain[i]);
    Plain[p_length] = '\0';

    int key_stream[p_length];
    generate_key_stream(S, length_s, key_stream, p_length);

    char Cipher[p_length];
    printf("Ciphertext la: ");
    encrypt_text(Plain, Cipher, key_stream, p_length);

    return 0;
}
