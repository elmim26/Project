#include <pigment.h>
#include <stdio.h>
#include <stdlib.h>

int loadPigmentData(char* filename, pigment_t* pArray, int* n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; //return 1 if file cant be opened
    }
int count = 0;

int loadPaintData(char* filename, paint_t* pArray, int* n){
    in = fopen(*filename, "r");
    get[500] = "";
    // paints.dat: C.I.NAME, MARKETING NAME, Manufacturer, Code, Tr, St, VR, Gr, Bl, Df, HA, HS, Lf
    while(!feof(in)){
        *n = 0;
        
    }
}