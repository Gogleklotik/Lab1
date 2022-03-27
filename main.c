#include <stdio.h>
#include "Header.h"
#include "menu.h"
#include "all.h"

int main(){
    int test_choice;
    printf("Test?\n1.Yes\n2.No\n");
     scanf("%d", &test_choice);
     if(test_choice == 1){
         test();
     }
     else if(test_choice < 1 || test_choice > 2)
         do{
             printf("ERROR\nDo you want to run a Test?\n1.Yes\n2.No\n");
             scanf("%d", &test_choice);
         }while(test_choice < 1 || test_choice > 2);
    
    int i;
    double d;
    vector* vect1 = NULL;
    vector* vect2 = NULL;
    vector* vect3 = NULL;
    int menu1 = menu_type();
    int menu2 = menu_op();
    switch(menu2){
        case 1:
            vect1 = (vector*)create();
            vect2 = (vector*)create();
            vect3 = (vector*)create();
            vect1 = (vector*)fill(vect1, menu1);
            vect2 = (vector*)fill(vect2, menu1);
            print(vect1, menu1);
            printf("+");
            print(vect2, menu1);
            printf("=");
            vect3 = (vector*)sum(vect1, vect2, vect3, menu1);
            print(vect3, menu1);
            printf("\n");
            break;
        case 2:
            vect1 = (vector*)create();
            vect2 = (vector*)create();
            vect1 = (vector*)fill(vect1, menu1);
            vect2 = (vector*)fill(vect2, menu1);
            switch(menu1){
                case 1:
                    i = *(int*)scalprois(vect1, vect2, menu1);
                    break;
                case 2:
                    d = *(double*)scalprois(vect1, vect2, menu1);
                    break;
            }
            printf("(");
            print(vect1,menu1);
            printf(";");
            print(vect2, menu1);
            printf(")");
            printf("=");
            switch(menu1){
                case 1:
                    printf("%d", i);
                    break;
                case 2:
                    printf("%lf", d);
                    break;
            }
            printf("\n");
            break;
    }
    return 0;
}
