#include "app.h"
#include <stdio.h>

#define LED_L    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET)
#define LED_H    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET)
#define LED_I    HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin)
#define BTN_IS_H HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin)
#define BTN_IS_L !HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin)

int16_t count;

void APP_Init() {
	count = 0;
	LED_L;
	printf("\r\n\r\n\r\n");
}

void APP_MainLoop() {
	LED_H;
	printf("Hello World! [%6d]\r\n",count);
	HAL_Delay(50);
	count++;
	LED_L;
	HAL_Delay(100);
}
