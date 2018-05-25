#include <reg52.h>
#include "timers.h"


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
	
	
//setup timer 2 - 10ms
void setup_timer2()
{
	T2CON = 0;
	RCAP2H =0xB8;
	RCAP2L = 0x00;
	TH2= RCAP2H;
	TL2= RCAP2L;
	EA = 1; //enable global interrupt.
	TR2=1; // run control flag set by software
	ET2=1; // enable interrupt timer 2
}

//relógio usando o timer 2
void relogio () interrupt 5
{
	int dezmili, segundos, minutos, horas = 0; //iniciar no .c principal
	dezmili++;
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

void timer_serial ()
{
	TF1 = 0;
	TMOD = 2;
	TL1 = 253;  //para baud rate 19200
	TR1 = 1;
	while (TF0==0);
}
