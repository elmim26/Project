#include <stdio.h>
#include "pigment.h"

int main(void) {
    pigment_t pigments[100];  // Array to store 100 pigments
    int n = 0;

    int result = loadPigmentData("pigments.dat", pigments, &n);
    if (result != 0) {
        printf("pigment data load failed.\n");
        return 1;
    }
}
 printf("Loaded %d pigments:\n", n);

  for (int i = 0; i < n; i++){
     printf("Pigment %d: CI Name: %s, Pigment Name: %s,Value: %d,Chroma: %d,aC: %d,bC: %d,Hue Angle: %d,Hue Purity: %.2f,aHP: %.2f,bHP: %.2f\n",
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

     return 0;





  }