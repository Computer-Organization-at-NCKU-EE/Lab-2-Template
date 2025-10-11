# Tester for Merge Sort (array_sort)
add_executable(ArraySortChecker array_sort_checker.c)
target_link_libraries(ArraySortChecker iss)
add_test(NAME MergeSortTester )

# Tester for 2x2 Sudoku Solver
add_executable(SudokuSolverTester sudoku_solver_tester.c)
target_link_libraries(SudokuSolverTester iss)
