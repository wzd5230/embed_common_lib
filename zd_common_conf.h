



#ifndef __ZD_COMMON_CONF_H__
#define __ZD_COMMON_CONF_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */


/*******************************************************************************
 * Macro
 */

/* Note:Some components are dependent on the LOGCAT.
 */

#define ZD_COMMON_USE_LOGCAT            (1)                                     /* 0:disable,other:enable */
#define ZD_COMMON_USE_ASSERT            (1)                                     /* 0:disable,other:enable */
#define ZD_COMMON_USE_SYSTICK           (1)                                     /* 0:disable,other:enable */
#define ZD_COMMON_USE_TRACE             (1)                                     /* 0:disable,other:enable */


/*******************************************************************************
 * Include head file according from the config in Macro segment.
 */
#if ZD_COMMON_USE_LOGCAT
#include "common/inc/zd_assert.h"
#endif /* ZD_COMMON_USE_LOGCAT */

#if ZD_COMMON_USE_LOGCAT
#include "common/inc/zd_logcat.h"
#endif /* ZD_COMMON_USE_LOGCAT */

#if ZD_COMMON_USE_SYSTICK
#include "common/inc/zd_sysTick.h"
#endif /* ZD_COMMON_USE_SYSTICK */

#if ZD_COMMON_USE_TRACE
#include "common/inc/zd_trace.h"
#endif /* ZD_COMMON_USE_TRACE */
  

/*******************************************************************************
 * Method extern.
 */  
int8_t zd_commonInit(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ZD_COMMON_CONF_H__ */

/********************************end of file***********************************/