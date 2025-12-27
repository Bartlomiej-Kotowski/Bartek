#include <stdio.h>

void displayContent(const int *arr, int size) {
    printf("Zawartosc tablicy:\n");
    for (int i = 0; i < size; i++) {
        printf("Krysztal [%d]: %d\n", i, *(arr + i));
    }
}

int main() {
    int crystals[5] = {10, 20, 30, 40, 50};
    int size = 5;
    int choice;

    do {
        displayContent(crystals, size);
        printf("--- MENU ---\n");
        printf("Wybierz krysztal (0 do 4) lub -1, aby zakonczyc: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -2;
        }

        if (choice >= 0 && choice < size) {
            int newValue;
            int *crystalPtr = crystals + choice;

            printf("Aktualny poziom kryszalu %d: %d\n", choice, *crystalPtr);
            printf("Wpisz nowa wartosc: ");
            if (scanf("%d", &newValue) == 1) {
                *crystalPtr = newValue;
                printf("Poziom kryszalu %d zaktualizowany.\n", choice);
            } else {
                while (getchar() != '\n');
                printf("Niepoprawna wartosc. Anulowanie modyfikacji.\n");
            }
        } else if (choice != -1) {
            printf("Niepoprawny wybor.\n");
        }

        printf("\n");
    } while (choice != -1);

    printf("Program zakonczony.\n");

    return 0;
}