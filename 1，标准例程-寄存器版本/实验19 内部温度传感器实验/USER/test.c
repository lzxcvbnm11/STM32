#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h" 
#include "adc.h"
//ALIENTEK ̽����STM32F407������ ʵ��19
//�ڲ��¶ȴ����� ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
    
int main(void)
{       
	short temp; 
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz 
	delay_init(168);			//��ʱ��ʼ��  
	uart_init(84,115200);		//��ʼ�����ڲ�����Ϊ115200   
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//��ʼ��LCD
	Adc_Init(); 				//��ʼ��ADC
	POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"Temperature TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/6");	  
	POINT_COLOR=BLUE;//��������Ϊ��ɫ      
	LCD_ShowString(30,140,200,16,16,"TEMPERATE: 00.00C");	      
	while(1)
	{
		temp=Get_Temprate();	//�õ��¶�ֵ 
		if(temp<0)
		{
			temp=-temp;
			LCD_ShowString(30+10*8,140,16,16,16,"-");	//��ʾ����
		}else LCD_ShowString(30+10*8,140,16,16,16," ");	//�޷���
		
		LCD_ShowxNum(30+11*8,140,temp/100,2,16,0);		//��ʾ��������
		LCD_ShowxNum(30+14*8,140,temp%100,2,16,0X80);	//��ʾС������ 
		 
		LED0=!LED0;
		delay_ms(250);	
	}
}

















