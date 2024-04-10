cmake_minimum_required(VERSION 3.21)
project(projeto-1-caiowporto C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        libprg
        GIT_REPOSITORY https://github.com/caiowporto/libprg
        GIT_TAG origin/main
        # GIT_TAG 0.0.1
        # You can reference a local directory instead
        # URL file:///${CMAKE_CURRENT_SOURCE_DIR}/../libprg
)
FetchContent_MakeAvailable(libprg)

add_executable(projeto-1-caiowporto main.c)

# linking libprg
target_link_libraries(projeto-1-caiowporto PUBLIC libprg)




