#define count_switch portc.f0
#define tens portd.f1
#define ones portd.f2

char display(char num)
{
char x;
char segment[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

x=segment[num];

return x;
}

void main()
{
char i, lsd, msd, count=0;

trisc=1; 
trisd=0;
trisb=0;

portc=0;
portb=0;
portd=0;

while(count_switch==0);

loop:
for (i=0;i<50;i++)
{
msd=count/10;
portb=display(msd);

tens=1;
delay_ms(10);
tens=0;

lsd=count%10;
portb=display(lsd);

ones=1
;delay_ms(10);
ones=0;
}
count++;

if(count==100)
  count=0;
  
goto loop;
}
