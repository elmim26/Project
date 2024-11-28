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
        printf("Error: Could not open file %s\n", filename);
        return 1;  // Return 1 if file can't be opened
    }

    int count = 0;

    // Skip header lines
    char line[500];
    while (fgets(line, sizeof(line), file) && line[0] == '#') {
        // Skip header
    }

    // Read data lines
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%49[^,],%99[^,],%49[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d",
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
            printf("Successfully read paint %d: CI Name: %s, Hue Angle: %d\n", 
                   count + 1, pArray[count].ciName, pArray[count].hueAngle);
            count++;
        } else {
            printf("Warning: Failed to parse line: %s", line);



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


//QUESTION 3 MILESTONE 2

paint_t* getPaintRange(paint_t* pp, int npp, float rmin, float rmax, gRange_t getType, int* nspp) {
    // Check if pp is NULL or invalid range
    if (pp == NULL || rmin < 0.0 || rmax > 1.0 || rmin > rmax) {
        *nspp = 0;
        return NULL;
    }

    float minRange, maxRange;
    switch (getType) {
        case HUE:
            minRange = rmin * 359.0f;  //0 to 359
            maxRange = rmax * 359.0f;
            break;
        case VALUE:
            minRange = rmin * 100.0f;  //0 to 100
            maxRange = rmax * 100.0f;
            break;
        case GRANULATING:
            minRange = rmin * 4.0f;    //0 to 4
            maxRange = rmax * 4.0f;
            break;
        case TRANSPARENT:
            minRange = rmin * 4.0f; //0 to 4
            maxRange = rmax * 4.0f;
            break;
        case STAINING:
            minRange = rmin * 4.0f; //0 to 4
            maxRange = rmax * 4.0f;
            break;
        case BLOOM:
            minRange = rmin * 4.0f;  //0 to 4
            maxRange = rmax * 4.0f;
            break;
        case LIGHTFAST:
            minRange = rmin * 10.0f;  //0 to 10
            maxRange = rmax * 10.0f;
            break;
        default:
            *nspp = 0;
            return NULL;  // Invalid
    }
    paint_t* result = (paint_t*)malloc(npp * sizeof(paint_t));
    if (result == NULL) {
        *nspp = 0;
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < npp; i++) {
        float propertyValue = 0.0f;

        switch (getType) {
            case HUE:
                propertyValue = pp[i].hueAngle;
                break;
            case VALUE:
                propertyValue = pp[i].valueRange;
                break;
            case GRANULATING:
                propertyValue = pp[i].granulating;
                break;
            case TRANSPARENT:
                propertyValue = pp[i].transparency;
                break;
            case STAINING:
                propertyValue = pp[i].staining;
                break;
            case BLOOM:
                propertyValue = pp[i].blossom;
                break;
            case LIGHTFAST:
                propertyValue = (pp[i].lightfast1 + pp[i].lightfast2)/2;
                break;
        }

        // range check & incramwntation
        if (propertyValue >= minRange && propertyValue <= maxRange) {
            result[count] = pp[i];  
            count++;
        }
    }
    result = (paint_t*)realloc(result, count * sizeof(paint_t));
    *nspp = count;
    return result;
}


//question1 for milestone3
// Helper function to check if hue angle falls within the range of a specific colour
int isHueInRange(int hue, colour_t colour) {
    switch (colour) {
        case RED:
            return (hue >= 0 && hue < 30) || (hue >= 330 && hue <= 360);
        case RED_ORANGE:
            return (hue >= 30 && hue < 45);
        case ORANGE:
            return (hue >= 45 && hue < 60);
        case YELLOW_ORANGE:
            return (hue >= 60 && hue < 75);
        case YELLOW:
            return (hue >= 75 && hue < 90);
        case YELLOW_GREEN:
            return (hue >= 90 && hue < 120);
        case GREEN:
            return (hue >= 120 && hue < 150);
        case BLUE_GREEN:
            return (hue >= 150 && hue < 180);
        case BLUE:
            return (hue >= 180 && hue < 210);
        case BLUE_VIOLET:
            return (hue >= 210 && hue < 240);
        case VIOLET:
            return (hue >= 240 && hue < 270);
        case RED_VIOLET:
            return (hue >= 270 && hue < 330);
        default:
            return 0; // Invalid colour
    }
}

// Function to retrieve paints based on hue
paint_t* getPaintHue(paint_t* pp, int* n, colour_t colour) {
    if (!pp || !n || *n <= 0) {
        printf("Error: Invalid input data.\n");
        return NULL; 
    }
    
    int count = 0; // Matching paint count
    paint_t* subset = malloc(*n * sizeof(paint_t)); 

    if (subset == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL; 
    }

    // Iterate through paints to find matches
    for (int i = 0; i < *n; i++) {
        if (isHueInRange(pp[i].hueAngle, colour)) {
            printf("Match found: %s with Hue Angle: %d for color GREEN\n", 
                   pp[i].marketingName, pp[i].hueAngle);
            subset[count++] = pp[i]; // Add matching paint to subset
        }
    }

    if (count == 0) {
        //printf("No paints found for the specified color.\n");
        free(subset); // Free memory if no matches found
        *n = 0;
        return NULL;
    }

    *n = count; // Update size of the subset
    return subset; 
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
        








