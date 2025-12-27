#include <stdio.h>
#include <string.h>

struct book {
    char author[32], title[64];
    int copies;
    float price;
};

struct book getBookData() {
    struct book newBook;

    printf("Podaj Imię i Nazwisko Autora: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    printf("Podaj Tytuł Księgi: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

    printf("Podaj Liczbę Egzemplarzy: ");
    scanf("%d", &newBook.copies);
    while (getchar() != '\n');

    printf("Podaj Cenę Egzemplarza (w zł/koronach): ");
    scanf("%f", &newBook.price);
    while (getchar() != '\n');

    return newBook;
}

void printBookData(struct book b) {
    printf("Author:             %s\n", b.author);
    printf("Title:              %s\n", b.title);
    printf("No of copies:       %d\n", b.copies);
    printf("Price:              %.2f zk\n", b.price);
}

int main() {
    struct book magicTome;

    printf("--- Wczytywanie Danych Księgi ---\n");
    magicTome = getBookData();

    printf("\n--- Katalog Biblioteczny ---\n");
    printBookData(magicTome);
    printf("----------------------------\n");

    return 0;
}