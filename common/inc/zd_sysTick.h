/**
 *******************************************************************************
 * @file name       wzd_sysTime.h
 * @author          wzd
 * @date            20170605
 * @brief           xxxxx
 *******************************************************************************
 * @attention
 *
 */

#ifndef __ZD_SYSTICK_H__
#define __ZD_SYSTICK_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

/*******************************************************************************
 * Includes.
 */
#include <stdint.h>


/*******************************************************************************
 * Macro.
 */
#define Delay_ms(x_ms)                  do{SysTick_SWDelayMs(x_ms);}while(0)    /*  */
 
/*******************************************************************************
 * Type def.
 */

 
/*******************************************************************************
 * Method extern.
 */
int8_t zd_SysTick_Init(void);
void zd_SysTick_upgradeCallback(void);
uint32_t zd_SysTick_get(void);
void zd_SysTick_SWDelayMs(uint32_t x_ms);

 
 
/*******************************************************************************
 * Global variable extern.
 */
 
 

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*__ZD_SYSTICK_H__ */