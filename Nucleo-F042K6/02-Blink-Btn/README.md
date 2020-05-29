# 02-GPIO-Blink

* Nucleo搭載LED(D4)の点滅、A2(PullUp,ActiveLow)につないだボタンで点滅具合が変わる
* コードはapp.cなどに分離している

# ビルドと実行

	$ make all flash

# CubeMX書き出しコードとの差分

	$ diff -cr ../CubeMX/default/Src/main.c main.c

