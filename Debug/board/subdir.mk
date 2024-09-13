################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MCXA153VLH -DCPU_MCXA153VLH_cm33_nodsp -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\source" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\sensors" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\drivers" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\device" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\utilities" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\component\uart" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\component\lists" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\CMSIS" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\board" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\frdmmcxa153\driver_examples\lpi2c\interrupt_b2b_transfer\master" -O0 -fno-common -g3 -gdwarf-4 -mcpu=cortex-m33+nodsp -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33+nodsp -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

