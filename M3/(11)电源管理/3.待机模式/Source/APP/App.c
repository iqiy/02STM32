/**
  ******************************************************************************
  * @file    APP.c
  * @author  phone
  * @version V1.0
  * @date    2014-11-09
  * @brief   电源管理之睡眠
  ******************************************************************************
  * @attention
  *
  * @{实验平台:野火 iSO STM32 开发板 
  * @{雅典娜程序整理	
	* @{ http://www.cnblogs.com/Ph-one/
  ******************************************************************************
  */ 
	
/* Includes ------------------------------------------------------------------*/
#include <stm32f10x.h>
#include "BSP.h"
#include "bsp_led.h"  
#include "bsp_usart1.h"
#include "bsp_exti.h" 
#include "delay.h"

#define CLI()      __set_PRIMASK(1)		/* 关闭总中断 */  
#define SEI() __set_PRIMASK(0)				/* 开放总中断 */

void SYSCLKConfig_STOP(void);

/**---------------------------------------------------------------------------------
  * @brief       CPU延时
  * @param    		无	
  ---------------------------------------------------------------------------------*/
#if 1
static void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
#endif

#if 1
/**---------------------------------------------------------------------------------
  * @brief       主函数.
  * @param    		无
  *	@arg         NULL
  * @retval     null
  ---------------------------------------------------------------------------------*/
int main(void)
{
	/*首先是调用系统时钟，在3.0版本的库中，
	在main函数中仍需调用，在3.5版本中，
	系统时钟放在了启动文件这里
	函数运行的时候是先从这个汇编函数执行的
	启动文件 151行    ：
	LDR     R0, =SystemInit			  ;设置系统时钟
	SetSysClock();	
	*/
	/*便于在线调试*/
	#ifdef DEBUG
		debug();
	#endif
	
	/*外设硬件初始化*/
	ALL_Config();
	EXTI_PC13_Config();
	//	CLI();  	//关
	//	SEI();		//开
	//	EXTI_PA0_Config();
	
	if(PWR_GetFlagStatus(PWR_FLAG_WU) == SET)
	{
		printf("\r\n 使能电源管理时钟单元前的检测，待机唤醒复位 \r\n");

	}
	else
		printf("\r\n 使能电源管理时钟单元前的检测，上电复位 \r\n");
	
	
	/* 使能电源管理单元的时钟 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR , ENABLE);
	
	
	if(PWR_GetFlagStatus(PWR_FLAG_WU) == SET)
	{
		printf("\r\n 使能后检测，待机唤醒复位 \r\n");

	}
	else
		printf("\r\n 使能后检测，上电复位 \r\n");
	
	
	while(1)
	{
		/* wait interrupt */
		LED1( ON );			  // 亮
		Delay(0xFFFFF);
		LED1( OFF );		  // 灭

		LED2( ON );			  // 亮
		Delay(0xFFFFF);
		LED2( OFF );		  // 灭

		LED3( ON );			  // 亮
		Delay(0xFFFFF);
		LED3( OFF );		  // 灭		
	
		//__WFI();					//进入睡眠模式，等待中断唤醒
	}
}
#endif

/**---------------------------------------------------------------------------------
  * @brief       检测传递给函数的参数是否是有效的参数
  * @param    		无
	* @example		 某个参数的取值范围只能是小于3的正整数，如果给出的参数大于3，
	* @example	   则这个assert_param()可以再运行程序调用到这个函数时报错			
  ---------------------------------------------------------------------------------*/
#ifdef DEBUG
void assert_failed(uint8_t* file, uint32_t line){
while (1);}
#endif
/*********************************************END OF FILE**********************/




