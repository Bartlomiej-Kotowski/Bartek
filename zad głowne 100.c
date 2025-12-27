//
// Created by kotek on 18.12.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Definicja struktury artefaktu
typedef struct Artefakt {
    int moc;
    char nazwa[100];
    struct Artefakt* nastepny;
} Artefakt;

// 1. Tworzenie Zwoju (Wstawianie na początek)
Artefakt* stworzZwój(int n) {
    const char* artifacts[] = {
        "Talizman Zgubionego Wczoraj", "Mlotek Do Glaskania", "Krysztal Wiecznej Zdjeciowki",
        "Gwizdek Na Komary W Krawatach", "Klejnot Huncwota", "Kapelusz Na Lewa Strone",
        "Pierscien Wiecznie Spozniony", "Kamien Krzyczacy Po Cichu", "Amulet Dwoch Lewych Skarpet",
        "Lampa ByleCzego"
    };

    Artefakt* glowa = NULL;
    for (int i = 0; i < n; i++) {
        Artefakt* nowy = (Artefakt*)malloc(sizeof(Artefakt));
        nowy->moc = rand() % 100 + 1; // Moc od 1 do 100
        strcpy(nowy->nazwa, artifacts[rand() % 10]);

        // Wstawianie na początek listy
        nowy->nastepny = glowa;
        glowa = nowy;
    }
    return glowa;
}

// 2. Wyświetlanie Zwoju
void wyswietlZwój(Artefakt* glowa) {
    printf("\n--- ZWOJ ODKRYC ---\n");
    Artefakt* aktualny = glowa;
    while (aktualny != NULL) {
        printf("Artefakt: %-30s | Moc: %d\n", aktualny->nazwa, aktualny->moc);
        aktualny = aktualny->nastepny;
    }
}

// 3. Wyszukiwanie po nazwie (true/false)
bool czyIstnieje(Artefakt* glowa, const char* szukanaNazwa) {
    Artefakt* aktualny = glowa;
    while (aktualny != NULL) {
        if (strcmp(aktualny->nazwa, szukanaNazwa) == 0) return true;
        aktualny = aktualny->nastepny;
    }
    return false;
}

// 4. Pozycja pierwszego wystąpienia (licząc od 1)
int pozycjaArtefaktu(Artefakt* glowa, const char* szukanaNazwa) {
    Artefakt* aktualny = glowa;
    int licznik = 1;
    while (aktualny != NULL) {
        if (strcmp(aktualny->nazwa, szukanaNazwa) == 0) return licznik;
        aktualny = aktualny->nastepny;
        licznik++;
    }
    return 0;
}

// 5. Zliczanie wystąpień
int zliczWystapienia(Artefakt* glowa, const char* szukanaNazwa) {
    Artefakt* aktualny = glowa;
    int ile = 0;
    while (aktualny != NULL) {
        if (strcmp(aktualny->nazwa, szukanaNazwa) == 0) ile++;
        aktualny = aktualny->nastepny;
    }
    return ile;
}

// 6. Oczyszczenie Zwoju (Zwalnianie pamięci)
void wyczyscZwoj(Artefakt** glowa) {
    Artefakt* aktualny = *glowa;
    Artefakt* nastepny;
    while (aktualny != NULL) {
        nastepny = aktualny->nastepny;
        free(aktualny);
        aktualny = nastepny;
    }
    *glowa = NULL;
    printf("\nZwoj zostal spalony (pamiec zwolniona).\n");
}

int main() {
    srand(time(NULL));

    // Tworzymy listę 5 losowych artefaktów
    Artefakt* mojZwoj = stworzZwój(5);

    wyswietlZwój(mojZwoj);

    const char* szukany = "Klejnot Huncwota";
    printf("\nSzukamy: %s\n", szukany);
    printf("Czy jest w zwoju? %s\n", czyIstnieje(mojZwoj, szukany) ? "Tak" : "Nie");
    printf("Pozycja: %d\n", pozycjaArtefaktu(mojZwoj, szukany));
    printf("Liczba sztuk: %d\n", zliczWystapienia(mojZwoj, szukany));

    wyczyscZwoj(&mojZwoj);

    return 0;
}