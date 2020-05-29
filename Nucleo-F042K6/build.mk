
HOST_USART2_PORT=/dev/ttyACM0
HOST_USART2_BAUD=115200

flash:
	st-flash --reset --format ihex write $(BUILD_DIR)/$(TARGET).hex

serial:
	screen $(HOST_USART2_PORT) $(HOST_USART2_BAUD)

.PHONY: flash serial
