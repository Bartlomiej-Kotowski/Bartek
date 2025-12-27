#include <stdio.h>
#include <stdlib.h> // Do funkcji system("cls") lub system("clear")
#include <limits.h>

// Stałe programu
#define MAX_SENSORS 10             // Maksymalna liczba czujników
#define SENSOR_READ_MIN -100.0     // Minimalna dopuszczalna wartość odczytu
#define SENSOR_READ_MAX 200.0      // Maksymalna dopuszczalna wartość odczytu
#define FAULT_MIN_ALLOWED -50.0    // Minimalna wartość dla wykrywania błędu
#define FAULT_MAX_ALLOWED 150.0    // Maksymalna wartość dla wykrywania błędu

// Deklaracje funkcji
void showIntro();
int showMenu();
void readSensors(double sensors[], int n);
void displaySensors(double sensors[], int n);
void calibrateSensors(double sensors[], int n, double offset);
int findFaultySensor(double sensors[], int n, double minAllowed, double maxAllowed);
void modifySensor(double sensors[], int n, int index);
int readValue(double *value, double min, double max);

// Główna funkcja programu
int main() {
    double sensors[MAX_SENSORS] = {0.0}; // Tablica na odczyty z czujników
    int num_sensors = 5;                 // Liczba aktywnych czujników
    int choice;
    double offset;
    int faulty_index;

    // Początkowe powitanie
    showIntro();

    do {
        // Wyświetlenie menu i pobranie wyboru
        choice = showMenu();

        // System("cls") lub system("clear") dla przejrzystości menu
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch (choice) {
            case 1:
                printf("\n--- Wczytywanie Danych z Czujników ---\n");
                readSensors(sensors, num_sensors);
                break;
            case 2:
                printf("\n--- Bieżące Odczyty Czujników ---\n");
                displaySensors(sensors, num_sensors);
                break;
            case 3:
                printf("\n--- Kalibracja Czujników ---\n");
                printf("Podaj wartość przesunięcia (offset) dla kalibracji (np. od -10.0 do 10.0): ");
                // Użycie readValue do pobrania wartości offset z walidacją
                if (readValue(&offset, -10.0, 10.0)) {
                    calibrateSensors(sensors, num_sensors, offset);
                    printf("✅ Kalibracja zakończona! Wartość przesunięcia: %.2lf\n", offset);
                    displaySensors(sensors, num_sensors);
                } else {
                    printf("❌ Błąd: Wprowadzono niepoprawną wartość offset.\n");
                }
                break;
            case 4:
                printf("\n--- Wykrywanie i Naprawa Błędnych Odczytów ---\n");
                printf("Dopuszczalny zakres pomiarowy: <%.2lf, %.2lf)\n", FAULT_MIN_ALLOWED, FAULT_MAX_ALLOWED);
                faulty_index = findFaultySensor(sensors, num_sensors, FAULT_MIN_ALLOWED, FAULT_MAX_ALLOWED);

                if (faulty_index != -1) {
                    printf("⚠️ Wykryto błędny odczyt w Czujniku %d (Indeks: %d). Bieżąca wartość: %.2lf\n",
                           faulty_index + 1, faulty_index, sensors[faulty_index]);

                    // Automatyczna 'naprawa' - prośba o nową wartość
                    modifySensor(sensors, num_sensors, faulty_index);
                } else {
                    printf("✅ Wszystkie odczyty czujników są w dopuszczalnym zakresie.\n");
                }
                break;
            case 5: {
                printf("\n--- Modyfikacja Pojedynczego Odczytu ---\n");
                int index_to_modify = -1;
                printf("Podaj numer czujnika do modyfikacji (1 do %d): ", num_sensors);

                // Prosty odczyt numeru czujnika (nie indeksu)
                if (scanf("%d", &index_to_modify) == 1 && index_to_modify >= 1 && index_to_modify <= num_sensors) {
                    // Konwersja numeru czujnika na indeks tablicy
                    modifySensor(sensors, num_sensors, index_to_modify - 1);
                } else {
                    printf("❌ Błąd: Niepoprawny numer czujnika.\n");
                    // Oczyszczenie bufora wejściowego
                    while(getchar() != '\n');
                }
                break;
            }
            case 6:
                printf("\n--- Zakończenie Działania Programu ---\n");
                printf("Dziękujemy za skorzystanie z systemu diagnostycznego Orion One.\n");
                break;
            default:
                printf("\n❌ Nieznany błąd wyboru menu.\n");
                break;
        }

        if (choice != 6) {
            printf("\nNaciśnij ENTER, aby kontynuować...\n");
            // Oczyszczenie bufora wejściowego i oczekiwanie na ENTER
            while(getchar() != '\n');
            getchar();
        }

    } while (choice != 6);

    return 0;
}

