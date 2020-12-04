#include<bits/stdc++.h>
#include<climits>
#include<cmath>

using namespace std;

class utility {
    public:
        static int min(int a, int b) {
            return (a > b)? b : a;
        }

        static int max(int a, int b) {
            return (a > b)? a : b;
        }
};

int minPathSum(int row, int col, vector<vector<int>> &grid);
int minPathSum_helper(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &answers);

int main() {
    int m, n;

    cout << "\nEnter Number of Rows : ";
    cin >> m;
    cout << "Enter Number of Columns : ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\nThe minimum path sum is " << minPathSum(grid) << "\n";
    
    return 0;
}

int minPathSum(vector<vector<int>> &grid) {
    vector<vector<int>> answers(grid.size(), vector<int>(grid[0].size(), INT_MIN));

    minPathSum_helper(0, 0, grid, answers);

    return answers[0][0];
}

int minPathSum_helper(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &answers) {
    if(answers[row][col] == INT_MIN) {
        if(row == grid.size() - 1 && col == grid[row].size() - 1) {
            answers[row][col] = grid[row][col];
        }
        else if(row < grid.size() - 1 && col == grid[row].size() - 1) {
            answers[row][col] = grid[row][col] + minPathSum_helper(row + 1, col, grid, answers);
        }
        else if(row == grid.size() - 1 && col < grid[row].size() - 1) {
            answers[row][col] = grid[row][col] + minPathSum_helper(row, col + 1, grid, answers);
        }
        else {
            answers[row][col] = grid[row][col] + utility::min(minPathSum_helper(row + 1, col, grid, answers), minPathSum_helper(row, col + 1, grid, answers));
        }   
    }
    return answers[row][col];
}