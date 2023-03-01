#cmake_minimum_required(VERSION 3.5)

#project(Otus_cpp_11 LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(Otus_cpp_11 main.cpp
#    gettingCommands.h gettingCommands.cpp
#    initTable.h initTable.cpp
#    error_code.h error_code.cpp serverTables.h serverTables.cpp
#    server_commands.h server_commands.cpp)

cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
   project(Otus_cpp_11 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
   project(Otus_cpp_11 VERSION 0.0.1)
endif()

find_package(GTest REQUIRED)
find_package(Boost REQUIRED)

#set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
#file(GLOB HEADER_FILES ${INCLUDE_DIR}/*.h)
#add_executable(Otus_cpp_11 ${HEADER_FILES} main.cpp)
add_executable(Otus_cpp_11 main.cpp
    gettingCommands.h gettingCommands.cpp
    initTable.h initTable.cpp
    error_code.h error_code.cpp serverTables.h serverTables.cpp
    server_commands.h server_commands.cpp tests_ggogle.cpp)


set_target_properties(Otus_cpp_11 PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIR};${INCLUDE_DIR}"
)

enable_testing()
add_executable(Otus_cpp_11_tests ${HEADER_FILES} main.cpp)

set_target_properties(Otus_cpp_11_tests PROPERTIES INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS} )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        set_target_properties(Otus_cpp_11 PROPERTIES COMPILE_OPTIONS -W3)
        target_link_libraries(Otus_cpp_11 ${Boost_LIBRARIES} )
        target_link_libraries(Otus_cpp_11_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
else()
        set_target_properties(Otus_cpp_11 PROPERTIES COMPILE_OPTIONS -Wpedantic -Wall -Wextra)
        target_link_libraries(Otus_cpp_11 pthread ${Boost_LIBRARIES} )
        target_link_libraries(Otus_cpp_11_tests pthread ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
endif()


add_test(test_symmetric_difference	Otus_cpp_11_tests)
add_test(test_intersection			Otus_cpp_11_tests)
add_test(test_output				Otus_cpp_11_tests)
add_test(test_commands				Otus_cpp_11_tests)
add_test(test_command_errors		Otus_cpp_11_tests)

install(TARGETS Otus_cpp_11 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT Alttaira@yandex.ru)

include (CPack)
