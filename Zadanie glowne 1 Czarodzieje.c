#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
    srand(time(NULL));
    int a;
    printf("Podaj 1 jak chcesz KULA OGNIA\n");
    printf("Podaj 2 jak chcesz LODOWA STRZALA\n");
    printf("Podaj 3 jak chcesz  BLYSKAWICA\n");
    printf("Podaj numer zaklecia\n");
    scanf("%d",&a);
    int czarodziej=rand()%3+1;


    if (a==1) {
        printf("Ty uzyles Kula ognia\n");
    }else if (a==2) {
        printf("Ty uzyles Lodowa strzala\n");
    }else {
        printf("Ty uzyles Blyskawica\n");
    }
    if (czarodziej==1) {
        printf("Czarodziej uzyl Kula ognia\n");
    }else if (czarodziej==2) {
        printf("Czarodziej uzyl Lodowa strzala\n");
    }else {
        printf("Czarodziej uzyl Blyskawica\n");
    }

    if (czarodziej==a){
        printf("Remis nikt nie wygral");
    }else if ((czarodziej==1&&a==2)||(czarodziej==3&&a==1)||(czarodziej==2&&a==3)) {
        printf("Czarodziej wygral");
    }else {
        printf("Ty wygrales");
    }
    return 0;
}


