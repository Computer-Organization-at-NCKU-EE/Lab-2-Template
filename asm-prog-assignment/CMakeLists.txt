include(${CMAKE_SOURCE_DIR}/cmake/riscv.cmake)

# setup target ArraySort
add_executable(ArraySort ${CMAKE_CURRENT_SOURCE_DIR}/merge.S)
target_compile_options(ArraySort PRIVATE ${COMMON_COMPILE_FLAG})
target_link_libraries(ArraySort startup base gcc)
target_link_options(ArraySort PRIVATE -nostdlib -nostartfiles -static -T${PROJECT_SOURCE_DIR}/src/link.ld)

# setup target Sudoku
add_executable(Sudoku ${CMAKE_CURRENT_SOURCE_DIR}/sudoku.S)
target_compile_options(Sudoku PRIVATE ${COMMON_COMPILE_FLAG})
target_link_libraries(Sudoku startup base gcc)
target_link_options(Sudoku PRIVATE -nostdlib -nostartfiles -static -T${PROJECT_SOURCE_DIR}/src/link.ld)
