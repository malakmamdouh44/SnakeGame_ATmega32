#include "../INCLUDE/LIB/FUNCTION.h"

int main(void)
{
    gameInit();
    while(1) {
    	startScreen();
    	gameReset();
        u8 g_gameOver= gameLoop();

    	if(!g_gameOver)
        {
    	    continue;
    	}

    	gameOverScreen();

    	u8 prevReset = 1;
        while(1)
        {
        	u8 currentReset = READ_RESET();
            if((currentReset == DIO_LOW) && (prevReset == DIO_HIGH))
            {
    	    _delay_ms(200);
    	    break;
            }
        prevReset = currentReset;
        _delay_ms(10);
        }

    }
    return 0;
}
