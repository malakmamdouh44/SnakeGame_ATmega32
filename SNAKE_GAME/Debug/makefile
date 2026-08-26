################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SOURCE/subdir.mk
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
SNAKE_GAME.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: SNAKE_GAME.elf secondary-outputs

# Tool invocations
SNAKE_GAME.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SNAKE_GAME.map -mmcu=atmega32 -o "SNAKE_GAME.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SNAKE_GAME.lss: SNAKE_GAME.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SNAKE_GAME.elf  >"SNAKE_GAME.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SNAKE_GAME.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SNAKE_GAME.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SNAKE_GAME.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
