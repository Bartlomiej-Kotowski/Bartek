#include <stdio.h>

// Definicja wymiarów tablicy
#define N 3 // Liczba wierszy (N < 10)
#define M 4 // Liczba kolumn (M < 10)

int main() {
    // Deklaracja tablicy
    int tablica[N][M];

    printf("--- Tablica Pozycyjna (%d x %d) ---\n", N, M);

    // Wypełnianie tablicy
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j

//============================================================
#include <stdio.h>

// Definicja wymiarów tablicy (N, M < 10)
#define N 3 // Liczba wierszy
#define M 4 // Liczba kolumn

int main() {
    // Deklaracja tablicy
    int tablica[N][M];
    int i, j;

    printf("--- 1. Tablica Pozycyjna (%d x %d) ---\n", N, M);

    // Wypełnianie tablicy
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            // Numer wiersza (od 1): (i + 1)
            // Numer kolumny (od 1): (j + 1)
            // Wartość = (Wiersz * 10) + Kolumna
            tablica[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    // Wyświetlanie tablicy
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%2d ", tablica[i][j]); // Użycie %2d dla czytelnego formatowania
        }
        printf("\n");
    }

    return 0;
}
//===========================================================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definicja wymiarów tablicy
#define DNI_TYGODNIA 7
#define PORY_DNIA 3

