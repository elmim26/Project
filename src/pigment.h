int loadPigmentData(char* filename, pigment_t* pArray, int* n);


typedef struct{
    char ciName[];       
    char pigmentName[50];  
    int value;             
    int chroma;            
    int abValue[2];        
    int hueAngle;         
    float huePurity;     
    float abHp[2];         
}pigment_t;


int loadPaintData(char* filename, paint_t* pArray, int* n){
typedef struct{
    char ciName[];
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
    int lightfast;
}











