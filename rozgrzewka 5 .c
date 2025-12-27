// #include <stdio.h>
// #define N 3 // Liczba wierszy
// #define M 4 // Liczba kolumn
//
// int main() {
//     int tablica[N][M];
//     int i, j;
//
//     printf("--- 1. Tablica Pozycyjna (%dx%d) ---\n",N,M);
//
//     for (i=0;i<N;i++){
//         for (j = 0; j < M; j++) {
//             tablica[i][j] = (i + 1) * 10 + (j + 1);
//         }
//     }
//     for (i = 0; i < N; i++) {
//         for (j = 0; j < M; j++) {
//             printf("%2d ", tablica[i][j]);
//         }
//         printf("\n");
//     }
//
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
//
// #define DNI_TYGODNIA 7
// #define PORY_DNIA 3

// int main() {
//     srand(time(NULL));
//
//     const char *nazwy_dni[DNI_TYGODNIA] = {
//         "Poniedzialek", "Wtorek", "Sroda", "Czwartek",
//         "Piatek", "Sobota", "Niedziela"
//     };
//
//     float temperatury[DNI_TYGODNIA][PORY_DNIA];
//     int i, j;
//
//     printf("\n--- 2. Analiza Danych Temperatury ---\n");
//
//     for (i = 0; i < DNI_TYGODNIA; i++) {
//         for (j = 0; j < PORY_DNIA; j++) {
//             float r = (float)rand() / (float)RAND_MAX;
//             temperatury[i][j] = -5.0 + r * (25.0 - (-5.0));
//             temperatury[i][j] = (float)((int)(temperatury[i][j] * 10 + 0.5)) / 10;
//         }
//     }
//
//     printf("\n%12s | %6s | %6s | %6s\n", "Dzien", "Rano", "Poludnie", "Wieczor");
//     printf("-------------|--------|--------|--------\n");
//     for (i = 0; i < DNI_TYGODNIA; i++) {
//         printf("%12s |", nazwy_dni[i]);
//         for (j = 0; j < PORY_DNIA; j++) {
//             printf(" %5.1f |", temperatury[i][j]);
//         }
//         printf("\n");
//     }
//     printf("----------------------------------------\n");
//
//     printf("\n--- Srednie Temperatury Dnia ---\n");
//     float suma_tygodnia = 0.0;
//     float max_srednia = -100.0;
//     int dzien_max = -1;
//
//     for (i = 0; i < DNI_TYGODNIA; i++) {
//         float suma_dzienna = 0.0;
//         for (j = 0; j < PORY_DNIA; j++) {
//             suma_dzienna += temperatury[i][j];
//         }
//         float srednia_dzienna = suma_dzienna / PORY_DNIA;
//
//         suma_tygodnia += suma_dzienna;
//
//         if (srednia_dzienna > max_srednia) {
//             max_srednia = srednia_dzienna;
//             dzien_max = i;
//         }
//
//         printf("Srednia %12s: %.1f%cC\n", nazwy_dni[i], srednia_dzienna, 248);
//     }
//
//
//     float srednia_tygodnia = suma_tygodnia / (DNI_TYGODNIA * PORY_DNIA);
//     printf("\n--- Srednie Temperatury Tygodnia ---\n");
//     printf("**Srednia temperatura z calego tygodnia: %.1f%cC**\n", srednia_tygodnia, 248);
//
//
//     printf("\n--- Dzien o Najwyzszej Sredniej ---\n");
//     printf("**Dzien o najwyzszej sredniej temperaturze: %s (%.1f%cC)**\n",
//            nazwy_dni[dzien_max], max_srednia, 248);
//
//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_UCZESTNIKOW 10
#define LICZBA_UCZESTNIKOW 5 // Wczytamy 5 uczestników
#define MAX_DL_IMIENIA 11   // 10 znaków +'\0'
#define MAX_DL_NAZWISKA 26  // 25 znaków +'\0'
#define MAX_DL_LOGINU 40    // Maks.dl.Imienia(1)+Nazwiska(25)+Numer+'\0'=29

void na_male_litery(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}
int main() {
    char imiona[MAX_UCZESTNIKOW][MAX_DL_IMIENIA];
    char nazwiska[MAX_UCZESTNIKOW][MAX_DL_NAZWISKA];
    char loginy[MAX_UCZESTNIKOW][MAX_DL_LOGINU];
    int i;

    printf("\n--- 3. Generator Loginow Uczestnikow Kursu ---\n");
    printf("Wprowadz dane dla %d uczestnikow:\n\n", LICZBA_UCZESTNIKOW);

    for (i = 0; i < LICZBA_UCZESTNIKOW; i++) {
        printf("Uczestnik %d:\n", i + 1);
        printf("  Imie (max %d): ", MAX_DL_IMIENIA - 1);
        scanf("%10s", imiona[i]);
        printf("  Nazwisko (max %d): ", MAX_DL_NAZWISKA - 1);
        scanf("%25s", nazwiska[i]);
        printf("\n");
    }

    for (i = 0; i < LICZBA_UCZESTNIKOW; i++) {
        char temp_nazwisko[MAX_DL_NAZWISKA];
        char numer_porzadkowy[3];

        strcpy(temp_nazwisko, nazwiska[i]);
        na_male_litery(temp_nazwisko);

        sprintf(numer_porzadkowy, "%d", i + 1);


        loginy[i][0] = tolower((unsigned char)imiona[i][0]);
        loginy[i][1] = '\0';


        strcat(loginy[i], temp_nazwisko);

        strcat(loginy[i], numer_porzadkowy);
    }


    printf("\n--- Zestawienie Uczestnikow i Loginow ---\n");
    printf("%-12s | %-25s | %s\n", "Imie", "Nazwisko", "Login");
    printf("-------------|---------------------------|-----------------\n");
    for (i = 0; i < LICZBA_UCZESTNIKOW; i++) {
        printf("%-12s | %-25s | %s\n", imiona[i], nazwiska[i], loginy[i]);
    }
    printf("-----------------------------------------------------------\n");

    return 0;
}