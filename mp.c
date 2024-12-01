// Rosales, Kean Louis R.
// Albarracin, Clarissa
// This project was made in compliance to the partial requirements
// of the course LBYARCH under Sir Carlo Adriano
// Submitted this day of: 

#include<stdio.h>
#include <stdlib.h> 

extern void daxpy_sasm(int n, double* scalarValue, double* vectorX, double* vectorY, double* vectorZ);

double daxpy(double scalarValue, double arrXIndex, double arrYIndex){
    double daxpyValue;
    daxpyValue = (scalarValue * arrXIndex) + arrYIndex;
    return daxpyValue;
}
 
int main(){
    int vectorLength;
    double scalarValue, *arrX, *arrY, *arrZ;

    printf("%s", "Input the vector length:\n");
    scanf("%d", &vectorLength);

    arrX = malloc(vectorLength * sizeof(double));
    arrY = malloc(vectorLength * sizeof(double));
    arrZ = malloc(vectorLength * sizeof(double));

    printf("%s", "Input the scalar value (A):\n");
    scanf("%lf", &scalarValue);

    printf("Input the values of vector X:\n");
	int i;
    for (i = 0; i < vectorLength; i++) {
        printf("X[%d]: ", i);
        scanf("%lf", &arrX[i]);
    }

	int j;
    printf("Input the values of vector Y:\n");
    for (j = 0; j < vectorLength; j++) {
        printf("Y[%d]: ", j);
        scanf("%lf", &arrY[j]);
    }
    
	int k;
    for(k = 0; k < vectorLength; k++){
        arrZ[k] = daxpy(scalarValue, arrX[k], arrY[k]);
    }

    printf("%s", "C OUTPUT The output is:\n");
	int l;
    for (l = 0; l < vectorLength; l++){
        printf("%.2lf\n", arrZ[l]);
    }
	
	printf("This is about to execute sasm code...\n");
	int n;
    for (n = 0; n < vectorLength; n++){
        arrZ[n] = 0;
    }
	
	daxpy_sasm(vectorLength, &scalarValue, arrX, arrY, arrZ);
	
	printf("%s", "SASM OUTPUT The output is:\n");
	int m;
    for (m = 0; m < vectorLength; m++){
        printf("arrZ %d %.2lf\n", m, arrZ[m]);
    }
	
	free(arrX);
    free(arrY);
    free(arrZ);
	
	return 0;
}