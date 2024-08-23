#include"led_3.h"
void setup() {
  init_portf();
}

void loop() {
  volatile  unsigned char led_state = 0x00;
  volatile unsigned char x, y;
  volatile unsigned long led_sequence[] = {0, 2, 1, 3, 4, 6, 5, 7};
  /*1.Glow the LEDs in following order
    3,7 delay – 2,6 delay – 1,5 delay – 0,4 delay*/
  output(0x88);// 3,7 delay
  delay();
  output(0x24);// – 2,6 delay
  delay();
  output(0x12);//– 1,5 delay
  delay();
  output(0x10);// – 0,4 delay
  delay();

  /* 2. Glow the LEDs in following order
    0,4 delay – 1,5 delay – 2,6 delay – 3,7 delay */
  output(0x10);// – 0,4 delay
  delay();
  output(0x12);//– 1,5 delay
  delay();
  output(0x24);// – 2,6 delay
  delay();
  output(0x88);//3,7 delay
  delay();

  /* 3. Glow 0 to 7 LEDs with delay and 7 to 0 LEDs with
    delay*/
  for (x = 0; x < 8; x++) {
    led_state |= (1 << x);
    output(led_state);
    delay();
  }
  led_state = 0x00;
  for (x = 0; x < 8; x++) {
    led_state |= (1 << (7 - x));
    output(led_state);
    delay();
  }

  /* 4. Glow 0,2,1,3,4,6,5,7 LEDs with delay*/
  led_state = 0x00;
  for (x = 0; x < 8; x++) {
    led_state |= (1 << led_sequence[x]);
    output(led_state);
    delay();
  }

  /* 5. Glow the LEDs in following order
    0,1 delay – 6,7, delay – 2,3, delay – 4,5, delay*/
  led_state = 0x00;
  output(0x03);
  delay();
  output(0xC0);
  delay();
  output(0x0C);
  delay();
  output(0x30);
  delay();

  /* 6. Glow the LEDs in following order
    4,5 delay – 2,3, delay – 6,7, delay – 0,1, delay*/
  led_state = 0x00;
  output(0x30);
  delay();
  output(0x0C);
  delay();
  output(0xC0);
  delay();
  output(0x03);
  delay();

  /* 7. Glow the LEDs in following order
    0,1,2 delay – 5,6,7, delay – 3,4, delay*/
  led_state = 0x00;
  output(0x07);
  delay();
  output(0xE0);
  delay();
  output(0x18);
  delay();

  /* 8. Glow the LEDs in following order
    3,4 delay – 5,6,7, delay – 0,1,2, delay*/
  led_state = 0x00;
  output(0x18);
  delay();
  output(0xE0);
  delay();
  output(0x07);
  delay();

  /* 9. Glow the LEDs in following order
    0 then 0,1 then 0,1, 2...... then 0,1,2,3,4,5,6,7
    with delay.*/
  for (y = 0; y < 8; y++) {
    led_state = 0x00;
    for (x = 0; x <= y; x++) {
      led_state |= (1 << x);
    }
    output(led_state);
    delay();
  }
  delay();

  /* 10. Glow the LEDs in following order
    7 then 7,6 then 7,6, 5...... then 7,6,5,4,3,2,1,0
    with delay.*/
  for (y = 0; y < 8; y++) {
    led_state = 0x00;
    for (x = 0; x <= y; x++) {
      led_state |= (1 << (7 - x));
    }
    output(led_state);
    delay();
  }
  delay();
}
