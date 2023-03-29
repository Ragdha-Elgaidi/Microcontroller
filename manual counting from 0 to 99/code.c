#define count_switch portd.f0
#define digit1 portd.f1
#define digit2 portd.f2

char display(char num)
{
char pattern;
char segment[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

pattern=segment[num];

return pattern;
}

void main()
{
unsigned char lsd,msd,count=0; 

trisd=1;
trisb=0;

digit1=0;
digit2=0;

for(;;)
{
do
{
msd=count/10;
portb=display(msd);

digit1=1;
delay_ms(20);
digit1=0;

lsd=count%10;
portb=display(lsd);

digit2=1;
delay_ms(20);
digit2=0;

}while(count_switch==0);

count++;
if(count==100)
  count=0;
  
do{
msd=count/10;
portb=display(msd);

digit1=1;
delay_ms(20);
digit1=0;

lsd=count%10;
portb=display(lsd);

digit2=1;
delay_ms(20);
digit2=0;
}while(count_switch==1);
}
}


