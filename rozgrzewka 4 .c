#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Definicje stałych
#define MAX_POTIONS 10
#define POWER_THRESHOLD_HIGH 100.0
#define POWER_THRESHOLD_LOW 10.0

// --- Deklaracje funkcji ---

/**
 * Wyświetla wprowadzenie do programu.
 */
void showIntro();

/**
 * Wyświetla menu dostępnych opcji, pobiera wybór użytkownika i go waliduje.
 * Zwraca numer wybranej opcji.
 */
int showMenu();

/**
 * Symuluje proces warzenia nowej mikstury.
 * Oblicza i zwraca moc mikstury na podstawie wzoru i losowej wartości.
 * * @param ingredientA Wartość pierwszego składnika.
 * @param ingredientB Wartość drugiego składnika.
 * @return Obliczona moc nowej mikstury.
 */
double brewPotion(double ingredientA, double ingredientB);

/**
 * Oblicza i zwraca średnią moc wszystkich mikstur.
 * * @param potions Tablica z mocami mikstur.
 * @param n Aktualna liczba mikstur.
 * @return Średnia moc mikstur.
 */
double averagePower(double potions[], int n);

/**
 * Znajduje i zwraca indeks mikstury o największej mocy.
 * * @param potions Tablica z mocami mikstur.
 * @param n Aktualna liczba mikstur.
 * @return Indeks najsilniejszej mikstury.
 */
int findStrongest(double potions[], int n);

/**
 * Wzmacnia wszystkie mikstury o 10%.
 * * @param potions Tablica z mocami mikstur.
 * @param n Aktualna liczba mikstur.
 */
void strengthenAll(double potions[], int n);

/**
 * Stabilizuje moc wybranej mikstury w zależności od jej wartości.
 * * @param power Wskaźnik na moc mikstury do stabilizacji.
 */
void stabilizePotion(double *power);

/**
 * Czyści miksturę z zanieczyszczeń, zwiększając jej moc i zmniejszając zanieczyszczenia.
 * * @param power Wskaźnik na moc mikstury.
 * @param impurities Wskaźnik na poziom zanieczyszczeń mikstury.
 */
void purifyPotion(double *power, int *impurities);

// --- Implementacja funkcji ---

void showIntro() {
    printf("====================================================\n");
    printf("🧪 AKADEMIA MAGII IM. GEDEONA SZKARŁATNEGO 🧪\n");
    printf("----------------------------------------------------\n");
    printf("Wspomaganie adepta: System Zarządzania Miksturami\n");
    printf("Autor: AI Gemini, na zlecenie mistrzów Alchemii\n");
    printf("====================================================\n");
}

int showMenu() {
    int choice;
    char buffer[100]; // Bufor do odczytu linii

    while (true) {
        printf("\n--- MENU GŁÓWNE ---\n");
        printf("1. ➕ Dodaj nową miksturę\n");
        printf("2. 📊 Oblicz średnią moc\n");
        printf("3. ⭐ Znajdź najsilniejszą miksturę\n");
        printf("4. ⚡ Wzmocnij wszystkie mikstury (o 10%%)\n");
        printf("5. ⚖️ Ustabilizuj wybraną miksturę\n");
        printf("6. ✨ Oczyść miksturę z zanieczyszczeń\n");
        printf("7. 🚪 Zakończ program\n");
        printf("Wybierz opcję (1-7): ");

        // Próba odczytu liczby
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &choice) != 1) {
            printf("\n❗️ Błąd: Wprowadzona wartość nie jest liczbą. Spróbuj ponownie.\n");
            continue;
        }

        // Walidacja zakresu
        if (choice >= 1 && choice <= 7) {
            return choice;
        } else {
            printf("\n❗️ Błąd: Wybór poza zakresem dostępnych opcji (1-7). Spróbuj ponownie.\n");
        }
    }
}

double brewPotion(double ingredientA, double ingredientB) {
    // Generowanie losowej wartości z przedziału (0; 1>
    // RAND_MAX to maksymalna wartość zwracana przez rand()
    double randomValue = (double)rand() / (RAND_MAX + 1.0); // Zapewnia zakres [0, 1)

    // Wzór: moc = (ingredientA * 0.6 + ingredientB * 0.4) * randomValue
    double power = (ingredientA * 0.6 + ingredientB * 0.4) * randomValue;
    return power;
}

