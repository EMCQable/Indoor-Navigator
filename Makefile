# Set serial port
PORT := /dev/ttyUSB0
BAUD := 115200 

ARDUINO_CLI := arduino-cli
ESP32_FQBN := esp32:esp32:esp32
LIB_FILE := libraries.txt

.PHONY: flash run
all: compile upload

.PHONY: install-esp32
install-esp32:
	$(ARDUINO_CLI) config init
#	$(ARDUINO_CLI) config set network.timeout 600
	$(ARDUINO_CLI) core update-index
	$(ARDUINO_CLI) core install esp32:esp32


.PHONY: check
check:
	$(ARDUINO_CLI) core list
	$(ARDUINO_CLI) board list
	$(ARDUINO_CLI) board listall esp32

.PHONY: compile
compile:
	$(ARDUINO_CLI) compile --fqbn $(ESP32_FQBN)

.PHONY: upload
upload:
	$(ARDUINO_CLI) upload -p $(PORT) --fqbn $(ESP32_FQBN)

monitor:
	@echo "Opening serial monitor on $(PORT) with baud $(BAUD)..."
	$(ARDUINO_CLI) monitor -p $(PORT) -b $(BAUD)

.PHONY: install-libs
install-libs:
	@echo "Installing Arduino libraries..."
	@while IFS= read -r lib; do \
		# skip empty lines and lines starting with # \
		case "$$lib" in \
			""|"#"*) continue ;; \
		esac; \
		echo "|x| Installing Project Requirement $$lib..."; \
		arduino-cli lib install "$$lib"; \
	done < $(LIB_FILE)
	@echo "All libraries installed."