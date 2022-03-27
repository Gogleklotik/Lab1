#include "menu.h"


int menu_type(){
    int Opt1;
    printf("\nselect your data type\n");
    printf("1.int\n");
    printf("2.float\n");
    scanf("%d", &Opt1);
    if(Opt1 > 2 || Opt1 < 1)
            do{
                printf("\nselect your data type\n");
                printf("1.int\n");
                printf("2.float\n");
                scanf("%d", &Opt1);
            }
            while(Opt1 > 2 || Opt1 < 1);
    return Opt1;
}


int menu_op(){
    int Opt2;
    printf("select the operation\n");
    printf("1.vector addition\n");
    printf("2.scalar multiplication\n");
    scanf("%d", &Opt2);
    if(Opt2 > 2 || Opt2 < 1)
            do{
                printf("select the operation\n");
                printf("1.vector addition\n");
                printf("2.scalar multiplication\n");
                scanf("%d", &Opt2);
            }
            while(Opt2 > 2 || Opt2 < 1);
    return Opt2;

}
