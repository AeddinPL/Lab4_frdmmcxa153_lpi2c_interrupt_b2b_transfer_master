################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sensors/nmh1000_driver.c \
../sensors/sensor_comm.c \
../sensors/sensor_common.c 

C_DEPS += \
./sensors/nmh1000_driver.d \
./sensors/sensor_comm.d \
./sensors/sensor_common.d 

OBJS += \
./sensors/nmh1000_driver.o \
./sensors/sensor_comm.o \
./sensors/sensor_common.o 


# Each subdirectory must supply rules for building sources it contributes
sensors/%.o: ../sensors/%.c sensors/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MCXA153VLH -DCPU_MCXA153VLH_cm33_nodsp -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\source" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\drivers" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\device" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\utilities" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\component\uart" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\component\lists" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\CMSIS" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\board" -I"C:\Dev\NXP\Training\workspace\frdmmcxa153_lpi2c_interrupt_b2b_transfer_master\frdmmcxa153\driver_examples\lpi2c\interrupt_b2b_transfer\master" -O0 -fno-common -g3 -gdwarf-4 -mcpu=cortex-m33+nodsp -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33+nodsp -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-sensors

clean-sensors:
	-$(RM) ./sensors/nmh1000_driver.d ./sensors/nmh1000_driver.o ./sensors/sensor_comm.d ./sensors/sensor_comm.o ./sensors/sensor_common.d ./sensors/sensor_common.o

.PHONY: clean-sensors

