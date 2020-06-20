# 開発環境

## STM32CubeMXのインストール(macOS)

* [STM32CubeMX](https://www.st.com/ja/development-tools/stm32cubemx.html)
* [Java 11 (OpenJDK: AdoptOpenJDK) を Homebrew で macOS にインストールする](https://qiita.com/niwasawa/items/460ccd0fa0041e7a2491)

AdoptOpenJDKのインストール(JRE)

	$ brew tap AdoptOpenJDK/openjdk
	$ brew cask install adoptopenjdk11

ダウンロードしたSTM32CubeMXインストーラをダブルクリック実行する。

## ビルド・アップロード環境

### Debian(RaspberryPi + Raspbian)

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

## macOS Brew

	$ brew update
	$ brew upgrade
	$ brew tap ArmMbed/homebrew-formulae
	$ brew install arm-none-eabi-gcc

	$ arm-none-eabi-gcc --version
	arm-none-eabi-gcc (GNU Tools for Arm Embedded Processors 9-2019-q4-major) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]
	Copyright (C) 2019 Free Software Foundation, Inc.
	This is free software; see the source for copying conditions.  There is NO
	warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	
	$ brew install stlink
	
	$ st-util --version
	v1.6.0
	
	$ st-info --version
	v1.6.0
	
	$ st-flash --version
	v1.6.0


* [【macOS】ARMのGCCコンパイル環境を構築する](https://www.yokoweb.net/2018/05/16/macos-gcc-arm-brew-install/)
* [Homebrew formulae for Arm Mbed](https://github.com/ARMmbed/homebrew-formulae)
* [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
* [Open source version of the STMicroelectronics STlink Tools](https://github.com/stlink-org/stlink)

## Lチカ(STM32 Nucleo F401RE)

1. STM32CubeMXでボードを選ぶ
2. Create Project
3. 「Initalize app peripherals with their default Mode」でYes
4. Project Managerで保存先を設定、ToolchainでMakefileを洗濯して「Generate Code」
5. Src/main.c を開く
6. /* USER CODE BEGIN 3 */ と   /* USER CODE END 3 */ の手前の } の間に以下のコードを入れる

コード

	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	HAL_Delay(100);

7. make を実行する
8. STM Nucleo BoardをMacに接続する
9. st-info --probe を実行して接続状態を確認する
10. プログラムをアップロードする

コマンド

	$ st-flash --format ihex write ./build/blink.hex

* 搭載LED(D4)が細かくチカチカしたら成功。なお、デフォルトではボタンでチカチカ具合がかわるソフトがすでに入っている。
* Nucleo F401REボードはボードの小さい方がST-Linkになりプログラマになるそうだ。

# make flash で書き込めるようにする

	$ cat > flash.make << 'EOS'
	flash:
		st-flash --format ihex write $(BUILD_DIR)/$(TARGET).hex
	EOS
	
	$ echo 'include flash.make' >> Makefile

