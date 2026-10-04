class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();
      vector<int> zeroRows(rows,0);
      vector<int> zeroCols(cols,0);
      for(int i = 0; i < rows; i++)
      {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == 0)
            {
                zeroRows[i] = 1;
                zeroCols[j] = 1;
            }
        }
      }  
      for(int i = 0; i < rows; i++)
      {
        for(int j = 0; j < cols; j++)
        {
            if(zeroRows[i] == 1 || zeroCols[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
      }
    }
};