/**
 * @brief Wyświetla powitanie, nazwę statku i autora programu.
 */
void showIntro() {
    printf("==========================================\n");
    printf("     SYSTEM DIAGNOSTYCZNY ORION ONE 🛰️\n");
    printf("==========================================\n");
    printf("Misja: Badanie odległego układu planetarnego\n");
    printf("Autor programu: Gemini (AI)\n");
    printf("------------------------------------------\n");
}

/**
 * @brief Wyświetla menu główne programu, pobiera wybór użytkownika i zwraca jego numer.
 * Sprawdza poprawność danych wejściowych.
 * @return Numer wybranej opcji (1-6).
 */
int showMenu() {
    int choice = 0;
    printf("\n--- MENU GŁÓWNE ---\n");
    printf("1. Wczytaj dane z czujników\n");
    printf("2. Wyświetl odczyty\n");
    printf("3. Przeprowadź kalibrację\n");
    printf("4. Napraw błędne odczyty (Wykryj i Modyfikuj)\n");
    printf("5. Modyfikuj pojedynczy odczyt\n");
    printf("6. Zakończ działanie programu\n");
    printf("Wybierz opcję (1-6): ");

    // Pętla do walidacji wyboru
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
        printf("❌ Niepoprawny wybór. Wprowadź liczbę od 1 do 6: ");
        // Oczyszczenie bufora wejściowego
        while(getchar() != '\n');
    }
    // Oczyszczenie bufora wejściowego po poprawnym odczycie
    while(getchar() != '\n');

    return choice;
}

/**
 * @brief Wczytuje pojedynczą wartość typu double przez wskaźnik.
 * Sprawdza, czy wprowadzona liczba mieści się w zakresie <min, max>.
 * @param value Wskaźnik, pod który zostanie zapisana wczytana wartość.
 * @param min Minimalna dopuszczalna wartość.
 * @param max Maksymalna dopuszczalna wartość.
 * @return 1 w przypadku poprawnego odczytu i walidacji, 0 w przypadku błędu.
 */
int readValue(double *value, double min, double max) {
    if (scanf("%lf", value) != 1) {
        // Błąd odczytu typu danych
        printf("❌ Błąd odczytu: Wprowadzona wartość nie jest liczbą.\n");
        // Oczyszczenie bufora wejściowego
        while(getchar() != '\n');
        return 0;
    }

    if (*value < min || *value > max) {
        // Błąd walidacji zakresu
        printf("❌ Błąd walidacji: Wartość %.2lf jest poza dopuszczalnym zakresem <%.2lf, %.2lf>.\n", *value, min, max);
        // Oczyszczenie bufora wejściowego
        while(getchar() != '\n');
        return 0;
    }

    // Oczyszczenie bufora wejściowego po poprawnym odczycie
    while(getchar() != '\n');

    return 1; // Sukces
}

/**
 * @brief Wczytuje dane z czujników, prosząc użytkownika o n wartości.
 * Każdy odczyt jest sprawdzany pod względem poprawności.
 * @param sensors Tablica na odczyty.
 * @param n Liczba czujników do odczytania.
 */
