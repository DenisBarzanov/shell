cmake_minimum_required(VERSION 3.12)
project(os_shell_1 C)

set(CMAKE_C_STANDARD 11)

SET(LIB_FILE ${CMAKE_CURRENT_SOURCE_DIR}/apue.3e/lib/libapue.a)
SET(LIB_HEADER_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/apue.3e/include)

add_custom_command(OUTPUT ${LIB_FILE}
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/apue.3e/lib/
        )

add_custom_target(apue_target ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/apue.3e/lib/libapue.a)

add_library(apue STATIC IMPORTED GLOBAL)
add_dependencies(apue apue_target)

set_target_properties(apue
        PROPERTIES
        IMPORTED_LOCATION ${LIB_FILE}
        INTERFACE_INCLUDE_DIRECTORIES ${LIB_HEADER_FOLDER}
        )

add_executable(os_shell_1 main.c dsh_builtins.c dsh_builtins.h)
target_link_libraries(os_shell_1 apue)