/*
 * main.c
 *
 *  Created on: Aug 23, 2026
 *      Author: Target
 */

#include "../INCLUDE/LIB/FUNCTION.h"

int main()
{

	gameInit();
	startScreen();
    HLCD_voidSendStringLine("GOOD JOB!!", ROW3);

    return 0;
}
