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

float Vm;
unsigned int ADRead, Tm;
unsigned char Display[7]; // IntToStr function outputs 7 characters
unsigned char unit[2];

void main()
{
ADCON1 = 0x0E; //RA0 analog and others are digital, VREF+ =VDD, VREF-=Vss
TRISA = 0x01; //RA0/AN0 is input and others are output
PORTA = 0;
TRISC = 0; // PORTD is output
PORTC = 0;

LCD_init();
LCD_Cmd(_LCD_CURSOR_OFF);
LCD_Cmd(_LCD_CLEAR);
LCD_Out(1, 1, "Temp:");

unit[0] = 223; //degree character, different LCD displays have different//char code for degree if you see greek alpha letter try typing 178instead of 223
unit[1]= 'C'; // 'C' for Centigrade                          LM

LCD_Out(2,11,unit); // Print degree character, 'C' for Centigrade
 ADC_Init(); // initialize ADC module

while (1)
{
ADRead = ADC_Get_Sample(0); // Read AN0 = Vdig [0 to 1023]
Vm = ADRead * 5.0 / 1023.0; // Calculate Vm in volts
Tm = 100 * Vm; // calculate actual temperature Tm in C
IntToStr(Tm, Display); // Covert Tm value to Strig such that it canbe displayed in LCD
LCD_Out(2,4,Display); // Print the value of "Tm" on LCD row2,column4
delay_ms(200); //200ms delay for waiting
}
}
