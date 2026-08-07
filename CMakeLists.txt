cmake_minimum_required(VERSION 4.0)
project(BZCC-DLL-Example)

add_library(Mission SHARED)
target_compile_features(Mission PRIVATE cxx_std_23)

target_include_directories(Mission PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

target_sources(Mission PRIVATE
    src/dllmain.cpp
    src/Mission.cpp
)

add_library(libbzcc STATIC IMPORTED)

set_target_properties(libbzcc PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/battlezone2.lib
)

target_include_directories(libbzcc INTERFACE
    include/
)

target_link_libraries(Mission PRIVATE libbzcc)


#[[ Todo: better way to do this, if you need compile commands for your editor
it might need to be in the build folder to detect it
file(CREATE_LINK
    "${PRESET_DIR}/compile_commands.json"
    "${CMAKE_SOURCE_DIR}/build/compile_commands.json"
    SYMBOLIC
)
]]
