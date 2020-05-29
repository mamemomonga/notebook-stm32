# 01-Blink

Nucleo搭載LED(D4)の点滅

# ビルドと実行

	$ make all flash

# CubeMX書き出しコードとの差分

	$ diff -cr ../CubeMX/default/Src/main.c main.c

	*** ../CubeMX/default/Src/main.c	2020-05-28 20:35:53.234784439 +0900
	--- main.c	2020-05-28 20:37:44.004426969 +0900
	***************
	*** 98,104 ****
	    while (1)
	    {
	      /* USER CODE END WHILE */
	! 
	      /* USER CODE BEGIN 3 */
	    }
	    /* USER CODE END 3 */
	--- 98,107 ----
	    while (1)
	    {
	      /* USER CODE END WHILE */
	! 	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
	! 	HAL_Delay(100);
	! 	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	! 	HAL_Delay(100);
	      /* USER CODE BEGIN 3 */
	    }
	    /* USER CODE END 3 */
