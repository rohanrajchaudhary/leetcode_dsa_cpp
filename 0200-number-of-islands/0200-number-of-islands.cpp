class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r, int c)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        grid[r][c] = '0';
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1')
            {
                dfs(grid,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};