#include <stdio.h>
#include <stdlib.h>

int problem1() {
    FILE *inputFile, *positiveFile, *negativeFile;
    float value;

    inputFile = fopen("Rejestr_Wartosci.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }

    positiveFile = fopen("Rejestr_Dodatni.txt", "w");
    if (positiveFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    negativeFile = fopen("Rejestr_Ujemny.txt", "w");
    if (negativeFile == NULL) {
        fclose(inputFile);
        fclose(positiveFile);
        return 1;
    }

    while (fscanf(inputFile, "%f", &value) == 1) {
        if (value > 0.0) {
            fprintf(positiveFile, "%.2f\n", value);
        } else if (value < 0.0) {
            fprintf(negativeFile, "%.2f\n", value);
        }
    }

    fclose(inputFile);
    fclose(positiveFile);
    fclose(negativeFile);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100

int problem2() {
    FILE *inputFile, *outputFile;
    char word[MAX_WORD_LENGTH];
    const char *s1 = "alchemia";
    const char *s2 = "transmutacja";

    inputFile = fopen("Zwój_Badan.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }

    outputFile = fopen("Zwój_Poprawiony.txt", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%s", word) == 1) {
        if (strcmp(word, s1) == 0) {
            fprintf(outputFile, "%s ", s2);
        } else {
            fprintf(outputFile, "%s ", word);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

int main() {
    printf("--- Rozwiązanie Problem 1 ---\n");
    if (problem1() == 0) {
        printf("Sortowanie wartości zakończone. Dane zapisano do Rejestr_Dodatni.txt i Rejestr_Ujemny.txt.\n");
    } else {
        printf("Błąd w Problemie 1 (upewnij się, że Rejestr_Wartosci.txt istnieje).\n");
    }

    printf("\n--- Rozwiązanie Problem 2 ---\n");
    if (problem2() == 0) {
        printf("Zastępowanie słów zakończone. Dane zapisano do Zwój_Poprawiony.txt.\n");
    } else {
        printf("Błąd w Problemie 2 (upewnij się, że Zwój_Badan.txt istnieje).\n");
    }

    return 0;
}