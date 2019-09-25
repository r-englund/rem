cmake_minimum_required(VERSION 3.12)
project(REM)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER cmake)


function (has_is_constant_evaluated retval)
    file(WRITE "${CMAKE_BINARY_DIR}/cmake/has_is_constant_evaluated.cpp" "#include <type_traits>\nint main(){std::is_constant_evaluated();}") # \nbool test(){ return /*std::is_constant_evaluated();*/ true; }
    try_compile(res "${CMAKE_BINARY_DIR}/cmake" SOURCES "${CMAKE_BINARY_DIR}/cmake/has_is_constant_evaluated.cpp" CXX_STANDARD 20 OUTPUT_VARIABLE output)
    set(${retval} ${res} PARENT_SCOPE)
endfunction()



function (has_three_way_comp retval)
    file(WRITE "${CMAKE_BINARY_DIR}/cmake/has_three_way_comp.cpp" "#include <compare>\nint main(){ auto a = 1 <=> 2;}") # \nbool test(){ return /*std::is_constant_evaluated();*/ true; }
    try_compile(res "${CMAKE_BINARY_DIR}/cmake" SOURCES "${CMAKE_BINARY_DIR}/cmake/has_three_way_comp.cpp" CXX_STANDARD 20 OUTPUT_VARIABLE output)
    set(${retval} ${res} PARENT_SCOPE)
endfunction()





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
    set(multiValueArgs MODULE_INTERFACE_UNITS MODULE_IMPLEMENTATION_UNITS)
    cmake_parse_arguments(PARSE_ARGV 1 ARG "${options}" "${oneValueArgs}" "${multiValueArgs}")

    message("Target: ${target}" )
    message("Interface Units: ${ARG_MODULE_INTERFACE_UNITS}" )
    message("Implementation Units: ${ARG_MODULE_IMPLEMENTATION_UNITS}" )

    if(MSVC)
    foreach(ixx ${ARG_MODULE_INTERFACE_UNITS})
        set_source_files_properties(${ixx} PROPERTIES LANGUAGE CXX)
    endforeach()
    foreach(mxx ${ARG_MODULE_IMPLEMENTATION_UNITS})
        set_source_files_properties(${mxx} PROPERTIES LANGUAGE CXX)
        set_source_files_properties(${mxx} PROPERTIES COMPILE_FLAGS /module:export)
    endforeach()
    endif()

    source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/src" FILES ${ARG_MODULE_INTERFACE_UNITS} )
    source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/src" FILES ${ARG_MODULE_IMPLEMENTATION_UNITS} )
    #source_group("Module Interface Units" FILES ${ARG_MODULE_INTERFACE_UNITS} )

    add_library(${target} STATIC ${ARG_MODULE_INTERFACE_UNITS} ${ARG_MODULE_IMPLEMENTATION_UNITS})

    my_enable_modules(${target})

endfunction()

has_is_constant_evaluated(has_is_constant_evaluated_res)
has_three_way_comp(has_three_way_comp_res)

my_add_module(
        rem 
    MODULE_INTERFACE_UNITS
        src/internal/common.ixx
        src/internal/util.ixx
        src/vec/vec.ixx
        src/vec/arithmeticoperators.ixx
        src/vec/algebraicoperators.ixx
        src/vec/comparisonoperators.ixx
        src/vec/bitwiseoperators.ixx

        src/mat/mat.ixx
        src/mat/arithmeticoperators.ixx
        src/mat/bitwiseoperators.ixx
        src/mat/comparisonoperators.ixx
        src/mat/inverse.ixx
        src/mat/transpose.ixx
        src/mat/transform.ixx
        
        
        src/vec.ixx
        src/mat.ixx

        src/rem.ixx
        
    MODULE_IMPLEMENTATION_UNITS
        src/mat/transform.mxx
    )

    target_compile_definitions(rem PRIVATE REM_NAMESPACE_START=namespace\ rem{)
    target_compile_definitions(rem PRIVATE REM_NAMESPACE_END=})

    if(${has_is_constant_evaluated_res})
        target_compile_definitions(rem PRIVATE -DHAS_IS_CONSTANT_EVALUATED)
    endif()
    if(${has_three_way_comp_res})
        target_compile_definitions(rem PRIVATE -DHAS_3WAY_COMP)
    endif()

file(GLOB tests tests/*.cpp)
foreach(test ${tests})
    get_filename_component(testname ${test} NAME_WE)
    add_executable(${testname} ${test})
    my_enable_modules(${testname})
    target_link_libraries(${testname} rem)
    set_target_properties( ${testname} PROPERTIES FOLDER "tests")
endforeach(test ${tests})


