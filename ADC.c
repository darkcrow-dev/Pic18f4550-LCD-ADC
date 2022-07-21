#include <ADC.h>     //incluyo la libreria de mi proyecto ADC
#include <LCD_ports.c>     //uso la libreria del LCD
#use delay(clock=8000000) //uso un oscilador de 8MHz que es el interno del pic

int16 dato;             //declaro la variable dato como un long o 2^16
int8 Vhigh, Vlow;
void voltaje();         //declaro voltaje() como la utilización de un void

void main()
{
   lcd_init();          //inicializo la lcd
   SETUP_ADC_PORTS(AN0);      //configuro el ADC en el puerto A0
   setup_adc(ADC_CLOCK_INTERNAL);      //configuro el ADC con oscilador interno
   
   while(TRUE)
   {
   voltaje();           //llamo a voltaje para que haga la accion necesaria
   }
}

void voltaje()
{
   set_adc_channel(0);        //declaro que usaré solo 1 ADC
   //delay_us(10);              //retardo de 10us
   dato = read_adc();         //dato se convierte en el voltaje leido en el ADC
   Vhigh = make8(dato, 1);
   Vlow = make8(dato, 0);
   //printf(lcd_putc, "VOLTAJE");
   printf(lcd_putc, "\f%u %u", Vhigh, Vlow);       //imprimo en el LCD la palabra temperatura y el voltaje tomado
   lcd_gotoxy(1,2);
   printf(lcd_putc, "%Lu", make16(Vhigh, Vlow));
   //printf(lcd_putc, "%u", Vlow);       //imprimo en el LCD la palabra temperatura y el voltaje tomado
   //lcd_gotoxy(1,2);
   //printf(lcd_putc, "%4Lu",dato);
   delay_ms(50);             //retardo de 200ms
}
