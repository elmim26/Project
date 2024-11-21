#include "pigment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to load pigment data
int loadPigmentData(char* filename, pigment_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;  
    }

    int count = 0;

    // Skip header lines
    char line[200];
    while (fgets(line, sizeof(line), file) && line[0] == '#') {
        // Skip header lines 
    }

    // Read data lines
    while (fgets(line, sizeof(line), file)) {
        
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

    *n = count;  // set the total number of entries found
    return 0;
}



// function to load paint data
int loadPaintData(char* filename, paint_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1; 
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


//QUESTION4 FUNCTION(mohamed):
paint* getPaintValue(paint_t* pp, int npp, char* name, gValue_t getType, int* nspp ){
    
    if (pp == NULL || name == NULL || nspp == NULL || npp <= 0) { //making sure inputs are good
        return NULL; 
    }
    *nspp = 0; //count of subset paints

    
    paint_t* subset = malloc(npp * sizeof(paint_t)); //allocating memory
    if (subset == NULL) {
        return NULL; 
    }

     for (int i = 0; i < npp; i++) {
        int isMatch = 0; //indicate a match
        








}