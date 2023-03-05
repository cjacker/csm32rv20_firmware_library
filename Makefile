######################################
# target
######################################
# this is all you should modify
TARGET = csm32rv20
TARGET_DEFS = 
USER_SOURCES = \
	src/sys_io.c \
	src/main.c

USER_INCLUDES = \
  -Isrc

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization for size
OPT = -Os


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES = \
	fw_lib/drivers/Src/data_always.c \
	fw_lib/drivers/Src/comp.c \
	fw_lib/drivers/Src/timer.c \
	fw_lib/drivers/Src/i2c.c \
	fw_lib/drivers/Src/cmu.c \
	fw_lib/drivers/Src/adc.c \
	fw_lib/drivers/Src/wup.c \
	fw_lib/drivers/Src/lv.c \
	fw_lib/drivers/Src/spi.c \
	fw_lib/drivers/Src/iwdg.c \
	fw_lib/drivers/Src/ee_printf.c \
	fw_lib/drivers/Src/usb.c \
	fw_lib/drivers/Src/lowpower.c \
	fw_lib/drivers/Src/uart.c \
	fw_lib/drivers/Src/random.c \
	fw_lib/drivers/Src/flash.c \
	fw_lib/drivers/Src/rtc.c \
	fw_lib/drivers/Src/gpio.c \
	fw_lib/drivers/Src/clic.c \
	$(USER_SOURCES)

# ASM sources
ASM_SOURCES =  fw_lib/startup/vectors.S

#######################################
# binaries
#######################################
PREFIX = riscv-none-embed-

CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size

HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

#######################################
# CFLAGS
#######################################
# cpu
CPU = -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 

# For gcc v12 and above
# CPU = -march=rv32imac_zicsr -mabi=ilp32 -msmall-data-limit=8

# mcu
MCU = $(CPU) $(FPU) $(FLOAT-ABI)

# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
	-Ifw_lib/drivers/Inc \
	$(USER_INCLUDES)

# compile gcc flags
ASFLAGS = $(MCU) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(TARGET_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = fw_lib/ld/target.ld

# libraries
LIBS = -lc -lm -lnosys
LIBDIR = 
LDFLAGS = $(MCU) -mno-save-restore -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -T $(LDSCRIPT) -nostartfiles -Xlinker --gc-sections -Wl,-Map=$(BUILD_DIR)/$(TARGET).map --specs=nano.specs $(LIBS)

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.S=.o)))
vpath %.S $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.S Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@
#$(LUAOBJECTS) $(OBJECTS)
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# program 
#######################################
flash: $(BUILD_DIR)/$(TARGET).hex
	./import-csm-jflash
	JLinkExe -device csm32rv20 -if cJTAG -speed 4000 -jtagconf -1,-1 -JLinkScriptFile ./Devices/csmflash.JLinkScript -autoconnect 1 -nogui 1 -commandfile flash.jlink
#######################################
# debug 
#######################################
debug: $(BUILD_DIR)/$(TARGET).hex
	@echo "Open another window to launch gdb"
	JLinkGDBServerCLExe -select USB -device csm32rv20 -endian little  -timeout 4000 -novd -if cJTAG -s -speed 4000 -ir -LocalhostOnly  -JLinkDevicesXMLPath $(shell pwd)/Devices/ -jlinkscriptfile $(shell pwd)/Devices/csmflash.JLinkScript
#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
