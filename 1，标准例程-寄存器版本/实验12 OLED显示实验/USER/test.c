#include "sys.h"
#include "delay.h"  
#include "usart.h"  
#include "led.h"
#include "oled.h"
//ALIENTEK 探索者STM32F407开发板 实验12
//OLED显示实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
 
int main(void)
{   
	u8 t=0;
	Stm32_Clock_Init(336,8,2,7);//设置时钟,168Mhz 
	delay_init(168);			//延时初始化  
	uart_init(84,115200);		//初始化串口波特率为115200 
	LED_Init();					//初始化LED
 	OLED_Init();				//初始化OLED
  	OLED_ShowString(0,0,"ALIENTEK",24);  
	OLED_ShowString(0,24, "0.96' OLED TEST",16);  
 	OLED_ShowString(0,40,"ATOM 2014/5/4",12);  
 	OLED_ShowString(0,52,"ASCII:",12);  
 	OLED_ShowString(64,52,"CODE:",12);  
	OLED_Refresh_Gram();//更新显示到OLED	 
	t=' ';  
	while(1) 
	{		
		OLED_ShowChar(36,52,t,12,1);//显示ASCII字符	
		OLED_ShowNum(94,52,t,3,12);	//显示ASCII字符的码值    
		OLED_Refresh_Gram();//更新显示到OLED
		t++;
		if(t>'~')t=' ';  
		delay_ms(500);
		LED0=!LED0;
	}
}

















