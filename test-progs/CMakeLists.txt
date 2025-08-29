# set compiler by  riscv-gnu-toolchain
set(CMAKE_C_COMPILER riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv32-unknown-elf-gcc)

# set common compile flags
set(COMMON_COMPILE_FLAG -march=rv32i -mabi=ilp32 -ffreestanding -fno-builtin -Wall -Werror)

# test-progs list
set(TEST_PROGS main msort qsort matmul malloc_test)

foreach(prog IN LISTS TEST_PROGS)
    # setup target main (executable)
    add_executable(${prog})
    target_sources(${prog} PRIVATE ${prog}.c)
    target_include_directories(${prog} PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_compile_options(${prog} PRIVATE ${COMMON_COMPILE_FLAG})
    target_link_libraries(${prog} startup base gcc)
    target_link_options(${prog} PRIVATE -nostdlib -nostartfiles -static -T${CMAKE_SOURCE_DIR}/src/link.ld -Xlinker --print-memory-usage)
endforeach()
