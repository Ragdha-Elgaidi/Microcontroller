#define count_switch portd.f0
#define tens portd.f1
#define ones portd.f2

void main()
{
char cnt1=0,cnt2=0,x;

trisd=1;trisb=0;
tens=0;ones=0;
portb=0;

while(count_switch==0);

loop:
cnt1++;

for(x=0;x<50;x++)
{
portb=cnt1;

ones=1;
delay_ms(10);
ones=0;

portb=cnt2;

tens=1
;delay_ms(10);
tens=0;
}

goto loop;
}

