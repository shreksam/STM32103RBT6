#ifndef __24L01_H
#define __24L01_H	 		  
#include "sys.h"   
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//Mini STM32开发板
//NRF24L01 驱动函数	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2010/6/16 
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 正点原子 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  


/************************************************************
* TI LMP91200 REGISTER SET INITIALIZATION VALUES
************************************************************/

#define TI_LMP91200_CONFIG_REG_VALUE                  (0xB080)                 /* Temp Measurement, RTD, 2mA, PGA=5, VOCM=GND */                          
#define TI_LMP91200_CONFIG_REG_NEW_VALUE              (0xA080)                 /* Temp Measurement, RTD, 1mA, PGA=5, VOCM=GND */
#define TI_LMP91200_CONFIG_REG_TEST_VALUE             (0x0080)				   /* VOCM=GND */

#define Set_LMP91200_CSN  {GPIO_SetBits(GPIOC,GPIO_Pin_4);}
#define Clr_LMP91200_CSN  {GPIO_ResetBits(GPIOC,GPIO_Pin_4);}
		 
 

void LMP91200_Init(void);//初始化

#endif











