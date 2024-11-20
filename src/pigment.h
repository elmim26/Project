#ifndef PIGMENT_H  
#define PIGMENT_H

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

// Definition of paint_t structure
typedef struct {
    char ciName[50];            // color index name
    char marketingName[100];    // marketing
    char manufacturer[50];      
    int transparency;           
    int staining;               
    int valueRange;             
    int granulating;           
    int blossom;            
    int diffusion;             
    int hueAngle;               
    int hueShift;               
    int lightfast;              
} paint_t;

// Function prototypes
int loadPigmentData(char* filename, pigment_t* pArray, int* n);
int loadPaintData(char* filename, paint_t* pArray, int* n);

#endif  
