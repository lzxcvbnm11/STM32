#include "sys.h"
#include "delay.h"  
#include "usart.h"  
#include "led.h"
#include "tpad.h"
//ALIENTEK ̽����STM32F407������ ʵ��11
//���ݴ�������ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
 
int main(void)
{   
	u8 t=0;
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz 
	delay_init(168);			//��ʱ��ʼ��  
	uart_init(84,115200);		//��ʼ�����ڲ�����Ϊ115200 
	LED_Init();					//��ʼ��LED
 	TPAD_Init(8);				//��ʼ����������,��84/4=21MhzƵ�ʼ���
   	while(1)
	{					  						  		 
 		if(TPAD_Scan(0))	//�ɹ�������һ��������(�˺���ִ��ʱ������15ms)
		{
			LED1=!LED1;		//LED1ȡ��
		}
		t++;
		if(t==15)		 
		{
			t=0;
			LED0=!LED0;		//LED0ȡ��,��ʾ������������
		}
		delay_ms(10);
	}
}

















