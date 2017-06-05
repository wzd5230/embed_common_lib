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
#include "zd_sysTick.h"
#include "zd_assert.h"


/*******************************************************************************
 * Macro.
 */
#define _ZD_STD_MINUS_COMPARE              (0x7FFFFFFF)



/*******************************************************************************
 * local variable.
 */
static volatile uint32_t _SysTick_ms=0;


/**
  * @fun    SysTick_upgrade
  * @param  none
  * @retval none
  * @brief  This method should be called per 1ms.
  *         This method always be called in ISR,such as SysTick_Handler() in stm32.
  */
void SysTick_upgrade(void)
{
    ++_SysTick_ms;
}

/**
  * @fun    SysTick_get
  * @param  none
  * @retval system tick cnt.
  * @brief  Get current system tick in ms.
  */
uint32_t SysTick_get(void)
{
    return _SysTick_ms;
}

/**
  * @fun    SysTick_SWDelayMs
  * @param  x_ms :delay time in ms.
  * @retval none
  * @brief  Altenna function of system-tick,soft-delay with ms-level.
  */
void SysTick_SWDelayMs(uint32_t x_ms)
{
    uint32_t end;

    /* Check parameter */
    zd_assert_param(x_ms < _ZD_STD_MINUS_COMPARE);


    end = _SysTick_ms + x_ms;
    
    /* wait */
    while ((end - _SysTick_ms) < _ZD_STD_MINUS_COMPARE)
    {
    }
}

/*****************************end of file.*************************************/
