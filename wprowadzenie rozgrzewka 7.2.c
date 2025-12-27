#include <stdio.h>

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
    int collection[] = {15, 7, 22, 1, 9, 30};
    int n = sizeof(collection) / sizeof(collection[0]);

    printf("Zawartosc tablicy: ");
    printArray(collection, n);

    double avg = average(collection, n);
    printf("Srednia arytmetyczna: %.2f\n", avg);

    int minVal = minValue(collection, n);
    printf("Najmniejsza wartosc: %d\n", minVal);

    int maxVal = maxValue(collection, n);
    printf("Najwieksza wartosc: %d\n", maxVal);

    printf("Zamiana wartosci na indeksach 1 (7) i 4 (9):\n");
    swapValues(&collection[1], &collection[4]);

    printf("Zawartosc tablicy po zamianie: ");
    printArray(collection, n);

    return 0;
}