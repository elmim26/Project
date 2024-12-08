#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pigment.h"

void printPalette(const paint_t* palette, int size) {
    if (palette == NULL || size <= 0) {
        printf("Palette is empty or invalid.\n");
        return;
    }
    printf("Generated Palette:\n");
    for (int i = 0; i < size; i++) {
        printf("Paint #%d: %s, Hue: %d, Transparency: %d\n", // Adjust format as per the actual type
               i + 1, palette[i].marketingName, palette[i].hueAngle, palette[i].transparency);
    }
}

int main() {
    // Load paint data
    paint_t paints[800];
    int paintCount = 800;
    if (loadPaintData("paints.dat", paints, &paintCount) != 0) {
        printf("Failed to load paint data.\n");
        return EXIT_FAILURE;
    }

    // Test cases for getPalette
    const char* paletteTypes[] = {
        "full", 
        "triad:yellow", 
        "complimentary:blue", 
        "split-complimentary:red"
    };
    const char* properties[] = {NULL, "granulating", "non-granulating", "transparent"};

    // Test each palette type with different properties
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("\nTesting palette type: '%s', Property: '%s'\n",
                   paletteTypes[i], properties[j] ? properties[j] : "None");

            int paletteSize = paintCount; // Reset to total number of paints
            paint_t* paintPtr = paints;   // Create a pointer to the array
            paint_t* palette = getPalette(&paintPtr, &paletteSize, paletteTypes[i], properties[j]);
            
            if (palette) {
                printPalette(palette, paletteSize);
                free(palette); // Free the allocated memory
            } else {
                printf("No palette generated.\n");
            }
        }
    }

    return EXIT_SUCCESS;
}
