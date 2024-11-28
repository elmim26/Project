#include "pigment.h"
#include <stdio.h>

int main(void) {
    paint_t paints[200];
    int n = 0; 

    // Load paint data from file
    if (loadPaintData("paints.dat", paints, &n) != 0) {
        printf("Failed to load paint data.\n");
        return 1;
    }

    printf("Loaded %d paints.\n", n);

    // Choose a color to test
    colour_t testColor = GREEN; 
    printf("Testing for color: GREEN\n");

    
    int filteredCount = n; 
    paint_t* greenPaints = getPaintHue(paints, &filteredCount, testColor);

    
    if (greenPaints == NULL || filteredCount == 0) {
        //printf("No paints found for the color GREEN.\n");
    } else {
        printf("Found %d paints for the color GREEN:\n", filteredCount);

        for (int i = 0; i < filteredCount; i++) {
            printf("Paint %d:\n", i + 1);
            printf("  CI Name: %s\n", greenPaints[i].ciName);
            printf("  Marketing Name: %s\n", greenPaints[i].marketingName);
            printf("  Manufacturer: %s\n", greenPaints[i].manufacturer);
            printf("  Hue Angle: %d\n", greenPaints[i].hueAngle);
            printf("----------------------------\n");
        }
    }

    // Free  memory
    free(greenPaints);

    return 0;
}
