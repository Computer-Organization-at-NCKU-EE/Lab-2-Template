include(${CMAKE_SOURCE_DIR}/cmake/riscv.cmake)

# setup target ArraySort
add_executable(ArraySort ${CMAKE_CURRENT_SOURCE_DIR}/merge.c ${CMAKE_CURRENT_SOURCE_DIR}/merge.S)
target_compile_options(ArraySort PRIVATE ${COMMON_COMPILE_FLAG})
target_include_directories(ArraySort PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(ArraySort startup base gcc)
target_link_options(ArraySort PRIVATE -nostdlib -nostartfiles -static -T${PROJECT_SOURCE_DIR}/src/link.ld)
# generate random test case for Array Sort
string(RANDOM LENGTH 2 ALPHABET "123456789" MERGE_SORT_RANDOM_ARRAY_SIZE)
set(MERGE_SORT_RANDOM_ARRAY "")
foreach(i RANGE 0 ${MERGE_SORT_RANDOM_ARRAY_SIZE})
  string(RANDOM LENGTH 2 ALPHABET "123456789" random_val)
  string(APPEND MERGE_SORT_RANDOM_ARRAY, "{random_val}, ")
endforeach()
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/merge_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/merge_config.h)

# setup target Sudoku
add_executable(Sudoku ${CMAKE_CURRENT_SOURCE_DIR}/sudoku.c ${CMAKE_CURRENT_SOURCE_DIR}/sudoku.S)
target_compile_options(Sudoku PRIVATE ${COMMON_COMPILE_FLAG})
target_include_directories(Sudoku PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Sudoku startup base gcc)
target_link_options(Sudoku PRIVATE -nostdlib -nostartfiles -static -T${PROJECT_SOURCE_DIR}/src/link.ld)
# generate random test case for Sudoku Solver
set(SUDOKU_RANDOM_ARRAY "2, 4, -1, -1, 3, 1, -1, 2, -1, 3, -1, 4, -1, 2, 3, 1")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sudoku_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/sudoku_config.h)
