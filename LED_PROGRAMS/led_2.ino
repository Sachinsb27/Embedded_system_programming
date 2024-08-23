#include"led_2.h"
void setup() {
  init_portf();
}
void loop() {
  volatile unsigned long x;
  volatile unsigned char led_state = 0x00; // Initialize the LED state to all off
  output(0x01);//Blink First LED (With Delay)
  delay();

  output(0xFF);//Blink all the 8 LEDs (with delay)
  delay();

  for (x = 0; x < 8; x++) {    //Glow the LEDs one by one (Do not off the LED)
    led_state |= (1 << x);
    output(led_state);
    delay();
  }
  delay();


  led_state=0x00;             //Glow the LEDs one by one(at a time one LED should glow)
  for (x = 0; x < 8; x++) {
    output(1 << x);
    delay();
  }
  delay();


  led_state=0x00;            // Glow the EVEN LEDs one by one (Do not off the LED)
  for (x = 0; x < 8; x += 2) {
    led_state |= (1 << x);
    output(led_state);

    delay();
  }
  delay();


  led_state=0x00;             //Glow the ODD LEDs one by one (Do not off the LED)
  for (x = 1; x < 8; x += 2) {
    led_state |= (1 << x);
    output(led_state);
    delay();
  }
  delay();


  led_state=0x00;           //Glow 0 to 3 LEDs (one by one)
  for (x = 0; x < 4; x++) {
    led_state |= (1 << x);
    output(led_state);
    delay();
  }
  delay();

  led_state=0x00;         //Glow 4 to 7 LEDs (one by one)
  for (x = 4; x < 8; x++) {
    led_state |= (1 << x);
    output(led_state);
    delay();
  }
  delay();


    led_state=0x00;       //Glow 3 to 0 LEDs (one by one)
  for (x = 0; x < 4; x++) {
    led_state |= (1 << (3 - x));
    output(led_state);
    delay();
  }
  delay();


  led_state = 0x00;       //Glow 7 to 4 LEDs (one by one)
  for (x = 0; x < 4; x++) {
    led_state |= (1 << (7 - x));
    output(led_state);
    delay();
  }
  delay();
}
