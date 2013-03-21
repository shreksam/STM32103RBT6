#ifndef __TSENSOR_H
#define __TSENSOR_H	
#include "stm32f10x.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//Mini STM32开发板
//ADC 驱动代码			   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2010/6/7 
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 正点原子 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  

/*
#define T_ADC_CH0  0  //通道0
#define T_ADC_CH1  1  //通道1
#define T_ADC_CH2  2  //通道2
#define T_ADC_CH3  3  //通道3
#define T_TEMP_CH  16 //温度传感器通道
*/
	   
u16  T_Get_Temp(void);  //取得温度值
void T_Adc_Init(void); //ADC通道初始化
u16  T_Get_Adc(u8 ch); //获得某个通道值  	  
#endif 
