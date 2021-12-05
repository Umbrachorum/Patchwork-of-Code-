cmake_minimum_required(VERSION 3.12)
project(abstractVM CXX)


### GTEST ###

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

set(SOURCES
        Exceptions
        BigDecimal
        Double
        Factory
        Float
        Int8
        Int16
        Int32
        Stack
        Core
        is_empty
        Parser
        main
        roundOperand)

list(TRANSFORM SOURCES PREPEND src/)
add_executable(abstractVM ${SOURCES})
target_include_directories(abstractVM PRIVATE include)

####

set(SOURCES
        Exceptions
        BigDecimal
        Double
        Factory
        Float
        Int8
        Int16
        Int32
        Stack
        Core
        Parser
        is_empty
        roundOperand
        )

list(TRANSFORM SOURCES PREPEND src/)

set(SOURCES_TESTS
        test_stack
        test_core
        test_parsing
        test_factory
        test_div
        test_add
        test_mod
        test_sub
        test_mul
        test_roundOperand)

list(TRANSFORM SOURCES_TESTS PREPEND tests/)

add_executable(abstractVM_test ${SOURCES} ${SOURCES_TESTS})
target_include_directories(abstractVM_test PRIVATE include)
target_link_libraries(abstractVM_test gtest_main)