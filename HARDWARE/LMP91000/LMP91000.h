#ifndef __24CXX_H
#define __24CXX_H
#include "myiic.h"   
//Mini STM32开发板
//24CXX驱动函数(适合24C01~24C16,24C32~256未经过测试!有待验证!)
//正点原子@ALIENTEK
//2010/6/10
//V1.2

u8 LMP91000_ReadOneByte(u8 ReadAddr);
void LMP91000_ENABLE(void);
void LMP91000_DISABLE(void);
u8 LMP91000_Status(void);
void LMP91000_WriteOneByte(u8 WriteAddr,u8 DataToWrite);

#endif



/************************************************************
* TI LMP91000 REGISTER SET ADDRESSES
************************************************************/

#define LMP91000_I2C_Address_R                         (0x91)                  // Device Address
#define LMP91000_I2C_Address_W                         (0x90)   
#define TI_LMP91000_STATUS_REG                         (0x00)                  /* Read only status register */
#define TI_LMP91000_LOCK_REG                           (0x01)                  /* Protection Register */
#define TI_LMP91000_TIACN_REG                          (0x10)                  /* TIA Control Register */
#define TI_LMP91000_REFCN_REG                          (0x11)                  /* Reference Control Register*/
#define TI_LMP91000_MODECN_REG                         (0x12)                  /* Mode Control Register */

#define TI_LMP91000_WRITE_LOCK                         (0x01)
#define TI_LMP91000_WRITE_UNLOCK                       (0x00)
#define TI_LMP91000_READY                              (0x01)
#define TI_LMP91000_NOT_READY                          (0x00)

/************************************************************
* TI LMP91000 REGISTER set VALUE
************************************************************/

#define TIACN_NEW_VALUE									(0x1f)	//0x1b:120k,100ohm   0x1f:350k,100ohm，实验证明，RLOAD对于输出没有影响  
#define REFCN_NEW_VALUE									(0x4d)	//配置为0xcd(ref_v=2.5V)：输出为1.635V(air)~1.645V(water) ;
																//配置为0x4d(ref_v=3.3V)：输出为2.166V(air)~2.181V(water) ;
																// 配置成0xdd则无论电极是否在水里，adcx始终在0x821（1.676v）

#define MODECN_NEW_VALUE								(0x03)	//实验证明，只能配置为3-lead,配置为2-lead时输出为0


/************************************************************
*极化电压为0.68V，配置ref_v=3.3V,极化电压为3.3×0.67×0.24=0.53V
*若供电电压改为5V，则极化电压为5×0.67×0.20=0.67V
*电极的输出为1～100nA，放大350k后，vout=0.35～35mV，而ADC分辨率
*为3.3/4.96=0.8mV。
*论文中提到，电极在空气中响应为60nA，则vout=60nA×350k=21mV
*则在无氧水和空气中，若VOUT相差21mV，则可基本验证电路
*
************************************************************/




