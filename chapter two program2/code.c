#define start_switch portb.f0
#define LL portb.f1
#define HL portb.f2
#define pump portd.f2
#define valve portd.f3

void main()
{
trisd=0; //define portd as output
portd=0;

trisb=0b00000111; //define RB0,RB1and RB2 as input
portb=0;

while(start_switch==0); //check the start switch

for(;;)
{
if(LL==1)
{
pump=1;
valve=0;
}

if(HL==1)
{
pump=0;
valve=1;
}

}
}
