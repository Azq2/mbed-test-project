# Copyright (c) 2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.19.0)

set(MBED_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mbed-os CACHE INTERNAL "")
set(MBED_CONFIG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.mbedbuild CACHE INTERNAL "")
set(APP_TARGET ir-cabsim)

include(${MBED_PATH}/tools/cmake/app.cmake)

#if(${MBED_TARGET} STREQUAL "STM32F405XG")
#	include(${MBED_PATH}/tools/cmake/set_linker_script.cmake)
#	add_subdirectory(TARGET_STM32F405XG)
#endif()

add_subdirectory(${MBED_PATH})

add_executable(${APP_TARGET}
    main.cpp
)

mbed_configure_app_target(${APP_TARGET})

project(${APP_TARGET})

target_link_libraries(${APP_TARGET} mbed-os mbed-usb mbed-events)

mbed_set_post_build(${APP_TARGET})

option(VERBOSE_BUILD "Have a verbose build process")
if(VERBOSE_BUILD)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()
