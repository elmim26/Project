#ifndef PIGMENT_H  
#define PIGMENT_H
#include <stdlib.h>

// Definition of pigment_t structure
typedef struct {
    char ciName[50];       // COLOR INDEX
    char pigmentName[50];  // PIGMENT NAME
    int value;             // J value
    int chroma;            // C value
    int abValue[2];        // ac and bc values
    int hueAngle;          // Hue angle
    float huePurity;       // Hue purity
    float abHp[2];         // aHP and bHP values
} pigment_t;

typedef enum {ciName,marketingName,manufacturer} gValue_t //enumerator for q4


// Definition of paint_t structure
typedef struct {
    char ciName[50];
    char marketingName[100];
    char manufacturer[50];
    int transparency;
    int staining;
    int valueRange;
    int granulating;
    int blossom;
    int diffusion;
    int hueAngle;
    int hueShift;
    int lightfast1;  // First part of Lightfastness
    int lightfast2;  // Second part of Lightfastness
} paint_t;

// Function prototypes of milestone 1
int loadPigmentData(char* filename, pigment_t* pArray, int* n);
int loadPaintData(char* filename, paint_t* pArray, int* n);



//prototypes for milestone 2
int printPigment(pigment_t* pp, int i, int n); //q1
paint* getPaintValue(paint_t* pp, int npp, char* name, gValue_t getType, int* nspp ) //q4
















#endif