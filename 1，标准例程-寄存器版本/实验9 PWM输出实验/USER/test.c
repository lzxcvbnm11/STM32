#include "sys.h"
#include "delay.h"  
#include "led.h"
#include "timer.h"
//ALIENTEK ̽����STM32F407������ ʵ��9
//PWM���ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
  
int main(void)
{  
	u16 led0pwmval=0;    
	u8 dir=1;
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz 
	delay_init(168);			//��ʱ��ʼ��   
 	TIM14_PWM_Init(500-1,84-1);	//1Mhz�ļ���Ƶ��,2Khz��PWM.     
   	while(1)
	{
 		delay_ms(10);	 
		if(dir)led0pwmval++;
		else led0pwmval--;	 
 		if(led0pwmval>300)dir=0;
		if(led0pwmval==0)dir=1;	   					 
		LED0_PWM_VAL=led0pwmval;	   
	}
}

















