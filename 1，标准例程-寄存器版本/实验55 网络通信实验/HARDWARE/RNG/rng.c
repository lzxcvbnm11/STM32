#include "rng.h"
#include "delay.h"
 //////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//RNG(�����������)��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/5
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

//��ʼ��RNG
u8 RNG_Init(void)
{
	u16 retry=0; 
	RCC->AHB2ENR=1<<6;	//����RNGʱ��,����PLL48CLK
	RNG->CR|=1<<2;		//ʹ��RNG
	while((RNG->SR&0X01)==0&&retry<10000)	//�ȴ����������
	{
		retry++;
		delay_us(100);
	}
	if(retry>=10000)return 1;//���������������������
	return 0;
}
//�õ������
//����ֵ:��ȡ���������
u32 RNG_Get_RandomNum(void)
{	 
	while((RNG->SR&0X01)==0);	//�ȴ����������  
	return RNG->DR;	
}
//�õ�ĳ����Χ�ڵ������
//min,max,��С,���ֵ.(����max-min>5000,�������Ҫ�Ⱥܾ�)
//����ֵ:�õ��������(rval),����:min<=rval<=max
int RNG_Get_RandomRange(int min,int max)
{	  
	int temp; 
	if(min>max)return 0;//�Ƿ��ķ�Χ,ֱ�ӷ���0
	while(1)
	{
		temp=(int)RNG_Get_RandomNum();
		if(temp<=max&&temp>=min)break;
	}
	return temp;
}















