#include "pigment.h"  
#include <stdio.h>    
#include <stdlib.h>   

int main() { //first two pigments from data sheet
    
    pigment_t pigments[2] = {
        {"NA", "sodalite", 15, 3, {-3, 0}, 182, 0.04, {-0.04, 0.00}},
        {"PBr6", "iron oxide black", 17, 7, {5, 4}, 38, 0.07, {0.05, 0.04}}
    };

    int n = 2; // Number of pigments in array

    //printing first pigment 
    printf("Printing first pigment :\n");
    printPigment(pigments, 0, n);

    printf("\n");

    //print all pigments in the array
    printf("Printing all pigments:\n");
    printPigment(pigments, -1, n);

    return EXIT_SUCCESS;
}
