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

//setup timer 0
void setup_timer0()
{
	TMOD = 2;
	TH0 = 163;
	TL0 = 163;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
	
//função delay para o LCD
void atraso() //50us
{
	TF0 = 0;
	TMOD = 2;
	TL0 = 210;  //Ttimer=1.085 us --> 46clocks --> 256-46=210.
	TR0 = 1;
	while (TF0==0);
}

//função delay para o lcd 
void atraso_display() //2ms = 40*atraso
{
	int disp_delay=0;
	do{
	atraso();
	disp_delay ++;
	}while (disp_delay==40);
}
	
void atraso_debounce() //10ms = 200*atraso
{
	int debounce_delay=0;
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

	atraso(); 
}

	
	
//setup timer 2 - 10ms
void setup_timer2()
{
	T2CON = 4;  //recarga automática - nao sei se tá certo, MESMO TR2
	RCAP2H =0xB8;
	RCAP2L = 0x00;
	TH1= RCAP2H;
	TL1= RCAP2L;
	EA = 1; //enable global interrupt.
	//TR2=1; // run control flag set by software
	ET2=1; // enable interrupt timer 2
}

//relógio usando o timer 2
void relogio () interrupt 5
{
	int dezmili, segundos, minutos, horas = 0; //iniciar no .c principal
	milissegundos++;
	if(dezmili == 100)//entra a cada segundo
	{
		dezmili = 0;
		segundos ++;
		if(segundos == 60)
		{
			segundos = 0;
			minutos ++;
			if(minutos == 60)
			{
				minutos = 0;
				horas ++;
				if(horas == 24)
					horas=0;
			}
		}
	}
	TF2 = 0;
}

