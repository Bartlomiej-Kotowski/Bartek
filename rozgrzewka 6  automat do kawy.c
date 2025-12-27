#include <stdio.h>
#include <stdbool.h>

enum MachineState {
    IDLE,
    ACCEPTING,
    BREWING,
    ERROR
};

void printState(enum MachineState state) {
    printf(">> Stan: ");
    switch (state) {
        case IDLE:
            printf("IDLE\n");
            break;
        case ACCEPTING:
            printf("ACCEPTING\n");
            break;
        case BREWING:
            printf("BREWING\n");
            break;
        case ERROR:
            printf("ERROR\n");
            break;
    }
}

int main() {
    enum MachineState state = IDLE;
    int waterLevel = 5;
    int choice;

    while (true) {
        printf("=== AUTOMAT DO KAWY ===\n");
        printState(state);
        printf("1. Wloz monete\n");
        printf("2. Wybierz kawe\n");
        printf("3. Uzupelnij wode\n");
        printf("4. Reset bledu\n");
        printf("0. Zakoncz program\n");
        printf("Wybierz akcje: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice) {
            case 1:
                if (state == IDLE) {
                    state = ACCEPTING;
                } else if (state != ERROR) {
                    printf("Nie mozna wlozyc monety w tym stanie.\n");
                }
                break;
            case 2:
                if (state == ACCEPTING) {
                    if (waterLevel > 0) {
                        state = BREWING;
                        printf("Parzenie kawy...\n");
                        waterLevel--;
                        state = IDLE;
                        if (waterLevel == 0) {
                            state = ERROR;
                            printf("Brak wody! Przejscie do stanu ERROR.\n");
                        }
                    } else {
                        state = ERROR;
                        printf("Brak wody! Przejscie do stanu ERROR.\n");
                    }
                } else if (state != ERROR) {
                    printf("Najpierw wloz monete (Stan: IDLE) lub czekaj na koniec parzenia (Stan: BREWING).\n");
                }
                break;
            case 3:
                if (state != ERROR) {
                    waterLevel = 5;
                    printf("Woda uzupelniona. Aktualny poziom: %d.\n", waterLevel);
                } else {
                    printf("Nie mozna uzupelnic wody w stanie ERROR.\n");
                }
                break;
            case 4:
                if (state == ERROR) {
                    waterLevel = 5;
                    state = IDLE;
                    printf("Reset bledu wykonany. Poziom wody przywrocony. Powrot do stanu IDLE.\n");
                } else {
                    printf("Reset bledu mozliwy tylko w stanie ERROR.\n");
                }
                break;
            case 0:
                printf("Wylaczanie automatu.\n");
                return 0;
            default:
                printf("Niepoprawna akcja.\n");
        }
        printf("------------------------\n");
    }

    return 0;
}