void readSensors(double sensors[], int n) {
    printf("Zakres dla wprowadzanych odczytów: <%.2lf, %.2lf>\n", SENSOR_READ_MIN, SENSOR_READ_MAX);
    for (int i = 0; i < n; i++) {
        double temp_value;
        printf("Wprowadź odczyt dla Czujnika %d: ", i + 1);
        // Pętla do momentu poprawnego odczytu i walidacji
        while (!readValue(&temp_value, SENSOR_READ_MIN, SENSOR_READ_MAX)) {
            printf("Spróbuj ponownie. Wprowadź odczyt dla Czujnika %d: ", i + 1);
        }
        sensors[i] = temp_value;
    }
    printf("✅ Wczytano wszystkie dane z czujników.\n");
}

/**
 * @brief Wyświetla bieżące dane pomiarowe w czytelnej formie.
 * @param sensors Tablica z odczytami.
 * @param n Liczba czujników.
 */
void displaySensors(double sensors[], int n) {
    if (n <= 0) {
        printf("Brak aktywnych czujników do wyświetlenia.\n");
        return;
    }
    printf("\n| Czujnik | Indeks | Wartość |\n");
    printf("|---------|--------|---------|\n");
    for (int i = 0; i < n; i++) {
        printf("| %-7d | %-6d | %7.2lf |\n", i + 1, i, sensors[i]);
    }
    printf("--------------------------------\n");
}

/**
 * @brief Dodaje do każdego odczytu wartość offset, aby zasymulować kalibrację.
 * @param sensors Tablica z odczytami.
 * @param n Liczba czujników.
 * @param offset Wartość przesunięcia kalibracji.
 */
void calibrateSensors(double sensors[], int n, double offset) {
    for (int i = 0; i < n; i++) {
        sensors[i] += offset;
    }
}

/**
 * @brief Wyszukuje pierwszy czujnik, którego odczyt wychodzi poza dopuszczalny zakres <minAllowed, maxAllowed).
 * @param sensors Tablica z odczytami.
 * @param n Liczba czujników.
 * @param minAllowed Minimalna dopuszczalna wartość.
 * @param maxAllowed Maksymalna dopuszczalna wartość (wykluczająca).
 * @return Indeks pierwszego błędnego czujnika lub -1, jeśli wszystkie są poprawne.
 */
int findFaultySensor(double sensors[], int n, double minAllowed, double maxAllowed) {
    for (int i = 0; i < n; i++) {
        // Sprawdzenie, czy odczyt jest poza zakresem <minAllowed, maxAllowed)
        if (sensors[i] < minAllowed || sensors[i] >= maxAllowed) {
            return i; // Zwraca indeks pierwszego błędnego czujnika
        }
    }
    return -1; // Wszystkie czujniki są poprawne
}

/**
 * @brief Pozwala ręcznie zmienić odczyt wybranego czujnika.
 * @param sensors Tablica z odczytami.
 * @param n Liczba czujników.
 * @param index Indeks czujnika do modyfikacji.
 */
void modifySensor(double sensors[], int n, int index) {
    if (index < 0 || index >= n) {
        printf("❌ Błąd: Nieprawidłowy indeks czujnika (%d).\n", index);
        return;
    }

    double new_value;
    printf("\n--- Modyfikacja Czujnika %d (Indeks: %d) ---\n", index + 1, index);
    printf("Bieżąca wartość: %.2lf\n", sensors[index]);
    printf("Podaj nową wartość (zakres <%.2lf, %.2lf>): ", SENSOR_READ_MIN, SENSOR_READ_MAX);

    // Walidacja nowej wartości
    if (readValue(&new_value, SENSOR_READ_MIN, SENSOR_READ_MAX)) {
        sensors[index] = new_value;
        printf("✅ Odczyt Czujnika %d zmieniono na: %.2lf\n", index + 1, new_value);
    } else {
        printf("❌ Modyfikacja anulowana z powodu niepoprawnej wartości.\n");
    }
}