#include <stdio.h>
#include <string.h>

// enumeration for colors
typedef enum {
    RED, RED_ORANGE, ORANGE, YELLOW_ORANGE, YELLOW, YELLOW_GREEN,
    GREEN, BLUE_GREEN, BLUE, BLUE_VIOLET, VIOLET, RED_VIOLET
} colour_t;

// Function to get the color name as a string
const char* getColourName(colour_t colour) {
    const char* names[] = {
        "Red", "Red-Orange", "Orange", "Yellow-Orange", "Yellow",
        "Yellow-Green", "Green", "Blue-Green", "Blue", "Blue-Violet",
        "Violet", "Red-Violet"
    };
    return names[colour];
}

int main() {
    int running = 1; // Flag to keep the program running
    int paletteType = -1; // Palette type: -1 means none selected
    int paletteProperty = -1; // Palette property: -1 means none selected

    printf("Welcome to Paints Program\n");

    while (running) {
        // Print the menu
        printf("\nChoose one of the following:\n");
        printf("0) Quit\n");
        printf("1) Enter a Palette type (Currently set at: %s)\n",
               paletteType == -1 ? "None" : (paletteType == 1 ? "Full" :
               paletteType == 2 ? "Triad" : paletteType == 3 ? "Complementary" : "Split Complementary"));
        printf("2) Enter a Palette Property (Currently set at: %s)\n",
               paletteProperty == -1 ? "None" : getColourName((colour_t)paletteProperty));
        printf("3) Print Palette Choice\n");
        printf("4) Help (view valid palette types and properties)\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice); // Get user choice

        switch (choice) {
            case 0:
                running = 0; // Quit the program
                printf("Goodbye!\n");
                break;
            case 1:
                printf("Choose a Palette Type (1: Full, 2: Triad, 3: Complementary, 4: Split Complementary): ");
                scanf("%d", &paletteType);
                if (paletteType >= 1 && paletteType <= 4) {
                    printf("Palette type set to %s.\n",
                           paletteType == 1 ? "Full" :
                           paletteType == 2 ? "Triad" :
                           paletteType == 3 ? "Complementary" : "Split Complementary");
                } else {
                    printf("Invalid Palette Type. Try again.\n");
                    paletteType = -1; // Reset to None
                }
                break;
            case 2:
                printf("Choose a Palette Property (0-11 corresponding to colours): ");
                scanf("%d", &paletteProperty);
                if (paletteProperty >= 0 && paletteProperty <= 11) {
                    printf("Palette property set to %s.\n", getColourName((colour_t)paletteProperty));
                } else {
                    printf("Invalid Palette Property. Try again.\n");
                    paletteProperty = -1; // Reset to None
                }
                break;
            case 3:
                printf("Current Palette Type: %s\n",
                       paletteType == -1 ? "None" :
                       paletteType == 1 ? "Full" :
                       paletteType == 2 ? "Triad" :
                       paletteType == 3 ? "Complementary" : "Split Complementary");
                printf("Palette Property: %s\n",
                       paletteProperty == -1 ? "None" : getColourName((colour_t)paletteProperty));
                break;
            case 4:
                printf("\nHelp - Valid Palette Types and Properties:\n");
                printf("Palette Types:\n");
                printf("1) Full - All 12 main colors.\n");
                printf("2) Triad - Three colors equally spaced on the wheel.\n");
                printf("3) Complementary - Two opposite colors.\n");
                printf("4) Split Complementary - One color and two adjacent to its complement.\n");
                printf("Palette Properties:\n");
                for (int i = 0; i < 12; i++) {
                    printf("%d) %s\n", i, getColourName((colour_t)i));
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
