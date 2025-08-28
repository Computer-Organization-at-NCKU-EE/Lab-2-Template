# set compiler by  riscv-gnu-toolchain
set(CMAKE_C_COMPILER riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv32-unknown-elf-gcc)

# set common compile flags
set(COMMON_COMPILE_FLAG -march=rv32i -mabi=ilp32 -ffreestanding -fno-builtin -Wall -Werror)

# setup target main (executable)
add_executable(main)
target_sources(main PRIVATE main.c)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(main PRIVATE ${COMMON_COMPILE_FLAG})
target_link_libraries(main startup base gcc)
target_link_options(main PRIVATE -nostdlib -nostartfiles -static -T${CMAKE_SOURCE_DIR}/src/link.ld -Xlinker --print-memory-usage)
