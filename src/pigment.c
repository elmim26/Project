#include "pigment.h"
#include <stdio.h>
#include <stdlib.h>

int loadPigmentData(char* filename, pigment_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; //return 1 if file cant be opened
    }

int count = 0;

char header[200];
    while (fgets(header, sizeof(header), file) && header[0] == '#') {
        // Skipping header line
    }

 while (fscanf(file, "%s,%s,%d,%d,%d,%d,%d,%f,%f,%f",    //NEED TO FIX THE READING ON THE FILE
                  pArray[count].ciName,
                  pArray[count].pigmentName,
                  &pArray[count].value,
                  &pArray[count].chroma,
                  &pArray[count].abValue[0],
                  &pArray[count].abValue[1],
                  &pArray[count].hueAngle,
                  &pArray[count].huePurity,
                  &pArray[count].abHp[0],
                  &pArray[count].abHp[1]) == 10) {
        printf("Read pigment %d: CI Name: %s, Pigment Name: %s\n", count + 1, pArray[count].ciName, pArray[count].pigmentName); 
        count++;
    }

 fclose(file);

    *n = count;  // Set the number of entries found
    return 0; 
}

