
#define start_switch portd.f0

void main()
{
char segment[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
char count;

trisd=1;
trisc=0;
trisb=0;

PORTb=0;
portc=0;
portd=0;

while(start_switch==0);

while(1)
{

for(count=9;count>0;count--)
{
portc=0b00001001;
portb=segment[count];
delay_ms(1000);
}

for(count=9;count>0;count--)
{
portc=0b00000110;
portb=segment[count];
delay_ms(1000);
}

}

}

