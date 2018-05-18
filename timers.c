#include <reg52.h>

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


//setup timer 0
void setup_timer0(){
//configure timer 0
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
