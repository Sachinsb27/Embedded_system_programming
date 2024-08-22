//initialize port F
void init_portf(void){
  volatile char *dirf=(char*)0x30;
  *dirf=0xFF;
}
//output value from port F
void output(char out){
  volatile char*outf=(char*)0x31;
  *outf=out;
}
//create a delay
void delay(void){
  volatile unsigned long i;
  for(i=0;i<500000;i++);
}
