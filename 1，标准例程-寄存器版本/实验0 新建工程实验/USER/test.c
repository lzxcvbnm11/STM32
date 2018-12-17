#include "sys.h"
#include "usart.h" 
#include "delay.h" 
//ALIENTEK ̽����STM32F407������ ʵ��0
//�½�����ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

int main(void)
{ 
	u8 t=0;
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz
	delay_init(168);		//��ʼ����ʱ����
	uart_init(84,115200);	//���ڳ�ʼ��Ϊ115200
	while(1)
	{
		printf("t:%d\r\n",t);
		delay_ms(500);
		t++;
	}
}
