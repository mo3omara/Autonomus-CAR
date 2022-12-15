#include "main.h"


#define  Trigger_pin	PA0	/* Trigger pin */

int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

int main(void)
{
	
	int right_clear = 0;
	int left_clear = 0;
	int front_clear = 0;
	int Next_check = right;
	int last_check = front;

	
	
	long count;																 //Ultrasonic intialize
	double distance;														 //Ultrasonic intialize
																			 //Ultrasonic intialize
	DDRA = 0x01;		/* Make trigger pin as output */					 //Ultrasonic intialize
	PORTD = 0b00000010;		/* Turn on Pull-up */							 //Ultrasonic intialize
																			 //Ultrasonic intialize
																			 //Ultrasonic intialize
																			 //Ultrasonic intialize
	sei();			/* Enable global interrupt */							 //Ultrasonic intialize
	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */			 //Ultrasonic intialize
	TCCR1A = 0;		/* Set all bit to zero Normal operation */				 //Ultrasonic intialize

Servo_intialize();
Motor_intialization();
LED_intialize(0);
LCD_intialize();

	while(1)
	{
		Servo_Rotate(7.58);				// servo 0 degree 'front'
		
		
 		/* Give 10us trigger pulse on trig. pin to HC-SR04 */						//Ultrasonic reads Distance
 		PORTA |= (1 << Trigger_pin);												//Ultrasonic reads Distance
 		_delay_us(10);																//Ultrasonic reads Distance
 		PORTA &= (~(1 << Trigger_pin));												//Ultrasonic reads Distance
 		
 		TCNT1 = 0;		/* Clear Timer counter */									//Ultrasonic reads Distance
 		TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/					//Ultrasonic reads Distance
 		TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */					//Ultrasonic reads Distance
 		TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */								//Ultrasonic reads Distance
 		
 		/*Calculate width of Echo by Input Capture (ICP) */							//Ultrasonic reads Distance
 		
 		while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */				//Ultrasonic reads Distance
 		TCNT1 = 0;			/* Clear Timer counter */								//Ultrasonic reads Distance
 		TCCR1B = 0x01;		/* Capture on falling edge, No prescaler */				//Ultrasonic reads Distance
 		TIFR = 1<<ICF1;		/* Clear ICP flag (Input Capture flag) */				//Ultrasonic reads Distance
 		TIFR = 1<<TOV1;		/* Clear Timer Overflow flag */							//Ultrasonic reads Distance
 		TimerOverflow = 0;	/* Clear Timer overflow count */						//Ultrasonic reads Distance
 		
 		while ((TIFR & (1 << ICF1)) == 0);		/* Wait for falling edge */			//Ultrasonic reads Distance
 		count = ICR1 + (65535 * TimerOverflow);	/* Take count */	
		 				//Ultrasonic reads Distance
 		/* 8MHz Timer freq, sound speed =343 m/s */									//Ultrasonic reads Distance
 		distance = (double)count / 932;												//Ultrasonic reads Distance
		
		 

 		switch (last_check)
		 {
			 case right:
			 if (distance<=30 && distance>=5)
			 {
			 right_clear = 0;
			 }
			 else
			 {
			 right_clear = 1;
			 }
			  break;
			 case left:
			 if (distance<=30 && distance>=5)
			 {
				 left_clear = 0;
				 rotate_180 = 1;
			 }
			 else
			 {
				 left_clear = 1;
			 }
			  break;
			 case front:
			 if (distance<=30 && distance>=5)
			 {
				front_clear = 0;
			 }
			 else
			 {
				 front_clear = 1;
			 }
			 break;
			 
			 default: break;
		 }
		 
		 
 		
 if (front_clear == 0) //if obstacle detected
 {
	 Motor_OFF(0); //stop car
	 Motor_OFF(1); //stop car
	 LCD_write_string("Obstacle");  //display direction
	  
	  switch(Next_check)
	  {
	  case right:  
	  Servo_Rotate(5.08); //check right
	  last_check = right;
	  Next_check = left;
	  break;
	  
	  case left:
	  Servo_Rotate(10); //check left
	  Next_check = front;
	  last_check = left;
	  break;
	  
	   case front:
	   Servo_Rotate(7.58); //return front
	   Next_check = right;
	   last_check = front;
	   break;
	  }
 }
 	if(right_clear == 1 )
	 {
 	Motor_ON(0,Motor_CW);    //turn right for 1/4 second
 	Motor_ON(1,Motor_CCW);
 	_delay_ms(250);
	 Motor_OFF(0); //stop car
	 Motor_OFF(1); //stop car
	 
	 
	 right_clear = 0;
	 front_clear = 0;
	  }
	 if(left_clear == 1 )
	 {
		 Motor_ON(0,Motor_CCW);    //turn left for 1/4 second
		 Motor_ON(1,Motor_CW);
		 _delay_ms(250);
		 Motor_OFF(0); //stop car
		 Motor_OFF(1); //stop car
		 
		 right_clear = 0;
		 left_clear = 0;
		 front_clear =0;
		 
	 }
 	
 }
 
 if(front_clear == 1)
 {
	 
	LCD_write_string("Forward");  //display direction
  	Motor_ON(0,Motor_CW);
  	Motor_ON(1,Motor_CW);
  	_delay_ms(250);
	  

	Next_check = right;
	last_check = front;

 }
 if (rotate_180 == 1)
 {
	 
	 LCD_write_string("Rotating");  //display direction
	 Motor_ON(0,Motor_CW);
	 Motor_ON(1,Motor_CCW);
	 _delay_ms(250);
 }

}

