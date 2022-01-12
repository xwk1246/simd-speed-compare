#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* in;
    FILE* out;
    in = fopen("data.txt", "r");
    out = fopen("output.txt", "w");
    float A[200][198];
    float B[200][198];
    float C[200];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 198; j++) {
            fscanf(in, "%f", &A[i][j]);
        }
    }
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 198; j++) {
            fscanf(in, "%f", &B[i][j]);
        }

    }
    for (int i = 0; i < 200; i++) {
        C[i] = 0;
        for (int j = 0; j < 198; j++) {
            C[i] += A[i][j] * B[i][j];
        }
    }
    for (int i = 0; i < 200; i++) {
        fprintf(out, "%f\n", C[i]);
    }
    fclose(in);
    fclose(out);
    return 0;
}