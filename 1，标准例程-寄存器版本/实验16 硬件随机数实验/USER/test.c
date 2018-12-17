#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "usmart.h"
#include "key.h"
#include "rng.h"
//ALIENTEK ̽����STM32F407������ ʵ��16
//�����������(RNG) ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
    
int main(void)
{     
	u32 random;
	u8 t=0,key;
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz 
	delay_init(168);			//��ʱ��ʼ��  
	uart_init(84,115200);		//��ʼ�����ڲ�����Ϊ115200  
	usmart_dev.init(84); 		//��ʼ��USMART	
	LED_Init();					//��ʼ��LED
	KEY_Init();					//������ʼ��
 	LCD_Init();					//��ʼ��LCD
	POINT_COLOR=RED;
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"RNG TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/5");	 
	while(RNG_Init())	 		//��ʼ�������������
	{
		LCD_ShowString(30,130,200,16,16,"  RNG Error! ");	 
		delay_ms(200);
		LCD_ShowString(30,130,200,16,16,"RNG Trying...");	 
	}                                 
	LCD_ShowString(30,130,200,16,16,"RNG Ready!   ");	 
	LCD_ShowString(30,150,200,16,16,"KEY0:Get Random Num");	 
	LCD_ShowString(30,180,200,16,16,"Random Num:");	 
 	LCD_ShowString(30,210,200,16,16,"Random Num[0-9]:");
 	POINT_COLOR=BLUE;
	while(1) 
	{		
		key=KEY_Scan(0);
		if(key==KEY0_PRES)
		{
			random=RNG_Get_RandomNum(); 
			LCD_ShowNum(30+8*11,180,random,10,16); 
		} 
		if((t%20)==0)
		{
			LED0=!LED0;	//ÿ200ms,��תһ��LED0 
			random=RNG_Get_RandomRange(0,9);		//��ȡ[0,9]����������
			LCD_ShowNum(30+8*16,210,random,1,16); 	//��ʾ�����
		}
		delay_ms(10);
		t++;
	}	
}

















