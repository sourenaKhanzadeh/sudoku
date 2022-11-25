#include "solver.h"

Solver::Solver() {
    grid = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}

Solver::Solver(const std::vector<std::vector<int>> &grid) {
    this->grid = grid;
}

Solver::Solver(const Solver &other) {
    grid = other.grid;
}

Solver::Solver(Solver &&other) {
    grid = std::move(other.grid);
}

Solver &Solver::operator=(const Solver &other) {
    grid = other.grid;
    return *this;
}

Solver::Solver(Sudoku &sudoku) {
    grid = sudoku.getGrid();
}

Solver &Solver::operator=(Solver &&other) {
    grid = std::move(other.grid);
    return *this;
}

Solver::~Solver() {
}

void Solver::setGrid(const std::vector<std::vector<int>> &grid) {
    this->grid = grid;
}

std::vector<std::vector<int>> Solver::getGrid() const {
    return grid;
}

void Solver::setCell(int row, int col, int value) {
    grid[row][col] = value;
}

int Solver::getCell(int row, int col) const {
    return grid[row][col];
}

bool Solver::isSolved() const {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

void Solver::solve() {
    if (isSolved()) {
        return;
    }
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (grid[row][col] == 0) {
                for (int value = 1; value <= 9; value++) {
                    if (isValid(row, col, value)) {
                        grid[row][col] = value;
                        solve();
                        if (isSolved()) {
                            return;
                        }
                        grid[row][col] = 0;
                    }
                }
                return;
            }
        }
    }
}

bool Solver::isValid(int row, int col, int value) const {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == value) {
            return false;
        }
        if (grid[i][col] == value) {
            return false;
        }
    }
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Solver &solver) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            os << solver.grid[row][col] << " ";
        }
        os << std::endl;
    }
    return os;
}
