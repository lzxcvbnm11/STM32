#ifndef __W25Q16_H
#define __W25Q16_H			    
#include "lpc11xx.h" 

#define	F_CS_High  LPC_GPIO1->DATA|=(1<<10) 	  // F_CS = 1;
#define F_CS_Low   LPC_GPIO1->DATA&=~(1<<10)	  // F_CS = 0;
//#define	F_CS_High  LPC_GPIO0->DATA|=(1<<7) 	  // F_CS = 1;
//#define F_CS_Low   LPC_GPIO0->DATA&=~(1<<7)	  // F_CS = 0;

#define GBK_EN			 
////////////////////////////////////////////////////////////////////////////
//W25Q16读写
#define FLASH_ID 0XEF14
//指令�?
#define W25Q_WriteEnable		0x06 
#define W25Q_WriteDisable		0x04 
#define W25Q_ReadStatusReg		0x05 
#define W25Q_WriteStatusReg		0x01 
#define W25Q_ReadData			0x03 
#define W25Q_FastReadData		0x0B 
#define W25Q_FastReadDual		0x3B 
#define W25Q_PageProgram		0x02 
#define W25Q_BlockErase			0xD8 
#define W25Q_SectorErase		0x20 
#define W25Q_ChipErase			0xC7 
#define W25Q_PowerDown			0xB9 
#define W25Q_ReleasePowerDown	0xAB 
#define W25Q_DeviceID			0xAB 
#define W25Q_ManufactDeviceID	0x90 
#define W25Q_JedecDeviceID		0x9F 







extern void W25Q16_Init(void);	// 初始化W25Q16
extern uint16_t W25Q16_ReadID(void);  //读取W25Q16 ID�?
extern uint8_t W25Q16_ReadSR(void);//读取状�?�寄存器 
extern void W25Q16_Write_SR(uint8_t sr); //写状态寄存器
extern void W25Q16_Write_Enable(void);   //写使�? 
extern void W25Q16_Write_Disable(void);//写禁�?
extern void W25Q16_Read(uint8_t* Buffer,uint32_t Addr,uint16_t ByteNum);  //读取W25Q16
extern void W25Q16_Write_Page(uint8_t* Buffer,uint32_t Addr,uint16_t ByteNum);//写一页W25Q16
extern void W25Q16_Write(uint8_t* Buffer,uint32_t Addr,uint16_t NumByte);//写多页W25Q16
extern void W25Q16_Erase_Chip(void);  //整片擦除
extern void W25Q16_Erase_Sector(uint32_t Dst_Addr);//扇区擦除
extern void W25Q16_Erase_Block(uint32_t Bst_Addr); // 块区擦除
extern void W25Q16_Wait_Busy(void);       //等待空闲


#endif
















