
/*******************************************************************************
* Inlcudes.
*/
#include <stdint.h>
#include <stdio.h>

#include "zd_trace.h"

#if ZD_TRACE_ENABLE

/*******************************************************************************
* Local variable.
*/

static uint32_t trace_index;
static uint32_t trace_log[TRACE_LOG_SIZE];


/**
  * @fun    tpReset
  * @param  none
  * @retval none
  * @brief  Init the log engine.This method should be called at every beginning of
  *         tracing.
  */
void tpReset(void)
{
    trace_index = 0;
}


/**
  * @fun    tpAddLog
  * @param  log -the log message should be saved to the tarceing-buffer.
  * @retval saved status
  *             @args TRACE_STATUS_SUCCESS :saved success.
  *             @args TRACE_STATUS_TOO_LARGE :saved data is too large.
  *             @args TRACE_STATUS_OVERFLOW :saved buffer is full.
  * @brief  Save a log message to the buffer.
  */
traceStatus_t tpAddLog(uint32_t log)
{
    traceStatus_t retStatus = TRACE_STATUS_SUCCESS;

    while (1)
    {
        if (log > TRACE_MAX_32BIT)
        {
            /* The log is too large beyond the max value of current data type. */

            retStatus = TRACE_STATUS_TOO_LARGE;
#if TRACE_EXCEPTION_PRINT_ENABLE
            printf("retStatus = TRACE_STATUS_TOO_LARGE;\r\n");
#endif /* TRACE_EXCEPTION_PRINT_ENABLE */
            break;
        }

        if (trace_index >= TRACE_LOG_SIZE)
        {
            /* saved buffer is full,so can't save anyone log. */

            retStatus = TRACE_STATUS_OVERFLOW;
#if TRACE_EXCEPTION_PRINT_ENABLE
            printf("retStatus = TRACE_STATUS_OVERFLOW;\r\n");
#endif /* TRACE_EXCEPTION_PRINT_ENABLE */
            break;
        }

        /* save log to buffer. */
        {
            trace_log[trace_index++] = log;
        }
        break;
    }

    /* return add log status. */
    return retStatus;
}


/**
* @fun    tpTracePrint
* @param  none
* @retval none
* @brief  Print all saved trace.
*/
void tpTracePrint(void)
{
    uint32_t i;

    printf("\r\nTrace Log:\r\n");
    for (i = 0; i < trace_index; i++)
    {
        if (i == 0)
        {
            printf("%d", trace_log[i]);
        }
        else
        {
            printf(" --> %d", trace_log[i]);
        }
    }
    printf("\r\n");
}

#endif /* ZD_TRACE_ENABLE */
