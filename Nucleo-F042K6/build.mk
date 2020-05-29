flash:
	st-flash --reset --format ihex write $(BUILD_DIR)/$(TARGET).hex
.PHONY: flash
