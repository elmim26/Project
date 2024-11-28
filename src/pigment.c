#include "pigment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to load pigment data
int loadPigmentData(char* filename, pigment_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; // File could not be opened
    }

    int count = 0;
    char header[200];

    // Skip header lines
    while (fgets(header, sizeof(header), file) && header[0] == '#');

    // Read data from file
    while (fscanf(file, "%[^,],%[^,],%d,%d,%d,%d,%d,%f,%f,%f",
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
        count++;
    }

    fclose(file);
    *n = count; //number of pigments 
    return 0;
}




// function to load paint data
int loadPaintData(char* filename, paint_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; // File could not be opened
    }

    int count = 0;
    char header[500];

    // Skip header lines
    while (fgets(header, sizeof(header), file) && header[0] == '#');

    // Read data from the file
    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d",
                  pArray[count].ciName,
                  pArray[count].marketingName,
                  pArray[count].manufacturer,
                  &pArray[count].transparency,
                  &pArray[count].staining,
                  &pArray[count].valueRange,
                  &pArray[count].granulating,
                  &pArray[count].blossom,
                  &pArray[count].diffusion,
                  &pArray[count].hueAngle,
                  &pArray[count].hueShift,
                  &pArray[count].lightfast) == 12) {
        count++;
    }

    fclose(file);
    *n = count; // Set number of paints loaded
    return 0;
}



//QUESTION1 OF MILESTONE2
int printPigment(pigment_t* pp, int i, int n){
    if (pp == NULL || n <= 0) {
        return 1; 
    }

    if (i == -1) { // if index is -1, print whole array
        for (int index = 0; index < n; index++) {
            printf("--------------\n");
            printf("ciName: %s\n", pp[index].ciName);
            printf("pigmentName: %s\n", pp[index].pigmentName);
            printf("value: %d\n", pp[index].value);
            printf("chroma: %d\n", pp[index].chroma);
            printf("(a,b): (%d,%d)\n", pp[index].abValue[0], pp[index].abValue[1]);
            printf("hue [degrees]: %d\n", pp[index].hueAngle);
            printf("huePurity: %.2f\n", pp[index].huePurity);
            printf("(ahp, bhp): (%.2f, %.2f)\n", pp[index].abHp[0], pp[index].abHp[1]);
        }
    } 
    else if (i >= 0 && i < n) { //a certain pgiment
        printf("--------------\n");
        printf("ciName: %s\n", pp[i].ciName);
        printf("pigmentName: %s\n", pp[i].pigmentName);
        printf("value: %d\n", pp[i].value);
        printf("chroma: %d\n", pp[i].chroma);
        printf("(a,b): (%d,%d)\n", pp[i].abValue[0], pp[i].abValue[1]);
        printf("hue [degrees]: %d\n", pp[i].hueAngle);
        printf("huePurity: %.2f\n", pp[i].huePurity);
        printf("(ahp, bhp): (%.2f, %.2f)\n", pp[i].abHp[0], pp[i].abHp[1]);
    } 
    else {
        return 1;
    }
    return 0;
}


//QUESTION4 FUNCTION:
paint_t* getPaintValue(paint_t* pp, int npp, char* name, gValue_t getType, int* nspp) {
    int count = 0;
    paint_t* subset = malloc(npp * sizeof(paint_t));
    if (!subset) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < npp; i++) {
        int match = 0;
        switch (getType) {
            case ciName:
                match = (strcmp(pp[i].ciName, name) == 0);
                break;
            case marketingName:
                match = (strcmp(pp[i].marketingName, name) == 0);
                break;
            case manufacturer:
                match = (strcmp(pp[i].manufacturer, name) == 0);
                break;
        }

        if (match) {
            subset[count++] = pp[i];
        }
    }

    *nspp = count; // Update the number of matching paints

    if (count == 0) {
        free(subset); // No matches found
        return NULL;
    }

    return subset; // Return the filtered subset
}

        








