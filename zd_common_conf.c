






/*******************************************************************************
 * Includes.
 */
#include "zd_common_conf.h"


/**
  * @fun    zd_commonInit
  * @brief  Initial the zd common library.
  * @param  none
  * @param  none
  * @retval Initial result.
  *           0 -success.
  *           other -failure.
  */

int8_t zd_commonInit(void)
{
  int8_t result=0;

  while(1)
  {
    /* Note:zd_logcat should be config complete first. 
     */


#if ZD_COMMON_USE_SYSTICK
    result = zd_logcatInit();    
    if(result)
    {
      ZD_LOGCAT(ZD_LOGCAT_LEVEL_LOWER, "Logcat initial failure.\r\n");
      break;
    }
#endif /* ZD_COMMON_USE_SYSTICK */

#if ZD_COMMON_USE_SYSTICK
    result = zd_SysTick_Init();
    if(result)
    {
      ZD_LOGCAT(ZD_LOGCAT_LEVEL_LOWER, "SytemTick initial failure.\r\n");
      break;
    }
#endif /* ZD_COMMON_USE_SYSTICK */
  }
  
  return 0;
}
