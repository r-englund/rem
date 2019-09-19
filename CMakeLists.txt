cmake_minimum_required(VERSION 3.12)
project(REM)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER cmake)

function(my_enable_modules target)
    if(MSVC)
        target_compile_options(${target} PUBLIC "/experimental:module" )
        target_compile_options(${target} PUBLIC "/std:c++latest")
    else()
        message("WARNING untested platform")
    endif()
endfunction()

function(my_add_module target)
    set(options "")
    set(oneValueArgs "TARGET")
    set(multiValueArgs MODULE_INTERFACE_UNITS)
    cmake_parse_arguments(PARSE_ARGV 1 ARG "${options}" "${oneValueArgs}" "${multiValueArgs}")

    message("Target: ${target}" )
    message("Interface Units: ${ARG_MODULE_INTERFACE_UNITS}" )

    if(MSVC)
        foreach(ixx ${ARG_MODULE_INTERFACE_UNITS})
            set_source_files_properties(${ixx} PROPERTIES LANGUAGE CXX)
        endforeach()
    endif()

    source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/src" FILES ${ARG_MODULE_INTERFACE_UNITS} )
    #source_group("Module Interface Units" FILES ${ARG_MODULE_INTERFACE_UNITS} )

    add_library(${target} STATIC ${ARG_MODULE_INTERFACE_UNITS})

    my_enable_modules(${target})

endfunction()



my_add_module(
        rem 
    MODULE_INTERFACE_UNITS
        src/internal/common.ixx
        src/internal/util.ixx
        src/vec/vec.ixx
        src/vec/algebraicoperators.ixx
        src/vec/arithmeticoperators.ixx
        src/vec/comparisonoperators.ixx
        src/vec/bitwiseoperators.ixx

        src/mat/mat.ixx
        src/mat/arithmeticoperators.ixx
        src/mat/bitwiseoperators.ixx
        src/mat/comparisonoperators.ixx
        src/mat/inverse.ixx
        src/mat/transpose.ixx

        src/rem.ixx
    )

file(GLOB tests tests/*.cpp)
foreach(test ${tests})
    get_filename_component(testname ${test} NAME_WE)
    add_executable(${testname} ${test})
    my_enable_modules(${testname})
    target_link_libraries(${testname} rem)
    set_target_properties( ${testname} PROPERTIES FOLDER "tests")
endforeach(test ${tests})


