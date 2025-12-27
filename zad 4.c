 dodaj_miksture(nazwa)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Potion {
     char name[MAX_NAME_LENGTH];
     int power;
     char type[MAX_NAME_LENGTH];
     struct Potion *next;
 } Potion;

Potion *collection = NULL;

void addPotion(const char *pName, int pPower, const char *pType) {
    Potion *newPotion = (Potion *)malloc(sizeof(Potion));
    if (newPotion == NULL) {
        printf("Błąd alokacji pamięci.\n");
        return;
    }

    strncpy(newPotion->name, pName, MAX_NAME_LENGTH - 1);
    newPotion->name[MAX_NAME_LENGTH - 1] = '\0';
    newPotion->power = pPower;
    strncpy(newPotion->type, pType, MAX_NAME_LENGTH - 1);
    newPotion->type[MAX_NAME_LENGTH - 1] = '\0';
    newPotion->next = NULL;

    if (collection == NULL) {
        collection = newPotion;
    } else {
        Potion *current = collection;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPotion;
    }
}

void displayCollection() {
    Potion *current = collection;
    if (current == NULL) {
        printf("Kolekcja jest pusta.\n");
        return;
    }
    printf("--- Kolekcja Mikstur ---\n");
    while (current != NULL) {
        printf("Nazwa: %s, Moc: %d, Typ: %s\n", current->name, current->power, current->type);
        current = current->next;
    }
    printf("------------------------\n");
}

int main() {
    addPotion("Eliksir Siły", 50, "Wzmocnienie");
    addPotion("Wywar Uzdrowienia", 100, "Leczenie");
    addPotion("Serum Niewidzialności", 10, "Iluzja");

    displayCollection();

    Potion *current = collection;
    Potion *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    collection = NULL;

    return 0;
}