#ifndef __STM32F4xx_HAL_PWR_H
#define __STM32F4xx_HAL_PWR_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_def.h"

/* PWR PVD detection level */
#define PWR_PVDLEVEL_0                  0x00000000U
#define PWR_PVDLEVEL_1                  0x00000020U
#define PWR_PVDLEVEL_2                  0x00000040U
#define PWR_PVDLEVEL_3                  0x00000060U
#define PWR_PVDLEVEL_4                  0x00000080U
#define PWR_PVDLEVEL_5                  0x000000A0U
#define PWR_PVDLEVEL_6                  0x000000C0U
#define PWR_PVDLEVEL_7                  0x000000E0U

/* PWR PVD Mode */
#define PWR_PVD_MODE_NORMAL                 0x00000000U   /*!< basic mode is used */
#define PWR_PVD_MODE_IT_RISING              0x00010001U   /*!< External Interrupt Mode with Rising edge trigger detection */
#define PWR_PVD_MODE_IT_FALLING             0x00010002U   /*!< External Interrupt Mode with Falling edge trigger detection */
#define PWR_PVD_MODE_IT_RISING_FALLING      0x00010003U   /*!< External Interrupt Mode with Rising/Falling edge trigger detection */
#define PWR_PVD_MODE_EVENT_RISING           0x00020001U   /*!< Event Mode with Rising edge trigger detection */
#define PWR_PVD_MODE_EVENT_FALLING          0x00020002U   /*!< Event Mode with Falling edge trigger detection */
#define PWR_PVD_MODE_EVENT_RISING_FALLING   0x00020003U   /*!< Event Mode with Rising/Falling edge trigger detection */

/* PWR regulator voltage scaling */
#define PWR_REGULATOR_VOLTAGE_SCALE1         0x00000001U
#define PWR_REGULATOR_VOLTAGE_SCALE2         0x00000002U
#define PWR_REGULATOR_VOLTAGE_SCALE3         0x00000003U

/* PWR SLEEP mode entry */
#define PWR_SLEEPENTRY_WFI              ((uint8_t)0x01)
#define PWR_SLEEPENTRY_WFE              ((uint8_t)0x02)

/* PWR STOP mode entry */
#define PWR_STOPENTRY_WFI               ((uint8_t)0x01)
#define PWR_STOPENTRY_WFE               ((uint8_t)0x02)

/* PWR Regulator state in STOP mode */
#define PWR_MAINREGULATOR_ON                        0x00000000U
#define PWR_LOWPOWERREGULATOR_ON                    0x00000001U

/* PWR STANDBY mode entry */
#define PWR_STANDBYENTRY_WFI                        0x00000001U
#define PWR_STANDBYENTRY_WFE                        0x00000002U

/* PWR structures */
typedef struct
{
  uint32_t PVDLevel;   /*!< PVDLevel: Specifies the PVD detection level.
                            This parameter can be a value of @ref PWR_PVD_detection_level */

  uint32_t Mode;       /*!< Mode: Specifies the operating mode for the selected pins.
                            This parameter can be a value of @ref PWR_PVD_Mode */
} PWR_PVDTypeDef;

/* PWR function declarations */
void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);

void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);

void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);

void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTANDBYMode(void);

void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVDCallback(void);

void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);

/* PWR macros */
#define __HAL_PWR_VOLTAGESCALING_CONFIG(__REGULATOR__) do { } while(0)

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_PWR_H */
