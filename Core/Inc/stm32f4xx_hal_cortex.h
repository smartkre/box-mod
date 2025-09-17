#ifndef __STM32F4xx_HAL_CORTEX_H
#define __STM32F4xx_HAL_CORTEX_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_def.h"

/* NVIC Priority group definitions */
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bits for pre-emption priority, 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bits for pre-emption priority, 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority, 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority, 1 bits for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority, 0 bits for subpriority */

/* SysTick clock source definitions */
#define SYSTICK_CLKSOURCE_HCLK_DIV8    ((uint32_t)0x00000000)
#define SYSTICK_CLKSOURCE_HCLK         ((uint32_t)0x00000004)

/* Cortex-M4 functions */
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
void HAL_NVIC_SetPriority(int32_t IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(int32_t IRQn);
void HAL_NVIC_DisableIRQ(int32_t IRQn);
void HAL_NVIC_SystemReset(void);
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb);
void HAL_NVIC_GetPriority(int32_t IRQn, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority);
uint32_t HAL_NVIC_GetPriorityGrouping(void);
void HAL_NVIC_GetPendingIRQ(int32_t IRQn);
void HAL_NVIC_SetPendingIRQ(int32_t IRQn);
void HAL_NVIC_ClearPendingIRQ(int32_t IRQn);
uint32_t HAL_NVIC_GetActive(int32_t IRQn);
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource);
void HAL_SYSTICK_IRQHandler(void);
void HAL_SYSTICK_Callback(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_CORTEX_H */
