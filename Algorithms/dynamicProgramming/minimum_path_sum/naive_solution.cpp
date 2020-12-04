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

    cout << "\nThe minimum path sum is " << minPathSum(0, 0, grid) << "\n";
    
    return 0;
}

int minPathSum(int row, int col, vector<vector<int>> &grid) {
    if(row == grid.size() - 1 && col == grid[row].size() - 1) {
        return grid[row][col];
    }
    else if(row < grid.size() - 1 && col == grid[row].size() - 1) {
        return grid[row][col] + minPathSum(row + 1, col, grid);
    }
    else if(row == grid.size() - 1 && col < grid[row].size() - 1) {
        return grid[row][col] + minPathSum(row, col + 1, grid);
    }
    else {
        return grid[row][col] + utility::min(minPathSum(row + 1, col, grid), minPathSum(row, col + 1, grid));
    }
}