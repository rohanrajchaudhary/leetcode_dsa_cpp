class Solution {
public:

    bool solve(vector<vector<char>>& board, string& word,
               int row, int col, int index)
    {
        if(index == word.size())
        {
            return true;
        }

        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size())
        {
            return false;
        }

        if(board[row][col] != word[index])
        {
            return false;
        }

        char original = board[row][col];
        board[row][col] = '#';

        bool found = solve(board, word, row - 1, col, index + 1);

        if(found == false)
        {
            found = solve(board, word, row + 1, col, index + 1);
        }

        if(found == false)
        {
            found = solve(board, word, row, col - 1, index + 1);
        }

        if(found == false)
        {
            found = solve(board, word, row, col + 1, index + 1);
        }

        board[row][col] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(solve(board, word, row, col, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};