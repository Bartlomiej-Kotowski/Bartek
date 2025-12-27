#include <stdio.h>
#include <stdlib.h>

double average(const int *tab, int size) {
    if (size <= 0) {
        return 0.0;
    }
    long long sum = 0;
    const int *ptr = tab;
    for (int i = 0; i < size; ++i) {
        sum += *ptr;
        ptr++;
    }
    return (double)sum / size;
}

int minValue(const int *tab, int size) {
    if (size <= 0) {
        return 0;
    }
    int min = *tab;
    const int *ptr = tab + 1;
    for (int i = 1; i < size; ++i) {
        if (*ptr < min) {
            min = *ptr;
        }
        ptr++;
    }
    return min;
}

int maxValue(const int *tab, int size) {
    if (size <= 0) {
        return 0;
    }
    int max = *tab;
    const int *ptr = tab + 1;
    for (int i = 1; i < size; ++i) {
        if (*ptr > max) {
            max = *ptr;
        }
        ptr++;
    }
    return max;
}

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(const int *tab, int size) {
    const int *ptr = tab;
    for (int i = 0; i < size; ++i) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

int main() {
    int size;
    int *dynamicArray = NULL;

    printf("Podaj liczbe artefaktow (rozmiar tablicy): ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Niepoprawny rozmiar tablicy.\n");
        return 1;
    }

    dynamicArray = (int *)malloc(size * sizeof(int));
    if (dynamicArray == NULL) {
        printf("Blad alokacji pamieci.\n");
        return 1;
    }

    printf("Wypelnij tablice wartosciami mocy energetycznej:\n");
    for (int i = 0; i < size; ++i) {
        printf("Podaj wartosc dla elementu %d: ", i);
        if (scanf("%d", &dynamicArray[i]) != 1) {
            printf("Niepoprawna wartosc.\n");
            free(dynamicArray);
            return 1;
        }
    }

    printf("\n--- Analiza Artefaktow ---\n");
    
    printf("Wartosci artefaktow: ");
    printArray(dynamicArray, size);

    printf("Srednia moc energetyczna: %.2f\n", average(dynamicArray, size));
    printf("Najmniejsza moc: %d\n", minValue(dynamicArray, size));
    printf("Najwieksza moc: %d\n", maxValue(dynamicArray, size));

    if (size >= 2) {
        printf("\nZamiana mocy pierwszego i ostatniego artefaktu:\n");
        swapValues(&dynamicArray[0], &dynamicArray[size - 1]);
        printf("Tablica po zamianie: ");
        printArray(dynamicArray, size);
    }

    free(dynamicArray);
    printf("\nPamiec zostala zwolniona. Program zakonczony.\n");

    return 0;
}