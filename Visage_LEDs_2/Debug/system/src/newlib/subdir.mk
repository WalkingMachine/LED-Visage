################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../system/src/newlib/_cxx.cpp 

C_SRCS += \
../system/src/newlib/_exit.c \
../system/src/newlib/_sbrk.c \
../system/src/newlib/_startup.c \
../system/src/newlib/_syscalls.c \
../system/src/newlib/assert.c 

OBJS += \
./system/src/newlib/_cxx.o \
./system/src/newlib/_exit.o \
./system/src/newlib/_sbrk.o \
./system/src/newlib/_startup.o \
./system/src/newlib/_syscalls.o \
./system/src/newlib/assert.o 

C_DEPS += \
./system/src/newlib/_exit.d \
./system/src/newlib/_sbrk.d \
./system/src/newlib/_startup.d \
./system/src/newlib/_syscalls.d \
./system/src/newlib/assert.d 

CPP_DEPS += \
./system/src/newlib/_cxx.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/newlib/%.o: ../system/src/newlib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F417xx -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/newlib/%.o: ../system/src/newlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F417xx -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\Samuel Otis\Documents\Eclipse WorkSpace\Workspace_Walking_Machine\LED-Visage\Visage_LEDs_2\include\FreeRTOS" -I"C:\Program Files (x86)\GNU Tools ARM Embedded\4.9 2015q2\arm-none-eabi\include" -I"C:\Program Files (x86)\GNU Tools ARM Embedded\4.9 2015q2\lib\gcc\arm-none-eabi\4.9.3\include" -I"C:\Program Files (x86)\GNU Tools ARM Embedded\4.9 2015q2\lib\gcc\arm-none-eabi\4.9.3\include-fixed" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/newlib/_startup.o: ../system/src/newlib/_startup.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F417xx -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -DOS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\Samuel Otis\Documents\Eclipse WorkSpace\Workspace_Walking_Machine\LED-Visage\Visage_LEDs_2\include\FreeRTOS" -I"C:\Program Files (x86)\GNU Tools ARM Embedded\4.9 2015q2\arm-none-eabi\include" -I"C:\Program Files (x86)\GNU Tools ARM Embedded\4.9 2015q2\lib\gcc\arm-none-eabi\4.9.3\include" -I"C:\Program Files (x86)\GNU Tools ARM Embedded\4.9 2015q2\lib\gcc\arm-none-eabi\4.9.3\include-fixed" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"system/src/newlib/_startup.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


