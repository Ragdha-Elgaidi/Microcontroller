
void main()
{
trisc=1; //define RC0 as switch input
portc=0;

trisb=0; //define portb as output
portb=0;

while(portc.f0==0); //check for start switch

for(;;)
{
portb=0b00100001; // turn on G1 and R2
delay_ms(10000);

portb=0b00110011; // turn on G1, Y1 and R2, Y2
delay_ms(3000);

portb=0b00001100; // turn on R1 and G2
delay_ms(10000);

portb=0b00011110; // turn on R1,Y1 and G2, Y2
delay_ms(3000);

}
}
