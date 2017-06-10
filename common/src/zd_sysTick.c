/**
 *******************************************************************************
 * @file name       wzd_sysTick.h
 * @author          wzd
 * @date            20170605
 * @brief           xxxxx
 *******************************************************************************
 * @attention
 *
 */

 
/*******************************************************************************
 * Includes.
 */
#include "common/inc/zd_sysTick.h"
#include "common/inc/zd_assert.h"


#include "stm32f10x.h"


/*******************************************************************************
 * Macro.
 */
#define _SYSTICK_MAX_DELAY_MS           (0x7FFFFFFF)


/*******************************************************************************
 * local variable.
 */
static volatile uint32_t _SysTick_ms = 0;


/**
  * @fun    zd_SysTick_Init
  * @param  none
  * @retval 0 -
  * @brief  Init systick driver.
  */
int8_t zd_SysTick_Init(void)
{
  int8_t result = 0;

  /*------------------edit this segment if needed-----------------------------*/

  /* 1ms */
  if(0 != SysTick_Config(SystemCoreClock/1000))
  {
    /* failure */
#if 0
    ZD_LOGCAT(ZD_LOGCAT_LEVEL_HIGHEST, "SytemTick initial failure.\r\n");
#endif
    result = -1;
  }

  return result;
}


/**
  * @fun    SysTick_upgradeCallback
  * @param  none
  * @retval none
  * @brief  This method should be called per 1ms.
  *         This method always be called in ISR,such as SysTick_Handler() in stm32.
  */
void zd_SysTick_upgradeCallback(void)
{
    /* sysTick cnt increasement. */
    ++_SysTick_ms;
}


/**
  * @fun    SysTick_get
  * @param  none
  * @retval system tick cnt.
  * @brief  Get current system tick in ms.
  */
uint32_t zd_SysTick_get(void)
{
    return _SysTick_ms;
}

/**
  * @fun    SysTick_SWDelayMs
  * @param  x_ms :delay time in ms.
  * @retval none
  * @brief  Altenna function of system-tick,soft-delay with ms-level.
  */
void zd_SysTick_SWDelayMs(uint32_t x_ms)
{
  uint32_t start;

  /* Check the parameters. */
  zd_assert_param(x_ms < _SYSTICK_MAX_DELAY_MS);

  start = _SysTick_ms;

  while((_SysTick_ms - start) < x_ms);
}

/*****************************end of file.*************************************/
