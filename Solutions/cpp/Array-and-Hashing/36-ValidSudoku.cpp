#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// vector of unordered_set *** if you want to use pair for keys in map or set, you have to define hash
// Time:O(N^2)
// Space:O(N^2)
class Solution1
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int size = board.size();
        vector<unordered_set<char>> rows(size);
        vector<unordered_set<char>> cols(size);
        vector<vector<unordered_set<char>>> squars(3, vector<unordered_set<char>>(3));

        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                char element = board[r][c];
                if (element == '.')
                    continue;
                if (rows[r].find(element) != rows[r].end() ||
                    cols[c].find(element) != cols[c].end() ||
                    squars[r / 3][c / 3].find(element) != squars[r / 3][c / 3].end())
                    return false;
                rows[r].insert(element);
                cols[c].insert(element);
                squars[r / 3][c / 3].insert(element);
            }
        }
        return true;
    }
};

// array
// Time:O(N^2)
// Space:O(N^2)
class Solution2
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        const int cnt = 9;
        bool rows[cnt][cnt] = {false};
        bool cols[cnt][cnt] = {false};
        bool squars[cnt][cnt] = {false};

        for (int r = 0; r < cnt; r++)
        {
            for (int c = 0; c < cnt; c++)
            {
                int idx = board[r][c] - '0' - 1;
                if (board[r][c] == '.')
                    continue;
                int area = (r / 3) * 3 + c / 3;
                if (rows[r][idx] || cols[c][idx] || squars[area][idx])
                    return false;
                rows[r][idx] = true;
                cols[c][idx] = true;
                squars[area][idx] = true;
            }
        }
        return true;
    }
};

int main()
{
    Solution1 solution1;
    Solution2 solution2;

    return 0;
}