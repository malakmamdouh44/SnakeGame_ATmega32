#include "../INCLUDE/LIB/FUNCTION.h"

int main(void)
{
    gameInit();
    while(1) {

    	startScreen();
    	gameReset();
        u8 g_gameOver= gameLoop();

    	if(!g_gameOver) //got out of gameloop without losing,then RESET button is hit
        {
    	    continue;
    	}

    	gameOverScreen();

        while(1)
        {
            if(READ_RESET() == DIO_LOW)
            {
    	    _delay_ms(200);
    	    break;
            }
        }

    }
    return 0;
}
