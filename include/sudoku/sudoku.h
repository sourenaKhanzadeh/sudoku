#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>



class Sudoku {
public:
    Sudoku();
    Sudoku(const std::vector<std::vector<int>> &grid);
    Sudoku(const Sudoku &other);
    Sudoku(Sudoku &&other);
    Sudoku &operator=(const Sudoku &other);
    Sudoku &operator=(Sudoku &&other);
    ~Sudoku();

    void setGrid(const std::vector<std::vector<int>> &grid);
    std::vector<std::vector<int>> getGrid() const;

    void setCell(int row, int col, int value);
    int getCell(int row, int col) const;

    bool isSolved() const;
    void read_file(std::string filename);

    void generate(std::string tofile);

    friend std::ostream &operator<<(std::ostream &os, const Sudoku &sudoku);


private:
    std::vector<std::vector<int>> grid;
};


#endif // SUDOKU_H