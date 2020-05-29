# 03-Printf

* Nucleo搭載LED(D4)の点滅
* Virtual COM Port 経由でHello World!とカウンタを出力

# ビルドと実行

	$ make all flash serial

# 差分

`diff -c ../CubeMX/default/Src/main.c main.c`

	*** ../CubeMX/default/Src/main.c	2020-05-29 22:56:30.989357295 +0900
	--- main.c	2020-05-29 22:48:16.380968911 +0900
	***************
	*** 20,25 ****
	--- 20,26 ----
	  
	  /* Includes ------------------------------------------------------------------*/
	  #include "main.h"
	+ #include "app.h"
	  
	  /* Private includes ----------------------------------------------------------*/
	  /* USER CODE BEGIN Includes */
	***************
	*** 57,63 ****
	  
	  /* Private user code ---------------------------------------------------------*/
	  /* USER CODE BEGIN 0 */
	! 
	  /* USER CODE END 0 */
	  
	  /**
	--- 58,67 ----
	  
	  /* Private user code ---------------------------------------------------------*/
	  /* USER CODE BEGIN 0 */
	! int _write( int file, char *buf, int len ) {
	! 	HAL_UART_Transmit(&huart2, (uint8_t *)buf, len, 1000);
	! 	return len;
	! }
	  /* USER CODE END 0 */
	  
	  /**
	***************
	*** 90,95 ****
	--- 94,100 ----
	    MX_GPIO_Init();
	    MX_USART2_UART_Init();
	    /* USER CODE BEGIN 2 */
	+   APP_Init();
	  
	    /* USER CODE END 2 */
	  
	***************
	*** 98,104 ****
	    while (1)
	    {
	      /* USER CODE END WHILE */
	! 
	      /* USER CODE BEGIN 3 */
	    }
	    /* USER CODE END 3 */
	--- 103,109 ----
	    while (1)
	    {
	      /* USER CODE END WHILE */
	! 	APP_MainLoop();
	      /* USER CODE BEGIN 3 */
	    }
	    /* USER CODE END 3 */
