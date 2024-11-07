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









