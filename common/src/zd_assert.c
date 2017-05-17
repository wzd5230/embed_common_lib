
#include "zd_assert.h"

/** @defgroup Types_Private_Functions                 Types Private Functions
* @{
*/

#if ZD_ASSERT_NORMAL
/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param file  pointer to the source file name
* @param line  assert_param error line source number
* @retval : None
*/
void zd_assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number */
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);

    /* Infinite loop */
    while (1)
    {
    }
}
#elif ZD_ASSERT_PROFESSIONAL


/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param file pointer to the source file name
* @param line  assert_param error line source number
* @param expression: string representing the assert failed expression
* @retval : None
*/
void zd_assert_failed(uint8_t* file, uint32_t line, char* expression)
{

    printf("\n\rVCOM DEBUG: Incorrect parameter. Please reboot.\n\r");
    printf("%s:%d \n\r", file, line);
    printf("The expression \"%s\" returned FALSE.\n\r", expression);

    /* Infinite loop */
    while (1)
    {
    }
}

#endif