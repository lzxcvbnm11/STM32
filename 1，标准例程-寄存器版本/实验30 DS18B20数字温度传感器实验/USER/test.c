#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "usmart.h" 
#include "ds18b20.h"
//ALIENTEK 探索者STM32F407开发板 实验30
//DS18B20数字温度传感器 实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
 
int main(void)
{    
	u8 t=0;			    
	short temperature;  
	Stm32_Clock_Init(336,8,2,7);//设置时钟,168Mhz 
	delay_init(168);			//延时初始化  
	uart_init(84,115200);		//初始化串口波特率为115200  	  
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化 
  	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"DS18B20 TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/7");
 	while(DS18B20_Init())	//DS18B20初始化	
	{
		LCD_ShowString(30,130,200,16,16,"DS18B20 Error");
		delay_ms(200);
		LCD_Fill(30,130,239,130+16,WHITE);
 		delay_ms(200);
	}   
	LCD_ShowString(30,130,200,16,16,"DS18B20 OK");
	POINT_COLOR=BLUE;//设置字体为蓝色 
 	LCD_ShowString(30,150,200,16,16,"Temp:   . C");	 
	while(1)
	{	    	    
 		if(t%10==0)//每100ms读取一次
		{									  
			temperature=DS18B20_Get_Temp();	
			if(temperature<0)
			{
				LCD_ShowChar(30+40,150,'-',16,0);			//显示负号
				temperature=-temperature;					//转为正数
			}else LCD_ShowChar(30+40,150,' ',16,0);			//去掉负号
			LCD_ShowNum(30+40+8,150,temperature/10,2,16);	//显示正数部分	    
   			LCD_ShowNum(30+40+32,150,temperature%10,1,16);	//显示小数部分 		   
		}				   
	 	delay_ms(10);
		t++;
		if(t==20)
		{
			t=0;
			LED0=!LED0;
		}
	}
}
















