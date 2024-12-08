#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pigment.h"

int main() {
    // Load paint data
    paint_t paints[800];
    int paintCount = 800;
    if (loadPaintData("paints.dat", paints, &paintCount) != 0) {
        printf("Failed to load paint data.\n");
        return EXIT_FAILURE;
    }

    const char* paletteTypes[] = {  //4 tests to input into getPallete
        "full", 
        "triad:yellow", 
        "complimentary:blue", 
        "split-complimentary:red"
    };

    for (int i = 0; i < 4; i++) {
        printf("\n=================Testing palette type: '%s'===============\n", paletteTypes[i]);

        int paletteSize = paintCount;
        paint_t* paintPtr = paints;   
        paint_t* palette = getPalette(&paintPtr, &paletteSize, paletteTypes[i], NULL); //inputs palleteType inside type directly using for loop going through each type
        
        if (palette) {  //prints the pallete or prints error if did not work
            if (paletteSize <= 0) {
                printf("Palette empty or invalid.\n");
            } 
            free(palette); 
        }
    }

    return EXIT_SUCCESS;
}
