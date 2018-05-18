#include <reg52.h>

int milissegundos, segundos, minutos, horas;

//setup timer 2
void setup_timer2()
{
	T2CON = 4;  //recarga automática - nao sei se tá certo, MESMO TR2
	RCAP2H =0xFC;
	RCAP2L = 0x66;
	TH1= RCAP2H;
	TL1= RCAP2L;
	EA = 1; //enable global interrupt.
	//TR2=1; // run control flag set by software
	ET2=1; // enable interrupt timer 2
	while(1); //NÃO TENHO CERTEZA
}

//relógio usando o timer 2
void timer2_clock () interrupt 5
{
	int flag_ms = 0;
	flag_ms ++;
	TF2 = 0;
}

void relogio () //REVER AQUI
{
	int milissegundos, segundos, minutos, horas;
	milissegundos++;
	if(milissegundos == 1000)//entra a cada segundo
	{
		milissegundos = 0;
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
