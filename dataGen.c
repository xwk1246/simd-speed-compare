#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double fRand(double min, double max) {
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

int main() {
    FILE* fp;
    fp = fopen("data.txt", "w");
    int rows, cols;
    double x;
    scanf("%d%d", &rows, &cols);
    srand(time(NULL));
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