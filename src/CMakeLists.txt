# set compiler by  riscv-gnu-toolchain
set(CMAKE_C_COMPILER riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv32-unknown-elf-gcc)

# set source file list of libbase
set(LIB_SRCS basic.c print.c memory.c)

# set common compile flags
set(COMMON_COMPILE_FLAG -march=rv32i -mabi=ilp32 -ffreestanding -fno-builtin -Wall -Werror)

# setup target base (static library)
add_library(base STATIC)
target_sources(base PRIVATE ${LIB_SRCS})
target_include_directories(base PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(base PRIVATE ${COMMON_COMPILE_FLAG})

# setup startup files object (which defines _start symbol)
add_library(startup OBJECT ${CMAKE_SOURCE_DIR}/src/start.S)
target_compile_options(startup PRIVATE ${COMMON_COMPILE_FLAG})
