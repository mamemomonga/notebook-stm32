#ifndef __APP_H
#define __APP_H

#include "main.h"

#define LED_L    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET)
#define LED_H    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET)
#define LED_I    HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin)
#define BTN_IS_H HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin)
#define BTN_IS_L !HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin)

UART_HandleTypeDef *APP_huart;
uint8_t APP_RxData;

void APP_Init();
void APP_MainLoop();

#endif
