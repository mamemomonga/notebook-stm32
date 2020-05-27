# 02-UART

NucleoのST-LinkのUSB Serial (VCP)経由でシリアル接続し、出力を確認

# ビルドと実行

	$ make all flash serial

# CubeMXテンプレートとの違いを確認

	$ diff -cr ../CubeMX/default/Src/main.c main.c

