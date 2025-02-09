cmake_minimum_required(VERSION 3.8)

if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "")
    string(JOIN "" CMAKE_MSVC_DEBUG_INFORMATION_FORMAT 
        "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,"
        "$<CXX_COMPILER_ID:MSVC>>,"
        "$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,"
        "$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(blok C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCES
    "src/main.c" "src/core/context.h" "src/core/context.c" "src/core/module.h" 
    "src/core/module.c" "src/presentation/viewport/window.h" 
    "src/presentation/viewport/window.c" "src/presentation/graphics/drawing.c"
    "src/presentation/graphics/drawing.h" "src/presentation/graphics/renderer.c" 
    "src/presentation/graphics/renderer.h" "src/presentation/graphics/theme.c"
    "src/presentation/graphics/theme.h"
)

add_definitions(/DUNICODE /D_UNICODE /DSTRICT)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})