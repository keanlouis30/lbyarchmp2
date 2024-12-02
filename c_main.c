// Rosales, Kean Louis R.
// Albarracin, Clarissa
// This project was made in compliance to the partial requirements
// of the course LBYARCH under Sir Carlo Adriano
// Submitted this day of: 
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include "daxpy_c.h"
#include <string.h>

extern void daxpy_sasm(int n, double* scalarValue, double* vectorX, double* vectorY, double* vectorZ);

void init_vectors(int n, double* arrX, double* arrY) {
    int x;
    
    for (x = 0; x < n; x++) {
        arrX[x] = (double)rand() / RAND_MAX * 100.0;
        arrY[x] = (double)rand() / RAND_MAX * 100.0;
    }
}

void write_md(double time_taken_c, double time_taken_asm, int powerOfTwo) {
    const char *filename = "readMe.md";
    int execution_count = 1;  

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            if (strncmp(line, "Execution #", 11) == 0) {
                int count;
                if (sscanf(line, "Execution # %d", &count) == 1) {
                    execution_count = count + 1;  
                }
            }
        }
        fclose(file);
    }

    if (execution_count > 30) {
        execution_count = 1;
    }

    file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "Execution # %d\n", execution_count);
    fprintf(file, "Vector Length: 2, %d\n", powerOfTwo);
    fprintf(file, "C file execution time: %.6f\n", time_taken_c);
    fprintf(file, "ASM file execution time: %.6f\n\n", time_taken_asm);

    printf("Content added successfully to %s.\n", filename);

    fclose(file);
}


int main() {
    int vectorLength;
    double scalarValue, *arrX, *arrY, *arrZ;
    int powerOfTwo = 28;
    vectorLength = pow(2, powerOfTwo);
    arrX = malloc(vectorLength * sizeof(double));
    arrY = malloc(vectorLength * sizeof(double));
    arrZ = malloc(vectorLength * sizeof(double));
    srand(time(NULL));
    scalarValue = rand();
    init_vectors(vectorLength, arrX, arrY);
    
    clock_t start = clock();
    
    daxpy_C(vectorLength, scalarValue, arrX, arrY, arrZ);
    
    clock_t end = clock();
    double time_taken_c = ((double) (end - start) / CLOCKS_PER_SEC);
    printf("C kernel took %lf seconds to execute \n", time_taken_c);
    
    clock_t start1 = clock();
    
    daxpy_sasm(vectorLength, &scalarValue, arrX, arrY, arrZ);
    
    clock_t end1 = clock();
    double time_taken_asm = ((double) (end1 - start1) / CLOCKS_PER_SEC);
    printf("ASM kernel took %lf seconds to execute \n", time_taken_asm);
    
    printf("\n\n");
    
    printf("%s", "FIRST 5 C OUTPUTS\n");
    int l;
    for (l = 0; l < 5; l++) {
        printf("%.2lf\n", arrZ[l]);
    }
    
    printf("%s", "FIRST 5 SASM OUTPUTS\n");
    int m;
    for (m = 0; m < 5; m++) {
        printf("%.2lf\n", arrZ[m]);
    }
    
    free(arrX);
    free(arrY);
    free(arrZ);
    
    write_md(time_taken_c, time_taken_asm, powerOfTwo);
    return 0;
}