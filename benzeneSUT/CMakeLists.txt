project(BenzeneSUT VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB BENZENE_SUT_SRC "src/*.cpp")
include_directories("src")

add_executable(BenzeneSUT ${BENZENE_SUT_SRC})

target_link_libraries(BenzeneSUT Benzene)
add_custom_command(TARGET BenzeneSUT POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:BenzeneSUT> $<TARGET_RUNTIME_DLLS:BenzeneSUT>
  COMMAND_EXPAND_LISTS
)