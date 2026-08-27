/*
 * FUNCTION.c
 *
 *  Created on: Aug 24, 2026
 *      Author: Target
 */

#include "../INCLUDE/LIB/FUNCTION.h"
#include "../INCLUDE/HAL/SEGMENT/SEGMENT_INTERFACE.h"

#include <stdlib.h>
#include <util/delay.h>

static Snake g_snake; //struct holds all data related to snake
static Position g_food; //x-y coordinations of food

static u8 g_gameRunning; //flags
static u8 g_gameOver;

static u8 g_displayBuffer[4][20]; //all data to be sent to LCD

//initial value of button flags
static u8 g_prevUp = 1;
static u8 g_prevDown = 1;
static u8 g_prevLeft = 1;
static u8 g_prevRight = 1;
static u8 g_prevReset = 1;


void gameInit(void)//sets values & directions of ports and pins
{
    HLCD_voidInit();
    HBuzzer_voidInit();

    SevenSegment_Init();
    HLCD_voidCreateCustomCharacters();

    MDIO_voidSetPinValue(BUTTON_PORT, MOVE_UP, DIO_HIGH);
    MDIO_voidSetPinValue(BUTTON_PORT, MOVE_DOWN, DIO_HIGH);
    MDIO_voidSetPinValue(BUTTON_PORT, MOVE_RIGHT, DIO_HIGH);
    MDIO_voidSetPinValue(BUTTON_PORT, MOVE_LEFT, DIO_HIGH);
    MDIO_voidSetPinValue(BUTTON_PORT, RESET, DIO_HIGH);

    MDIO_voidSetPinDirection(BUTTON_PORT, MOVE_UP, DIO_INPUT);
    MDIO_voidSetPinDirection(BUTTON_PORT, MOVE_DOWN, DIO_INPUT);
    MDIO_voidSetPinDirection(BUTTON_PORT, MOVE_RIGHT, DIO_INPUT);
    MDIO_voidSetPinDirection(BUTTON_PORT, MOVE_LEFT, DIO_INPUT);
    MDIO_voidSetPinDirection(BUTTON_PORT, RESET, DIO_INPUT);
}


void snakeInit(void) //initializes data for each round
{
	//sets snake at the center of LCD ,directed to the right

    g_snake.length = 4;

    g_snake.currentDir = DIR_RIGHT;
    g_snake.nextDir = DIR_RIGHT;

    g_snake.isDead = 0;

    g_snake.score = 0;

    SevenSegment_DisplayNumber(0);


    g_snake.body[0].x = 8;
    g_snake.body[0].y = 1;

    g_snake.body[1].x = 7;
    g_snake.body[1].y = 1;

    g_snake.body[2].x = 6;
    g_snake.body[2].y = 1;

    g_snake.body[3].x = 5;
    g_snake.body[3].y = 1;


    HLCD_voidClearDisplay();

    generateFood();

    g_gameOver = 0;
    g_gameRunning = 1;

    g_prevUp = 1;
    g_prevDown = 1;
    g_prevLeft = 1;
    g_prevRight = 1;
    g_prevReset = 1;
}


void gameReset(void)
{
    HLCD_voidClearDisplay();

    _delay_ms(200);

    snakeInit();
}


void generateFood(void) //generate random coordinates of food position
{
    do {
        g_food.x = rand() % 20;// random number range => 0:19
        g_food.y = rand() % 4;// random number range => 0:3
    } while(checkFoodPosition(g_food.x, g_food.y));
}

u8 checkFoodPosition(u8 x, u8 y)// checks if the random position is on the snake body
{
    for(u8 i = 0; i < g_snake.length; i++)
    {
        if(g_snake.body[i].x == x && g_snake.body[i].y == y)
        {
            return 1;
        }
    }

    return 0;
}


u8 checkCollision(Position newHead)
{
	// check if snake is going to hit the borders

    if(newHead.x < 0 ||newHead.x >= 20 ||newHead.y < 0 ||newHead.y >= 4)
    {
        return 1;
    }

    // check if snake is going to hit its own body
    for(u8 i = 0; i < g_snake.length - 1; i++)
    {
        if(newHead.x == g_snake.body[i].x && newHead.y == g_snake.body[i].y)
        {
            return 1;
        }
    }

    return 0;
}


void buttonInput(void) //handle input of buttons
{
	// checks falling edge

    u8 currentUp = READ_UP();
    u8 currentDown = READ_DOWN();
    u8 currentLeft = READ_LEFT();
    u8 currentRight = READ_RIGHT();
    u8 currentReset = READ_RESET();


    if(IS_PRESSED(currentReset, g_prevReset))
    {
    	g_gameRunning=0;
        _delay_ms(200);
        g_prevReset = currentReset;

        return;
    }

    // prevent 180-direction change
    if(IS_PRESSED(currentUp, g_prevUp))
    {
        if(g_snake.currentDir != DIR_DOWN)
        {
            g_snake.nextDir = DIR_UP;
        }
    }

    else if(IS_PRESSED(currentDown, g_prevDown))
    {
        if(g_snake.currentDir != DIR_UP)
        {
            g_snake.nextDir = DIR_DOWN;
        }
    }

    else if(IS_PRESSED(currentLeft, g_prevLeft))
    {
        if(g_snake.currentDir != DIR_RIGHT)
        {
            g_snake.nextDir = DIR_LEFT;
        }
    }

    else if(IS_PRESSED(currentRight, g_prevRight))
    {
        if(g_snake.currentDir != DIR_LEFT)
        {
            g_snake.nextDir = DIR_RIGHT;
        }
    }

    //change flag value with new one

    g_prevUp = currentUp;
    g_prevDown = currentDown;
    g_prevLeft = currentLeft;
    g_prevRight = currentRight;
    g_prevReset = currentReset;
}


