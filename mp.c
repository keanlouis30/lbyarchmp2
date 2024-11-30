// Rosales, Kean Louis R.
// Albarracin, Clarissa
// This project was made in compliance to the partial requirements
// of the course LBYARCH under Sir Carlo Adriano
// Submitted this day of: 

#include<stdio.h>
#include <stdlib.h> 

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

    arrX = malloc(vectorLength * sizeof(int));
    arrY = malloc(vectorLength * sizeof(int));
    arrZ = malloc(vectorLength * sizeof(int));

    printf("%s", "Input the scalar value (A):\n");
    scanf("%lf", &scalarValue);

    printf("Input the values of vector X:\n");
    for (int i = 0; i < vectorLength; i++) {
        printf("X[%d]: ", i);
        scanf("%lf", &arrX[i]);
    }

    printf("Input the values of vector Y:\n");
    for (int i = 0; i < vectorLength; i++) {
        printf("Y[%d]: ", i);
        scanf("%lf", &arrY[i]);
    }
    
    for(int i = 0; i < vectorLength; i++){
        arrZ[i] = daxpy(scalarValue, arrX[i], arrY[i]);
    }

    printf("%s", "The output is:\n");
    for (int i = 0; i < vectorLength; i++){
        printf("%.2lf\n", arrZ[i]);
    }
}