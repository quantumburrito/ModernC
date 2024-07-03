#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "derivative.h"


// Derivative of F
double f(double x) {
    double h = 1e-8;
    double numerator = F(x + h) - F(x);
    double denominator = h;

    return numerator / denominator;
}

// Function will be sin(x) for now
double F(double x) {

    return sin(x);
}


int main(void) {
    int low = 0;
    int high = 10;
    double resolution = 0.01;
    int arrayLength = (int)((high-low)/resolution);
    
    double x[arrayLength];

    double Fx[arrayLength];
    double fx[arrayLength];

    // fill x array
    for(int i = 0; i < arrayLength; i ++) {
        x[i] = low + (i * resolution);
    }

    for(int i = 0; i < arrayLength; i++) {
        Fx[i] = F(low + (i * resolution));
        fx[i] = f(low + (i * resolution));
    }


    // Write Data to file
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return EXIT_FAILURE;
    }

    fprintf(file, "x,F(x),f(x)\n");
    for (int i = 0; i < arrayLength; i++) {
        fprintf(file, "%lf,%lf,%lf\n", x[i], Fx[i], fx[i]);
    }

    fclose(file);


    return EXIT_SUCCESS;
}
