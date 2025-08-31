# set compiler by  riscv-gnu-toolchain
set(CMAKE_C_COMPILER riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv32-unknown-elf-gcc)
set(CMAKE_OBJDUMP riscv32-unknown-elf-objdump)
set(CMAKE_OBJCOPY riscv32-unknown-elf-objcopy)

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

    # add custom commands to generate disassembly dump and hex dump files
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${prog}.disasm
        COMMAND ${CMAKE_OBJDUMP} -xsd ${CMAKE_CURRENT_BINARY_DIR}/${prog} > ${CMAKE_CURRENT_BINARY_DIR}/${prog}.disasm
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${prog}
    )
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${prog}.hex
        COMMAND ${CMAKE_OBJCOPY} -S -O verilog ${CMAKE_CURRENT_BINARY_DIR}/${prog} ${CMAKE_CURRENT_BINARY_DIR}/${prog}.hex
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${prog}
    )
    add_custom_target(
        ${prog}-dump ALL
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${prog}.disasm ${CMAKE_CURRENT_BINARY_DIR}/${prog}.hex
    )
endforeach()
