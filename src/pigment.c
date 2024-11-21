#include "pigment.h"
#include <stdio.h>
#include <stdlib.h>

// Function to load pigment data
int loadPigmentData(char* filename, pigment_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;  // Return 1 if file can't be opened
    }

    int count = 0;

    // Skip header lines
    char line[200];
    while (fgets(line, sizeof(line), file) && line[0] == '#') {
        // Skip header lines (debug line removed)
    }

    // Read data lines
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        if (sscanf(line, "%49[^,],%49[^,],%d,%d,%d,%d,%d,%f,%f,%f",
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
        } else {
            
        }
    }

    fclose(file);

    *n = count;  // Set the total number of entries found
    return 0;
}



// Function to load paint data
int loadPaintData(char* filename, paint_t* pArray, int* x) {
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
        } else {
            printf("Skipping malformed line: %s", line);  // Optional: skip malformed lines
        }
    }

    fclose(file);

    *x = count;  
    printf("Total paints loaded: %d\n", count);  
    return 0;
}