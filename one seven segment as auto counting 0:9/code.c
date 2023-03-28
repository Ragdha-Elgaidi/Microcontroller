#define start_switch PORTd.f0

void main()
{
  
char count=1; // take a location from memory (8 bits) called count
char segment[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F}; // segment is a location to store the codes from 0 to 9

TRISD=1; //Define D0 as input
TRISB=0; //Define PORTB as output

portd=0;
portb=0; // as initial

PORTB =segment[0]; // to write zero on the 7 segment

while (start_switch==0); //check for start switch

for(;;) //endless loop
{
portb=segment[count]; // to take the codes from vector segment to display on the 7-segment

delay_ms(1000); // wait 1 second

count++; //next count

if(count==10)
   count=0;
}
  
}
