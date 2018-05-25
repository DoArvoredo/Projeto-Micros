#include <reg52.h>
#include "serial.h"

void serial_config ()
{
	SCON = 4;
	REN = 1;
	EA = 1;
	ES = 1;
	
}

void envia_serial(char *send) //ENVIA CHAR SERIAL
{
	int A=0;
	
	TI=0;
	
	
	while(send[A]!='\0')
	{
		SBUF = send[A];
		while(TI==0){}
		TI = 0;
		A++;
	}
	
}	

//void recebe_serial(void) interrupt 4 { //INTERRUPÇÃO SERIAL

//	if (RI){

//		imgSBUF = SBUF;

//		RI = 0;	

//		if(Pint==0){

//			if(imgSBUF=='P'){

//				Pint++;}}

//		else if ((Sint==0)&&(Aint==0)&&(Rint==0)){

//			if (imgSBUF=='S'){ 

//				Sint++;}

//			if (imgSBUF=='A'){

//				Aint++;}

//			if (imgSBUF=='R'){

//				Rint++;}

//		}

//		else{

//			if(Pint&&Aint){ //Subiu uma pessoa

//				peso = peso + imgSBUF;

//			}

//			if(Pint&&Rint){ //Desceu uma pessoa

//				peso = peso - imgSBUF;

//				if (peso<0){

//				peso=0;}

//			}

//			if(Pint&&Sint){ //Chegou a um andar

//				if(imgSBUF==1){ // MUDAAARRR QUANDO FOR PASSAR PARA O MICRO (TIRAR '')

//					if (movAtu > 0){

//						atual=atual<<1;

//						flagAndar = 1;

//					}

//					if (movAtu < 0){

//						atual=atual>>1;

//						flagAndar = 1;

//					}

//					movAnt = movAtu;

//					movAtu = 0;

//				}

//			}

//			Pint=0;Sint=0;Aint=0;Rint=0;

//		}

//			

//	}

//}