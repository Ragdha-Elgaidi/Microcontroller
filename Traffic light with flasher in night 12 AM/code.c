void interrupt()
{
intcon.intf=0;

while(1)
{
portc=0b00010010;
delay_ms(1000);

portc=0 ;
delay_ms(1000);
}

}

void main ()
{
trisc=0;
trisd=1; 
trisb=1;

portc=0;

intcon.inte=1;
intcon.gie=1;
option_reg.intedg=1;

while (portd.f0==0); //check for start switch

for (; ;)
{
portc=0b00100001;
delay_ms(3000);
 
portc=0b00110011;
delay_ms(1000);
 
portc=0b00001100;
delay_ms(3000);
 
portc=0b00011110; 
delay_ms(1000);
}

}
