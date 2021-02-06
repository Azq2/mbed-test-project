# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

if(${MBED_TOOLCHAIN} STREQUAL "GCC_ARM")
    set(STARTUP_FILE TOOLCHAIN_GCC_ARM/startup_stm32f405xx.S)
    set(LINKER_FILE TOOLCHAIN_GCC_ARM/STM32F405XG.ld)
elseif(${MBED_TOOLCHAIN} STREQUAL "ARM")
    set(STARTUP_FILE TOOLCHAIN_ARM/startup_stm32f405xx.S)
    set(LINKER_FILE TOOLCHAIN_ARM/STM32F405XG.sct)
endif()

add_library(STM32F405XG INTERFACE)

target_sources(STM32F405XG
    INTERFACE
        system_clock.c
        PeripheralPins.c
        ${STARTUP_FILE}
)

target_include_directories(STM32F405XG
    INTERFACE
        .
)

mbed_set_linker_script(STM32F405XG ${CMAKE_CURRENT_SOURCE_DIR}/${LINKER_FILE})

target_link_libraries(STM32F405XG INTERFACE STM32F4)
