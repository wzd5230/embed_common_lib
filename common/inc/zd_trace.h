
#ifndef __ZD_TRACE_H__
#define __ZD_TRACE_H__


/*******************************************************************************
 * Inlcudes.
 */
#include <stdint.h>

/*******************************************************************************
* Macro def.
*/

/* enable & disable */
#define ZD_TRACE_ENABLE                 (1)

/* error status. */
#define TRACE_STATUS_SUCCESS            (0)
#define TRACE_STATUS_TOO_LARGE          (1)
#define TRACE_STATUS_OVERFLOW           (2)

/* */
#define TRACE_EXCEPTION_PRINT_ENABLE    (1)
#define TRACE_MAX_32BIT                 (0xFFFFFFFF)
#define TRACE_LOG_SIZE                  (8)

/* method */
#if ZD_TRACE_ENABLE
#define zd_tp_Reset()                   tpReset()
#define zd_tpAddLog(param)              tpAddLog(param)
#define zd_tpTracePrint()               tpTracePrint()
#else
#deifne zd_tp_Reset()                   {}
#define zd_tpAddLog                     {}
#define zd_tpTracePrint()               {}
#endif /* ZD_TRACE_ENABLE */


/*******************************************************************************
 * Type def.
 */
typedef uint8_t traceStatus_t;


/*******************************************************************************
 * Method extern.
 */
#if ZD_TRACE_ENABLE
void tpReset(void);
traceStatus_t tpAddLog(uint32_t log);
void tpTracePrint(void);
#endif /* ZD_TRACE_ENABLE */


#endif /* __ZD_TRACE_H__ */