#include "all.h"
#include "Header.h"
#include <time.h>
#include <stdio.h>



void* create(){
    vector *vect = calloc(1, sizeof(vector));
    return vect;
}

void *fill(void*v, int type){
    vector*vect = (vector*)v;
    switch(type){
        case 1:
            printf("enter your x:\n");
            scanf("%d", (int*)&vect->x);
            printf("enter your y:\n");
            scanf("%d", (int*)&vect->y);
            break;
        case 2:
            printf("enter your x:\n");
            scanf("%lf", (double*)&vect->x);
            printf("enter your y:\n");
            scanf("%lf", (double*)&vect->y);
            break;
    }
    return vect;
    
}

void print(void*v, int type){
    vector*vect = (vector*)v;
    switch(type){
        case 1:
            printf("(%d,%d)", *((int*)&vect->x), *((int*)&vect->y));
            break;
        case 2:
            printf("(%lf,%lf)", *((double*)&vect->x), *((double*)&vect->y));
            break;
    }
    
}

void* sum(void*v1, void*v2, void*v3, int type){
    vector*vect1 = (vector*)v1;
    vector*vect2 = (vector*)v2;
    vector*vect3 = (vector*)v3;
    switch(type){
        case 1:
            *((int*)&vect3->x) = *((int*)&vect1->x) + *((int*)&vect2->x);
            *((int*)&vect3->y) = *((int*)&vect1->y) + *((int*)&vect2->y);
            break;
        case 2:
            *((double*)&vect3->x) = *((double*)&vect1->x) + *((double*)&vect2->x);
            *((double*)&vect3->y) = *((double*)&vect1->y) + *((double*)&vect2->y);
            break;
            
    }
    return vect3;
}

void *scalprois(void*v1, void*v2, int type){
    vector*vect1 = (vector*)v1;
    vector*vect2 = (vector*)v2;
    void *q;
    int p;
    double t;
    switch(type){
        case 1:
            p = *((int*)&vect1->x) * (*((int*)&vect2->x)) + *((int*)&vect1->y) * (*((int*)&vect2->y));
            q = &p;
            break;
        case 2:
            t = *((double*)&vect1->x) * (*((double*)&vect2->x)) + *((double*)&vect1->y) * (*((double*)&vect2->y));
            q = &t;
            break;
    }
    return q;
}

int test_sum(void*v1, void *v2, void *v3, int k){
    vector*vect1 = (vector*)v1;
    vector*vect2 = (vector*)v2;
    vector*vect3 = (vector*)v3;
    switch(k){
        case 1:
            if( (*((int*)&vect1->x) + *((int*)&vect2->x))!= *((int*)&vect3->x) || (*((int*)&vect1->y) + *((int*)&vect2->y))!= *((int*)&vect3->y))
                return 1;
            break;
        case 2:
            if( (*((double*)&vect1->x) + *((double*)&vect2->x))!= *((double*)&vect3->x) || (*((double*)&vect1->y) + *((double*)&vect2->y))!= *((double*)&vect3->y))
                return 1;
            break;
    
        
    }
    return 0;
}

int test_scal(void*v1, void *v2, void*p, int k){
    vector*vect1 = (vector*)v1;
    vector*vect2 = (vector*)v2;
    switch(k){
        case 1:
            if((*((int*)&vect1->x) * (*((int*)&vect2->x)) + *((int*)&vect1->y) * (*((int*)&vect2->y)))!= *(int*)p)
                return 1;
            break;
        case 2:
            if((*((double *)&vect1->x) * (*((double*)&vect2->x)) + *((double*)&vect1->y) * (*((double*)&vect2->y)))!= *(int*)p)
                return 1;
            break;
    }
    return 0;
}


