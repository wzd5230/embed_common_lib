/**
 *******************************************************************************
 * @file name       zd_logcat.c
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
#include "common/inc/zd_logcat.h"

#include "DEBUG.H"


/**
  * @fun    zd_logcatInit
  * @param  ...
  * @retval ...
  * @brief  Init logcat hardware interface.
  */
int8_t zd_logcatInit(void)
{
  int8_t result = 0;

  Debug_Init( 115200 );

  return result;
}



/**
  * @fun    fputc
  * @param  ...
  * @retval ...
  * @brief  Redefine the output stream method.
  */
#if 1
int fputc(int ch, FILE *file)
{    
    USART_SendData(DBUG_COMX, (uint8_t) ch);
    
    while (USART_GetFlagStatus(DBUG_COMX, USART_FLAG_TC) == RESET);
    
    return ch;
}
#endif /* 1/0 */