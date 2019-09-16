cmake_minimum_required(VERSION 3.12)
project(REM)


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
    set(multiValueArgs MODULE_INTERFACE_UNIITS)
    cmake_parse_arguments(PARSE_ARGV 1 ARG "${options}" "${oneValueArgs}" "${multiValueArgs}")

    message("Target: ${target}" )
    message("Interface Units: ${MODULE_INTERFACE_UNITS}" )

    if(MSVC)
        foreach(ixx ${MODULE_INTERFACE_UNITS})
            set_source_files_properties(${ixx} PROPERTIES LANGUAGE CXX)
        endforeach()
    endif()

    add_library(${target} STATIC ${MODULE_INTERFACE_UNITS})

    my_enable_modules(${target})

endfunction()



my_add_module(
        rem 
    MODULE_INTERFACE_UNITS
        src/mat.ixx
        src/vec/vec.ixx
        src/vec/comparisonoperators.ixx
        src/vec/bitwiseoperators.ixx
        src/vec/arithmeticoperators.ixx
        src/rem.ixx
    )


    add_executable(simple1 examples/simple1.cpp)
    my_enable_modules(simple1)
    
    target_link_libraries(simple1 rem)