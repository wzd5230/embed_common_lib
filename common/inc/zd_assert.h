
#ifndef __ZD_ASSERT_H__
#define __ZD_ASSERT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * Includes
 */
#include <stdint.h>
#include "zd_logcat.h"

/*******************************************************************************
 * Macro
 */
#define ZD_ASSERT_NORMAL                (0)
#define ZD_ASSERT_PROFESSIONAL          (1)

#if ZD_ASSERT_NORMAL
    /**
     * @brief  The s_assert_param macro is used for function's parameters check.
     * @param  expr If expr is false, it calls assert_failed function which reports
     *         the name of the source file and the source line number of the call
     *         that failed. If expr is true, it returns no value.
     * @retval None
     */
#define zd_assert_param(expr) ((expr) ? (void)0 : zd_assert_failed((uint8_t *)__FILE__, __LINE__))
    void zd_assert_failed(uint8_t* file, uint32_t line);
#elif ZD_ASSERT_PROFESSIONAL
    /**
     * @brief  The s_assert_param macro is used for function's parameters check.
     * @param  expr  If expr is false, it calls assert_failed function which reports
     *         the name of the source file and the source line number of the call
     *         that failed. If expr is true, it returns no value.
     * @retval None
     */
#define zd_assert_param(expr) ((expr) ? (void)0 : zd_assert_failed((uint8_t *)__FILE__, __LINE__,#expr))
    void zd_assert_failed(uint8_t* file, uint32_t line, char* expression);

#else
#define zd_assert_param(expr)        {}
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WZD_ASSERT_H__ */