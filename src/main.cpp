#include <iostream>

#include <sudoku/solver.h>
#include <sudoku/sudoku.h>

int main(){
    Sudoku sudoku;
    
    sudoku.read_file("su.txt");

    std::cout << sudoku << std::endl;

    return 0;
}