#include <avr/io.h>
#include <util/delay.h>

#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define setBit(sfr, bit) (_SFR_BYTE(sfr) |= (1 << bit))
#define clearBit(sfr, bit) (_SFR_BYTE(sfr) &= ~(1 << bit))
#define toggleBit(sfr, bit) (_SFR_BYTE(sfr) ^= (1 << bit))

#define DELAYTIME 200 // ms

int main(void) {
	
	setBit(LED_DDR, LED);
	setBit(LED_PORT, LED);
	
	while(1) {
		
	toggleBit(LED_PORT, LED);
	
	_delay_ms(DELAYTIME);
	
	}
	return 0;
}