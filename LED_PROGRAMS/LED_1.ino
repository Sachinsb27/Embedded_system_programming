#include"led.h"
void setup() {
  init_portf(); // Initialize port F
}

void loop() {
  volatile unsigned long i;
  output(0x01);//Glow LSB LED only (bit 0)
  delay();
  output(0x80);// Glow MSB LED only (bit 7)
  delay();
  output(0x03);//Glow LSB 2 LEDs only (bit 0 & bit 1)
  delay();
  output(0xC0);//Glow MSB 2 LEDs only (bit 7 & bit 6)
  delay();
  output(0x09);//Glow LSB 4 LEDs only (bit 0 to bit 3)
  delay();
  output(0x90);//Glow MSB 4 LEDs only (bit 7 to bit 4)
  delay();
  output(0xFF);//Glow all 8 LEDs
  delay();
  output(0xAA);//Glow all ODD no LEDs
  delay();
  output(0x54);//Glow all EVEN no LEDs
  delay();
  output(0x9A);//Glow LEDs of bit7, bit4, bit3, bit1
  delay();

}
