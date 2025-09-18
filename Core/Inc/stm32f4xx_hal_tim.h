#ifndef __STM32F4xx_HAL_TIM_H
#define __STM32F4xx_HAL_TIM_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_def.h"

/* TIM Error Code */
#define HAL_TIM_ERROR_NONE                        0x00000000U    /*!< No error            */
#define HAL_TIM_ERROR_BASE                        0x00000001U    /*!< Base related error  */
#define HAL_TIM_ERROR_OC                          0x00000002U    /*!< Output compare error  */
#define HAL_TIM_ERROR_PWM                         0x00000004U    /*!< PWM related error   */
#define HAL_TIM_ERROR_IC                          0x00000008U    /*!< Input capture error */
#define HAL_TIM_ERROR_ENCODER                     0x00000010U    /*!< Encoder related error */
#define HAL_TIM_ERROR_DMA                         0x00000020U    /*!< DMA related error   */

/* TIM State definition */
#define HAL_TIM_STATE_RESET                       0x00000000U    /*!< Peripheral not yet initialized or disabled  */
#define HAL_TIM_STATE_READY                       0x00000001U    /*!< Peripheral Initialized and ready for use    */
#define HAL_TIM_STATE_BUSY                        0x00000002U    /*!< An internal process is ongoing               */
#define HAL_TIM_STATE_TIMEOUT                     0x00000003U    /*!< Timeout state                                */
#define HAL_TIM_STATE_ERROR                       0x00000004U    /*!< Reception process is ongoing                 */

/* TIM Channel definition */
#define TIM_CHANNEL_1                      0x00000000U
#define TIM_CHANNEL_2                      0x00000004U
#define TIM_CHANNEL_3                      0x00000008U
#define TIM_CHANNEL_4                      0x0000000CU
#define TIM_CHANNEL_ALL                    0x00000018U

/* TIM Counter Mode */
#define TIM_COUNTERMODE_UP                 0x00000000U
#define TIM_COUNTERMODE_DOWN               TIM_CR1_DIR
#define TIM_COUNTERMODE_CENTERALIGNED1     TIM_CR1_CMS_0
#define TIM_COUNTERMODE_CENTERALIGNED2     TIM_CR1_CMS_1
#define TIM_COUNTERMODE_CENTERALIGNED3     TIM_CR1_CMS

/* TIM Clock Division */
#define TIM_CLOCKDIVISION_DIV1                       0x00000000U
#define TIM_CLOCKDIVISION_DIV2                       TIM_CR1_CKD_0
#define TIM_CLOCKDIVISION_DIV4                       TIM_CR1_CKD_1

/* TIM Output Compare and PWM modes */
#define TIM_OCMODE_TIMING                   0x00000000U
#define TIM_OCMODE_ACTIVE                   TIM_CCMR1_OC1M_0
#define TIM_OCMODE_INACTIVE                 TIM_CCMR1_OC1M_1
#define TIM_OCMODE_TOGGLE                   (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_PWM1                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1)
#define TIM_OCMODE_PWM2                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_FORCED_ACTIVE            (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_FORCED_INACTIVE          TIM_CCMR1_OC1M_2

/* TIM constants */
#define TIM_CR1_DIR                         0x0010U
#define TIM_CR1_CMS                         0x0060U
#define TIM_CR1_CMS_0                       0x0020U
#define TIM_CR1_CMS_1                       0x0040U
#define TIM_CR1_CKD_0                       0x0100U
#define TIM_CR1_CKD_1                       0x0200U
#define TIM_CCMR1_OC1M_0                    0x0010U
#define TIM_CCMR1_OC1M_1                    0x0020U
#define TIM_CCMR1_OC1M_2                    0x0040U

/* TIM structures */
typedef struct
{
  uint32_t Prescaler;         /*!< Specifies the prescaler value used to divide the TIM clock. */
  uint32_t CounterMode;       /*!< Specifies the counter mode. */
  uint32_t Period;            /*!< Specifies the period value to be loaded into the active Auto-Reload Register at the next update event. */
  uint32_t ClockDivision;     /*!< Specifies the clock division. */
  uint32_t RepetitionCounter; /*!< Specifies the repetition counter value. Each time the RCR downcounter reaches zero, an update event is generated. */
  uint32_t AutoReloadPreload; /*!< Specifies the auto-reload preload. */
} TIM_Base_InitTypeDef;

typedef struct
{
  uint32_t OCMode;        /*!< Specifies the TIM mode. */
  uint32_t Pulse;         /*!< Specifies the pulse value to be loaded into the Capture Compare Register. */
  uint32_t OCPolarity;    /*!< Specifies the output polarity. */
  uint32_t OCNPolarity;   /*!< Specifies the complementary output polarity. */
  uint32_t OCFastMode;    /*!< Specifies the Fast mode state. */
  uint32_t OCIdleState;   /*!< Specifies the TIM Output Compare pin state during Idle state. */
  uint32_t OCNIdleState;  /*!< Specifies the TIM Output Compare pin state during Idle state. */
} TIM_OC_InitTypeDef;

typedef struct __TIM_HandleTypeDef
{
  void                         *Instance;     /*!< Register base address             */
  TIM_Base_InitTypeDef         Init;          /*!< TIM Time Base required parameters */
  uint32_t                     Channel;       /*!< Active channel                    */
  void                         *hdma[7];      /*!< DMA Handlers array This array is accessed by a @ref DMA_Handle_index */
  HAL_LockTypeDef              Lock;          /*!< Locking object                    */
  uint32_t                     State;         /*!< TIM operation state               */
} TIM_HandleTypeDef;

/* TIM function declarations */
HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_Base_Stop_DMA(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_OC_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_OC_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_OC_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_OC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_PWM_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_OC_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef *sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef *sConfig, uint32_t Channel);

void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim);

uint32_t HAL_TIM_GetState(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_TIM_H */
