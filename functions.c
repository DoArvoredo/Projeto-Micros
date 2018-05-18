#include <reg51.h>;
#include "functions.h"

char TECLA;

sbit pino1 = P1^0;
sbit pino2 = P1^1;
sbit pino3 = P1^2;

char varredura_teclado()
{
    //varredura primeira linha

   P0^4 = 1;
   P0^5 = 1;
   P0^6 = 1;
   P0^7 = 0;

   if(P0^0 == 0)
   {
       TECLA = '1';
       PINO = pino1;
   }
   if(P0^1 == 0)
   {
       TECLA = '2';
       PINO = pino2;
   }
   if(P0^2 == 0)
   {
       TECLA = '3';
       PINO = pino3;
   }

   //varredura segunda linha

   P0^4 = 1;
   P0^5 = 1;
   P0^6 = 0;
   P0^7 = 1;

   if(P0^0 == 0)
   {
       TECLA = '4';
       PINO = pino1;
   }
   if(P0^1 == 0)
   {
       TECLA = '5';
       PINO = pino2;
   }
   if(P0^2 == 0)
   {
       TECLA = '6';
       PINO = pino3;
   }

   //varredura terceira linha

   P0^4 = 1;
   P0^5 = 0;
   P0^6 = 1;
   P0^7 = 1;

   if(P0^0 == 0)
   {
       TECLA = '7';
       PINO = pino1;
   }
   if(P0^1 == 0)
   {
       TECLA = '8';
       PINO = pino2;
   }
   if(P0^2 == 0)
   {
       TECLA = '9';
       PINO = pino3;
   }

   //varredura quarta linha

   P0^4 = 0;
   P0^5 = 1;
   P0^6 = 1;
   P0^7 = 1;

   if(P0^0 == 0)
   {
       TECLA = '*';
       PINO = pino1;
   }
   if(P0^1 == 0)
   {
       TECLA = '0';
       PINO = pino2;
   }
   if(P0^2 == 0)
   {
       TECLA = '#';
       PINO = pino3;

}return TECLA;

char debouncing(char PINO)
{
    char key_valid;
    char key_last = 0;
    char key_now;
    int count = 0;

    for(count=0; count<3; count++)
    {
        delay();   !!!!!!!!!!!!!!!!!!!!!!

        key_now = PINO;

        if(key_now == key_last)
        {
           key_valid = key_now;
           break;
        }
        else
        {
            key_last = key_now;
        }
    }


};

char teclado()
{

    TECLA = varredura_teclado();

    debouncing(PINO);

}return TECLA;


//LCD

void LCD_init (void)
{
	RS = 0;

	//modo LCD
	P1 = 0x38;

	E = 1;
	E = 0;
	atraso();   // 50us

	//controle LCD
	P1 = 0xF;

	E = 1;
	E = 0;
	atraso();   

	//exibição LCD
	P1 = 0x6;

	E = 1;
	E = 0;
	atraso();   

	//limpa display
	P1 = 1;

	E = 1;
	E = 0;
	atraso_display();  //2ms

}

void escreve_lcd(char TECLA)
{
	RS = 1;

	P1 = TECLA;

	E = 1;
	E = 0;

	atraso();   !!!!!!!!!!!!!!!!!!!
}

