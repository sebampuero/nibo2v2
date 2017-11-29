################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
NiboIntroduction.lss \

FLASH_IMAGE += \
NiboIntroduction.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NiboIntroduction.elf secondary-outputs

# Tool invocations
NiboIntroduction.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NiboIntroduction.map -Wl,-u,vfprintf -L/home/defaultuser/nibolib/lib -mmcu=atmega128 -o "NiboIntroduction.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NiboIntroduction.lss: NiboIntroduction.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NiboIntroduction.elf  >"NiboIntroduction.lss"
	@echo 'Finished building: $@'
	@echo ' '

NiboIntroduction.hex: NiboIntroduction.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NiboIntroduction.elf  "NiboIntroduction.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NiboIntroduction.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 NiboIntroduction.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NiboIntroduction.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
