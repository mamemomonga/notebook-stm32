#include "app.h"
#include <stdio.h>

static uint16_t counter;

// printf
int _write( int file, char *buf, int len ) {
	HAL_UART_Transmit(APP_huart, (uint8_t *)buf, len, 100);
	return len;
}

// UART RX受信
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
	HAL_UART_Receive_IT(UartHandle, &APP_RxData, 1);
	printf("RECV(%06d): [0x%02x] %c\r\n", counter++, APP_RxData, APP_RxData);
}

void APP_Init() {
	LED_L;
	counter = 0;
	HAL_UART_Receive_IT(APP_huart, &APP_RxData, 1);
}

void APP_MainLoop() {
	LED_I;
	HAL_Delay(100);
}
