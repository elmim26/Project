#include "pigment.h"
#include <stdio.h>
#include <string.h>
int main(void) {
    
    paint_t paints[200];
    int npp = 0;
    int n = 1;
    //load paint data
    if (loadPaintData("paints.dat", paints, &npp) != 0) {
        printf("Failed to load paints data.\n");
        return 1;
    }

    //searching for testcase
    char testName[] = "blue"; 
    gValue_t testType = marketingName; 
    int nspp = 0;

    // get subset of paints matching 
    paint_t *subset = getPaintValue(paints, npp, testName, testType, &nspp);

    // Check if subset is found
    if (subset == NULL || nspp == 0) {
        printf("No matches found for '%s' under '%s'.\n", testName, "MARKETINGNAME");
    } 
    else {
        printPaint(subset,-1, n);
    }
    

    // Free memory

    return 0;
}
//wednesday work
