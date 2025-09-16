#ifndef __CORE_CM4_H_GENERIC
#define __CORE_CM4_H_GENERIC

#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

/* Minimal core definitions */
#define __disable_irq() __asm volatile ("cpsid i" : : : "memory")
#define __enable_irq()  __asm volatile ("cpsie i" : : : "memory")

typedef struct
{
  volatile uint32_t CPACR;
} SCB_Type;

#define SCB_BASE            (0xE000ED00UL)
#define SCB                 ((SCB_Type *)SCB_BASE)

#ifdef __cplusplus
}
#endif

#endif /* __CORE_CM4_H_GENERIC */
