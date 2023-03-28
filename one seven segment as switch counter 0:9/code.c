#define sensor PORTd.f0
void main()
{
char count=1;
char segment[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};

TRISD=1;
TRISB=0;

portd=0;
portb=0;

PORTB =segment[0];

for(;;)
{
while (sensor ==0);

portb=segment[count];

count++;

if(count==10)
      count=1;
      
while (sensor ==1); //check for switch releasing
}
}
