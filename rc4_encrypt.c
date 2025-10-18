#include <stdio.h>
#include "rc4_encrypt.h"

void encrypt_text(char Plain[], char Cipher[], int key_stream[], int p_length) {
    for(int i = 0; i < p_length; i++){
       //int tmp = (int)(key_stream[i] + (int)'0') ^ (int)Plain[i];
       int tmp = key_stream[i] ^ (int)Plain[i];
       printf("%c ", (char)tmp);
    }
    printf("\n");
}
