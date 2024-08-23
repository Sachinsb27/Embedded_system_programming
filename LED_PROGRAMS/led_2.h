
void init_portf (void);
void output(char);
void delay(void);

//Initialize PORT F
void init_portf(void){
volatile char *dirf=(char*)0x30;
*dirf=0xFF;
}

void output(char out){
  volatile char*outf=(char*)0x31;
  *outf=out;
}
//create a dealy
void delay(void){
  volatile unsigned long i;
  for(i=0;i<500000;i++);
}