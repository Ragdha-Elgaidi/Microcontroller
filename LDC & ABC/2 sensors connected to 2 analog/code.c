sbit LCD_RS at RC2_bit;
sbit LCD_EN at RC3_bit;
sbit LCD_D4 at RC4_bit;
sbit LCD_D5 at RC5_bit;
sbit LCD_D6 at RC6_bit;
sbit LCD_D7 at RC7_bit;

sbit LCD_RS_Direction at TRISC2_bit;
sbit LCD_EN_Direction at TRISC3_bit;
sbit LCD_D4_Direction at TRISC4_bit;
sbit LCD_D5_Direction at TRISC5_bit;
sbit LCD_D6_Direction at TRISC6_bit;
sbit LCD_D7_Direction at TRISC7_bit;

float Vm1,Vm2;
unsigned int ADRead1, Tm1,ADRead2, Tm2;
unsigned char Display1[7],Display2[7]; // IntToStr function outputs 7 characters
unsigned char unit[2];

void main()
{
ADCON1 = 0x00;
TRISA = 0x02; //RA0/AN0 is input and others are output
PORTA = 0;
TRISC = 0; // PORTD is output
PORTC = 0;

LCD_Init();
LCD_Cmd(_LCD_CURSOR_OFF);
LCD_Cmd(_LCD_CLEAR);
LCD_Out(1, 1, "T1:");

unit[0] = 223; //degree character, different LCD displays have different//char code for degree if you see greek alpha letter try typing 178instead of 223
unit[1]= 'C'; // 'C' for Centigrade
LCD_Out(1,11,unit); // Print degree character, 'C' for Centigrade

LCD_Out(2, 1, "T2:");
LCD_Out(2,11,unit); // Print degree character, 'C' for Centigrade
ADC_Init(); // initialize ADC module

while (1)
{
ADRead1 = ADC_Get_Sample(0); // Read AN0 = Vdig [0 to 1023]
Vm1 = ADRead1 * 5.0 / 1023.0; // Calculate Vm in volts
Tm1 = 100 * Vm1; // calculate actual temperature Tm in C
IntToStr(Tm1, Display1); // Covert Tm value to Strig such that it canbe displayed in LCD
LCD_Out(1,6,Display1); // Print the value of "Tm" on LCD row2,column4
delay_ms(200); //200ms delay for waiting

ADRead2 = ADC_Get_Sample(1); // Read AN0 = Vdig [0 to 1023]
Vm2 = ADRead2 * 5.0 / 1023.0; // Calculate Vm in volts
Tm2 = 100 * Vm2; // calculate actual temperature Tm in C
IntToStr(Tm2, Display2); // Covert Tm value to Strig such that it canbe displayed in LCD
LCD_Out(2,6,Display2); // Print the value of "Tm" on LCD row2,column4
delay_ms(200); //200ms delay for waiting

if(Tm1>Tm2)
portc.f0=1;
else
portc.f0=0;
delay_ms(20);
}
}
