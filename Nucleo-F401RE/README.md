# STM32 Nucleo F401RE

* STM32 Nucleo F401REを使った基本的な動作確認
* CubeMXで生成されるHALライブラリを使用する
* gccおよびMakefileを利用
* CubeMXで自動生成されたフォルダはできるだけ触らず、外側から参照するようにする(CubeMXの下位フォルダが生成されたもの)

## 環境の構築

* 作業用マシン(macOS)
* ビルド・アップロードマシン(Raspberry Pi Raspbian)
* STM32 Nucleo F401RE

### 作業用マシン

#### STM32CubeMXのインストール

* [STM32CubeMX](https://www.st.com/ja/development-tools/stm32cubemx.html)
* [Java 11 (OpenJDK: AdoptOpenJDK) を Homebrew で macOS にインストールする](https://qiita.com/niwasawa/items/460ccd0fa0041e7a2491)

AdoptOpenJDKのインストール(JRE)

	$ brew tap AdoptOpenJDK/openjdk
	$ brew cask install adoptopenjdk11
	
ダウンロードしたSTM32CubeMXインストーラを実行する。

### ビルド・アップロードマシン

#### macOSにARMのGCCコンパイル環境を構築する

	$ sudo apt update
	$ sudo apt install -y gcc-arm-none-eabi binutils-arm-none-eabi stlink-tools build-essential

	$ arm-none-eabi-gcc --version
	arm-none-eabi-gcc (15:7-2018-q2-6) 7.3.1 20180622 (release) [ARM/embedded-7-branch revision 261907]
	Copyright (C) 2017 Free Software Foundation, Inc.
	This is free software; see the source for copying conditions.  There is NO
	warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	$ st-util --version
	v1.5.1
	
	$ st-info --version
	v1.5.1
	
	$ st-flash --version
	v1.5.1

### CubeMXをつかった初期コードの生成

すでにサンプルのビルドに必要な CubeMXからのは生成ずみだが、以下の方法で新規にコードを生成できる。

1. CubeMXを起動
2. "Start My project from STBoard" を起動
3. Part Number Search に NUCLEO-F401RE を入力しEnter
4. NUCLEO-F401RE をクリックし、Start Project
5. Initalize all peripherials with their default Mode ? と聞いてくるので Yes
6. 好きなピンやベリフェラルを選んで設定
7. Project Manager を選ぶ
8. Project Locationに[CubeMX](./CubeMX)フォルダを選択
9. Project Nameに任意の名前を選択
10. ProjectのToolchain/IDEでMakefileを選択
11. Generate Codeを押す

### Nucleo F401REはSTM32F401xD/xE とどのように繋がっているのか？

[UM1724 STM32 Nucleo-64 boards User Manual](https://www.st.com/resource/en/user_manual/dm00105823-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf)

![UM1724](./images/01.png)
![UM1724](./images/02.png)
![UM1724](./images/03.png)
![UM1724](./images/04.png)

* ボード上緑LED(LD1) は PA5に接続
* ボード上青ボタン(B1) は PC13に接続
* USART\_TX(PA2)とUSART\_RX(PA3) は ST-LinkのVirtual COM Portに接続

### Linux(Raspberry Pi Raspbian)での認識

* Nucleoボードの上部分はST-Linkになっていて、ジャンパを変更すると素のSTM32のプログラマとして機能する
* Rasbperry Piに接続すると、STMicroelectronics ST-LINK/V2.1 として認識される
* マスストレージデバイス MBED が認識される
* Virtual COM Port /dev/ttyACM0 が認識される
* st-info --probe でボード情報が表示される（なぜか実行するとマイコンの動作がとまるが、st-info --serial を実行すると動き出す)
* ここではttyACM0への接続にscreenを利用する、終了はCTRL+A, k → y
* 私の場合macOSだとVCPデバイスが認識できず(ストレージの認識とプログラムはできる)、Windowsだとデバイスがうまく認識できなかった。

#### アプリケーションのビルドとアップロード例

	$ cd Nucleo-F401RE/01-blink
	$ make all
	$ make flash

