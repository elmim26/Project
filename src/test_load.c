#include <stdio.h>
#include "pigment.h"

int main() {
    pigment_t pigments[100];  // array to store 100 pigments
    int n = 800;                // variable to hold count of pigments

    //load pigment data
    int result = loadPigmentData("pigments.dat", pigments, &n);
    if (result != 0) {
        printf("Failed to load pigment data.\n");
        return 1;
    }

    printf("Loaded %d pigments:\n", n);  // Use n to show the count of loaded pigments

    // loop through array to display each pigment
    for (int i = 0; i < n; i++) {
        printf("Pigment %d: CI Name: %s, Pigment Name: %s, J Value: %d, Chroma: %d, aC: %d, bC: %d, Hue Angle: %d, Hue Purity: %.2f, aHP: %.2f, bHP: %.2f\n",
               i + 1,
               pigments[i].ciName,
               pigments[i].pigmentName,
               pigments[i].value,
               pigments[i].chroma,
               pigments[i].abValue[0],
               pigments[i].abValue[1],
               pigments[i].hueAngle,
               pigments[i].huePurity,
               pigments[i].abHp[0],
               pigments[i].abHp[1]);
    }
    paint_t paints[800];  // Array to store 800 paints
    int x = 800;          // Set x to 800 (maximum size of the array)

    // Load paint data
    int res = loadPaintData("paints.dat", paints, &x);
    if (res != 0) {
        printf("Failed to load paint data.\n");
        return 1;
    }

    printf("Loaded %d paints:\n", x);  

    for (int i = 0; i < x; i++) {
        printf("Paint %d: CI Name: %s, Marketing Name: %s, Manufacturer: %s, code: %d, Transparency: %d, Staining: %d, Value Range: %d, Granulating: %d, Blossom: %d, Diffusion: %d, Hue Angle: %d, Hue Shift: %d, Lightfast: %d/%d\n",
            i,
            paints[i].ciName,
            paints[i].marketingName,
            paints[i].manufacturer,
            paints[i].code,
            paints[i].transparency,
            paints[i].staining,
            paints[i].valueRange,
            paints[i].granulating,
            paints[i].blossom,
            paints[i].diffusion,
            paints[i].hueAngle,
            paints[i].hueShift,
            paints[i].lightfast1,  // Print the first lightfast value
            paints[i].lightfast2); // Print the second lightfast value
    }

    return 0;
}
