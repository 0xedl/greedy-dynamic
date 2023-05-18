#include <iostream>
#include <cstdlib>
#include <vector>

// 1. -> add up rows, 2. -> add up columns 3. -> iterate down/right find max otw and keep adding

int swampExplorer(std::vector<std::vector<int>> &swamp_maze) {
    int m = swamp_maze.size();
    int n = swamp_maze[0].size();
    std::vector<int> dp(n, 0);

    dp[0] = swamp_maze[0][0];
    for (int j = 1; j < n; j++) {
        dp[j] = dp[j - 1] + swamp_maze[0][j];
    }

    for (int i = 1; i < m; i++) {
        dp[0] += swamp_maze[i][0];
        for (int j = 1; j < n; j++) {
            dp[j] = std::max(dp[j], dp[j - 1]) + swamp_maze[i][j];
        }
    }

    return dp[n - 1];
}

int main() {
    std::vector<std::vector<int>> swamp_maze = {{5, 3, 4},
                                                {1, 6, 9},
                                                {9, 3, 2},
                                                {9, 6, 7},
                                                {9, 2, 3}}; // 5 + 1 + 9 + 9 + 6 + 7 + 3 = 40
    std::cout << swampExplorer(swamp_maze) << std::endl;
    return 0;
}
