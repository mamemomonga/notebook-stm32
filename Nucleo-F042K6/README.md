# Nucleo F042K6

* [Nucleo0F042K6](https://www.stmcu.jp/design/hwdevelop/nucleo/51864/)
* 基本的なセットアップは [F401RE](../Nucleo-F401RE) と同じ
* ユーザボタンのかわりにジャンパーになっている。
* Mac/Windowsでも正しく認識する模様。F401REがダメだったのはケーブルか基板の問題か？

## マイコン

STM32F042K6

* ARM 32-bit Coretex-M0 48MHz
* 32 Kbytes Flash
* USBとかいろいろある

# ボードとピンレイアウト
* [UM1956 User manual STM32 Nucleo-32 boards (MB1180)](https://www.st.com/resource/en/user_manual/dm00231744-stm32-nucleo32-boards-mb1180-stmicroelectronics.pdf)

* PB3(D3)は緑色LED(LD3)に接続
* デフォルトではPA12(D2)とGNDに黒のピンヘッダ・ジャンパーがある。デフォルトのソフトウェアでは抜くとLD3の点滅が早くなる。

![images](images/01.png)
![images](images/02.png)
![images](images/03.png)
![images](images/04.png)
![images](images/05.png)

