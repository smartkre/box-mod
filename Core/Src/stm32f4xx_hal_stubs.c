#include "main.h"

/* Заглушки HAL функций */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct)
{
  /* Простая заглушка - ничего не делаем, возвращаем OK */
  (void)RCC_OscInitStruct; /* Убираем warning о неиспользованном параметре */
  return HAL_OK;
}

HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency)
{
  /* Простая заглушка - ничего не делаем, возвращаем OK */
  (void)RCC_ClkInitStruct; /* Убираем warning о неиспользованном параметре */
  (void)FLatency;          /* Убираем warning о неиспользованном параметре */
  return HAL_OK;
}

void HAL_GPIO_Init(void *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
  /* Заглушка GPIO инициализации */
  (void)GPIOx;
  (void)GPIO_Init;
}

void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
  /* Заглушка SPI MSP */
  (void)hspi;
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  /* Заглушка ADC MSP */
  (void)hadc;
}
