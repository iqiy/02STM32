
/**
  ******************************************************************************
  * @file     BSP.c
  * @author   Phone
  * @version  V1.0
  * @date      2014/11/06
  * @brief    外设配置函数
  ******************************************************************************
  * @attention
  * 雅典娜程序
  * CPJ智能控制
  * @endverbatim
  ******************************************************************************
  * @attention
  * 无
  ******************************************************************************
  */ 
		
#include <stm32f10x.h>

#include "BSP.h"

#include "bsp_led.h"  
#include "bsp_usart1.h"
#include "delay.h"
#include "bsp_exti.h"

/**-------------------------------------------------------------------------------
  * @brief   独立看门狗配置
  * @param   无
  * @retval    无
---------------------------------------------------------------------------------*/

void ALL_Config(void)
{
	LED_GPIO_Config();
  USART1_Config();
	NVIC_Configuration();
	delay_init(72);
	EXTI_PA4_Config();
}


/*********************************************END OF FILE**********************/



























