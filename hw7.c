#include <stdio.h>
#include <stdlib.h>
#define ROWS 200 
#define COLS 198 

int main() {
    FILE* in;
    FILE* out;
    in = fopen("data.txt", "r");
    out = fopen("output.txt", "w");
    float A[ROWS][COLS];
    float B[ROWS][COLS];
    float C[ROWS];
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
    for (int i = 0; i < ROWS; i++) {
        C[i] = 0;
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++)
                C[i] += A[i][k] * B[j][k];
        }
    }
    for (int i = 0; i < ROWS; i++) {
        fprintf(out, "%f\n", C[i]);
    }
    fclose(in);
    fclose(out);
    return 0;
}