//
// Created by kotek on 18.12.2025.
//

// Napisz program, który poprosi użytkownika o dwie liczby całkowite. Następnie obliczy ich sumę i średnią arytmetyczną i poda wynik na ekranie.
// Napisz program, który sprawdzi, czy dwie liczby podane przez użytkownika są parzyste, nieparzyste, czy też jedna z nich jest parzysta, a druga nie. Komputer powinien na końcu wyświetlić odpowiedni komunikat, np. „Obie liczby są parzyste” albo „Jedna parzysta, druga nie”.
// Napisz program, który wczyta liczbę całkowitą oznaczającą rok. Następnie sprawdzi, czy ten rok jest przestępny, czy nie, i poda odpowiednią informację.
// Napisz program, który symuluje rzut kostką o dowolnej liczbie ścian. Najpierw użytkownik podaje, ile ścian ma mieć kostka (np. 4, 6, 10, 20…), a następnie komputer losuje wynik od 1 do podanej liczby i wyświetla go na ekranie.
#include <stdio.h>

int zad1suma (int a,int b) {
    return a+b;
}
int zad1srednia (int a,int b) {
    return a+b/2;
}
void zad2parzysta(int a,int b) {
    if (a%2==0) {
        if (b%2==0) {
            printf("Parzyste oba");
        }else {
            printf("jedna parzysta druga nie parzysta");
        }
    }else{
        if (b%2==0) {
            printf("jedna parzysta druga nie parzysta");

        }else {
            printf("oba nieparzysta");
        }

    }
}
void zad3rok(int a) {
    if (a%4==0 && a%100!=0 || a%400==0) {
        printf("jest przestępny");
    }else {
        printf("nie jeste przestępny");
    }
}


int main() {
    int a,b,suma,c;
    float srednia;
    printf("podaj dwie liczby\n");
    scanf("%d %d",&a,&b);
    printf("podaj liczbę scian\n");
    scanf("%d",&c);
    srand(time(null))
    suma=zad1suma(a,b);
    srednia=zad1srednia(a,b);
    printf("%d\n",suma);
    printf("%.2f\n",srednia);
    zad2parzysta(a, b);
    printf("\n");
    zad3rok(a);
    return 0;




