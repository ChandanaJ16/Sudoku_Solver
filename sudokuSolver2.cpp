#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define DASH "-------------------------------------"
#define N 9

bool RulesObeyed(int grid[N][N], int i, int j, int k)
{
    for (int p = 0; p < N; p++)
    { // row + col
        if (grid[i][p] == k || grid[p][j] == k)
        {
            return false;
        }
    }
    int sub_s = (int)sqrt(N);
    int r_i = i - i % sub_s, c_i = j - j % sub_s;
    for (int p = r_i; p < r_i+sub_s ; p++)
    {
        for (int q = c_i; q < c_i+sub_s; q++)
        {
            if (grid[p][q] == k)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudoku_solver(int grid[N][N])
{   int i,j, row, col;
    bool notSolved = false;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {   row = i;
                col = j;
                notSolved = true;
            }
        }
        if(notSolved == true){
            break;
        }
    }
    if (notSolved == false)
    {
        return true;
    }

    for (int y = 1; y <= N; y++)
    {
        if (RulesObeyed(grid, row, col, y))
        {
            grid[row][col] = y;
            if (sudoku_solver(grid))
            {
                return true;
            }
            else
            {
                grid[row][col] = 0;
            }
        }
    }

    return false;
}

void print_grid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        cout << "    " << endl;
        cout << DASH << endl;
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j])
            {
                cout << grid[i][j];
            }
            else
            {
                cout << " ";
            }
            cout << " | ";
        }
    }
    cout << endl << endl;
}

int main()
{
    int grid[N][N] = {{0, 9, 0, 0, 0, 0, 8, 5, 3},
                      {0, 0, 0, 8, 0, 0, 0, 0, 4},
                      {0, 0, 8, 2, 0, 3, 0, 6, 9},
                      {5, 7, 4, 0, 0, 2, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 9, 0, 0, 6, 3, 7},
                      {9, 4, 0, 1, 0, 8, 5, 0, 0},
                      {7, 0, 0, 0, 0, 6, 0, 0, 0},
                      {6, 8, 2, 0, 0, 0, 0, 9, 0}};
    cout << "Sudoku Solver: " << endl;
    print_grid(grid); // display the input sudoku
    if (sudoku_solver(grid))
    {
        cout << "Solved Puzzle: " << endl;
        print_grid(grid);
    }
    else
    {
        cout << "No solution" << endl;
    }
    return 0;
}