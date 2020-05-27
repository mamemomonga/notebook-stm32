# 02-UART

NucleoのST-LinkのUSB Serial (VCP)経由でシリアル接続し、出力を確認

# ビルドと実行

	$ make all flash serial

# CubeMX書き出しコードとの違い

	$ diff -cr ../CubeMX/default/Src/main.c main.c

	*** ../CubeMX/default/Src/main.c	2020-05-28 05:38:39.000000000 +0900
	--- main.c	2020-05-28 06:36:55.231192825 +0900
	***************
	*** 20,25 ****
	--- 20,26 ----
	  
	  /* Includes ------------------------------------------------------------------*/
	  #include "main.h"
	+ #include <string.h>
	  
	  /* Private includes ----------------------------------------------------------*/
	  /* USER CODE BEGIN Includes */
	***************
	*** 61,66 ****
	--- 62,71 ----
	  /* Private user code ---------------------------------------------------------*/
	  /* USER CODE BEGIN 0 */
	  
	+ void say(char *buf) {
	+ 	HAL_UART_Transmit(&huart2,(uint8_t *)buf,strlen(buf)+1,0xFFFF);
	+ }
	+ 
	  /* USER CODE END 0 */
	  
	  /**
	***************
	*** 103,108 ****
	--- 108,119 ----
	    {
	      /* USER CODE END WHILE */
	  
	+ 	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	+ 	say("Hello!\r\n");
	+ 	HAL_Delay(500);
	+ 	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	+ 	HAL_Delay(500);
	+ 
	      /* USER CODE BEGIN 3 */
	    }
	    /* USER CODE END 3 */
