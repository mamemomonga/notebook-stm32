# 02-UART

NucleoのST-LinkのUSB Serial (VCP)経由でシリアル接続し、出力を確認

# ビルドと実行

	$ make all flash serial

# CubeMXテンプレートとの違いを確認

	$ diff -cr ../CubeMX/default/Src/main.h main.h
	$ diff -cr ../CubeMX/default/Src/main.c main.c

# 参考

* [UART設定とPrintf](http://meerstern.seesaa.net/article/441845169.html)

