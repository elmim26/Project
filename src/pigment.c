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
    char header[500];

    /* Skip header lines
    while (fgets(header, sizeof(header), file) && header[0] == '#') {
        printf("Skipping header: %s", header);  
    }
    */
    // Read data lines 
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line using sscanf, matching the expected format
        if (sscanf(line,"%49[^,],%99[^,],%49[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d/%d",
                   pArray[count].ciName,
                   pArray[count].marketingName,
                   pArray[count].manufacturer,
                   &pArray[count].code,
                   &pArray[count].transparency,
                   &pArray[count].staining,
                   &pArray[count].valueRange,
                   &pArray[count].granulating,
                   &pArray[count].blossom,
                   &pArray[count].diffusion,
                   &pArray[count].hueAngle,
                   &pArray[count].hueShift,
                   &pArray[count].lightfast1,
                   &pArray[count].lightfast2) == 14) { 
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


//QUESTION 3 MILESTONE 2

paint_t* getPaintRange(paint_t* pp, int npp, float rmin, float rmax, gRange_t getType, int* nspp) {
    if (pp == NULL || rmin < 0.0 || rmax > 1.0 || rmin > rmax) {
        *nspp = 0;
        return NULL;
    }
    //convert the range to fit the given getType val
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
    paint_t* subarr = (paint_t*)malloc(npp * sizeof(paint_t)); //make the subarr array with initialized size of paint_t
    if (subarr == NULL) {
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
            subarr[count] = pp[i];  //if condition true, subarr val at count = arr val at count
            count++;
        }
    }
    //return subarr as subarray
    subarr = (paint_t*)realloc(subarr, count * sizeof(paint_t));
    *nspp = count;
    return subarr;
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

//MILESTONE3 Q1

paint_t* getPaintHue(paint_t* pp, int* n, colour_t colour) {
    if (pp == NULL || n == NULL || *n <= 0) {
        return NULL; // Invalid input
    }

    // my own hue angle ranges for each colou
    int hue_min, hue_max;
    switch (colour) {
        case RED: hue_min = 350; hue_max = 360; break;
        case RED_ORANGE: hue_min = 20; hue_max = 30; break;
        case ORANGE: hue_min = 30; hue_max = 50; break;
        case YELLOW_ORANGE: hue_min = 50; hue_max = 60; break;
        case YELLOW: hue_min = 60; hue_max = 90; break;
        case YELLOW_GREEN: hue_min = 90; hue_max = 140; break;
        case GREEN: hue_min = 120; hue_max = 180; break;
        case BLUE_GREEN: hue_min = 180; hue_max = 220; break;
        case BLUE: hue_min = 210; hue_max = 250; break;
        case BLUE_VIOLET: hue_min = 260; hue_max = 300; break;
        case VIOLET: hue_min = 300; hue_max = 320; break;
        case RED_VIOLET: hue_min = 320; hue_max = 350; break;
        default: return NULL; // Invalid color
    }

    // Allocate memory for paints
    paint_t* pps = malloc(sizeof(paint_t) * (*n));
    if (pps == NULL) {
        return NULL; // Memory allocation failed
    }

    int count = 0;
    for (int i = 0; i < *n; i++) {
        if (pp[i].hueAngle >= hue_min && pp[i].hueAngle <= hue_max) {
            pps[count++] = pp[i];
        }
    }

    if (count == 0) {
        free(pps);
        return NULL; // No matching paints
    }

    // Update the size of the returned array
    *n = count;
    return pps;
}

//question 2 MS3
paint_t* getPalette(paint_t** pp, int* n, const char* type, const char* properties) {
    if (pp == NULL || n == NULL || *n <= 0) {
        return NULL;
    }

    paint_t* palette = malloc(12 * sizeof(paint_t)); 
    if (palette == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    paint_t* filteredPaints = *pp; 
    int filteredCount = *n;


        const char* colorNames[] = {
            "yellow", "yellow-orange", "orange", "red-orange", "red",
            "red-violet", "violet", "blue-violet", "blue", "blue-green",
            "green", "yellow-green"
        };
    

    paint_t paints[800];
    int paintCount = 800;
    if (loadPaintData("paints.dat", paints, &paintCount) != 0) {
        printf("Failed to load paint data.\n");
        return NULL;
    }


    if (properties) {
        float rmin = 0.0f, rmax = 1.0f;
        gRange_t rangeType;

        if (strcmp(properties, "granulating") == 0) { //uses getPaintRange to see if it is in the granulating section
            rangeType = GRANULATING;
            rmin = 0.2f;
        } else if (strcmp(properties, "non-granulating") == 0) {
            rangeType = GRANULATING;
            rmax = 0.1f;
        } else if (strcmp(properties, "transparent") == 0) {
            rangeType = TRANSPARENT;
            rmin = 1.0f;
            rmax = 1.0f;
        } else {
            printf("Unknown property: %s\n", properties);
            free(palette);
            return NULL;
        }

        filteredPaints = getPaintRange(*pp, *n, rmin, rmax, rangeType, &filteredCount); //depending on what property given, sets the min and max then finds the paints in 
        if (filteredPaints == NULL || filteredCount == 0) {                            //the given subset and sees if they meet the criteria
            printf("No paints match the property: %s\n", properties);
            free(palette);
            return NULL;
        }
    }

    //was originally adjusting for properties but would not work
    int baseColour = 0;  
    if (strncmp(type, "full", 4) == 0) {
        const char* baseColourName = type + 5;
        if (strlen(baseColourName) > 0) {
            for (int i = 0; i < 12; i++) {
                if (strcmp(colorNames[i], baseColourName) == 0) {
                    baseColour = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 12; i++) {
            printf("%s\n", colorNames[(baseColour + i) % 12]);
        }
    } else if (strncmp(type, "triad:", 6) == 0) {
        const char* baseColourName = type + 6;
        for (int i = 0; i < 12; i++) {
            if (strcmp(colorNames[i], baseColourName) == 0) {
                baseColour = i;
                break;
            }
        }
        for (int i = 0; i < 3; i++) {
            printf("%s\n", colorNames[(baseColour + (i * 4)) % 12]);
        }
    } else if (strncmp(type, "complimentary:", 14) == 0) {
        const char* baseColourName = type + 14;
        for (int i = 0; i < 12; i++) {
            if (strcmp(colorNames[i], baseColourName) == 0) {
                baseColour = i;
                break;
            }
        }
        int opposite = (baseColour + 6) % 12;
        printf("%s\n", colorNames[baseColour]);
        printf("%s\n", colorNames[opposite]);
    } else if (strncmp(type, "split-complimentary:", 20) == 0) {
        const char* baseColourName = type + 20;
        for (int i = 0; i < 12; i++) {
            if (strcmp(colorNames[i], baseColourName) == 0) {
                baseColour = i;
                break;
            }
        }
        int oppositeLeft = (baseColour + 5) % 12;
        int oppositeRight = (baseColour + 7) % 12;
        printf("%s\n", colorNames[baseColour]);
        printf("%s\n", colorNames[oppositeLeft]);
        printf("%s\n", colorNames[oppositeRight]);
    } else {
        printf("Unknown palette type: %s\n", type);
    }
    return 0;
}