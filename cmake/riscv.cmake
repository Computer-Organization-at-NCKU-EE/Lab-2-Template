# set compiler by  riscv-gnu-toolchain
set(CMAKE_C_COMPILER riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv32-unknown-elf-gcc)
set(CMAKE_OBJDUMP riscv32-unknown-elf-objdump)
set(CMAKE_OBJCOPY riscv32-unknown-elf-objcopy)

# set common compile flags
set(COMMON_COMPILE_FLAG -march=rv32i -mabi=ilp32 -ffreestanding -fno-builtin -Wall -Werror)
