class Solution {
public:
    int func(int i, int j, vector<vector<int>>& obstacleGrid) {
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == -1){
            return 0;
        }
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }
        if (obstacleGrid[i][j] != 0)
            return obstacleGrid[i][j];

        int left = func(i, j - 1, obstacleGrid);
        int up = func(i - 1, j, obstacleGrid);

        return obstacleGrid[i][j] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = -1;
                    // break;
                }
            }
        }
        return func(m - 1, n - 1, obstacleGrid);
    }
};