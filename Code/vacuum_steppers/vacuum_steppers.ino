#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define S1      PB5
#define S1_DIR  PB4
#define S1_DDR  DDRB
#define S1_PORT PORTB

#define set(sfr, bit)     (_SFR_BYTE(sfr) |= (1 << bit))
#define clear(sfr, bit)   (_SFR_BYTE(sfr) &= ~(1 << bit))
#define toggle(sfr, bit)  (_SFR_BYTE(sfr) ^= (1 << bit))

int main(void) {
	
	set(S1_DDR, S1);
	set(S1_DDR, S1_DIR);
	set(S1_PORT, S1_DIR);
	
	cli();               //Hardware interupt to run the constant speed stepper, s1
	
	TCCR1A = 0;
	TCCR1A = 0;
	TCNT1 = 0;
	OCR1A = 1249;
	TCCR1B |= (1 << WGM12);
	TCCR1B |= (1 << CS11);
	TIMSK1 |= (1 << OCIE1A);
	
	sei();
	while(1) {
	
	}
	return 0;
}

ISR(TIMER1_COMPA_vect) {
	set(S1_PORT, S1);	
	_delay_us(2);
	clear(S1_PORT, S1);
}