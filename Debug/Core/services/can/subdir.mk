################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/services/can/can_service.c 

OBJS += \
./Core/services/can/can_service.o 

C_DEPS += \
./Core/services/can/can_service.d 


# Each subdirectory must supply rules for building sources it contributes
Core/services/can/%.o Core/services/can/%.su Core/services/can/%.cyclo: ../Core/services/can/%.c Core/services/can/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H733xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-services-2f-can

clean-Core-2f-services-2f-can:
	-$(RM) ./Core/services/can/can_service.cyclo ./Core/services/can/can_service.d ./Core/services/can/can_service.o ./Core/services/can/can_service.su

.PHONY: clean-Core-2f-services-2f-can

