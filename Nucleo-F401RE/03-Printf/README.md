# 02-UART

NucleoのST-LinkのUSB Serial (VCP)経由でシリアル接続し、出力を確認

# ビルドと実行

	$ make all flash serial

# 参考

* [UART設定とPrintf](http://meerstern.seesaa.net/article/441845169.html)

# CubeMX書き出しコードとの違い

main.h

	$ diff -cr ../CubeMX/default/Inc/main.h main.h

	*** ../CubeMX/default/Inc/main.h	2020-05-28 05:38:39.000000000 +0900
	--- main.h	2020-05-28 07:03:13.955921184 +0900
	***************
	*** 29,34 ****
	--- 29,35 ----
	  
	  /* Includes ------------------------------------------------------------------*/
	  #include "stm32f4xx_hal.h"
	+ #include "stdio.h"
	  
	  /* Private includes ----------------------------------------------------------*/
	  /* USER CODE BEGIN Includes */


main.c

	$ diff -cr ../CubeMX/default/Src/main.c main.c

	*** ../CubeMX/default/Src/main.c	2020-05-28 05:38:39.000000000 +0900
	--- main.c	2020-05-28 08:24:27.679040822 +0900
	***************
	*** 45,50 ****
	--- 45,52 ----
	  
	  UART_HandleTypeDef huart2;
	  
	+ int counter;
	+ 
	  /* USER CODE BEGIN PV */
	  
	  /* USER CODE END PV */
	***************
	*** 61,66 ****
	--- 63,73 ----
	  /* Private user code ---------------------------------------------------------*/
	  /* USER CODE BEGIN 0 */
	  
	+ int _write( int file, char *buf, int len ) {
	+ 	HAL_UART_Transmit(&huart2, (uint8_t *)buf, len, 1000);
	+ 	return len;
	+ }
	+ 
	  /* USER CODE END 0 */
	  
	  /**
	***************
	*** 95,100 ****
	--- 102,110 ----
	    MX_USART2_UART_Init();
	    /* USER CODE BEGIN 2 */
	  
	+   counter = 0;
	+ 	printf("\r\n\r\n");
	+ 
	    /* USER CODE END 2 */
	  
	    /* Infinite loop */
	***************
	*** 103,108 ****
	--- 113,124 ----
	    {
	      /* USER CODE END WHILE */
	  
	+ 	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	+ 	printf("Hello World! [%6d]\r\n",counter++);
	+ 	HAL_Delay(500);
	+ 	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	+ 	HAL_Delay(500);
	+ 
	      /* USER CODE BEGIN 3 */
	    }
	    /* USER CODE END 3 */


