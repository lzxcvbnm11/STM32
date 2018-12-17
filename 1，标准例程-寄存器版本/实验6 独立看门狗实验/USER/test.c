#include "sys.h"
#include "delay.h"  
#include "led.h"  
#include "key.h" 
#include "wdg.h"
//ALIENTEK ̽����STM32F407������ ʵ��6
//�������Ź�ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
  
int main(void)
{  
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz 
	delay_init(168);		//��ʱ��ʼ��   
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ� 
	KEY_Init();		  		//��ʼ������
 	delay_ms(100);			//��ʱ100ms�ٳ�ʼ�����Ź�,LED0�ı仯"�ɼ�"
	IWDG_Init(4,500);    	//Ԥ��Ƶ��Ϊ64,����ֵΪ500,���ʱ��Ϊ1s	   
	LED0=0;				 	//����LED0
	while(1)
	{ 
		if(KEY_Scan(0)==WKUP_PRES)//���WK_UP����,��ι��
		{
			IWDG_Feed();//ι��
		}
		delay_ms(10);
	};
}

















