/*
* @Author: GalenMoo
* @Date:   2018-07-31 09:01:29
* @Last Modified by:   GALENWU
* @Last Modified time: 2018-08-06 09:49:30
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "tuple.h"

/* print a block of x number of bytes */
void print_block(void *h, int x){
    uint8_t *temp = (uint8_t *)h;
    printf("\n");
    for (; --x >= 0;){
        printf("%02X ", temp[x]);
    }
    printf("\n\n");
}

//a function that returns a tuple
tuple_int_int *tuple_func(void){
    tuple_int_int *tp;

    tp = tuple_init(tp);
    tp->a = 123;
    tp->b = 256;

    return tp;
}


int main(int argc, char *argv[]){
    printf("Starting test for tuples\n");

    //also a test for function returns
    printf("------------INT/INT TEST------------\n");
    tuple_int_int *tp = tuple_func();

    print_block(tp, sizeof(*tp));
    printf("Tuple a: %u\n", tuple_a(tp, int));
    printf("Tuple b: %u\n", tuple_b(tp, int));
    printf("-------------------------------------\n\n");


    printf("------------STR/INT TEST------------\n");
    tuple_str_int *tp1;
    tp1 = tuple_init(tp1);

    tp1->a = "Hello";
    printf("pointer addr: %p, size: %lu\n", tp1->a, sizeof(tp1->a));
    tp1->b = 50;
    print_block(tp1, sizeof(*tp1));

    /* i understand why it needs an a char* but 
    *  how do i get around that, just not intutive 
    *   11  10  9  8  7  6  5  4  3  2  1  0
    *   (    int   )(         char *       )
    *              ^              ^
    *            char *          int
    */ 

    /*                     ((char * *)(tp1))[0] */
    printf("Tuple a: %s\n", tuple_a(tp1, char *));
    /*                     ((char * *)(tp1))[1] */
    printf("Tuple b: %d\n", tuple_b(tp1, char *));
    printf("-------------------------------------\n\n");


    printf("------------INT/STR TEST------------\n");
    tuple_int_str *tp2;
    tp2 = tuple_init(tp2);

    tp2->a = 0xAA;
    tp2->b = "World";
    print_block(tp2, sizeof(*tp2));


    printf("Tuple a: 0x%X\n", tuple_a(tp2, int)); 
    printf("Tuple b: %s\n", tuple_b(tp2, char *));
    printf("-------------------------------------\n\n");

    printf("------------STR/STR TEST------------\n");

    tuple_str_str *tp3;
    tp3 = tuple_init(tp3);

    tp3->a = "Goodbye";
    tp3->b = "World";
    print_block(tp3, sizeof(*tp3));

    printf("Tuple a: %s\n", tuple_a(tp3, char *));
    printf("Tuple b: %s\n", tuple_b(tp3, char *));
    printf("-------------------------------------\n\n");

    printf("\n");
    return EXIT_SUCCESS;
}