void test(){
    srand(time(NULL));
    int in;
    double d;
    int max = 10;
    int min = -10;
    vector*vect1 = NULL;
    vector *vect2 = NULL;
    vector *vect3 = NULL;
    for(int i=0; i<10; i++){
        vect1=(vector*)create();
        *((int*)&vect1->x)= rand()%(max-min+1)+min;
        *((int*)&vect1->y) = rand()%(max-min+1)+min;
        vect2=(vector*)create();
        *((int*)&vect2->x)= rand()%(max-min+1)+min;
        *((int*)&vect2->y) = rand()%(max-min+1)+min;
        vect3 =(vector*)create();
        vect3 = (vector*)sum(vect1, vect2, vect3, 1);
        if(test_sum(vect1, vect2, vect3, 1) == 1){
            printf("\nerror sum int\n");
        print(vect1, 1);
        printf("+");
        print(vect2, 1);
        printf("!=");
        vect3 = (vector*)sum(vect1, vect2, vect3, 1);
        print(vect3, 1);
        printf("\n");
        }
        else{
            printf("\nsuccess sum int\n");
            print(vect1, 1);
            printf("+");
            print(vect2, 1);
            printf("==");
            vect3 = (vector*)sum(vect1, vect2, vect3, 1);
            print(vect3, 1);
            printf("\n");
        }
        
        vect1=(vector*)create();
        *((double*)&vect1->x)= ((double)rand())/RAND_MAX * (max-min) + min;
        *((double*)&vect1->y) = ((double)rand())/RAND_MAX * (max-min) + min;
        vect2=(vector*)create();
        *((double*)&vect2->x)= ((double)rand())/RAND_MAX * (max-min) + min;
        *((double*)&vect2->y) = ((double)rand())/RAND_MAX * (max-min) + min;
        vect3 =(vector*)create();
        vect3 = (vector*)sum(vect1, vect2, vect3, 2);
        if(test_sum(vect1, vect2, vect3, 2) == 1){
            printf("\nerror sum int\n");
        print(vect1, 2);
        printf("+");
        print(vect2, 2);
        printf("!=");
        vect3 = (vector*)sum(vect1, vect2, vect3, 2);
        print(vect3, 2);
        printf("\n");
        }
        else{
            printf("\nsuccess sum double\n");
            print(vect1, 2);
            printf("+");
            print(vect2, 2);
            printf("==");
            vect3 = (vector*)sum(vect1, vect2, vect3, 2);
            print(vect3, 2);
            printf("\n");
        }
        
        vect1=(vector*)create();
        *((int*)&vect1->x)= rand()%(max-min+1)+min;
        *((int*)&vect1->y) = rand()%(max-min+1)+min;
        vect2=(vector*)create();
        *((int*)&vect2->x)= rand()%(max-min+1)+min;
        *((int*)&vect2->y) = rand()%(max-min+1)+min;
        in = *(int*)scalprois(vect1, vect2, 1);
        if(test_scal(vect1, vect2, &in, 1) == 1){
            printf("\nerror int scalar multiplication\n");
            printf("(");
            print(vect1, 1);
            printf(";");
            print(vect2, 1);
            printf(")");
            printf("!=");
            printf("%d", in);
        }
        else{
            printf("\nsuccess int scalar multiplication\n");
            printf("(");
            print(vect1, 1);
            printf(";");
            print(vect2, 1);
            printf(")");
            printf("==");
            printf("%d\n", in);
        }
        vect1=(vector*)create();
        *((double*)&vect1->x)= ((double)rand())/RAND_MAX * (max-min) + min;
        *((double*)&vect1->y) = ((double)rand())/RAND_MAX * (max-min) + min;
        vect2=(vector*)create();
        *((double*)&vect2->x)= ((double)rand())/RAND_MAX * (max-min) + min;
        *((double*)&vect2->y) = ((double)rand())/RAND_MAX * (max-min) + min;
        d = *(double*)scalprois(vect1, vect2, 2);
        if(test_scal(vect1, vect2, &d, 2) == 1){
            printf("\nerror double scalar multiplication\n");
            printf("(");
            print(vect1, 2);
            printf(";");
            print(vect2, 2);
            printf(")");
            printf("!=");
            printf("%lf", d);
        }
        else{
            printf("\nsuccess double scalar multiplication\n");
            printf("(");
            print(vect1, 2);
            printf(";");
            print(vect2, 2);
            printf(")");
            printf("==");
            printf("%lf\n", d);
        }
    }
}
