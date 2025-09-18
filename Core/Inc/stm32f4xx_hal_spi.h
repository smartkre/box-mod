#ifndef __STM32F4xx_HAL_SPI_H
#define __STM32F4xx_HAL_SPI_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_def.h"

/* SPI Error Code */
#define HAL_SPI_ERROR_NONE              0x00000000U   /*!< No error                               */
#define HAL_SPI_ERROR_MODF              0x00000001U   /*!< MODF error                             */
#define HAL_SPI_ERROR_CRC               0x00000002U   /*!< CRC error                              */
#define HAL_SPI_ERROR_OVR               0x00000004U   /*!< OVR error                              */
#define HAL_SPI_ERROR_FRE               0x00000008U   /*!< FRE error                              */
#define HAL_SPI_ERROR_DMA               0x00000010U   /*!< DMA transfer error                     */
#define HAL_SPI_ERROR_FLAG              0x00000020U   /*!< Error on RXNE/TXE/BSY Flag             */
#define HAL_SPI_ERROR_ABORT             0x00000040U   /*!< Error during SPI Abort procedure      */

/* SPI State */
#define HAL_SPI_STATE_RESET             0x00000000U   /*!< Peripheral not Initialized                         */
#define HAL_SPI_STATE_READY             0x00000001U   /*!< Peripheral Initialized and ready for use           */
#define HAL_SPI_STATE_BUSY              0x00000002U   /*!< an internal process is ongoing                      */
#define HAL_SPI_STATE_BUSY_TX           0x00000003U   /*!< Data Transmission process is ongoing                */
#define HAL_SPI_STATE_BUSY_RX           0x00000004U   /*!< Data Reception process is ongoing                   */
#define HAL_SPI_STATE_BUSY_TX_RX        0x00000005U   /*!< Data Transmission and Reception process is ongoing  */
#define HAL_SPI_STATE_ERROR             0x00000006U   /*!< SPI error state                                     */
#define HAL_SPI_STATE_ABORT             0x00000007U   /*!< SPI abort is ongoing                                */

/* SPI Mode */
#define SPI_MODE_SLAVE                  0x00000000U
#define SPI_MODE_MASTER                 (SPI_CR1_MSTR | SPI_CR1_SSI)

/* SPI Direction */
#define SPI_DIRECTION_2LINES            0x00000000U
#define SPI_DIRECTION_2LINES_RXONLY     SPI_CR1_RXONLY
#define SPI_DIRECTION_1LINE             SPI_CR1_BIDIMODE

/* SPI Data Size */
#define SPI_DATASIZE_8BIT               0x00000000U
#define SPI_DATASIZE_16BIT              SPI_CR1_DFF

/* SPI Clock Polarity */
#define SPI_POLARITY_LOW                0x00000000U
#define SPI_POLARITY_HIGH               SPI_CR1_CPOL

/* SPI Clock Phase */
#define SPI_PHASE_1EDGE                 0x00000000U
#define SPI_PHASE_2EDGE                 SPI_CR1_CPHA

/* SPI Slave Select management */
#define SPI_NSS_SOFT                    SPI_CR1_SSM
#define SPI_NSS_HARD_INPUT              0x00000000U
#define SPI_NSS_HARD_OUTPUT             (SPI_CR2_SSOE << 16U)

/* SPI BaudRate Prescaler */
#define SPI_BAUDRATEPRESCALER_2         0x00000000U
#define SPI_BAUDRATEPRESCALER_4         (SPI_CR1_BR_0)
#define SPI_BAUDRATEPRESCALER_8         (SPI_CR1_BR_1)
#define SPI_BAUDRATEPRESCALER_16        (SPI_CR1_BR_1 | SPI_CR1_BR_0)
#define SPI_BAUDRATEPRESCALER_32        (SPI_CR1_BR_2)
#define SPI_BAUDRATEPRESCALER_64        (SPI_CR1_BR_2 | SPI_CR1_BR_0)
#define SPI_BAUDRATEPRESCALER_128       (SPI_CR1_BR_2 | SPI_CR1_BR_1)
#define SPI_BAUDRATEPRESCALER_256       (SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0)

