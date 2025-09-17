#ifndef __STM32F4xx_HAL_EXTI_H
#define __STM32F4xx_HAL_EXTI_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_def.h"

/* EXTI mode enumeration */
typedef enum
{
  HAL_EXTI_COMMON_CB_ID          = 0x00U
} EXTI_CallbackIDTypeDef;

/* EXTI Handle structures definition */
typedef struct
{
  uint32_t Line;                    /*!<  Exti line number */
  void (* PendingCallback)(void);   /*!<  Exti pending callback */
} EXTI_HandleTypeDef;

/* EXTI configuration structure definition */
typedef struct
{
  uint32_t Line;      /*!< The Exti line to be configured. This parameter
                           can be a value of @ref EXTI_Line */
  uint32_t Mode;      /*!< The Exit Mode to be configured for a core.
                           This parameter can be a combination of @ref EXTI_Mode */
  uint32_t Trigger;   /*!< The Exti Trigger to be configured. This parameter
                           can be a value of @ref EXTI_Trigger */
  uint32_t GPIOSel;   /*!< The Exti GPIO multiplexer selection to be configured.
                           This parameter is only possible for line 0 to 15. It
                           can be a value of @ref EXTI_GPIOSel */
} EXTI_ConfigTypeDef;

/* EXTI line definition */
#define EXTI_LINE_0                        (EXTI_GPIO | EXTI_REG1 | 0x00u)
#define EXTI_LINE_1                        (EXTI_GPIO | EXTI_REG1 | 0x01u)
#define EXTI_LINE_2                        (EXTI_GPIO | EXTI_REG1 | 0x02u)
#define EXTI_LINE_3                        (EXTI_GPIO | EXTI_REG1 | 0x03u)
#define EXTI_LINE_4                        (EXTI_GPIO | EXTI_REG1 | 0x04u)
#define EXTI_LINE_5                        (EXTI_GPIO | EXTI_REG1 | 0x05u)
#define EXTI_LINE_6                        (EXTI_GPIO | EXTI_REG1 | 0x06u)
#define EXTI_LINE_7                        (EXTI_GPIO | EXTI_REG1 | 0x07u)
#define EXTI_LINE_8                        (EXTI_GPIO | EXTI_REG1 | 0x08u)
#define EXTI_LINE_9                        (EXTI_GPIO | EXTI_REG1 | 0x09u)
#define EXTI_LINE_10                       (EXTI_GPIO | EXTI_REG1 | 0x0Au)
#define EXTI_LINE_11                       (EXTI_GPIO | EXTI_REG1 | 0x0Bu)
#define EXTI_LINE_12                       (EXTI_GPIO | EXTI_REG1 | 0x0Cu)
#define EXTI_LINE_13                       (EXTI_GPIO | EXTI_REG1 | 0x0Du)
#define EXTI_LINE_14                       (EXTI_GPIO | EXTI_REG1 | 0x0Eu)
#define EXTI_LINE_15                       (EXTI_GPIO | EXTI_REG1 | 0x0Fu)

/* EXTI constants */
#define EXTI_GPIO                          0x00000001u
#define EXTI_REG1                          0x00000000u
#define EXTI_MODE_NONE                     0x00000000u
#define EXTI_MODE_INTERRUPT                0x00000001u
#define EXTI_MODE_EVENT                    0x00000002u
#define EXTI_TRIGGER_NONE                  0x00000000u
#define EXTI_TRIGGER_RISING                0x00000001u
#define EXTI_TRIGGER_FALLING               0x00000002u
#define EXTI_TRIGGER_RISING_FALLING        (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)
#define EXTI_GPIOA                         0x00000000u
#define EXTI_GPIOB                         0x00000001u
#define EXTI_GPIOC                         0x00000002u
#define EXTI_GPIOD                         0x00000003u
#define EXTI_GPIOE                         0x00000004u
#define EXTI_GPIOH                         0x00000007u

/* EXTI function declarations */
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);
void HAL_EXTI_IRQHandler(EXTI_HandleTypeDef *hexti);
uint32_t HAL_EXTI_GetPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_ClearPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_GenerateSWI(EXTI_HandleTypeDef *hexti);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_EXTI_H */
