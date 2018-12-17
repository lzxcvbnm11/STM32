#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "usmart.h"  
#include "sram.h"   
//ALIENTEK 探索者STM32F407开发板 实验36
//外部SRAM 实验 
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

u32 testsram[250000] __attribute__((at(0X68000000)));//测试用数组
//外部内存测试(最大支持1M字节内存测试)	    
void fsmc_sram_test(u16 x,u16 y)
{  
	u32 i=0;  	  
	u8 temp=0;	   
	u8 sval=0;	//在地址0读到的数据	  				   
  	LCD_ShowString(x,y,239,y+16,16,"Ex Memory Test:   0KB"); 
	//每隔4K字节,写入一个数据,总共写入256个数据,刚好是1M字节
	for(i=0;i<1024*1024;i+=4096)
	{
		FSMC_SRAM_WriteBuffer(&temp,i,1);
		temp++;
	}
	//依次读出之前写入的数据,进行校验		  
 	for(i=0;i<1024*1024;i+=4096) 
	{
  		FSMC_SRAM_ReadBuffer(&temp,i,1);
		if(i==0)sval=temp;
 		else if(temp<=sval)break;//后面读出的数据一定要比第一次读到的数据大.	   		   
		LCD_ShowxNum(x+15*8,y,(u16)(temp-sval+1)*4,4,16,0);//显示内存容量  
 	}					 
}	

int main(void)
{        
	u8 key;		 
 	u8 i=0;	     
	u32 ts=0;
	Stm32_Clock_Init(336,8,2,7);//设置时钟,168Mhz 
	delay_init(168);			//延时初始化  
	uart_init(84,115200);		//初始化串口波特率为115200 
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化  
 	KEY_Init();					//按键初始化 
 	FSMC_SRAM_Init();			//初始化外部SRAM
	usmart_dev.init(84);		//初始化USMART   
 	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"SRAM TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/14");   
	LCD_ShowString(30,130,200,16,16,"KEY0:Test Sram");
	LCD_ShowString(30,150,200,16,16,"KEY1:TEST Data");
 	POINT_COLOR=BLUE;//设置字体为蓝色  
	for(ts=0;ts<250000;ts++)testsram[ts]=ts;//预存测试数据	 
  	while(1)
	{	
		key=KEY_Scan(0);//不支持连按	
		if(key==KEY0_PRES)fsmc_sram_test(60,170);//测试SRAM容量
		else if(key==KEY1_PRES)//打印预存测试数据
		{
			for(ts=0;ts<250000;ts++)LCD_ShowxNum(60,190,testsram[ts],6,16,0);//显示测试数据	 
		}else delay_ms(10);   
		i++;
		if(i==20)//DS0闪烁.
		{
			i=0;
			LED0=!LED0;
 		}
	}
}
















