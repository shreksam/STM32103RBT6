#include "LMP91000.h" 
//#include "delay.h" 
#include "delay.h"
//Mini STM32开发板
//24CXX驱动函数(适合24C01~24C16,24C32~256未经过测试!有待验证!)
//正点原子@ALIENTEK
//2010/6/10
//V1.2


//在LMP91000指定地址读出一个数据
//ReadAddr:开始读数的地址  
//返回值  :读到的数据
u8 LMP91000_ReadOneByte(u8 ReadAddr)
{				  
	u8 temp=0;		  	    																 
    IIC_Start();  
	IIC_Send_Byte(LMP91000_I2C_Address_W);	   //发送器件地址
	IIC_Wait_Ack();
	IIC_Send_Byte(ReadAddr);	   //发送寄存器地址
	IIC_Wait_Ack();

	IIC_Start();  	 	   
	IIC_Send_Byte(LMP91000_I2C_Address_R);	   //发送器件地址		   
	IIC_Wait_Ack();	 
    temp=IIC_Read_Byte(0);
	IIC_NAck();		   
    IIC_Stop();//产生一个停止条件	    
	return temp;
}

//在LMP91000指定地址写入一个数据
//WriteAddr  :写入数据的目的地址    
//DataToWrite:要写入的数据
void LMP91000_WriteOneByte(u8 WriteAddr,u8 DataToWrite)
{				   	  	    																 
    IIC_Start();  
	IIC_Send_Byte(LMP91000_I2C_Address_W);	   //发送器件地址	 
	IIC_Wait_Ack();	   
    IIC_Send_Byte(WriteAddr);   //发送寄存器地址
	IIC_Wait_Ack(); 	 										  		   
	IIC_Send_Byte(DataToWrite);     //发送字节							   
	IIC_Wait_Ack();  		    	   
    IIC_Stop();//产生一个停止条件
	delay_ms(10);	 
}



//检查LMP91000是否ready
//返回1:ready
//返回0:not ready（default）
u8 LMP91000_Status(void)
{
	u8 temp;
//	LM91000_ENABLE();
	temp=LMP91000_ReadOneByte(TI_LMP91000_STATUS_REG);			   
//	LM91000_DISABLE();
	return temp;											  
}


 void LMP91000_ENABLE(void)
 {
    GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //使能PC端口时钟
	
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				 //PC.6 端口配置
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
 	GPIO_ResetBits(GPIOC,GPIO_Pin_6);						 //PC.6 输出0

 }


 void LMP91000_DISABLE(void)
 {
    GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //使能PC端口时钟
	
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				 //PC.6 端口配置
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOC,GPIO_Pin_6);						 //PC.6 输出1

 }







