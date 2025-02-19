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

enable_language(RC)

set(SOURCES
    "src/main.c"
    "src/core/config/args.c" "src/core/config/args.h"
    "src/core/debug/console.c" "src/core/debug/console.h"
    "src/core/gfx/drawtools.c" "src/core/gfx/drawtools.h"
    "src/core/gfx/graphics.c" "src/core/gfx/graphics.h"
    "src/core/gfx/theme.c" "src/core/gfx/theme.h"
    "src/core/context.c" "src/core/context.h"
    "src/core/lifecycle.c" "src/core/lifecycle.h"
    "src/model/maths/direction.c" "src/model/maths/direction.h"
    "src/model/maths/dynlist.c" "src/model/maths/dynlist.h"
    "src/model/maths/vector.c" "src/model/maths/vector.h"
    "src/model/objects/square.h"
    "src/model/state.c" "src/model/state.h"
    "src/presentation/controls/button.c" "src/presentation/controls/button.h"
    "src/presentation/controls/progressbar.c" "src/presentation/controls/progressbar.h"
    "src/presentation/controls/text.c" "src/presentation/controls/text.h"
    "src/presentation/controls/toggle.c" "src/presentation/controls/toggle.h"
    "src/presentation/components/canvas.c" "src/presentation/components/canvas.h"
    "src/presentation/components/panel.c" "src/presentation/components/panel.h"
    "src/presentation/events/process.c" "src/presentation/events/process.h"
    "src/presentation/frame/window.c" "src/presentation/frame/window.h"
    "src/presentation/viewport.c" "src/presentation/viewport.h"
    "src/service/convert.c" "src/service/convert.h"
    "res/resource.rc"
)

add_definitions(/DUNICODE /D_UNICODE /DSTRICT)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})