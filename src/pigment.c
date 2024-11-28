#include "pigment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to load pigment data
int loadPigmentData(char* filename, pigment_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; // File could not be opened
    }

    int count = 0;
    char header[200];

    // Skip header lines
    while (fgets(header, sizeof(header), file) && header[0] == '#');

    // Read data from the file
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
    *n = count; // Set number of pigments loaded
    return 0;
}




// function to load paint data
int loadPaintData(char* filename, paint_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;  // Return 1 if file can't be opened
    }

    int count = 0;

    // Skip header lines
    char header[200];
    while (fgets(header, sizeof(header), file) && header[0] == '#') {
        printf("Skipping header: %s", header);  
    }

    // Read data lines 
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line using sscanf, matching the expected format
        if (sscanf(line, "%49[^,],%99[^,],%49[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d/%d",
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
                   &pArray[count].lightfast1,
                   &pArray[count].lightfast2) == 12) {
            printf("Successfully read paint %d\n", count + 1);  
            count++;
        }
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


//QUESTION 2 FUNCTION
int printPaint(paint_t* pp, int i, int n){
    if (pp == NULL || n <= 0) {
        return 1; 
    }

    if (i == -1) { // if index is -1, print the whole array
        for (int index = 0; index < n; index++) {
            printf("--------------\n");
            printf("ciName: %s\n", pp[index].ciName);
            printf("Marketing Name: %s\n", pp[index].marketingName);
            printf("Manufacturer: %s\n", pp[index].manufacturer);
            printf("Transparency: %d\n", pp[index].transparency);
            printf("Staining: %d\n", pp[index].staining);
            printf("Value Range: %d\n", pp[index].valueRange);
            printf("Granulating: %d\n", pp[index].granulating);
            printf("Blossom: %d\n", pp[index].blossom);
            printf("Diffusion: %d\n", pp[index].diffusion);
            printf("Hue Angle [degrees]: %d\n", pp[index].hueAngle);
            printf("Hue Shift: %d\n", pp[index].hueShift);
            printf("Lightfastness: %d/%d\n", pp[index].lightfast1, pp[index].lightfast2);
        }
    }
    
    else if (i >= 0 && i < n) { // a certain paint
        printf("--------------\n");
        printf("ciName: %s\n", pp[i].ciName);
        printf("Marketing Name: %s\n", pp[i].marketingName);
        printf("Manufacturer: %s\n", pp[i].manufacturer);
        printf("Transparency: %d\n", pp[i].transparency);
        printf("Staining: %d\n", pp[i].staining);
        printf("Value Range: %d\n", pp[i].valueRange);
        printf("Granulating: %d\n", pp[i].granulating);
        printf("Blossom: %d\n", pp[i].blossom);
        printf("Diffusion: %d\n", pp[i].diffusion);
        printf("Hue Angle [degrees]: %d\n", pp[i].hueAngle);
        printf("Hue Shift: %d\n", pp[i].hueShift);
        printf("Lightfastness: %d/%d\n", pp[i].lightfast1, pp[i].lightfast2);
    } 
    else {
        return 1;
    }
    return 0;

}
//END OF QUESTION 2 FUNCTION


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
                match = (strcasecmp(pp[i].ciName, name) == 0);
                break;
            case marketingName:
                match = (strcasecmp(pp[i].marketingName, name) == 0);
                break;
            case manufacturer:
                match = (strcasecmp(pp[i].manufacturer, name) == 0);
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

        








