#include <iostream>
#include <vector>

using namespace std;

void solveNQueens(int n, int row, int ld, int rd, int col, int &solutions)
{
    if (row == n)
    {
        solutions++;
        return;
    }

    int availablePositions = ((1 << n) - 1) & (~(col | ld | rd));

    while (availablePositions)
    {
        int position = availablePositions & -availablePositions;
        availablePositions -= position;

        solveNQueens(n, row + 1, (ld | position) << 1, (rd | position) >> 1, col | position, solutions);
    }
}

int totalNQueens(int n)
{
    int solutions = 0;
    solveNQueens(n, 0, 0, 0, 0, solutions);
    return solutions;
}

int main()
{
    int n = 18; // You can change N to the desired value.

    int solutions = totalNQueens(n);

    cout << "Total solutions for " << n << "-Queens: " << solutions << endl;

    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// void solveNQueens(int n, int row, int ld, int rd, int col, int &solutions)
// {
//     if (row == n)
//     {
//         solutions++;
//         return;
//     }

//     int availablePositions = ((1 << n) - 1) & (~(col | ld | rd));

//     while (availablePositions)
//     {
//         int position = availablePositions & -availablePositions;
//         availablePositions -= position;

//         solveNQueens(n, row + 1, (ld | position) << 1, (rd | position) >> 1, col | position, solutions);
//     }
// }

// int totalNQueens(int n)
// {
//     int solutions = 0;
//     solveNQueens(n, 0, 0, 0, 0, solutions);
//     return solutions;
// }

// int main()
// {
//     int n;
//     cout << "Enter the board size (N): ";
//     cin >> n;

//     if (n <= 0)
//     {
//         cout << "Invalid board size. Please enter a positive integer." << endl;
//         return 1;
//     }

//     int solutions = totalNQueens(n);

//     cout << "Total solutions for " << n << "-Queens: " << solutions << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// // Helper function to solve the N-Queens problem.
// void solveNQueens(int n, int row, vector<string> &board, vector<bool> &col, vector<bool> &leftDiag, vector<bool> &rightDiag, int &solutions)
// {
//     if (row == n)
//     {
//         solutions++;
//         return;
//     }

//     for (int c = 0; c < n; c++)
//     {
//         if (!col[c] && !leftDiag[row - c + n - 1] && !rightDiag[row + c])
//         {
//             board[row][c] = 'Q';
//             col[c] = leftDiag[row - c + n - 1] = rightDiag[row + c] = true;

//             solveNQueens(n, row + 1, board, col, leftDiag, rightDiag, solutions);

//             board[row][c] = '.';
//             col[c] = leftDiag[row - c + n - 1] = rightDiag[row + c] = false;
//         }
//     }
// }

// int totalNQueens(int n)
// {
//     int solutions = 0;

//     vector<string> board(n, string(n, '.'));
//     vector<bool> col(n, false);
//     vector<bool> leftDiag(2 * n - 1, false);
//     vector<bool> rightDiag(2 * n - 1, false);

//     solveNQueens(n, 0, board, col, leftDiag, rightDiag, solutions);

//     return solutions;
// }

// int main()
// {
//     int n;
//     cout << "Enter the board size (N): ";
//     cin >> n;

//     if (n <= 0)
//     {
//         cout << "Invalid board size. Please enter a positive integer." << endl;
//         return 1;
//     }

//     int solutions = totalNQueens(n);

//     cout << "Total solutions for " << n << "-Queens: " << solutions << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// // Global variable for storing the number of solutions.
// int totalSolutions = 0;

// // Helper function to solve the N-Queens problem.
// void solveNQueens(int n, int row, int ld, int rd, int col, vector<string> &board)
// {
//     if (row == n)
//     {
//         totalSolutions++;
//         cout << "Solution " << totalSolutions << ":\n";
//         for (int i = 0; i < n; i++)
//         {
//             cout << board[i] << endl;
//         }
//         cout << endl;
//         return;
//     }

//     int availablePositions = ((1 << n) - 1) & (~(col | ld | rd));

//     while (availablePositions)
//     {
//         int position = availablePositions & -availablePositions;
//         availablePositions -= position;

//         string rowStr(n, '.');
//         rowStr[__builtin_ctz(position)] = 'Q';

//         board[row] = rowStr;
//         solveNQueens(n, row + 1, (ld | position) << 1, (rd | position) >> 1, col | position, board);
//         board[row] = string(n, '.');
//     }
// }

// int totalNQueens(int n)
// {
//     totalSolutions = 0;

//     vector<string> board(n, string(n, '.'));

//     solveNQueens(n, 0, 0, 0, 0, board);

//     return totalSolutions;
// }

// int main()
// {
//     int n;
//     cout << "Enter the board size (N): ";
//     cin >> n;

//     if (n <= 0)
//     {
//         cout << "Invalid board size. Please enter a positive integer." << endl;
//         return 1;
//     }

//     int solutions = totalNQueens(n);

//     cout << "Total solutions for " << n << "-Queens: " << solutions << endl;

//     return 0;
// }