void snakeUpdate(void)// updates snake data
{
    if(g_snake.isDead || g_gameOver)
    {
        return;
    }


    g_snake.currentDir = g_snake.nextDir;


    Position newHead = g_snake.body[0]; //initialization


    switch(g_snake.currentDir)
    {
        case DIR_UP:
            newHead.y--;
            break;

        case DIR_DOWN:
            newHead.y++;
            break;

        case DIR_LEFT:
            newHead.x--;
            break;

        case DIR_RIGHT:
            newHead.x++;
            break;

        default:
            break;
    }

    //checks if head at same position of food
    u8 foodEaten =(newHead.x == g_food.x && newHead.y == g_food.y);


    if(checkCollision(newHead))
    {
        g_snake.isDead = 1;
        g_gameOver = 1;

        return;
    }

    //shifts position data of body parts in the direction of the tail

    for(u8 i = g_snake.length - 1; i > 0; i--)
    {
        g_snake.body[i] = g_snake.body[i - 1];
    }

    g_snake.body[0] = newHead;

    if(foodEaten)
    {
        HBuzzer_voidBeep();


        if(g_snake.length < MAX_SNAKE_LENGTH)
        {
            g_snake.length++;

            g_snake.body[g_snake.length - 1] =
                g_snake.body[g_snake.length - 2];
        }

        g_snake.score += 5;
        SevenSegment_DisplayNumber((u8)g_snake.score);

        generateFood();
    }
}


void snakeDraw(void)
{
	//clears LCD quickly

    for(u8 row = 0; row < 4; row++)
    {
        for(u8 col = 0; col < 20; col++)
        {
            g_displayBuffer[row][col] = ' ';
        }
    }

    // assign position of snake to LCD buffer

    for(u8 i = 0; i < g_snake.length; i++)
    {
        u8 x = g_snake.body[i].x;
        u8 y = g_snake.body[i].y;
        u8 symbol;
            if(i == 0)
            {
            	switch(g_snake.currentDir) {
            	                case DIR_UP:    symbol = HEAD_UP; break;
            	                case DIR_DOWN:  symbol = HEAD_DOWN; break;
            	                case DIR_LEFT:  symbol = HEAD_LEFT; break;
            	                case DIR_RIGHT: symbol = HEAD_RIGHT; break;
            	            }
                g_displayBuffer[y][x] = symbol;
            }

            else
            {
                g_displayBuffer[y][x] = SOLID_BLOCK;
            }

    }

        g_displayBuffer[g_food.y][g_food.x] = DIAMOND;

        //send data to LCD
    for(u8 row = 0; row < 4; row++)
    {
        HLCD_voidGoToPos(row + 1, col1);

        for(u8 col = 0; col < 20; col++)
        {
            HLCD_voidSendData(g_displayBuffer[row][col]);
        }
    }


    // Keep displaying the current score
    SevenSegment_DisplayNumber((u8)g_snake.score);
}


void gameOverScreen(void)
{
    HLCD_voidClearDisplay();



    HLCD_voidSendStringLine("    GAME OVER!    ",ROW1);


    HLCD_voidSendStringLine("    SCORE:        ",ROW3);


    HLCD_voidGoToPos(ROW3, col12);

    HLCD_voidDisplayNumberUnsigned(
        g_snake.score);


    HLCD_voidSendStringLine("    Press RESET    ",ROW4);

    HBuzzer_voidBeep();

     _delay_ms(500);

     HBuzzer_voidBeep();

     _delay_ms(500);


}


void startScreen(void)
{

    HLCD_voidClearDisplay();

    HLCD_voidSendStringLine("      SNAKE GAME    ",ROW2);


    HLCD_voidSendStringLine("      START(UP)?    ",ROW3);


    HBuzzer_voidBeep();
    _delay_ms(500);
    HBuzzer_voidBeep();
    _delay_ms(500);


    while(1)
    {
        u8 currentUp = READ_UP();


        if((currentUp == DIO_LOW) &&(g_prevUp == DIO_HIGH))
        {
            _delay_ms(200);

            break;
        }

    	//stay in start screen until up button is pressed
        u8 currentReset = READ_RESET();


        if((currentReset == DIO_LOW) && (g_prevReset == DIO_HIGH))
        {
            _delay_ms(200);// Debounce
        }


        g_prevUp = currentUp;

        _delay_ms(10);
    }


    HLCD_voidClearDisplay();
}


u8 gameLoop(void)
{
    u8 frameCounter = 0;//counter to work with different speeds

    while(g_gameRunning) {
        buttonInput();//is checked every 50ms

        if(!g_gameRunning) {
            return 0;
        }

        if(frameCounter >= 5) {// frames are updated every 50*5=250ms
            snakeUpdate();
            frameCounter = 0;

            if(g_snake.isDead) {
                g_gameOver = 1;
                g_gameRunning = 0;

                return 1;
            }

            snakeDraw();
        }
        frameCounter++;
        _delay_ms(50);
    }
}
