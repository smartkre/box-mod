#ifndef __STM32F4xx_HAL_ADC_H
#define __STM32F4xx_HAL_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_def.h"

/* ADC state definition */
#define HAL_ADC_STATE_RESET                    0x00000000U
#define HAL_ADC_STATE_READY                    0x00000001U
#define HAL_ADC_STATE_BUSY_INTERNAL            0x00000002U
#define HAL_ADC_STATE_TIMEOUT                  0x00000003U

/* ADC Error Code */
#define HAL_ADC_ERROR_NONE                     0x00U   /*!< No error             */
#define HAL_ADC_ERROR_INTERNAL                 0x01U   /*!< ADC IP internal error*/
#define HAL_ADC_ERROR_OVR                      0x02U   /*!< Overrun error        */
#define HAL_ADC_ERROR_DMA                      0x04U   /*!< DMA transfer error   */

/* ADC channels */
#define ADC_CHANNEL_0                          0x00000000U
#define ADC_CHANNEL_1                          0x00000001U
#define ADC_CHANNEL_2                          0x00000002U
#define ADC_CHANNEL_3                          0x00000003U
#define ADC_CHANNEL_4                          0x00000004U
#define ADC_CHANNEL_5                          0x00000005U
#define ADC_CHANNEL_6                          0x00000006U
#define ADC_CHANNEL_7                          0x00000007U
#define ADC_CHANNEL_8                          0x00000008U
#define ADC_CHANNEL_9                          0x00000009U
#define ADC_CHANNEL_10                         0x0000000AU
#define ADC_CHANNEL_11                         0x0000000BU
#define ADC_CHANNEL_12                         0x0000000CU
#define ADC_CHANNEL_13                         0x0000000DU
#define ADC_CHANNEL_14                         0x0000000EU
#define ADC_CHANNEL_15                         0x0000000FU

/* ADC sampling time */
#define ADC_SAMPLETIME_3CYCLES                 0x00000000U
#define ADC_SAMPLETIME_15CYCLES                0x00000001U
#define ADC_SAMPLETIME_28CYCLES                0x00000002U
#define ADC_SAMPLETIME_56CYCLES                0x00000003U
#define ADC_SAMPLETIME_84CYCLES                0x00000004U
#define ADC_SAMPLETIME_112CYCLES               0x00000005U
#define ADC_SAMPLETIME_144CYCLES               0x00000006U
#define ADC_SAMPLETIME_480CYCLES               0x00000007U

/* ADC resolution */
#define ADC_RESOLUTION_12B                     0x00000000U
#define ADC_RESOLUTION_10B                     0x00000001U
#define ADC_RESOLUTION_8B                      0x00000002U
#define ADC_RESOLUTION_6B                      0x00000003U

/* ADC data align */
#define ADC_DATAALIGN_RIGHT                    0x00000000U
#define ADC_DATAALIGN_LEFT                     0x00000001U

/* ADC scan conversion mode */
#define ADC_SCAN_DISABLE                       0x00000000U
#define ADC_SCAN_ENABLE                        0x00000001U

/* ADC continuous conversion mode */
#define ADC_CONTINUOUS_DISABLE                 0x00000000U
#define ADC_CONTINUOUS_ENABLE                  0x00000001U

/* ADC discontinuous conversion mode */
#define ADC_DISCONTINUOUS_DISABLE              0x00000000U
#define ADC_DISCONTINUOUS_ENABLE               0x00000001U

/* ADC external trigger */
#define ADC_SOFTWARE_START                     0x00000000U

/* ADC structures */
typedef struct
{
  uint32_t ClockPrescaler;
  uint32_t Resolution;
  uint32_t DataAlign;
  uint32_t ScanConvMode;
  uint32_t EOCSelection;
  uint32_t ContinuousConvMode;
  uint32_t NbrOfConversion;
  uint32_t DiscontinuousConvMode;
  uint32_t NbrOfDiscConversion;
  uint32_t ExternalTrigConv;
  uint32_t ExternalTrigConvEdge;
  uint32_t DMAContinuousRequests;
} ADC_InitTypeDef;

typedef struct
{
  uint32_t Channel;
  uint32_t Rank;
  uint32_t SamplingTime;
  uint32_t Offset;
} ADC_ChannelConfTypeDef;

typedef struct __ADC_HandleTypeDef
{
  void                     *Instance;
  ADC_InitTypeDef          Init;
  uint32_t                 NbrOfCurrentConversionRank;
  void                     *DMA_Handle;
  HAL_LockTypeDef          Lock;
  uint32_t                 State;
  uint32_t                 ErrorCode;
} ADC_HandleTypeDef;

/* ADC function declarations */
HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef *hadc);
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);
HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc);
void HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);
HAL_StatusTypeDef HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc);
uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef* hadc);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc);
void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc);
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);
uint32_t HAL_ADC_GetState(ADC_HandleTypeDef* hadc);
uint32_t HAL_ADC_GetError(ADC_HandleTypeDef *hadc);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_ADC_H */
