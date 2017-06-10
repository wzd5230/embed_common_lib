/**
 *******************************************************************************
 * @file name       zd_logcat.h
 * @author          wzd
 * @date            20170605
 * @brief           xxxxx
 *******************************************************************************
 * @attention
 *
 */

#ifndef __ZD_LOGCAT_H__
#define __ZD_LOGCAT_H__
    
#ifdef __cplusplus
extern "C"{
#endif

/*******************************************************************************
 * Includes.
 */
#include <stdint.h>
#include <stdio.h>

/*******************************************************************************
 * Macro.
 */
#define ZD_LOGCAT_ENABLE                (1)                                     /* 0:disable, !0:enable */

#define ZD_LOGCAT_LEVEL                 (ZD_LOGCAT_LEVEL_LOWEST)                /* the level current used. */


#if ZD_LOGCAT_ENABLE
  
  
/* output stream,modify if needed. */
#define ZD_LOGCAT_PRINTF(...)           printf(__VA_ARGS__)                     /*  */

  
  
#define ZD_LOGCAT(LEVEL,...)            do{\
                                            if(LEVEL <5)\
                                            {ZD_LOGCAT_PRINTF(__VA_ARGS__);}\
                                          }while (0)                            /* log with level-control. */
  
#else
#define ZD_LOGCAT_PRINTF(...)
#define ZD_LOGCAT(LEVEL,EXP,...)
#endif


/* abstract of logcat level. */
#define ZD_LOGCAT_LEVEL_HIGHEST         (ZD_LOGCAT_LEVEL_0)
#define ZD_LOGCAT_LEVEL_HIGHER          (ZD_LOGCAT_LEVEL_1)
#define ZD_LOGCAT_LEVEL_MIDDLE          (ZD_LOGCAT_LEVEL_2)
#define ZD_LOGCAT_LEVEL_LOWER           (ZD_LOGCAT_LEVEL_3)
#define ZD_LOGCAT_LEVEL_LOWEST          (ZD_LOGCAT_LEVEL_5)



/*******************************************************************************
 * Type def.
 */
typedef enum _ZD_LOGCAT_LEVEL_T
{
    /* highest */
    ZD_LOGCAT_LEVEL_0 = 0,
    ZD_LOGCAT_LEVEL_1,
    ZD_LOGCAT_LEVEL_2,
    ZD_LOGCAT_LEVEL_3,
    ZD_LOGCAT_LEVEL_4,
    /* lowest */
    ZD_LOGCAT_LEVEL_5
}ZD_LOGCAT_LEVEL_T, *P_ZD_LOGCAT_LEVEL_T;


/*******************************************************************************
 * Method extern.
 */
int8_t zd_logcatInit(void);


/*******************************************************************************
 * Global variable extern.
 */



#ifdef __cplusplus
}
#endif

#endif /* __ZD_LOGCAT_H__ */

/****************************end of file***************************************/