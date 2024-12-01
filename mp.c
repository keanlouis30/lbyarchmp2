// Rosales, Kean Louis R.
// Albarracin, Clarissa
// This project was made in compliance to the partial requirements
// of the course LBYARCH under Sir Carlo Adriano
// Submitted this day of: 

#include<stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

extern void daxpy_sasm(int n, double* scalarValue, double* vectorX, double* vectorY, double* vectorZ);

void daxpy_C(int vectorLength, double scalarValue, double* arrX, double* arrY, double* arrZ){
	int k;
    for(k = 0; k < vectorLength; k++){
        arrZ[k] = (scalarValue * arrX[k]) + arrY[k];
    }
}

void init_vectors(int n, double* arrX, double* arrY) {
	int x;
	
	for (x = 0; x < n; x++) {
		arrX[x] = (double)rand() / RAND_MAX * 100.0;
		arrY[x] = (double)rand() / RAND_MAX * 100.0;
	}
}
 
int main(){
    int vectorLength;
    double scalarValue, *arrX, *arrY, *arrZ;

    vectorLength = pow(2,25);

    arrX = malloc(vectorLength * sizeof(double));
    arrY = malloc(vectorLength * sizeof(double));
    arrZ = malloc(vectorLength * sizeof(double));

	scalarValue = rand();

    init_vectors(vectorLength, arrX, arrY);
    
	clock_t start = clock();
	
	daxpy_C(vectorLength, scalarValue, arrX, arrY, arrZ);
	
	clock_t end = clock();
	double time_taken_c = ((double) (end - start) / CLOCKS_PER_SEC );
	printf("C kernel took %lf seconds to execute \n", time_taken_c);

	clock_t start1 = clock();
	
	daxpy_sasm(vectorLength, &scalarValue, arrX, arrY, arrZ);
	
	clock_t end1 = clock();
	double time_taken_asm = ((double) (end1 - start1) / CLOCKS_PER_SEC );
	printf("ASM kernel took %lf seconds to execute \n", time_taken_asm);
	
	printf("\n\n");
	
    printf("%s", "FIRST 5 C OUTPUTS\n");
	int l;
    for (l = 0; l < 5; l++){
        printf("%.2lf\n", arrZ[l]);
    }
	
	printf("%s", "FIRST 5 SASM OUTPUTS\n");
	int m;
    for (m = 0; m < 5; m++){
        printf("%.2lf\n", arrZ[m]);
    }
	
	free(arrX);
    free(arrY);
    free(arrZ);
	
	return 0;
}