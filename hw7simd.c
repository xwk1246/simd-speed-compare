#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#define ROWS 200 
#define COLS 198

int main() {
    FILE* in;
    FILE* out;
    in = fopen("data.txt", "r");
    out = fopen("simdOutput.txt", "w");
    float A[ROWS][COLS] __attribute__((aligned(32)));
    float B[ROWS][COLS] __attribute__((aligned(32)));
    float C[ROWS] __attribute__((aligned(32)));

    __m256* pA256;
    __m256* pB256;
    __m256* pC256;


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(in, "%f", &A[i][j]);
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(in, "%f", &B[i][j]);
        }

    }
    __m256 tmp256;

    for (int i = 0; i < ROWS; i++) {
        pA256 = (__m256*)(A[i]);
        for (int j = 0; j < ROWS; j++) {
            pB256 = (__m256*)(B[j]);
            tmp256 = _mm256_set1_ps(0.0);
            for (int k = 0; k < COLS / 8; k++) {
                _mm256_mul_ps(pA256[k], pB256[k]);
                // _mm256_add_ps(tmp256, _mm256_mul_ps(pA256[k], pB256[k]));
                tmp256 = _mm256_add_ps(tmp256, _mm256_mul_ps(pA256[k], pB256[k]));
            }
            for (int k = 0; k < 8; k++) {
                C[i] += ((float*)&tmp256)[k];
            }
            for (int k = 0; k < COLS % 8; k++) {
                C[i] += A[i][COLS / 8 * 8 + k] * B[j][COLS / 8 * 8 + k];
            }

        }
    }
    for (int i = 0; i < ROWS; i++) {
        fprintf(out, "%f\n", C[i]);
    }
    fclose(in);
    fclose(out);
    return 0;
}