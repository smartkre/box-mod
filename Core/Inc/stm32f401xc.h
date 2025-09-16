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

#ifdef __cplusplus
}
#endif

#endif /* __STM32F401xC_H */
