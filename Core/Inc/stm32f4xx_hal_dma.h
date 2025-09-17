#ifndef __STM32F4xx_HAL_DMA_H
#define __STM32F4xx_HAL_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_def.h"

/* DMA handle structures definition */
typedef struct __DMA_HandleTypeDef
{
  void                 *Instance;
  void                 *Init;
  HAL_LockTypeDef      Lock;
  uint32_t             State;
  void                 *Parent;
  void                 (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);
  void                 (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);
  void                 (* XferM1CpltCallback)( struct __DMA_HandleTypeDef * hdma);
  void                 (* XferM1HalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);
  void                 (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);
  void                 (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);
  uint32_t             ErrorCode;
  uint32_t             StreamBaseAddress;
  uint32_t             StreamIndex;
} DMA_HandleTypeDef;

/* DMA function declarations */
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_DMA_H */
