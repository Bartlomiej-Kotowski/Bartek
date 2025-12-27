#include  <stdio.h>
#include  <math.h>
//zad1
// int main() {
//     int a, b;
//     printf("Podaj pierwszy i drugi numer : \n");
//     scanf("%d %d", &a, &b);
//     printf("Suma to %d + %d = %d, Srednia to : %d", a, b, a + b, (a + b)/2);
//     return 0;
// }

//zad2
// int main() {
//     int a,b;
//     printf("podaj dwie liczby:\n");
//     scanf("%d %d",&a,&b);
//     if(a%2==0 && b%2==0) {
//         printf("obydwa");
//     }else {
//         printf("nie obydwa");
//     }
//     return 0;
// }

//zad3
// int main() {
//     int a;
//     scanf("%d",&a);
//     if (a%4==0&&a%100!=0) {
//         printf("rokiem przestempnym jest %d",a);
//     }else {
//         printf("rokiem przestempnym nie jest %d",a);
//     }
//     return 0;
// }
#include <stdlib.h>
#include <time.h>
// //zad4
// int main() {
//     srand(time(NULL));
//     int a;
//     int min=1;
//     scanf("%d",&a);
//     int max=a;
//     int wylosowana_liczba =rand()%(max-min+1)+min;
//     printf("wylosowana liczba to %d ",wylosowana_liczba);
//     return 0;
// }

























int main() {
    int t,x;
    int numbers[t], i;
    scanf("%d",&t);
    for (i = 0; i < t; i++) {
        while(i<=13){
            printf("Podaj Ocene %d: ", i + 1);
            scanf("%d", &x);
            if (x>=2&&x<=5);
                numbers[i] = x;
            }else{
                i=i-1;
            }
        }
    }
    printf("Oceny: ");
    for (i = 0; i < t; i++) {
        printf("%3d ", numbers[i]);
    }
    return 0;
}


