double averagePower(double potions[], int n) {
    if (n == 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += potions[i];
    }
    return sum / n;
}

int findStrongest(double potions[], int n) {
    if (n == 0) {
        return -1; // -1 jako wskaźnik błędu (pusta tablica)
    }

    int strongestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (potions[i] > potions[strongestIndex]) {
            strongestIndex = i;
        }
    }
    return strongestIndex;
}

void strengthenAll(double potions[], int n) {
    for (int i = 0; i < n; i++) {
        // Zwiększenie mocy o 10% (pomnożenie przez 1.1)
        potions[i] *= 1.10;
    }
}

void stabilizePotion(double *power) {
    if (*power > POWER_THRESHOLD_HIGH) {
        // Zmniejszenie o 20%
        *power *= 0.80;
        printf("Mikstura była zbyt silna (%.2f)! Zredukowano moc o 20%%.\n", *power / 0.80);
    } else if (*power < POWER_THRESHOLD_LOW) {
        // Zwiększenie o 50%
        *power *= 1.50;
        printf("Mikstura była zbyt słaba (%.2f)! Zwiększono moc o 50%%.\n", *power / 1.50);
    } else {
        printf("Mikstura w zakresie stabilności. Nie wprowadzono zmian.\n");
    }
}

void purifyPotion(double *power, int *impurities) {
    // Oczyszczanie: zmniejszenie zanieczyszczeń o 2
    if (*impurities >= 2) {
        *impurities -= 2;
        printf("Poziom zanieczyszczeń obniżony o 2.\n");
    } else if (*impurities == 1) {
        *impurities = 0;
        printf("Poziom zanieczyszczeń obniżony do 0.\n");
    } else {
        printf("Mikstura jest już czysta. Brak zanieczyszczeń do usunięcia.\n");
    }

    // Wzmocnienie: zwiększenie mocy o 5%
    *power *= 1.05;
    printf("Moc mikstury zwiększona o 5%%.\n");
}

/**
 * Pomocnicza funkcja do wyświetlania wszystkich mikstur.
 */
void displayPotions(double potions[], int impurities[], int n) {
    if (n == 0) {
        printf("Aktualnie nie ma żadnych mikstur w laboratorium.\n");
        return;
    }
    printf("\n--- Stan Laboratorium ---\n");
    for (int i = 0; i < n; i++) {
        printf("| Mikstura %d: Moc: %.2f | Zanieczyszczenia: %d |\n",
               i, potions[i], impurities[i]);
    }
    printf("-------------------------\n");
}

/**
 * Pomocnicza funkcja do bezpiecznego odczytu liczby z walidacją.
 */
int getValidatedInt(const char* prompt, int min, int max) {
    int value;
    char buffer[100];
    while (true) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &value) != 1) {
            printf("❗️ Błąd: Wprowadzona wartość nie jest liczbą całkowitą. Spróbuj ponownie.\n");
            continue;
        }
        if (value >= min && value <= max) {
            return value;
        } else {
            printf("❗️ Błąd: Wartość musi być w zakresie od %d do %d. Spróbuj ponownie.\n", min, max);
        }
    }
}

/**
 * Pomocnicza funkcja do bezpiecznego odczytu liczby zmiennoprzecinkowej z walidacją.
 */
double getValidatedDouble(const char* prompt) {
    double value;
    char buffer[100];
    while (true) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%lf", &value) != 1) {
            printf("❗️ Błąd: Wprowadzona wartość nie jest liczbą. Spróbuj ponownie.\n");
            continue;
        }
        if (value >= 0) {
             return value;
        } else {
            printf("❗️ Błąd: Wartość musi być nieujemna. Spróbuj ponownie.\n");
        }
    }
}


// --- Funkcja główna ---

