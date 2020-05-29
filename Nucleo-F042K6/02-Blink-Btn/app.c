#include "app.h"

#define LED_L     HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET)
#define LED_H     HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET)
#define LED_I     HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin)
#define BTN_IS_H  HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin)
#define BTN_IS_L  !HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin)

uint8_t   btn_flag;
uint8_t   wait;

#define WAITS_IDX 7
uint16_t  waits[]={ 25, 50, 100, 150, 200, 250, 500, 1000 };

void APP_Init() {
	wait = 0;
	btn_flag = 0;
	for(uint8_t i=0; i < WAITS_IDX;i++) waits[i]=waits[i]-10;

	LED_L;
}

void APP_MainLoop() {
	if(BTN_IS_L) {
		if(!btn_flag) btn_flag = 1;
	} else {
		btn_flag = 0;
	}
	if(btn_flag) {
		wait++;
		if(wait > WAITS_IDX) wait = 0;
		LED_L;
		HAL_Delay(500);
	}
	LED_H;
	HAL_Delay(10);
	LED_L;
	HAL_Delay(waits[wait]);
}
