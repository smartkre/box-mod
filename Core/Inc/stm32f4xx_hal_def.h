#ifndef __STM32F4xx_HAL_DEF
#define __STM32F4xx_HAL_DEF

#ifdef __cplusplus
 extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

/* HAL Status definitions */
typedef enum 
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

/* HAL Lock definitions */
typedef enum 
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U  
} HAL_LockTypeDef;

/* RCC structures */
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

/* RCC константы - добавляем недостающие */
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

/* RCC макросы - заглушки */
#define __HAL_RCC_PWR_CLK_ENABLE()     do { } while(0)
#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { } while(0)
#define __HAL_RCC_GPIOB_CLK_ENABLE()   do { } while(0)  
#define __HAL_RCC_GPIOC_CLK_ENABLE()   do { } while(0)
#define __HAL_RCC_GPIOH_CLK_ENABLE()   do { } while(0)

/* Function declarations */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_DEF */
