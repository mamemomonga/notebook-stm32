# 01-Blink

Nucleo搭載LED(D4)の点滅

# ビルドと実行

	$ make all flash

# CubeMX書き出しコードとの差分

	$ diff -cr ../CubeMX/default/Src/main.c main.c

	*** ../CubeMX/default/Src/main.c	2020-05-28 05:38:39.000000000 +0900
	--- main.c	2020-05-28 06:04:36.000000000 +0900
	***************
	*** 103,108 ****
	--- 103,113 ----
	    {
	      /* USER CODE END WHILE */
	  
	+ 	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	+ 	HAL_Delay(100);
	+ 	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	+ 	HAL_Delay(100);
	+ 
	      /* USER CODE BEGIN 3 */
	    }
	    /* USER CODE END 3 */