/* SPI MSB/LSB transmission */
#define SPI_FIRSTBIT_MSB                0x00000000U
#define SPI_FIRSTBIT_LSB                SPI_CR1_LSBFIRST

/* SPI CRC Calculation */
#define SPI_CRCCALCULATION_DISABLE      0x00000000U
#define SPI_CRCCALCULATION_ENABLE       SPI_CR1_CRCEN

/* SPI constants */
#define SPI_CR1_MSTR                    0x00000004U
#define SPI_CR1_SSI                     0x00000100U
#define SPI_CR1_RXONLY                  0x00000400U
#define SPI_CR1_BIDIMODE                0x00008000U
#define SPI_CR1_DFF                     0x00000800U
#define SPI_CR1_CPOL                    0x00000002U
#define SPI_CR1_CPHA                    0x00000001U
#define SPI_CR1_SSM                     0x00000200U
#define SPI_CR2_SSOE                    0x00000004U
#define SPI_CR1_BR_0                    0x00000008U
#define SPI_CR1_BR_1                    0x00000010U
#define SPI_CR1_BR_2                    0x00000020U
#define SPI_CR1_LSBFIRST                0x00000080U
#define SPI_CR1_CRCEN                   0x00002000U

/* SPI structures */
typedef struct
{
  uint32_t Mode;                /*!< Specifies the SPI operating mode. */
  uint32_t Direction;           /*!< Specifies the SPI bidirectional mode state. */
  uint32_t DataSize;            /*!< Specifies the SPI data size. */
  uint32_t CLKPolarity;         /*!< Specifies the serial clock steady state. */
  uint32_t CLKPhase;            /*!< Specifies the clock active edge for the bit capture. */
  uint32_t NSS;                 /*!< Specifies whether the NSS signal is managed by hardware (NSS pin) or by software using the SSI bit. */
  uint32_t BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be used to configure the transmit and receive SCK clock. */
  uint32_t FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit. */
  uint32_t TIMode;              /*!< Specifies if the TI mode is enabled or not. */
  uint32_t CRCCalculation;      /*!< Specifies if the CRC calculation is enabled or not. */
  uint32_t CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation. */
} SPI_InitTypeDef;

typedef struct __SPI_HandleTypeDef
{
  void                 *Instance;      /*!< SPI registers base address               */
  SPI_InitTypeDef      Init;           /*!< SPI communication parameters             */
  uint8_t              *pTxBuffPtr;    /*!< Pointer to SPI Tx transfer Buffer       */
  uint16_t             TxXferSize;     /*!< SPI Tx Transfer size                     */
  uint16_t             TxXferCount;    /*!< SPI Tx Transfer Counter                  */
  uint8_t              *pRxBuffPtr;    /*!< Pointer to SPI Rx transfer Buffer       */
  uint16_t             RxXferSize;     /*!< SPI Rx Transfer size                     */
  uint16_t             RxXferCount;    /*!< SPI Rx Transfer Counter                  */
  void                 *hdmatx;        /*!< SPI Tx DMA Handle parameters             */
  void                 *hdmarx;        /*!< SPI Rx DMA Handle parameters             */
  HAL_LockTypeDef      Lock;           /*!< Locking object                           */
  uint32_t             State;          /*!< SPI communication state                  */
  uint32_t             ErrorCode;      /*!< SPI Error code                           */
} SPI_HandleTypeDef;

/* SPI function declarations */
HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DeInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi);

HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Transmit_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Receive_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Transmit_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Receive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Abort(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Abort_IT(SPI_HandleTypeDef *hspi);

void HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi);

uint32_t HAL_SPI_GetState(SPI_HandleTypeDef *hspi);
uint32_t HAL_SPI_GetError(SPI_HandleTypeDef *hspi);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_SPI_H */
