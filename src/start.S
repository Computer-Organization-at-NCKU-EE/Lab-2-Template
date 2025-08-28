        .section .text._start
        .global _start
_start:
        .option push
        .option norelax
        la gp, __global_pointer$ # symbol is set by linker
        .option pop
        la sp, __stack_top # symbol is set by linker
        # jump to main() func
        call main
        # end of the program
        tail terminate