int main() {
    // Inicjalizacja generatora liczb losowych
    srand((unsigned int)time(NULL));

    // Deklaracja tablic na mikstury
    double potionPowers[MAX_POTIONS] = {0.0};
    int potionImpurities[MAX_POTIONS] = {0};
    int currentPotionsCount = 0; // Aktualna liczba mikstur

    showIntro();

    int choice;
    do {
        displayPotions(potionPowers, potionImpurities, currentPotionsCount);
        choice = showMenu();

        switch (choice) {
            case 1: { // Dodać nową miksturę
                if (currentPotionsCount >= MAX_POTIONS) {
                    printf("\n🛑 Osiągnięto maksymalną liczbę mikstur (%d). Nie można dodać nowej.\n", MAX_POTIONS);
                    break;
                }

                printf("\n--- Tworzenie Nowej Mikstury ---\n");
                double ingredientA = getValidatedDouble("Podaj moc składnika A (np. 50.0): ");
                double ingredientB = getValidatedDouble("Podaj moc składnika B (np. 30.0): ");
                int impurities = getValidatedInt("Podaj początkowy poziom zanieczyszczeń (0+): ", 0, 1000);

                double newPower = brewPotion(ingredientA, ingredientB);

                potionPowers[currentPotionsCount] = newPower;
                potionImpurities[currentPotionsCount] = impurities;

                printf("\n✅ Utworzono nową miksturę %d:\n", currentPotionsCount);
                printf("   Moc: %.2f | Zanieczyszczenia: %d\n", newPower, impurities);

                currentPotionsCount++;
                break;
            }

            case 2: { // Obliczyć średnią moc
                if (currentPotionsCount == 0) {
                    printf("\n⚠️ Brak mikstur do obliczenia średniej.\n");
                    break;
                }
                double avg = averagePower(potionPowers, currentPotionsCount);
                printf("\n📊 Średnia moc wszystkich %d mikstur wynosi: **%.2f**\n", currentPotionsCount, avg);
                break;
            }

            case 3: { // Znaleźć najsilniejszą miksturę
                if (currentPotionsCount == 0) {
                    printf("\n⚠️ Brak mikstur do znalezienia najsilniejszej.\n");
                    break;
                }
                int strongestIdx = findStrongest(potionPowers, currentPotionsCount);
                printf("\n⭐ Najsilniejsza mikstura to Mikstura %d:\n", strongestIdx);
                printf("   Moc: **%.2f** | Zanieczyszczenia: %d\n",
                       potionPowers[strongestIdx], potionImpurities[strongestIdx]);
                break;
            }

            case 4: { // Wzmocnić wszystkie mikstury
                if (currentPotionsCount == 0) {
                    printf("\n⚠️ Brak mikstur do wzmocnienia.\n");
                    break;
                }
                strengthenAll(potionPowers, currentPotionsCount);
                printf("\n⚡ **Wszystkie** %d mikstury zostały wzmocnione o 10%%!\n", currentPotionsCount);
                break;
            }

            case 5: { // Ustabilizować wybraną miksturę
                if (currentPotionsCount == 0) {
                    printf("\n⚠️ Brak mikstur do stabilizacji.\n");
                    break;
                }
                int idx = getValidatedInt("Podaj indeks (numer) mikstury do stabilizacji (0 do %d): ", 0, currentPotionsCount - 1);

                printf("\n⚖️ Próba stabilizacji Mikstury %d...\n", idx);
                stabilizePotion(&potionPowers[idx]);
                printf("   Nowa moc Mikstury %d: %.2f\n", idx, potionPowers[idx]);
                break;
            }

            case 6: { // Oczyścić miksturę z zanieczyszczeń
                if (currentPotionsCount == 0) {
                    printf("\n⚠️ Brak mikstur do oczyszczenia.\n");
                    break;
                }
                int idx = getValidatedInt("Podaj indeks (numer) mikstury do oczyszczenia (0 do %d): ", 0, currentPotionsCount - 1);

                printf("\n✨ Próba oczyszczenia Mikstury %d...\n", idx);
                purifyPotion(&potionPowers[idx], &potionImpurities[idx]);
                printf("   Nowa moc: %.2f | Nowe zanieczyszczenia: %d\n",
                       potionPowers[idx], potionImpurities[idx]);
                break;
            }

            case 7: { // Zakończ działanie programu
                printf("\n🚪 Działanie programu zakończone. Mistrz Gedeon Szkarłatny dziękuje za służbę!\n");
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
}