#include "sudoku.h"


Sudoku::Sudoku() {
    grid = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}

Sudoku::Sudoku(const std::vector<std::vector<int>> &grid) {
    this->grid = grid;
}

Sudoku::Sudoku(const Sudoku &other) {
    grid = other.grid;
}

Sudoku::Sudoku(Sudoku &&other) {
    grid = std::move(other.grid);
}

Sudoku &Sudoku::operator=(const Sudoku &other) {
    grid = other.grid;
    return *this;
}

Sudoku &Sudoku::operator=(Sudoku &&other) {
    grid = std::move(other.grid);
    return *this;
}

Sudoku::~Sudoku() {
}

void Sudoku::setGrid(const std::vector<std::vector<int>> &grid) {
    this->grid = grid;
}

std::vector<std::vector<int>> Sudoku::getGrid() const {
    return grid;
}

void Sudoku::setCell(int row, int col, int value) {
    grid[row][col] = value;
}

int Sudoku::getCell(int row, int col) const {
    return grid[row][col];
}

void Sudoku::read_file(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    int row = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int col = 0;
        int value;
        while (iss >> value) {
            grid[row][col] = value;
            col++;
        }
        row++;
    }
}


bool Sudoku::isSolved() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Sudoku &sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            os << sudoku.grid[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
