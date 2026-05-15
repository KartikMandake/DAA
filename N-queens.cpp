#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check column above
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

void solve(int row, vector<string>& board, int n, vector<vector<string>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, board, n, solutions);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cout << "Enter board size (N): ";
    cin >> n;

    if (n < 1 || n > 15) {
        cout << "Please enter N between 1 and 15.\n";
        return 1;
    }

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;
    solve(0, board, n, solutions);

    cout << "\nTotal solutions for " << n << "-Queens: " << solutions.size() << "\n\n";
    for (int i = 0; i < (int)solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (auto& row : solutions[i]) {
            for (char c : row)
                cout << (c == 'Q' ? " Q" : " .") << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}