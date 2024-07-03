#include <stdlib.h>
#include <stdio.h>
#include "main.h"



void quicksort(double array[], int low, int high) {
    if(high > low) {
        double pi = partition(array, low, high);
        // recursion call
        quicksort(array, low, pi-1);
        quicksort(array, pi+1, high);
    }

}

int partition(double array[], int low, int high) {

    // choose a pivot
    double pivot = array[high];
    
    //index the smaller element and indicate 
    // the right position of the pivot found so far
    int i = (low - 1);
    for(int j = low; j < high; j++) {
        // if current element is lower than pivot
        if(array[j] < pivot) {
            // increment index of smaller element
            i++;
            swap(&array[i], &array[j]);

        }
    }
    swap(&array[i+1], &array[high]);
    return (i + 1);

}

void swap(double* a, double* b) {
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printDouble(double array[], int length) {

    for(int i = 0; i < length; i++) {
        printf( "%lf ", array[i]);
    }
    printf("\n");
}


int main(void) {
    static double array1[10] = {-1.2, 2,9, 200,-5, 3.4, 2000, 10, 19, -80};
    printDouble(array1, 10);
    quicksort(array1, 0, 9);
    printDouble(array1, 10);
    


    return EXIT_SUCCESS;
}

