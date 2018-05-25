//#include <reg52.h>


//void LCD_init (void)
//{
//	RS = 0;

//	//modo LCD
//	P1 = 0x38;

//	E = 1;
//	E = 0;
//	atraso();   // 50us

//	//controle LCD
//	P1 = 0xF;

//	E = 1;
//	E = 0;
//	atraso();   

//	//exibição LCD
//	P1 = 0x6;

//	E = 1;
//	E = 0;
//	atraso();   

//	//limpa display
//	P1 = 1;

//	E = 1;
//	E = 0;
//	atraso_display();  //2ms

//}

//void escreve_lcd(char TECLA)
//{
//	RS = 1;

//	P1 = TECLA;

//	E = 1;
//	E = 0;

//	atraso(); 
//	while(1);
//}
