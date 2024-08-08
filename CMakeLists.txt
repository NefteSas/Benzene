cmake_minimum_required(VERSION 3.0.0)
project(Benzene VERSION 0.1.0 LANGUAGES C CXX)
include(CMakePrintHelpers)
option(USE_SUT "Compile a standard library usage tool?" ON)
set(MAX_ELEMENT_ID_LENGH 16 CACHE STRING "MAX_ELEMENT_ID_LENGH")
#Когда будет уровни Бета и Гамма добавь их выбор


file(GLOB BenzeneSources "benzene/*.cpp")
file(GLOB BenzeneDefenitions "benzene/*.h")

file(GLOB AlphaSources "benzene/alpha/*.cpp")
file(GLOB AlphaDefenitions "benzene/alpha/*.h")

#add_compile_definitions(MAX_ELEMENT_LENGH=${MAX_ELEMENT_ID_LENGH
add_library(Benzene SHARED ${BenzeneSources} ${BenzeneDefenitions})

target_sources(Benzene PUBLIC ${AlphaSources} ${AlphaDefenitions})
set_target_properties(Benzene PROPERTIES PREFIX "")

if (USE_SUT)
    include_directories(benzene BenzeneSUT)
    add_subdirectory(BenzeneSUT)
endif() 