#ifndef __STM32F4xx_HAL_H
#define __STM32F4xx_HAL_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_conf.h"

/* STM32F4xx HAL library includes */
#include "stm32f401xc.h"

/* HAL modules */
typedef enum 
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

/* System functions */
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_IncTick(void);
uint32_t HAL_GetTick(void);
void HAL_Delay(uint32_t Delay);

/* GPIO definitions */
typedef struct
{
  uint32_t Pin;
  uint32_t Mode;
  uint32_t Pull;
  uint32_t Speed;
  uint32_t Alternate;
} GPIO_InitTypeDef;

typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
} GPIO_PinState;

/* RCC definitions */
typedef struct
{
  uint32_t OscillatorType;
  uint32_t HSEState;
  uint32_t HSIState;
  uint32_t HSICalibrationValue;
  struct {
    uint32_t PLLState;
    uint32_t PLLSource;
    uint32_t PLLM;
    uint32_t PLLN;
    uint32_t PLLP;
    uint32_t PLLQ;
  } PLL;
} RCC_OscInitTypeDef;

typedef struct
{
  uint32_t ClockType;
  uint32_t SYSCLKSource;
  uint32_t AHBCLKDivider;
  uint32_t APB1CLKDivider;
  uint32_t APB2CLKDivider;
} RCC_ClkInitTypeDef;

/* HAL function declarations */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);
void HAL_GPIO_Init(void *GPIOx, GPIO_InitTypeDef *GPIO_Init);

/* RCC macros */
#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { } while(0)
#define __HAL_RCC_GPIOB_CLK_ENABLE()   do { } while(0)  
#define __HAL_RCC_GPIOC_CLK_ENABLE()   do { } while(0)
#define __HAL_RCC_GPIOH_CLK_ENABLE()   do { } while(0)
#define __HAL_RCC_PWR_CLK_ENABLE()     do { } while(0)
#define __HAL_PWR_VOLTAGESCALING_CONFIG(x) do { } while(0)

/* RCC constants */
#define RCC_OSCILLATORTYPE_HSI     0x01U
#define RCC_HSI_ON                 0x01U
#define RCC_HSICALIBRATION_DEFAULT 16U
#define RCC_PLL_ON                 0x01U
#define RCC_PLLSOURCE_HSI          0x00U
#define RCC_PLLP_DIV4              0x01U
#define RCC_CLOCKTYPE_HCLK         0x01U
#define RCC_CLOCKTYPE_SYSCLK       0x02U
#define RCC_CLOCKTYPE_PCLK1        0x04U
#define RCC_CLOCKTYPE_PCLK2        0x08U
#define RCC_SYSCLKSOURCE_PLLCLK    0x02U
#define RCC_SYSCLK_DIV1            0x00U
#define RCC_HCLK_DIV2              0x04U
#define RCC_HCLK_DIV1              0x00U
#define FLASH_LATENCY_2            0x02U

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_H */
