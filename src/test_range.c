#include "pigment.h"  
#include <stdio.h>    
#include <stdlib.h>

int main(){
    //building the array from the .dat to have all paints
    paint_t paints[800]; 
    int x = 800; 
    int res = loadPaintData("paints.dat", paints, &x);
    if (res != 0) {
        printf("Failed to load paint data.\n");
        return EXIT_FAILURE;
    }

    //declare vars for paintRange
    float rmin = 0.5f;
    float rmax = 1.0f;
    gRange_t rangeType = GRANULATING;
    int nspp = 0;

    //using the getPaintRange to get the grandulation
    paint_t* test1 = getPaintRange(paints, x, rmin, rmax, rangeType, &nspp);
    if (test1 == NULL || nspp == 0) {
        printf("No paints found\n");
        return EXIT_SUCCESS;
    }
    printf("paints found: %d \n", nspp);

    // Print the filtered paints using the printPaint funct
    if (printPaint(test1, -1, nspp) != 0) {
        printf("Failed to print paints.\n");
        free(test1);
        return EXIT_FAILURE;
    }

    free(test1);
    return EXIT_SUCCESS;
}