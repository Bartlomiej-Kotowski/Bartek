//zad1
// #include <stdio.h>
//
// #define MAX_OCEN 14
//
// int wczytaj_ocenę() {
//     int ocena;
//     do {
//         printf("Podaj ocenę (2-5): ");
//         if (scanf("%d", &ocena) != 1) {
//             printf("Nieprawidłowy format. Podaj liczbę całkowitą.\n");
//             while (getchar() != '\n');
//             continue;
//         }
//         if (ocena >= 2 && ocena <= 5) {
//             return ocena;
//         } else {
//             printf("Ocena musi być w zakresie od 2 do 5. Spróbuj ponownie.\n");
//         }
//     } while (1);
// }
//
// int main() {
//     int oceny[MAX_OCEN];
//     int liczba_ocen = 0;
//     int suma_ocen = 0;
//     int najnizsza = 5;
//     int najwyzsza = 2;
//     int licznik_2 = 0;
//     int licznik_5 = 0;
//
//     printf("--- Wczytywanie Ocen Studenta ---\n");
//     printf("Podaj liczbę przedmiotów (maks. %d): ", MAX_OCEN);
//
//     while (scanf("%d", &liczba_ocen) != 1 || liczba_ocen <= 0 || liczba_ocen > MAX_OCEN) {
//         printf("Nieprawidłowa liczba. Podaj liczbę od 1 do %d: ", MAX_OCEN);
//         while (getchar() != '\n');
//     }
//
//     printf("\nRozpoczęto wczytywanie %d ocen:\n", liczba_ocen);
//
//     for (int i = 0; i < liczba_ocen; i++) {
//         printf("Ocena z przedmiotu %d/%d: ", i + 1, liczba_ocen);
//         int aktualna_ocena = wczytaj_ocenę();
//         oceny[i] = aktualna_ocena;
//
//         suma_ocen += aktualna_ocena;
//
//         if (aktualna_ocena < najnizsza) {
//             najnizsza = aktualna_ocena;
//         }
//
//         if (aktualna_ocena > najwyzsza) {
//             najwyzsza = aktualna_ocena;
//         }
//
//         if (aktualna_ocena == 2) {
//             licznik_2++;
//         }
//
//         if (aktualna_ocena == 5) {
//             licznik_5++;
//         }
//     }
//
//     float srednia = (float)suma_ocen / liczba_ocen;
//
//     printf("\n--- Wyniki Ocen Studenta ---\n");
//     printf("Liczba wczytanych ocen: %d\n", liczba_ocen);
//     printf("Suma punktów: %d\n", suma_ocen);
//     printf("Średnia ocen: %.2f\n", srednia);
//     printf("------------------------------\n");
//     printf("Najwyższa uzyskana ocena: %d\n", najwyzsza);
//     printf("Najniższa uzyskana ocena: %d\n", najnizsza);
//     printf("Liczba ocen niedostatecznych (2): %d\n", licznik_2);
//     printf("Liczba ocen bardzo dobrych (5): %d\n", licznik_5);
//     printf("------------------------------\n");
//
//     return 0;
// }
//zad1

//zad 2
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
//
// #define LICZBA_RZUTOW 50
// #define SCANY 6
//
// void drukuj_histogram(int wyniki[]) {
//     printf("\n--- Histogram Wyników ---\n");
//     for (int i = 0; i < SCANY; i++) {
//         printf("%d: ", i + 1);
//         for (int j = 0; j < wyniki[i]; j++) {
//             printf("*");
//         }
//         printf(" (%d)\n", wyniki[i]);
//     }
// }
//
// int main() {
//     int wyniki[SCANY] = {0};
//     int rzut;
//
//     srand(time(NULL));
//
//     for (int i = 0; i < LICZBA_RZUTOW; i++) {
//         rzut = (rand() % SCANY) + 1;
//
//         switch (rzut) {
//             case 1:
//                 wyniki[0]++;
//                 break;
//             case 2:
//                 wyniki[1]++;
//                 break;
//             case 3:
//                 wyniki[2]++;
//                 break;
//             case 4:
//                 wyniki[3]++;
//                 break;
//             case 5:
//                 wyniki[4]++;
//                 break;
//             case 6:
//                 wyniki[5]++;
//                 break;
//         }
//     }
//
//     printf("Symulacja zakończona: %d rzutów sześciościenną kostką.\n", LICZBA_RZUTOW);
//
//     drukuj_histogram(wyniki);
//
//     return 0;
// }
//zad2


//zad3

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DLUGOSC_KONTA 26

int main() {
    char numer_konta[DLUGOSC_KONTA + 2];
    int dlugosc;

    printf("Podaj numer konta bankowego (26 cyfr): ");

    if (scanf("%s", numer_konta) != 1) {
        return 1;
    }

    dlugosc = strlen(numer_konta);

    if (dlugosc != DLUGOSC_KONTA) {
        printf("Błąd: Ciąg nie składa się z 26 znaków. Znaleziono %d.\n", dlugosc);
        return 0;
    }

    int cyfra_niepoprawna = 0;
    for (int i = 0; i < dlugosc; i++) {
        if (!isdigit(numer_konta[i])) {
            printf("Błąd: Znak na pozycji %d ('%c') nie jest cyfrą.\n", i + 1, numer_konta[i]);
            cyfra_niepoprawna = 1;
        }
    }

    if (cyfra_niepoprawna) {
        return 0;
    }

    if (numer_konta[0] == '0' && numer_konta[1] == '0') {
        printf("Błąd: Pierwsze dwie cyfry (cyfry kontrolne) nie mogą tworzyć liczby \"00\".\n");
        return 0;
    }
}
// alal ma kota a kot ma ale