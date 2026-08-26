/*
 * MAIN.c
 *
 *  Created on: 26Aug.,2026
 *      Author: malak
 */


#include "../INCLUDE/LIB/FUNCTION.h"
#include<avr/io.h>

int main(void)
{

     gameInit();
    while(1) {
    snakeMain();
    }
    return 0;

}
