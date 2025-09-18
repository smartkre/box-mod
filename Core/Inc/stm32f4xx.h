#ifndef __STM32F4xx_H
#define __STM32F4xx_H

#ifdef __cplusplus
 extern "C" {
#endif

#if defined(STM32F401xC)
  #include "stm32f401xc.h"
#elif defined(STM32F401xE)  
  #include "stm32f401xe.h"
#else
 #error "Please select first the target STM32F4xx device used in your application"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_H */
