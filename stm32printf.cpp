/*
 * @file stm32printf.cpp
 *
 * @breaf stm32printf.cpp
 * 
 * @date Jan 7, 2019
 * @author Andrey Gramakov
 */

#include "stm32printf.h"

extern UART_HandleTypeDef huart1;

int printf(const char* format, ...)
{
    char str[128];
    char *s = str; // pointer for the buffer
    int ch_count = 0;

    va_list args; // holds args
    va_start(args, format); // format - last defined param name
    vsprintf(str, format, args); // formatting

    while (*s)
    {
        HAL_UART_Transmit(&huart1, (uint8_t*)s, 1, HAL_MAX_DELAY);
        s++;
        ch_count++;
    }
    va_end(args);
    return ch_count;
}
