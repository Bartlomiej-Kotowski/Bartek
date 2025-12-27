#include <stdio.h>
int main() {
    int key,x=50,d=0,o=0,system,c,max=1000;
    for (int i = 1; i < 4; i++) {
        printf("Enter the captain's number code:\n");
        scanf("%d",&key);
        if (key==1234) {
            d=1;
            break;
        }
        printf("%d attempts left: \n", 3-i);
        o++;
        if (o==3) {
            printf("---You don't have access---\n");
        }
    }
    if (d==1) {
        printf("1 - Charge the reactor core: \n");
        printf("2 - Discharge the reactor core: \n");
        printf("3 - Check energy level: \n");
        printf("0 - Log out: \n");
        scanf("%d",&system);
        while (system!=0) {
            switch (system) {
                case 1:
                    printf("Increase number of engine power: \n");
                    if (scanf("%d",&d)==1) {
                        x=x+d;
                        if (x>max) {
                            printf("---The operation failed---\n");
                            x=x-d;
                        }else {
                            printf("---The operation was successful---\n");
                        }
                    }else {
                        printf("---The operation failed--- \n");
                    }
                    break;
                case 2:
                    printf("Reduce the amount of fuel: \n");
                    if (scanf("%d",&d)==1) {
                        if (d>x) {
                            printf("---The operation failed---\n");
                        }else if (d<0) {
                            printf("---The number is negative---\n");
                        }else
                            x=x-d;
                            printf("---The operation was successful---\n");
                    }
                    break;
                case 3:
                    printf("Fuel level: %d \n",x);
                    printf("---The operation was successful---\n");
                    break;
                default:
                    break;
            }

            printf("1 - Charge the reactor core: \n");
            printf("2 - Discharge the reactor core: \n");
            printf("3 - Check energy level: \n");
            printf("0 - Log out: \n");
            printf("Enter number:\n");
            while ((c = getchar()) != '\n' && c != EOF) {

            }
            if (scanf("%d",&system)==0) {
                printf("---The operation failed---\n");
            }
        }
    }else {
        return 0;
    }
    return 0;
}
