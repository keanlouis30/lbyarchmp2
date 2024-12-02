void daxpy_C(int vectorLength, double scalarValue, double* arrX, double* arrY, double* arrZ) {
    int k;
    for (k = 0; k < vectorLength; k++) {
        arrZ[k] = (scalarValue * arrX[k]) + arrY[k];
    }
}
