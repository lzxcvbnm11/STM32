#include "sys.h"
#include "delay.h" 
#include "led.h"
#include "beep.h"
#include "key.h"
//ALIENTEK ̽����STM32F407������ ʵ��3
//��������ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
 
int main(void)
{ 
	u8 key;
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz 
	delay_init(168);		//��ʱ��ʼ�� 
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ� 
	BEEP_Init();		 	//��ʼ��������IO
	KEY_Init();         	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	LED0=0;					//�ȵ������
	while(1)
	{
 		key=KEY_Scan(0); 	//�õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//���Ʒ�����
					BEEP=!BEEP;
					break;
				case KEY2_PRES:	//����LED0��ת
					LED0=!LED0;
					break;
				case KEY1_PRES:	//����LED1��ת	 
					LED1=!LED1;
					break;
				case KEY0_PRES:	//ͬʱ����LED0,LED1��ת 
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}else delay_ms(10); 
	}
}

















