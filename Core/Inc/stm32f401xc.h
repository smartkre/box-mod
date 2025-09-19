#ifndef __STM32F401xC_H
#define __STM32F401xC_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

#define __CM4_REV                 0x0001U
#define __MPU_PRESENT             1U
#define __NVIC_PRIO_BITS          4U
#define __Vendor_SysTickConfig    0U
#define __FPU_PRESENT             1U

typedef enum IRQn
{
  NonMaskableInt_IRQn         = -14,
  MemoryManagement_IRQn       = -12,
  BusFault_IRQn               = -11,
  UsageFault_IRQn             = -10,
  SVCall_IRQn                 = -5,
  DebugMonitor_IRQn           = -4,
  PendSV_IRQn                 = -2,
  SysTick_IRQn                = -1,
  WWDG_IRQn                   = 0,
  PVD_IRQn                    = 1
} IRQn_Type;

#include "core_cm4.h"

/* Peripheral base addresses */
#define FLASH_BASE            0x08000000UL
#define SRAM_BASE             0x20000000UL
#define PERIPH_BASE           0x40000000UL

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)

/* GPIO */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)

#define GPIOA                 ((void*)GPIOA_BASE)
#define GPIOB                 ((void*)GPIOB_BASE)
#define GPIOC                 ((void*)GPIOC_BASE)
#define GPIOH                 ((void*)GPIOH_BASE)

/* SPI */
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)

#define SPI1                  ((void*)SPI1_BASE)
#define SPI2                  ((void*)SPI2_BASE)
#define SPI3                  ((void*)SPI3_BASE)

/* ADC */
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000UL)
#define ADC1                  ((void*)ADC1_BASE)

/* RCC регистры */
typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                             Address offset: 0x04 */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                           Address offset: 0x08 */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                               Address offset: 0x0C */
} RCC_TypeDef;

#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
#define RCC                   ((RCC_TypeDef *) RCC_BASE)

/* RCC constants */
#define RCC_CFGR_SWS                         0x0000000CU
#define RCC_PLLCFGR_PLLSRC                   0x00400000U
#define RCC_PLLCFGR_PLLM                     0x0000003FU
#define RCC_PLLCFGR_PLLN                     0x00007FC0U
#define RCC_PLLCFGR_PLLP                     0x00030000U
#define RCC_CFGR_HPRE                        0x000000F0U
#define RCC_CFGR_PPRE1                       0x00001C00U

/* SCB constants */
#define VECT_TAB_OFFSET  0x00000000U /*!< Vector Table base offset field. This value must be a multiple of 0x200. */

/* Дополнительные макросы для MSP */
#define __HAL_RCC_SYSCFG_CLK_ENABLE()  do { } while(0)
#define __HAL_RCC_SPI1_CLK_ENABLE()    do { } while(0)
#define __HAL_RCC_ADC1_CLK_ENABLE()    do { } while(0)

#ifdef __cplusplus
}
#endif

#endif /* __STM32F401xC_H */
