#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "usmart.h"  
#include "sram.h"   
#include "malloc.h" 
#include "w25qxx.h"    
#include "sdio_sdcard.h"
#include "ff.h"  
#include "exfuns.h"    
#include "fontupd.h"
#include "text.h"	 
#include "wm8978.h"	 
#include "audioplay.h"	
#include "recorder.h"	 
//ALIENTEK ̽����STM32F407������ ʵ��44
//¼���� ʵ�� 
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾


int main(void)
{ 
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz 
	delay_init(168);			//��ʱ��ʼ��  
	uart_init(84,115200);		//��ʼ�����ڲ�����Ϊ115200 
	LED_Init();					//��ʼ��LED 
	usmart_dev.init(84);		//��ʼ��USMART
 	LCD_Init();					//LCD��ʼ��  
 	KEY_Init();					//������ʼ��  
	W25QXX_Init();				//��ʼ��W25Q128
	WM8978_Init();				//��ʼ��WM8978
	WM8978_HPvol_Set(40,40);	//������������
	WM8978_SPKvol_Set(50);		//������������
	
	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ��
	my_mem_init(SRAMCCM);		//��ʼ��CCM�ڴ�� 
	exfuns_init();				//Ϊfatfs��ر��������ڴ�  
  	f_mount(fs[0],"0:",1); 		//����SD��  
	POINT_COLOR=RED;      
	while(font_init()) 			//����ֿ�
	{	    
		LCD_ShowString(30,40,200,16,16,"Font Error!");
		delay_ms(200);				  
		LCD_Fill(30,40,240,66,WHITE);//�����ʾ	     
		delay_ms(200);				  
	}  	 
	POINT_COLOR=RED;      
 	Show_Str(30,40,200,16,"Explorer STM32������",16,0);				    	 
	Show_Str(30,60,200,16,"¼����ʵ��",16,0);				    	 
	Show_Str(30,80,200,16,"����ԭ��@ALIENTEK",16,0);				    	 
	Show_Str(30,100,200,16,"2014��6��6��",16,0); 
	while(1)
	{ 
		wav_recorder();
		
	} 
}
