int main() {
    // Inicjalizacja generatora liczb losowych
    srand(time(NULL));

    // Nazwy dni tygodnia
    const char *nazwy_dni[DNI_TYGODNIA] = {
        "Poniedzialek", "Wtorek", "Sroda", "Czwartek",
        "Piatek", "Sobota", "Niedziela"
    };

    // Deklaracja tablicy temperatur (float)
    float temperatury[DNI_TYGODNIA][PORY_DNIA];
    int i, j;

    printf("\n--- 2. Analiza Danych Temperatury ---\n");

    // Wypełnianie tablicy losowymi wartościami
    for (i = 0; i < DNI_TYGODNIA; i++) {
        for (j = 0; j < PORY_DNIA; j++) {
            // Generowanie losowej liczby z przedziału [0.0, 1.0]
            float r = (float)rand() / (float)RAND_MAX;
            // Przeliczenie na przedział [-5.0, 25.0]
            temperatury[i][j] = -5.0 + r * (25.0 - (-5.0));
            // Zaokrąglenie do jednego miejsca po przecinku (mnożymy *10, zaokrąglamy, dzielimy przez 10)
            temperatury[i][j] = (float)((int)(temperatury[i][j] * 10 + 0.5)) / 10;
        }
    }

    // Wyświetlanie tabeli temperatur
    printf("\n%12s | %6s | %6s | %6s\n", "Dzien", "Rano", "Poludnie", "Wieczor");
    printf("-------------|--------|--------|--------\n");
    for (i = 0; i < DNI_TYGODNIA; i++) {
        printf("%12s |", nazwy_dni[i]);
        for (j = 0; j < PORY_DNIA; j++) {
            printf(" %5.1f |", temperatury[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------\n");

    // 1. Obliczanie i wypisywanie średniej temperatury każdego dnia
    printf("\n--- Srednie Temperatury Dnia ---\n");
    float suma_tygodnia = 0.0;
    float max_srednia = -100.0;
    int dzien_max = -1;

    for (i = 0; i < DNI_TYGODNIA; i++) {
        float suma_dzienna = 0.0;
        for (j = 0; j < PORY_DNIA; j++) {
            suma_dzienna += temperatury[i][j];
        }
        float srednia_dzienna = suma_dzienna / PORY_DNIA;

        // Zapis sumy do obliczenia średniej tygodnia
        suma_tygodnia += suma_dzienna;

        // Wyszukiwanie dnia o najwyższej średniej
        if (srednia_dzienna > max_srednia) {
            max_srednia = srednia_dzienna;
            dzien_max = i;
        }

        printf("Srednia %12s: %.1f%cC\n", nazwy_dni[i], srednia_dzienna, 248); // 248 to kod ASCII dla '°'
    }

    // 2. Obliczanie i wypisywanie średniej temperatury z całego tygodnia
    float srednia_tygodnia = suma_tygodnia / (DNI_TYGODNIA * PORY_DNIA);
    printf("\n--- Srednie Temperatury Tygodnia ---\n");
    printf("**Srednia temperatura z calego tygodnia: %.1f%cC**\n", srednia_tygodnia, 248);

    // 3. Wskazanie dnia o najwyższej średniej temperaturze
    printf("\n--- Dzien o Najwyzszej Sredniej ---\n");
    printf("**Dzien o najwyzszej sredniej temperaturze: %s (%.1f%cC)**\n",
           nazwy_dni[dzien_max], max_srednia, 248);

    return 0;
}
//==========================================================================
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_UCZESTNIKOW 10
#define LICZBA_UCZESTNIKOW 5 // Wczytamy 5 uczestników
#define MAX_DL_IMIENIA 11   // 10 znaków + '\0'
#define MAX_DL_NAZWISKA 26  // 25 znaków + '\0'
#define MAX_DL_LOGINU 40    // Maks. dl. Imienia(1) + Nazwiska(25) + Numer(2) + '\0' = 29, dajemy zapas

// Funkcja konwertująca ciąg znaków na małe litery
void na_male_litery(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    // Tablice do przechowywania danych
    char imiona[MAX_UCZESTNIKOW][MAX_DL_IMIENIA];
    char nazwiska[MAX_UCZESTNIKOW][MAX_DL_NAZWISKA];
    char loginy[MAX_UCZESTNIKOW][MAX_DL_LOGINU];
    int i;

    printf("\n--- 3. Generator Loginow Uczestnikow Kursu ---\n");
    printf("Wprowadz dane dla %d uczestnikow:\n\n", LICZBA_UCZESTNIKOW);

    // Wczytywanie danych uczestników
    for (i = 0; i < LICZBA_UCZESTNIKOW; i++) {
        printf("Uczestnik %d:\n", i + 1);
        printf("  Imie (max %d): ", MAX_DL_IMIENIA - 1);
        scanf("%10s", imiona[i]); // Wczytaj do MAX_DL_IMIENIA - 1
        printf("  Nazwisko (max %d): ", MAX_DL_NAZWISKA - 1);
        scanf("%25s", nazwiska[i]); // Wczytaj do MAX_DL_NAZWISKA - 1
        printf("\n");
    }

    // Tworzenie loginów
    for (i = 0; i < LICZBA_UCZESTNIKOW; i++) {
        char temp_nazwisko[MAX_DL_NAZWISKA];
        char numer_porzadkowy[3]; // np. "1", "10", '\0'

        // 1. Kopiowanie nazwiska do tymczasowego bufora i konwersja na małe litery
        strcpy(temp_nazwisko, nazwiska[i]);
        na_male_litery(temp_nazwisko);

        // 2. Generowanie numeru porządkowego
        sprintf(numer_porzadkowy, "%d", i + 1);

        // 3. Budowanie loginu:
        // a) Pierwsza litera imienia (mała)
        loginy[i][0] = tolower((unsigned char)imiona[i][0]);
        loginy[i][1] = '\0'; // Zakończenie ciagu, aby móc uzyc strcat

        // b) Dodanie nazwiska (małymi literami)
        strcat(loginy[i], temp_nazwisko);

        // c) Dodanie numeru porządkowego
        strcat(loginy[i], numer_porzadkowy);
    }

    // Wyświetlanie danych w formie tabeli
    printf("\n--- Zestawienie Uczestnikow i Loginow ---\n");
    printf("%-12s | %-25s | %s\n", "Imie", "Nazwisko", "Login");
    printf("-------------|---------------------------|-----------------\n");
    for (i = 0; i < LICZBA_UCZESTNIKOW; i++) {
        printf("%-12s | %-25s | %s\n", imiona[i], nazwiska[i], loginy[i]);
    }
    printf("-----------------------------------------------------------\n");

    return 0;
}