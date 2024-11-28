#include "pigment.h"
#include <stdio.h>
#include <string.h>
int main() {
    // Sample paints array and size
    paint_t paints[200];
    int npp = 0;

    // Load paint data
    if (loadPaintData("paints.dat", paints, &npp) != 0) {
        printf("Failed to load paints data.\n");
        return 1;
    }

    // Specify the search criteria
    char testName[] = "cerulean blue"; // Replace with your desired marketing name
    gValue_t testType = marketingName; // Searching by marketing name
    int nspp = 0;

    // Get subset of paints matching criteria
    paint_t *subset = getPaintValue(paints, npp, testName, testType, &nspp);

    // Check if subset is found
    if (subset == NULL || nspp == 0) {
        printf("No matches found for '%s' under '%s'.\n", testName, "MARKETINGNAME");
    } else {
        printf("Found %d matches for '%s':\n", nspp, testName);

        // Print matching paints
        for (int i = 0; i < nspp; i++) {
            printf("Paint %d:\n", i + 1);
            printf("  CI Name: %s\n", subset[i].ciName);
            printf("  Marketing Name: %s\n", subset[i].marketingName);
            printf("  Manufacturer: %s\n", subset[i].manufacturer);
            printf("  Transparency: %d\n", subset[i].transparency);
            printf("  Staining: %d\n", subset[i].staining);
            printf("  Value Range: %d\n", subset[i].valueRange);
            printf("  Granulation: %d\n", subset[i].granulating);
            printf("  Blossom: %d\n", subset[i].blossom);
            printf("  Diffusion: %d\n", subset[i].diffusion);
            printf("  Hue Angle: %d\n", subset[i].hueAngle);
            printf("  Hue Shift: %d\n", subset[i].hueShift);
           // printf("  Lightfastness: %d\n", subset[i].lightfast);
            printf("-----------------------\n");
        }
    }

    // Free dynamically allocated memory
    free(subset);

    return 0;
}

