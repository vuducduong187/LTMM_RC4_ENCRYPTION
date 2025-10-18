#ifndef RC4_INIT_H
#define RC4_INIT_H

void init_S(int S[], int length_s);
void init_T(int T[], int length_s, int K[], int length_k);
void swap(int *a, int *b);
void key_scheduling(int S[], int T[], int length_s);

#endif