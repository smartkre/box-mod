#ifndef __STM32F4xx_HAL_H
#define __STM32F4xx_HAL_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Включаем конфигурацию HAL */
#include "stm32f4xx_hal_conf.h"

/* Включаем базовые определения */
#include "stm32f401xc.h"

/* Системные функции - простые заглушки */
static inline HAL_StatusTypeDef HAL_Init(void) { return HAL_OK; }
static inline HAL_StatusTypeDef HAL_DeInit(void) { return HAL_OK; }
static inline void HAL_IncTick(void) { }
static inline uint32_t HAL_GetTick(void) { return 0; }
static inline void HAL_Delay(uint32_t Delay) { 
    volatile uint32_t i;
    /* Простая задержка - неточная, но работающая */
    for(uint32_t j = 0; j < Delay; j++) {
        for(i = 0; i < 16000; i++) { }
    }
}

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_H */
