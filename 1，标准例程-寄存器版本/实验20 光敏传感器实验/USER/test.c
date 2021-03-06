#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"  
#include "lsens.h"
//ALIENTEK 探索者STM32F407开发板 实验20
//光敏传感器 实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
    
int main(void)
{      
 	u8 adcx; 
	Stm32_Clock_Init(336,8,2,7);//设置时钟,168Mhz 
	delay_init(168);			//延时初始化  
	uart_init(84,115200);		//初始化串口波特率为115200   
	LED_Init();					//初始化LED 
 	LCD_Init();					//初始化LCD
	Lsens_Init(); 				//初始化光敏传感器
	POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"LSENS TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/7");	  
	POINT_COLOR=BLUE;//设置字体为蓝色
	LCD_ShowString(30,130,200,16,16,"LSENS_VAL:");	             
	while(1)
	{
		adcx=Lsens_Get_Val();
		LCD_ShowxNum(30+10*8,130,adcx,3,16,0);//显示ADC的值 
		LED0=!LED0;
		delay_ms(250);	
	}
}

















