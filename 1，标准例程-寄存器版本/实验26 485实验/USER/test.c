#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "usmart.h" 
#include "rs485.h"
//ALIENTEK 探索者STM32F407开发板 实验26
//485 实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
    
int main(void)
{   
	u8 key;
	u8 i=0,t=0;
	u8 cnt=0;
	u8 rs485buf[5]; 
	Stm32_Clock_Init(336,8,2,7);//设置时钟,168Mhz 
	delay_init(168);			//延时初始化  
	uart_init(84,115200);		//初始化串口波特率为115200  	 
	usmart_dev.init(84);		//初始化usmart
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化 
	KEY_Init(); 				//按键初始化  
	RS485_Init(42,9600);		//初始化RS485
 	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"RS485 TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/7");	
	LCD_ShowString(30,130,200,16,16,"KEY0:Send");	//显示提示信息		
 
 	POINT_COLOR=BLUE;//设置字体为蓝色	  
	LCD_ShowString(30,150,200,16,16,"Count:");			//显示当前计数值	
	LCD_ShowString(30,170,200,16,16,"Send Data:");		//提示发送的数据	
	LCD_ShowString(30,210,200,16,16,"Receive Data:");	//提示接收到的数据		
 									  
	while(1)
	{
		key=KEY_Scan(0);
		if(key==KEY0_PRES)//KEY0按下,发送一次数据
		{
			for(i=0;i<5;i++)
			{
				rs485buf[i]=cnt+i;//填充发送缓冲区
				LCD_ShowxNum(30+i*32,190,rs485buf[i],3,16,0X80);	//显示数据
 			}
			RS485_Send_Data(rs485buf,5);//发送5个字节 									   
		}		 
		RS485_Receive_Data(rs485buf,&key);
		if(key)//接收到有数据
		{
			if(key>5)key=5;//最大是5个数据.
 			for(i=0;i<key;i++)LCD_ShowxNum(30+i*32,230,rs485buf[i],3,16,0X80);	//显示数据
 		}
		t++; 
		delay_ms(10);
		if(t==20)
		{
			LED0=!LED0;//提示系统正在运行	
			t=0;
			cnt++;
			LCD_ShowxNum(30+48,150,cnt,3,16,0X80);	//显示数据
		}		   
	}   
}

















