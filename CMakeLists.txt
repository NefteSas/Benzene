cmake_minimum_required(VERSION 3.0.0)
project(Benzene VERSION 0.1.0 LANGUAGES C CXX)

option(USE_SUT "Compile a standard library usage tool?" ON)
#Когда будет уровни Бета и Гамма добавь их выбор
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out/library/)


file(GLOB AlphaSources "benzene/alpha/*.cpp")
file(GLOB AlphaDefenitions "benzene/alpha/*.h")

include_directories(benzene benzene/alpha)

add_library(Benzene SHARED ${AlphaSources} ${AlphaDefenitions})
set_target_properties(Benzene PROPERTIES PREFIX "")

if (USE_SUT)
    include_directories(benzene BenzeneSUT)
    add_subdirectory(BenzeneSUT)
endif()