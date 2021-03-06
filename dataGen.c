#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float fRand(int min, int max) {
    float f = (float)rand() / RAND_MAX;
    return min + f * (max - min);
}

int main() {
    FILE* fp;
    int rows, cols;
    float x;
    scanf("%d%d", &rows, &cols);
    srand(time(NULL));
    fp = fopen("data.txt", "w");
    for (int i = 0; i < rows * 2; i++) {
        x = fRand(0, 100);
        fprintf(fp, "%f", x);
        for (int j = 0; j < cols - 1; j++) {
            x = fRand(0, 100);
            fprintf(fp, " %f", x);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}