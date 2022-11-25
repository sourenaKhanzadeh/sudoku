#ifndef SOLVER_H
#define SOLVER_H


#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <sudoku/sudoku.h>



class Solver {
public:
    Solver();
    Solver(const std::vector<std::vector<int>> &grid);
    Solver(const Solver &other);
    Solver(Solver &&other);
    Solver(Sudoku &sudoku);
    Solver &operator=(const Solver &other);
    Solver &operator=(Solver &&other);
    ~Solver();

    void setGrid(const std::vector<std::vector<int>> &grid);
    std::vector<std::vector<int>> getGrid() const;

    void setCell(int row, int col, int value);
    int getCell(int row, int col) const;

    bool isSolved() const;
    void solve();
    bool isValid(int row, int col, int value) const;

    friend std::ostream &operator<<(std::ostream &os, const Solver &solver);


private:
    std::vector<std::vector<int>> grid;
};


#endif // SOLVER_H