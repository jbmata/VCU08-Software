################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/app/safety/ev23.c \
../Core/app/safety/t1189.c 

OBJS += \
./Core/app/safety/ev23.o \
./Core/app/safety/t1189.o 

C_DEPS += \
./Core/app/safety/ev23.d \
./Core/app/safety/t1189.d 


# Each subdirectory must supply rules for building sources it contributes
Core/app/safety/%.o Core/app/safety/%.su Core/app/safety/%.cyclo: ../Core/app/safety/%.c Core/app/safety/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H733xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-app-2f-safety

clean-Core-2f-app-2f-safety:
	-$(RM) ./Core/app/safety/ev23.cyclo ./Core/app/safety/ev23.d ./Core/app/safety/ev23.o ./Core/app/safety/ev23.su ./Core/app/safety/t1189.cyclo ./Core/app/safety/t1189.d ./Core/app/safety/t1189.o ./Core/app/safety/t1189.su

.PHONY: clean-Core-2f-app-2f-safety

