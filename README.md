# STM32のメモ帳

* STM32 Nucleo F401REを使った基本的な動作確認
* CubeMXで生成されるHALライブラリを使用する
* gccおよびMakefileを利用

## 環境の構築

* 作業用マシン(macOS)
* ビルド・アップロードホスト(Raspberry Pi Raspbian)
* STM32 Nucleo F401RE

### 作業用マシン

#### STM32CubeMXのインストール

* [STM32CubeMX](https://www.st.com/ja/development-tools/stm32cubemx.html)
* [Java 11 (OpenJDK: AdoptOpenJDK) を Homebrew で macOS にインストールする](https://qiita.com/niwasawa/items/460ccd0fa0041e7a2491)

AdoptOpenJDKのインストール(JRE)

	$ brew tap AdoptOpenJDK/openjdk
	$ brew cask install adoptopenjdk11
	
ダウンロードしたSTM32CubeMXインストーラを実行する。

### ビルド・アップロードホスト 

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

#### アプリケーションのビルドとアップロード例

	$ cd Nucleo-F401RE/01-blink
	$ make all
	$ make flash

