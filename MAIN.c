/*
 * MAIN.c
 *
 *  Created on: 26Aug.,2026
 *      Author: malak
 */

int main(void)
{

	u8 Score = 0 ;

	SevenSegment_Init();

	while(1){
		Snake_Move();
		if(Snake_EatFood())
		{
			Score++;
			SevenSegment_DisplayNumber(Score);

		}
		if(Snake_IsDead())
		{
			Score = 0;
			SevenSegment_DisplayNumber(Score);

		}
		_delay_ms(200);
	}
}
