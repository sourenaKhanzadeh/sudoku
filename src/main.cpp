#include <iostream>

#include <sudoku/solver.h>
#include <sudoku/sudoku.h>

int main(){
    Sudoku sudoku;
    
    sudoku.generate("generated.txt");

    sudoku.read_file("su.txt");
    
    Solver solver(sudoku);
    solver.solve();
    std::cout << solver;
    return 0;
}