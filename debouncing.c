#include <reg52.h>

char TECLA;

sbit pino1 = P1^0;
sbit pino2 = P1^1;
sbit pino3 = P1^2;
sbit pino0_4 = P0^4;
sbit pino0_5 = P0^5;
sbit pino0_6 = P0^6;
sbit pino0_7 = P0^7;


char PINO;


char varredura_teclado()
{
    //varredura primeira linha

   pino0_4 = 1;
   pino0_5 = 1;
   pino0_6 = 1;
   pino0_7 = 0;

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

   pino0_4 = 1;
   pino0_5 = 1;
   pino0_6 = 0;
   pino0_7 = 1;

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

   pino0_4 = 1;
   pino0_5 = 0;
   pino0_6 = 1;
   pino0_7 = 1;

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

   pino0_4 = 0;
   pino0_5 = 1;
   pino0_6 = 1;
   pino0_7 = 1;

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

void atraso_debounce() //10ms = 200*atraso
{
	char debounce_delay=0;
	
	do{
	atraso();
	debounce_delay ++;
	}while (debounce_delay==200);
}	
	
char debouncing(char PINO)
{
    char key_valid;
    char key_last = 0;
    char key_now;
    int count = 0;

    for(count=0; count<3; count++)
    {
        atraso_debounce();

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


