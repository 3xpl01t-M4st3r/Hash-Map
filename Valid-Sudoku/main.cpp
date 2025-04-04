
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_map<char, int>> row, col, box;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char num = board[i][j];
                if (num == '.')
                {
                    continue;
                }
                int bindex = (i / 3) * 3 + (j / 3);
                if (row[i][num]++ > 0 || col[j][num]++ > 0 || box[bindex][num]++ > 0)
                {
                    return false;
                }
            }
        }
        return true; 
    }
};

int main()
{
    vector<vector<char>> board(9, vector<char>(9));  
    cout << "Use '.' for empty cells:\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    Solution sol;
    cout << (sol.isValid(board) ? "Valid" : "Invalid") << endl;

    return 0;
}
