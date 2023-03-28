#define count_switch portd.f1

char display(unsigned char num)
{
char x;
unsigned char segment[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

x=segment[num];

return x;
}

void main()
{
unsigned lsd,msd,count=0;

trisd=2;
trisc=0;
trisb=0;

portb=0;
portc=0;

while(count_switch==0);

for(;;)
{
msd=count/10;
portb=display(msd);
lsd=count%10;
portc=display(lsd);

delay_ms(1000);

count++;

if(count==100)
  count=0;
}
}
