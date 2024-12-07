#include <stdio.h>
#include "pigment.h" // Include your header file with declarations

int main() {
    // Example paint data
    paint_t paints[] = {
        {"CI1", "Paint 1", "Manufacturer A", 0, 0, 0, 0, 0, 0, 350, 0, 0, 0}, // RED
        {"CI2", "Paint 2", "Manufacturer B", 0, 0, 0, 0, 0, 0, 10, 0, 0, 0},  // RED-ORANGE
        {"CI3", "Paint 3", "Manufacturer C", 0, 0, 0, 0, 0, 0, 45, 0, 0, 0},  // ORANGE
        {"CI4", "Paint 4", "Manufacturer D", 0, 0, 0, 0, 0, 0, 75, 0, 0, 0},  // YELLOW
        {"CI5", "Paint 5", "Manufacturer E", 0, 0, 0, 0, 0, 0, 120, 0, 0, 0}, // GREEN
        {"CI6", "Paint 6", "Manufacturer F", 0, 0, 0, 0, 0, 0, 150, 0, 0, 0}, // GREEN
        {"CI7", "Paint 7", "Manufacturer G", 0, 0, 0, 0, 0, 0, 210, 0, 0, 0}, // BLUE
        {"CI8", "Paint 8", "Manufacturer H", 0, 0, 0, 0, 0, 0, 220, 0, 0, 0}, // BLUE
        {"CI9", "Paint 9", "Manufacturer I", 0, 0, 0, 0, 0, 0, 240, 0, 0, 0}, // BLUE
    };

    int n = sizeof(paints) / sizeof(paints[0]);

    // Test for BLUE paints
    colour_t blue_colour = BLUE;
    printf("Testing for blue paints:\n");

    int blue_size = n;
    paint_t* blue_paints = getPaintHue(paints, &blue_size, blue_colour);

    if (blue_paints == NULL || blue_size == 0) {
        printf("No blue paints found.\n");
    } else {
        printf("Found %d blue paints:\n", blue_size);
        for (int i = 0; i < blue_size; i++) {
            printf("%s (Hue: %d)\n", blue_paints[i].marketingName, blue_paints[i].hueAngle);
        }
        free(blue_paints);
    }

    // Test for GREEN paints
    colour_t green_colour = GREEN;
    printf("\nTesting for green paints:\n");

    int green_size = n;
    paint_t* green_paints = getPaintHue(paints, &green_size, green_colour);

    if (green_paints == NULL || green_size == 0) {
        printf("No green paints found.\n");
    } else {
        printf("Found %d green paints:\n", green_size);
        for (int i = 0; i < green_size; i++) {
            printf("%s (Hue: %d)\n", green_paints[i].marketingName, green_paints[i].hueAngle);
        }
        free(green_paints);
    }

    return 0;
}
