#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word1[129];
    char word2[129];
    int c;
    int czy=0;
    int terminal=0;
    printf("Podaj pierszy wyraz: ");
    if (scanf("%128[^\n]", word1)!=1) {
        return 1;
    }
    while ((c=getchar()) != '\n' && c!=EOF) {
        czy=1;
    }

    printf("Podaj drugi wyraz: ");
    if (scanf("%128[^\n]", word2) != 1) {
    }
    while ((c=getchar()) != '\n' && c!=EOF) {
        czy=1;
    }

    if (czy==1) {
        printf("za długie hasła\n");

    }else while(1) {
        printf("=== TERMINAL ORION ONE ===\n");
        printf("1. Wyświetl długość obu wiadomości\n");
        printf("2. Porównaj wiadomości\n");
        printf("3. Połącz wiadomości\n");
        printf("4. Szyfruj wiadomość 1 (ROT13)\n");
        printf("5. Odwróć wiadomość 1\n");
        printf("0. Zakończ transmisję\n");
        printf("Wybierz opcję: ");
        scanf("%d", &terminal);
        switch (terminal) {
            case 1:
                int a = strlen(word1);
                int b = strlen(word2);
                printf("\nWyraz 1 ma długość %d: \n",a);
                printf("\nWyraz 2 ma długość %d: \n",b);
                continue;
            case 2:
                char w1;
                char w2;
                for (int i=0;i<strlen(word1);i++) {
                    w1=toupper(word1[i]);
                }
                for (int j=0;j<strlen(word2);j++) {
                    w2=toupper(word2[j]);
                }

                if (w1==w2) {
                    printf("Są takie same\n");
                }else {
                    printf("Nie są podobne\n");
                }
                continue;
            case 3:
                int liczba;
                printf("1---połącz 1+2\n");
                printf("2---połącz 2+1\n");
                printf("3---połącz ze spacją 1+2\n");
                printf("4---połącz ze spacją 2+1\n");
                scanf("%d",&liczba);
                printf("wybierz jak chcesz połączyć\n");
                switch (liczba) {
                    case 1:
                        printf("%s%s\n",word1,word2);
                        continue;
                    case 2:
                        printf("%s%s\n",word2,word1);
                        continue;
                    case 3:
                        printf("%s %s\n",word1,word2);
                        continue;
                    case 4:
                        printf("%s %s\n",word2,word1);
                        continue;
                    default:
                        printf("Podałeś złą komendę w terminalu\n");
                        continue;
                }
            case 4:
                char www1[129];
                for (int i=0;i<strlen(word1);i++) {
                    if (word1[i]>='A' && word1[i]<='Z') {
                        www1[i]=((word1[i]-'A'+13)%26)+'A';
                    }else if (word1[i]>='a' && word1[i]<='z') {
                        www1[i]=((word1[i]-'a'+13)%26)+'a';
                    }else {
                        www1[i]=word1[i];
                    }
                }
                www1[strlen(word1)] = '\0';
                printf("%s\n",www1);
                strcpy(word1,www1);
                continue;
            case 5:
                char odw[129];
                int len=strlen(word1);
                for (int i=0;i<strlen(word1);i++) {
                    odw[i]=word1[len-i-1];
                    }
                odw[len]='\0';
                printf("%s\n",odw);
                continue;
            case 0:
                return 0;
            default:
                printf("Nie ma takiej komendy podaj odpowiedni numer\n");
                while (c=getchar()!='\n' && c!=EOF);
                break;
        }

    }
    return 0;
}