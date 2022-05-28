cmake_minimum_required(VERSION 3.10)

set(ModName ExNihiloBedrock)
set(SourceDir source)
set(IncludeDir include)

# maybe figure out a way to move this all to another cmake file?
set(CMAKE_ASM_NASM_OBJECT_FORMAT win64)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT DEFINED CMAKE_ASM_NASM_COMPILER)
    if(DEFINED ENV{ASM_NASM})
        set(CMAKE_ASM_NASM_COMPILER $ENV{ASM_NASM})
    elseif(DEFINED ENV{NASMPATH}) # https://github.com/ShiftMediaProject/VSNASM
        set(CMAKE_ASM_NASM_COMPILER $ENV{NASMPATH})
    elseif(EXISTS "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/nasm.exe")
        set(CMAKE_ASM_NASM_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/nasm.exe")
    # add more cases in the future (like the other visual studios)
    endif()

    if(DEFINED CMAKE_ASM_NASM_COMPILER)
        string(REPLACE "\\" "/" CMAKE_ASM_NASM_COMPILER ${CMAKE_ASM_NASM_COMPILER})
    endif()
endif()

project(${ModName} CXX ASM_NASM)
enable_language(ASM_NASM)

if(MSVC)
    set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

    foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "$ENV{ZENOVA_DATA}/mods/${ModName}")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "$ENV{ZENOVA_DATA}/mods/${ModName}")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "$ENV{ZENOVA_DATA}/mods/${ModName}")
    endforeach(OUTPUTCONFIG)
endif()

include_directories("$ENV{ZENOVA_DATA}/dev/inc"
    "${SourceDir}"
    "${IncludeDir}")

file(GLOB_RECURSE INCLUDE_LIST
    "${IncludeDir}/*.hpp"
    "${IncludeDir}/*.h"
)

file(GLOB_RECURSE SRC_INCLUDE_LIST
    "${SourceDir}/*.hpp"
    "${SourceDir}/*.h"
)

file(GLOB_RECURSE INC_SOURCE_LIST
    "${IncludeDir}/*.cpp"
    "${IncludeDir}/*.cxx"
    "${IncludeDir}/*.cc"
    "${IncludeDir}/*.asm"
)

file(GLOB_RECURSE SOURCE_LIST
    "${SourceDir}/*.cpp"
    "${SourceDir}/*.cxx"
    "${SourceDir}/*.cc"
    "${SourceDir}/*.asm"
)

add_library(${ModName} SHARED
    ${SRC_INCLUDE_LIST}
    ${INCLUDE_LIST}
    ${INC_SOURCE_LIST}
    ${SOURCE_LIST}
)

target_link_libraries(${ModName} 
    $ENV{ZENOVA_DATA}/dev/lib/ZenovaAPI.lib
)

add_custom_command(TARGET ${ModName}
    PRE_BUILD
    COMMAND py -3 $ENV{ZENOVA_DATA}/dev/tools/process_symbol_map.py -e -a x64 -p windows -d ${CMAKE_CURRENT_SOURCE_DIR}/${SourceDir}/generated ${CMAKE_CURRENT_SOURCE_DIR}/maps/*.json
)

add_custom_command(TARGET ${ModName}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources
    $ENV{ZENOVA_DATA}/mods/${ModName}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/${IncludeDir} PREFIX "Header Files//" FILES ${INCLUDE_LIST})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/${SourceDir} PREFIX "Header Files//" FILES ${SRC_INCLUDE_LIST})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/${IncludeDir} PREFIX "Source Files//" FILES ${INC_SOURCE_LIST})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/${SourceDir} PREFIX "Source Files//" FILES ${SOURCE_LIST})