#include <pigment.h>
#include <stdio.h>
#include <stdlib.h>

int loadPigmentData(char* filename, pigment_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; //return 1 if file cant be opened
    }
int count = 0;

